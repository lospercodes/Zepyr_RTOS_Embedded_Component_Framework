#ifndef GPIO_H
#define GPIO_H

#include <zephyr/drivers/gpio.h>

namespace mcal {

template <typename T>
class Type
{
public:
    T io;
    explicit Type(const T &data) : io(data) {}
};

#ifdef __cplusplus
extern "C"
{
#endif
    class GPIO : public Type<gpio_dt_spec>
    {
    public:
        // GPIO direction flags
        static constexpr gpio_flags_t dir_o = GPIO_OUTPUT_ACTIVE;
        static constexpr gpio_flags_t dir_o_init_low = GPIO_OUTPUT_INACTIVE;
        static constexpr gpio_flags_t dir_i = GPIO_INPUT;
        static constexpr gpio_flags_t dir_i_pull_up = GPIO_INPUT | GPIO_PULL_UP;
        static constexpr gpio_flags_t dir_i_pull_down = GPIO_INPUT | GPIO_PULL_DOWN;

        // GPIO state values
        static constexpr int set = 1;
        static constexpr int clear = 0;

        using TYPE = gpio_dt_spec; // Explicitly define it here

        /**
         * @brief Constructor configuring the GPIO pin as output active
         * @param io The GPIO device specification
         */
        explicit GPIO(gpio_dt_spec io) : Type<gpio_dt_spec>(io)
        {
            gpio_pin_configure_dt(&io, GPIO_OUTPUT_ACTIVE);
        }

        /**
         * @brief Constructor with configurable direction
         * @param io The GPIO device specification
         * @param direction The direction and configuration for the GPIO pin
         */
        GPIO(gpio_dt_spec io, gpio_flags_t direction) : Type<gpio_dt_spec>(io)
        {
            gpio_pin_configure_dt(&io, direction);
        }

        /**
         * @brief Set the GPIO pin to the specified state
         * @param state Either 1 (set) or 0 (clear)
         * @return 0 on success, negative error code on failure
         */
        int write(int state)
        {
            return gpio_pin_set_dt(&io, state);
        }

        /**
         * @brief Read the current state of the GPIO pin
         * @return 1 if the pin is high, 0 if the pin is low
         */
        int read()
        {
            return gpio_pin_get_dt(&io);
        }

        /**
         * @brief Toggle the state of the GPIO pin
         * @return 0 on success, negative error code on failure
         */
        int toggle()
        {
            return gpio_pin_toggle_dt(&io);
        }

        /**
         * @brief Check if the GPIO device is ready
         * @return true if the device is ready, false otherwise
         */
        bool is_ready() const
        {
            return device_is_ready(io.port);
        }

        /**
         * @brief Configure the GPIO pin with specified flags
         * @param flags The configuration flags
         * @return 0 on success, negative error code on failure
         */
        int configure(gpio_flags_t flags)
        {
            return gpio_pin_configure_dt(&io, flags);
        }

        /**
         * @brief Configure the GPIO pin for interrupt
         * @param flags The interrupt flags
         * @return 0 on success, negative error code on failure
         */
        int configure_interrupt(gpio_flags_t flags)
        {
            return gpio_pin_interrupt_configure_dt(&io, flags);
        }

        /**
         * @brief Get the raw pin number
         * @return The raw pin number
         */
        gpio_pin_t get_pin() const
        {
            return io.pin;
        }

        /**
         * @brief Get the GPIO port device
         * @return Pointer to the GPIO port device
         */
        const struct device* get_port() const
        {
            return io.port;
        }

    private:
    };

#ifdef __cplusplus
}
#endif
}

#endif