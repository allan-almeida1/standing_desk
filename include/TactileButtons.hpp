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
     * @param digital_read_func Pointer to the digitalRead function
     */
    TactileButtons(uint8_t bt_up_pin, uint8_t bt_down_pin, uint8_t bt_mem_pin,
                   uint8_t bt1_pin, uint8_t bt2_pin, uint8_t bt3_pin,
                   int (*digital_read_func)(uint8_t),
                   unsigned long (*millis_func)(void));
    ~TactileButtons();

    /**
     * @brief Handle up button press events
     *
     * @param press_cb Button press callback function
     * @param release_cb Button release callback function
     * @param short_press_cb Short press callback function
     * @param long_press_cb Long press (>= 3s) callback function
     * @param held_cb Button held callback function
     */
    void handleUpButton(Btcb press_cb = nullptr, Btcb release_cb = nullptr,
                        Btcb short_press_cb = nullptr,
                        Btcb long_press_cb = nullptr,
                        Btcb held_cb = nullptr) override;

    /**
     * @brief Handle down button press events
     *
     * @param press_cb Button press callback function
     * @param release_cb Button release callback function
     * @param short_press_cb Short press callback function
     * @param long_press_cb Long press (>= 3s) callback function
     * @param held_cb Button held callback function
     */
    void handleDownButton(Btcb press_cb = nullptr, Btcb release_cb = nullptr,
                          Btcb short_press_cb = nullptr,
                          Btcb long_press_cb = nullptr,
                          Btcb held_cb = nullptr) override;

    /**
     * @brief Handle memory button press events
     *
     * @param press_cb Button press callback function
     * @param release_cb Button release callback function
     * @param short_press_cb Short press callback function
     * @param long_press_cb Long press (>= 3s) callback function
     * @param held_cb Button held callback function
     */
    void handleMemButton(Btcb press_cb = nullptr, Btcb release_cb = nullptr,
                         Btcb short_press_cb = nullptr,
                         Btcb long_press_cb = nullptr,
                         Btcb held_cb = nullptr) override;

    /**
     * @brief Handle button 1 press events
     *
     * @param press_cb Button press callback function
     * @param release_cb Button release callback function
     * @param short_press_cb Short press callback function
     * @param long_press_cb Long press (>= 3s) callback function
     * @param held_cb Button held callback function
     */
    void handleButton1(Btcb press_cb = nullptr, Btcb release_cb = nullptr,
                       Btcb short_press_cb = nullptr,
                       Btcb long_press_cb = nullptr,
                       Btcb held_cb = nullptr) override;

    /**
     * @brief Handle button 2 press events
     *
     * @param press_cb Button press callback function
     * @param release_cb Button release callback function
     * @param short_press_cb Short press callback function
     * @param long_press_cb Long press (>= 3s) callback function
     * @param held_cb Button held callback function
     */
    void handleButton2(Btcb press_cb = nullptr, Btcb release_cb = nullptr,
                       Btcb short_press_cb = nullptr,
                       Btcb long_press_cb = nullptr,
                       Btcb held_cb = nullptr) override;

    /**
     * @brief Handle button 3 press events
     *
     * @param press_cb Button press callback function
     * @param release_cb Button release callback function
     * @param short_press_cb Short press callback function
     * @param long_press_cb Long press (>= 3s) callback function
     * @param held_cb Button held callback function
     */
    void handleButton3(Btcb press_cb = nullptr, Btcb release_cb = nullptr,
                       Btcb short_press_cb = nullptr,
                       Btcb long_press_cb = nullptr,
                       Btcb held_cb = nullptr) override;

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

  private:
    uint8_t m_bt_up_pin;                  // Button up pin
    uint8_t m_bt_down_pin;                // Button down pin
    uint8_t m_bt_mem_pin;                 // Button memory pin
    uint8_t m_bt1_pin;                    // Button 1 pin
    uint8_t m_bt2_pin;                    // Button 2 pin
    uint8_t m_bt3_pin;                    // Button 3 pin
    int (*m_digital_read_func)(uint8_t);  // Pointer to the digitalRead function
    unsigned long (*m_millis_func)(void); // Pointer to the millis function
    bool m_button_state[6];               // Button state
    bool m_last_button_state[6];          // Last button state
    unsigned long m_last_debounce_time[6]; // Last debounce time
    unsigned long m_press_time[6];         // Press time
    bool m_button_active[6];     // Button is active (0) or inactive (1)
    bool m_button_long_press[6]; // Button is long pressed (0) or not (1)
};

#endif // TACTILEBUTTONS_HPP