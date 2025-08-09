#pragma once
#include "component_base.hpp"

class TempHumidityComponent : public Component {
public:
    TempHumidityComponent() : Component("TempHumidity") {}

    void handle_event(const Event&) override {}
    void handle_event(const MessageType_t&) override {}
    void init_component() override {}

    void run() override {
        while (true) {
            Event evt{EventType::TEMP_HUMIDITY_DATA};
            strcpy(evt.payload, "temp:25C,hum:60%");
            publish(evt);
            k_msleep(1200);
        }
    }
};