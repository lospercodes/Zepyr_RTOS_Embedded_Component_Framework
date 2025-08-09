#pragma once
#include "component_base.hpp"

class AltimeterComponent : public Component {
public:
    AltimeterComponent() : Component("Altimeter") {}

    void handle_event(const Event&) override;
    void handle_event(const MessageType_t&) override {}
    void init_component() override {}
    

    void run() override {
        while (true) {
            Event evt{EventType::ALTIMETER_DATA};
            strcpy(evt.payload, "alt:300m,press:1012hPa");
            publish(evt);
            k_msleep(2000);
        }
    }
};