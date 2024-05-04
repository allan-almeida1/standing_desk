#include "TactileButtons.hpp"
#include "Arduino.h"

TactileButtons::TactileButtons(uint8_t bt_up_pin, uint8_t bt_down_pin,
                               uint8_t bt_mem_pin, uint8_t bt1_pin,
                               uint8_t bt2_pin, uint8_t bt3_pin,
                               int (*digital_read_func)(uint8_t),
                               unsigned long (*millis_func)(void))
    : m_bt_up_pin(bt_up_pin), m_bt_down_pin(bt_down_pin),
      m_bt_mem_pin(bt_mem_pin), m_bt1_pin(bt1_pin), m_bt2_pin(bt2_pin),
      m_bt3_pin(bt3_pin), m_digital_read_func(digital_read_func),
      m_millis_func(millis_func), m_button_state{1, 1, 1, 1, 1, 1},
      m_last_button_state{1, 1, 1, 1, 1, 1},
      m_last_debounce_time{0, 0, 0, 0, 0, 0}
{
}

TactileButtons::~TactileButtons() {}

void TactileButtons::debounceAndTrigger(uint8_t bt_idx, bool active_state,
                                        Btcb press_cb, Btcb release_cb,
                                        Btcb short_press_cb, Btcb long_press_cb,
                                        Btcb held_cb)
{
    bool current_button_state = m_digital_read_func(bt_idx);

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
        m_millis_func() - m_press_time[bt_idx] > LONG_PRESS_TIME)
    {
        if (long_press_cb != nullptr)
        {
            long_press_cb();
        }
        m_press_time[bt_idx] = m_millis_func();
        m_button_long_press[bt_idx] = true;
    }

    if (current_button_state != m_last_button_state[bt_idx])
    {
        m_last_debounce_time[bt_idx] = m_millis_func();
    }

    if (m_millis_func() - m_last_debounce_time[bt_idx] > DEBOUNCE_DELAY)
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
                m_press_time[bt_idx] = m_millis_func();
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
                if (m_millis_func() - m_press_time[bt_idx] < LONG_PRESS_TIME &&
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

void TactileButtons::handleUpButton(Btcb press_cb, Btcb release_cb,
                                    Btcb short_press_cb, Btcb long_press_cb,
                                    Btcb held_cb)
{
    debounceAndTrigger(m_bt_up_pin, 0, press_cb, release_cb, short_press_cb,
                       long_press_cb, held_cb);
}

void TactileButtons::handleDownButton(Btcb press_cb, Btcb release_cb,
                                      Btcb short_press_cb, Btcb long_press_cb,
                                      Btcb held_cb)
{
    debounceAndTrigger(m_bt_down_pin, 0, press_cb, release_cb, short_press_cb,
                       long_press_cb, held_cb);
}

void TactileButtons::handleMemButton(Btcb press_cb, Btcb release_cb,
                                     Btcb short_press_cb, Btcb long_press_cb,
                                     Btcb held_cb)
{
    debounceAndTrigger(m_bt_mem_pin, 0, press_cb, release_cb, short_press_cb,
                       long_press_cb, held_cb);
}

void TactileButtons::handleButton1(Btcb press_cb, Btcb release_cb,
                                   Btcb short_press_cb, Btcb long_press_cb,
                                   Btcb held_cb)
{
    debounceAndTrigger(m_bt1_pin, 0, press_cb, release_cb, short_press_cb,
                       long_press_cb, held_cb);
}

void TactileButtons::handleButton2(Btcb press_cb, Btcb release_cb,
                                   Btcb short_press_cb, Btcb long_press_cb,
                                   Btcb held_cb)
{
    debounceAndTrigger(m_bt2_pin, 0, press_cb, release_cb, short_press_cb,
                       long_press_cb, held_cb);
}

void TactileButtons::handleButton3(Btcb press_cb, Btcb release_cb,
                                   Btcb short_press_cb, Btcb long_press_cb,
                                   Btcb held_cb)
{
    debounceAndTrigger(m_bt3_pin, 0, press_cb, release_cb, short_press_cb,
                       long_press_cb, held_cb);
}
