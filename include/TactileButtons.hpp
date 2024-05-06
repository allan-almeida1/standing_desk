/**
 * @file TactileButtons.hpp
 * @brief Class for tactile buttons
 * @author Allan Souza Almeida
 * @version 0.1
 * @date 2024-05-01
 */

#ifndef TACTILEBUTTONS_HPP
#define TACTILEBUTTONS_HPP

#include "interface/IButtons.hpp"
#include <Arduino.h>

#define DEBOUNCE_DELAY 17    // Debounce delay in milliseconds
#define LONG_PRESS_TIME 3000 // Long press time in milliseconds

/**
 * @note All events are optional and can be set to nullptr. Press, release,
 * short press and long press callbacks can all be set at once. However, if the
 * held callback is set, it will be called every time the button is pressed and
 * ignore the other callbacks. In this case, no debounce is performed.
 */

/**
 * @brief Tactile buttons class. This class implements the IButtons interface
 */
class TactileButtons final : public IButtons
{
  public:
    /**
     * @brief Construct a new Tactile Buttons object
     *
     * @param bt_up_pin Button up pin
     * @param bt_down_pin Button down pin
     * @param bt_mem_pin Button memory pin
     * @param bt1_pin Button 1 pin
     * @param bt2_pin Button 2 pin
     * @param bt3_pin Button 3 pin
     */
    TactileButtons(uint8_t bt_up_pin, uint8_t bt_down_pin, uint8_t bt_mem_pin,
                   uint8_t bt1_pin, uint8_t bt2_pin, uint8_t bt3_pin);
    ~TactileButtons();

    /**
     * @brief Handle button press events
     *
     * @param button Button index
     * @param press_cb Button press callback function
     * @param release_cb Button release callback function
     * @param short_press_cb Short press callback function
     * @param long_press_cb Long press (>= 3s) callback function
     * @param held_cb Button held callback function
     */
    void handleButtonEvent(ButtonIndex button, Btcb press_cb = nullptr,
                           Btcb release_cb = nullptr,
                           Btcb short_press_cb = nullptr,
                           Btcb long_press_cb = nullptr,
                           Btcb held_cb = nullptr) override;

    /**
     * @brief Handle button press events with a callback that receives an
     * integer parameter
     *
     * @param button Button index
     * @param press_cb Button press callback function
     * @param release_cb Button release callback function
     * @param short_press_cb Short press callback function
     * @param long_press_cb Long press (>= 3s) callback function
     * @param held_cb Button held callback function
     * @param param Parameter to be passed to the callback function
     */
    void handleButtonEvent(ButtonIndex button, BtcbParamInt press_cb = nullptr,
                           BtcbParamInt release_cb = nullptr,
                           BtcbParamInt short_press_cb = nullptr,
                           BtcbParamInt long_press_cb = nullptr,
                           BtcbParamInt held_cb = nullptr,
                           int param = 0) override;

    /**
     * @brief Debounce a button and trigger a callback function based
     * on the detected event
     *
     * @param bt_idx Button index (0 to 5)
     * @param active_state Active state of the button (0 or 1)
     * @param press_cb Button press callback function
     * @param release_cb Button release callback function
     * @param short_press_cb Short press callback function
     * @param long_press_cb Long press (>= 3s) callback function
     * @param held_cb Button held callback function
     */
    void debounceAndTrigger(uint8_t bt_idx, bool active_state, Btcb press_cb,
                            Btcb release_cb, Btcb short_press_cb,
                            Btcb long_press_cb, Btcb held_cb);

    /**
     * @brief Debounce a button and trigger a callback function based
     * on the detected event with an integer parameter
     *
     * @param bt_idx Button index (0 to 5)
     * @param active_state Active state of the button (0 or 1)
     * @param press_cb Button press callback function
     * @param release_cb Button release callback function
     * @param short_press_cb Short press callback function
     * @param long_press_cb Long press (>= 3s) callback function
     * @param held_cb Button held callback function
     * @param param Parameter to be passed to the callback function
     */
    void debounceAndTrigger(uint8_t bt_idx, bool active_state,
                            BtcbParamInt press_cb, BtcbParamInt release_cb,
                            BtcbParamInt short_press_cb,
                            BtcbParamInt long_press_cb, BtcbParamInt held_cb,
                            int param);

  private:
    uint8_t m_button_pins[6];              // Button pins
    bool m_button_state[6];                // Button state
    bool m_last_button_state[6];           // Last button state
    unsigned long m_last_debounce_time[6]; // Last debounce time
    unsigned long m_press_time[6];         // Press time
    bool m_button_active[6];     // Button is active (0) or inactive (1)
    bool m_button_long_press[6]; // Button is long pressed (0) or not (1)
};

#endif // TACTILEBUTTONS_HPP