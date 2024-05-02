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

#define DEBOUNCE_DELAY 50 // Debounce delay in milliseconds

/**
 * @brief Tactile buttons class
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
                   unsigned long (*millis_func)());
    ~TactileButtons();

    /**
     * @brief Check if the up button is pressed and execute the callback
     * function
     *
     * @param callback Callback function to be executed
     */
    void upPressed(void (*callback)()) override;

    /**
     * @brief Check if the down button is pressed and execute the callback
     * function
     *
     * @param callback Callback function to be executed
     */
    void downPressed(void (*callback)()) override;

    /**
     * @brief Check if the memory button is pressed and execute the callback
     * function
     *
     * @param callback Callback function to be executed
     */
    void memPressed(void (*callback)()) override;

    /**
     * @brief Check if the button 1 is pressed and execute the callback
     * function
     *
     * @param callback Callback function to be executed
     */
    void bt1Pressed(void (*callback)()) override;

    /**
     * @brief Check if the button 2 is pressed and execute the callback
     * function
     *
     * @param callback Callback function to be executed
     */
    void bt2Pressed(void (*callback)()) override;

    /**
     * @brief Check if the button 3 is pressed and execute the callback
     * function
     *
     * @param callback Callback function to be executed
     */
    void bt3Pressed(void (*callback)()) override;

    /**
     * @brief Debounce a button and execute the callback function if pressed
     *
     * @param pin Button pin
     * @param callback Callback function to be executed
     */
    void debounceButton(uint8_t pin, void (*callback)());

  private:
    uint8_t m_bt_up_pin;                 // Button up pin
    uint8_t m_bt_down_pin;               // Button down pin
    uint8_t m_bt_mem_pin;                // Button memory pin
    uint8_t m_bt1_pin;                   // Button 1 pin
    uint8_t m_bt2_pin;                   // Button 2 pin
    uint8_t m_bt3_pin;                   // Button 3 pin
    int (*m_digital_read_func)(uint8_t); // Pointer to the digitalRead function
    unsigned long (*m_millis_func)();    // Pointer to the millis function
    bool m_last_button_state[6];         // Last button state
    unsigned long m_last_debounce_time[6]; // Last debounce time
};

#endif // TACTILEBUTTONS_HPP