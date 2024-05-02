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

/**
 * @brief Desk class
 */
class Desk
{
  public:
    /**
     * @brief Construct a new Desk object
     *
     * @param bt_up_pin Button up pin
     * @param bt_down_pin Button down pin
     * @param bt_mem_pin Button memory pin
     * @param bt1_pin Button 1 pin
     * @param bt2_pin Button 2 pin
     * @param bt3_pin Button 3 pin
     * @param data_pin Data pin for shift register
     * @param shift_clk_pin Shift clock pin for shift register
     * @param latch_clk_pin Latch clock pin for shift register
     * @param en_disp1_pin Enable display 1 pin (active high)
     * @param pwml_pin1 PWM left motor pin 1
     * @param pwml_pin2 PWM left motor pin 2
     * @param pwmr_pin1 PWM right motor pin 1
     * @param pwmr_pin2 PWM right motor pin 2
     * @param speed_sensor_l_pin Left motor speed sensor pin
     * @param speed_sensor_r_pin Right motor speed sensor pin
     * @param digital_write_func Pointer to the digitalWrite function
     * @param digital_read_func Pointer to the digitalRead function
     * @param analog_write_func Pointer to the analogWrite function
     */
    Desk(uint8_t pwml_pin1, uint8_t pwml_pin2, uint8_t pwmr_pin1,
         uint8_t pwmr_pin2, uint8_t speed_sensor_l_pin,
         uint8_t speed_sensor_r_pin,
         void (*digital_write_func)(uint8_t, uint8_t),
         int (*digital_read_func)(uint8_t),
         void (*analog_write_func)(uint8_t, int), IDisplay &display,
         IButtons &buttons);
    ~Desk();

    /**
     * @brief Display a number
     *
     * @param number Number to be displayed
     */
    void displayNumber(int16_t number);

  private:
    uint8_t m_pwml_pin1;          // PWM left motor pin 1
    uint8_t m_pwml_pin2;          // PWM left motor pin 2
    uint8_t m_pwmr_pin1;          // PWM right motor pin 1
    uint8_t m_pwmr_pin2;          // PWM right motor pin 2
    uint8_t m_speed_sensor_l_pin; // Left motor speed sensor pin
    uint8_t m_speed_sensor_r_pin; // Right motor speed sensor pin
    void (*m_digital_write_func)(
        uint8_t, uint8_t);               // Pointer to the digitalWrite function
    int (*m_digital_read_func)(uint8_t); // Pointer to the digitalRead function
    void (*m_analog_write_func)(uint8_t,
                                int); // Pointer to the analogWrite function
    IDisplay &m_display;              // Display object
    IButtons &m_buttons;              // Buttons object
};

#endif // DESK_HPP