#pragma once

#include <vector>
#include <cstring>
#include <bits/stdc++.h>

#include <zephyr/kernel.h>
#include <zephyr/sys/util.h>
#include <memory>
#include <functional>
#include <zephyr/kernel/thread_stack.h>
#include <zephyr/logging/log.h>

#include "event.hpp"
#include "messages.hpp"

// Max number of events in queue
#define COMPONENT_QUEUE_SIZE 10
#define CONFIG_MAIN_THREAD_STACK_SIZE 1024
#define CONFIG_MAIN_THREAD_PRIORITY 5

class Component {
public:
    Component(const char* name, int priority = 5)
        : name_(name), priority_(priority) {
        k_msgq_init(&queue_, queue_buffer_, sizeof(Event), COMPONENT_QUEUE_SIZE);
    }

    virtual ~Component() = default;

    virtual void handle_event(const Event& evt) = 0;
    virtual void handle_event(const MessageType_t& evt) = 0;

    virtual void init_component() = 0;

    virtual void run() = 0;

    struct k_msgq* get_queue() {
        return &queue_;
    }

    // Subscribe another component to receive our events
    void subscribe(k_msgq* component) {
        subscribers_.push_back(component);
    }

    void start() {

        thread_id = k_thread_create(&thread, threadStack,
                            K_THREAD_STACK_SIZEOF(threadStack),
                            thread_entry,
                            this, NULL, NULL,
                            priority_, 0, K_NO_WAIT);
    }

protected:

    enum class State {
        Init,
        Working,
        Error
    };

    State current_state = State::Init;

    const char* name_;

    void publish(const Event& evt) {
        for (auto* q : subscribers_) {
            k_msgq_put(q, &evt, K_NO_WAIT);
        }
    }

private:
    // Zephyr thread control block
    struct k_thread thread;
    struct k_msgq queue_;
    struct k_thread thread_data_;
    k_tid_t thread_id;
    k_thread_stack_t threadStack[CONFIG_MAIN_THREAD_STACK_SIZE];

    char queue_buffer_[COMPONENT_QUEUE_SIZE * sizeof(Event)];

    std::vector<struct k_msgq*> subscribers_;

    int priority_;

    static void thread_entry(void* p1, void*, void*) {
        static_cast<Component*>(p1)->run();
    }
};