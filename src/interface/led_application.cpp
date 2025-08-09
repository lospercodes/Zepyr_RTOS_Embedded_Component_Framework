#include "led_application.hpp"

/*
This pattern is needed because static constexpr members are only declared in the class definition, 
not fully defined. The linker needs these definitions to resolve references to these variables.
*/

// Define the static members
constexpr struct gpio_dt_spec LED::status_led_spec_1;
constexpr struct gpio_dt_spec LED::status_led_spec_2;
constexpr struct gpio_dt_spec LED::status_led_spec_3;
constexpr struct gpio_dt_spec LED::status_led_spec_4;


void LED::handleEvent(const Event&) {

    switch (current_state) {
        case State::Init:
            printk("In Idle state\n");
            break;

        case State::Working:
            printk("In Working state\n");
            break;

        case State::Error:
            printk("In Error state. Awaiting reset.\n");
            break;
    }
}

void LED::run()
{
    printk("LED interface started!\n\r");

    Event evt;
    int result =0;
    while (true)
    {
        // do stuff ...
        gpio0.toggle();
        k_msleep(200);
        gpio1.toggle();
        k_msleep(400);
        gpio2.toggle();
        k_msleep(600);
        gpio3.toggle();
        k_msleep(800);
    }
}

void LED::init_component() {
    
}