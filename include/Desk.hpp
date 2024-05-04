/**
 * @file Desk.hpp
 * @brief Desk class declaration
 * @author Allan Souza Almeida
 * @version 0.1
 * @date 2024-05-01
 */

#ifndef DESK_HPP
#define DESK_HPP

#include "Types.hpp"
#include "interface/IButtons.hpp"
#include "interface/IDisplay.hpp"
#include "interface/IEncoder.hpp"

/**
 * @brief Desk class
 */
class Desk
{
  public:
    /**
     * @brief Construct a new Desk object
     *
     * @param pwml_pin1 PWM left motor pin 1
     * @param pwml_pin2 PWM left motor pin 2
     * @param pwmr_pin1 PWM right motor pin 1
     * @param pwmr_pin2 PWM right motor pin 2
     * @param digital_write_func Pointer to the digitalWrite function
     * @param digital_read_func Pointer to the digitalRead function
     * @param analog_write_func Pointer to the analogWrite function
     */
    Desk(uint8_t pwml_pin1, uint8_t pwml_pin2, uint8_t pwmr_pin1,
         uint8_t pwmr_pin2, void (*digital_write_func)(uint8_t, uint8_t),
         int (*digital_read_func)(uint8_t),
         void (*analog_write_func)(uint8_t, int), IDisplay &display,
         IButtons &buttons, IEncoder &left_encoder, IEncoder &right_encoder);
    ~Desk();

    /**
     * @brief Display a number
     *
     * @param number Number to be displayed
     */
    void displayNumber(int16_t number);

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
                        Btcb long_press_cb = nullptr, Btcb held_cb = nullptr);

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
                          Btcb long_press_cb = nullptr, Btcb held_cb = nullptr);

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
                         Btcb long_press_cb = nullptr, Btcb held_cb = nullptr);

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
                       Btcb long_press_cb = nullptr, Btcb held_cb = nullptr);

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
                       Btcb long_press_cb = nullptr, Btcb held_cb = nullptr);

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
                       Btcb long_press_cb = nullptr, Btcb held_cb = nullptr);

  private:
    uint8_t m_pwml_pin1; // PWM left motor pin 1
    uint8_t m_pwml_pin2; // PWM left motor pin 2
    uint8_t m_pwmr_pin1; // PWM right motor pin 1
    uint8_t m_pwmr_pin2; // PWM right motor pin 2
    void (*m_digital_write_func)(
        uint8_t, uint8_t);               // Pointer to the digitalWrite function
    int (*m_digital_read_func)(uint8_t); // Pointer to the digitalRead function
    void (*m_analog_write_func)(uint8_t,
                                int); // Pointer to the analogWrite function
    IDisplay &m_display;              // Display object
    IButtons &m_buttons;              // Buttons object
    IEncoder &m_left_encoder;         // Left encoder object
    IEncoder &m_right_encoder;        // Right encoder object
};

#endif // DESK_HPP