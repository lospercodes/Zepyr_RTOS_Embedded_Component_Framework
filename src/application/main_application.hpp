#ifndef MAIN_APPLICATION_H
#define MAIN_APPLICAION_H

#include <memory>
#include "component_base.hpp"
#include "led_application.hpp"
#include "Altimeter.hpp"
#include "Monitor.hpp"
#include "TEMP.hpp"


class MainApplication : public Component
{
private:

    std::unique_ptr<LED> led;
    std::unique_ptr<AltimeterComponent> alt;
    std::unique_ptr<MonitorComponent> monitor;
    std::unique_ptr<TempHumidityComponent> temphum;
    

public:
    MainApplication():
          Component("MainApp"),
          led(std::make_unique<LED>()),
          alt(std::make_unique<AltimeterComponent>()),
          monitor(std::make_unique<MonitorComponent>()),
          temphum(std::make_unique<TempHumidityComponent>())

    {
    }

    void handle_event(const Event&) override {}
    void handle_event(const MessageType_t&) override {}
    void init_component() override {}

    virtual ~MainApplication() = default;

protected:

    void transitionTo(State *newState)
    {
        // current_state = newState;
    }

    void run() override
    {
        init();

        while (true)
        {
            //... do event stuff
            k_msleep(5000);
            printk("Running Main app\n");
        }
    }

    void init()
    {   
        startAll();
    }

    void startAll() {
        led->start();
        alt->start();
        temphum->start();
        monitor->start();
        temphum->subscribe(monitor->get_queue()); // add subscriber monitor
        alt->subscribe(monitor->get_queue()); // add subscriber monitor
    }
};

#endif