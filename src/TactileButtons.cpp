#include "TactileButtons.hpp"

TactileButtons::TactileButtons(uint8_t bt_up_pin, uint8_t bt_down_pin,
                               uint8_t bt_mem_pin, uint8_t bt1_pin,
                               uint8_t bt2_pin, uint8_t bt3_pin,
                               int (*digital_read_func)(uint8_t),
                               unsigned long (*millis_func)())
    : m_bt_up_pin(bt_up_pin), m_bt_down_pin(bt_down_pin),
      m_bt_mem_pin(bt_mem_pin), m_bt1_pin(bt1_pin), m_bt2_pin(bt2_pin),
      m_bt3_pin(bt3_pin), m_digital_read_func(digital_read_func),
      m_millis_func(millis_func), m_last_button_state{1, 1, 1, 1, 1, 1},
      m_last_debounce_time{0, 0, 0, 0, 0, 0}
{
}

TactileButtons::~TactileButtons() {}

void TactileButtons::debounceButton(uint8_t pin, void (*callback)())
{
    bool button_state = m_digital_read_func(pin);
    if (button_state != m_last_button_state[pin])
    {
        m_last_debounce_time[pin] = m_millis_func();
    }

    if ((m_millis_func() - m_last_debounce_time[pin]) > DEBOUNCE_DELAY)
    {
        if (button_state == m_last_button_state[pin])
        {
            // Execute the callback function if the button is pressed
            if (!button_state) // Pull-up resistor, active low
            {
                callback();
            }
        }
    }
    m_last_button_state[pin] = button_state;
}

void TactileButtons::upPressed(void (*callback)())
{
    debounceButton(m_bt_up_pin, callback);
}

void TactileButtons::downPressed(void (*callback)())
{
    debounceButton(m_bt_down_pin, callback);
}

void TactileButtons::memPressed(void (*callback)())
{
    debounceButton(m_bt_mem_pin, callback);
}

void TactileButtons::bt1Pressed(void (*callback)())
{
    debounceButton(m_bt1_pin, callback);
}

void TactileButtons::bt2Pressed(void (*callback)())
{
    debounceButton(m_bt2_pin, callback);
}

void TactileButtons::bt3Pressed(void (*callback)())
{
    debounceButton(m_bt3_pin, callback);
}
