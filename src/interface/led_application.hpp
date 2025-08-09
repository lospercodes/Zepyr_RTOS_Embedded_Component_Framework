#ifndef LED_APP_H
#define LED_APP_H

#include <zephyr/drivers/gpio.h>
#include "component_base.hpp"
#include <vector>

#include "gpio.hpp"

#define LED1_NODE DT_ALIAS(led0)
#define LED2_NODE DT_ALIAS(led1)
#define LED3_NODE DT_ALIAS(led2)
#define LED4_NODE DT_ALIAS(led3)

#ifdef __cplusplus
extern "C"
{
#endif

    class LED : public Component//public ActiveObject
    {
    private:

        /* The devicetree node identifier for the "led0" alias. */
        static constexpr struct gpio_dt_spec status_led_spec_1 = GPIO_DT_SPEC_GET(LED1_NODE, gpios);
        static constexpr struct gpio_dt_spec status_led_spec_2 = GPIO_DT_SPEC_GET(LED2_NODE, gpios);
        static constexpr struct gpio_dt_spec status_led_spec_3 = GPIO_DT_SPEC_GET(LED3_NODE, gpios);
        static constexpr struct gpio_dt_spec status_led_spec_4 = GPIO_DT_SPEC_GET(LED4_NODE, gpios);

        mcal::GPIO gpio0; // Declare first, initialize in constructor
        mcal::GPIO gpio1;
        mcal::GPIO gpio2;
        mcal::GPIO gpio3;

    public:

        void handle_event(const Event&) override {}
        void handle_event(const MessageType_t&) override {}
        void init_component() override;


        LED(): Component("LED", 7),
              gpio0(status_led_spec_1),
              gpio1(status_led_spec_2),
              gpio2(status_led_spec_3),
              gpio3(status_led_spec_4)
        { // Initialize GPIO with the spec
        }

    protected:

        void handleEvent(const Event&);
        void run() override;
    };

#ifdef __cplusplus
}
#endif

#endif