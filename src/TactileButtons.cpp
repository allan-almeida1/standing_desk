#include "TactileButtons.hpp"

TactileButtons::TactileButtons(uint8_t bt_up_pin, uint8_t bt_down_pin,
                               uint8_t bt_mem_pin, uint8_t bt1_pin,
                               uint8_t bt2_pin, uint8_t bt3_pin)
    : m_button_pins{bt_up_pin, bt_down_pin, bt_mem_pin,
                    bt1_pin,   bt2_pin,     bt3_pin},
      m_button_state{1, 1, 1, 1, 1, 1}, m_last_button_state{1, 1, 1, 1, 1, 1},
      m_last_debounce_time{0, 0, 0, 0, 0, 0}
{
}

TactileButtons::~TactileButtons() {}

void TactileButtons::debounceAndTrigger(uint8_t bt_idx, bool active_state,
                                        Btcb press_cb, Btcb release_cb,
                                        Btcb short_press_cb, Btcb long_press_cb,
                                        Btcb held_cb)
{
    bool current_button_state = digitalRead(m_button_pins[bt_idx]);

    // If the held callback is set, call it every time the button is pressed
    // and ignore the other callbacks
    if (held_cb != nullptr)
    {
        if (current_button_state == active_state)
        {
            held_cb();
            return;
        }
    }

    // If the button is active and the button is pressed for more than 3
    // seconds, call the long press callback
    if (m_button_active[bt_idx] && current_button_state == active_state &&
        millis() - m_press_time[bt_idx] > LONG_PRESS_TIME)
    {
        if (long_press_cb != nullptr)
        {
            long_press_cb();
        }
        m_press_time[bt_idx] = millis();
        m_button_long_press[bt_idx] = true;
    }

    if (current_button_state != m_last_button_state[bt_idx])
    {
        m_last_debounce_time[bt_idx] = millis();
    }

    if (millis() - m_last_debounce_time[bt_idx] > DEBOUNCE_DELAY)
    {
        if (current_button_state != m_button_state[bt_idx])
        {
            m_button_state[bt_idx] = current_button_state;

            // Button pressed
            if (m_button_state[bt_idx] == active_state)
            {
                m_button_active[bt_idx] = true;
                if (press_cb != nullptr)
                {
                    press_cb();
                }
                m_press_time[bt_idx] = millis();
            }
            // Button released
            else
            {
                m_button_active[bt_idx] = false;
                if (release_cb != nullptr)
                {
                    release_cb();
                }
                // If the button was pressed for less than 3 seconds and then
                // released, call the short press callback
                if (millis() - m_press_time[bt_idx] < LONG_PRESS_TIME &&
                    !m_button_long_press[bt_idx])
                {
                    if (short_press_cb != nullptr)
                    {
                        short_press_cb();
                    }
                }
                m_button_long_press[bt_idx] = false;
            }
        }
    }

    m_last_button_state[bt_idx] = current_button_state;
}

void TactileButtons::handleButtonEvent(ButtonIndex button, Btcb press_cb,
                                       Btcb release_cb, Btcb short_press_cb,
                                       Btcb long_press_cb, Btcb held_cb)
{
    debounceAndTrigger(static_cast<uint8_t>(button), 0, press_cb, release_cb,
                       short_press_cb, long_press_cb, held_cb);
}