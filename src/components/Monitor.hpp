#pragma once
#include "component_base.hpp"

class MonitorComponent : public Component {
public:
    MonitorComponent() : Component("Monitor", 6) {}
    void init_component() override {}

    void handle_event(const Event& evt) override {
        printk("[%s] Received %d: %s\n", name_, static_cast<int>(evt.type), evt.payload);
    }

    void handle_event(const MessageType_t&) override {}

    void run() override {
        Event evt;
        while (true) {
            if (k_msgq_get(get_queue(), &evt, K_FOREVER) == 0) {
                handle_event(evt);
                printk("Running monitor app");
            }
        }
    }
};