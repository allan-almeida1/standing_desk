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
#include "interface/IController.hpp"
#include "interface/IDisplay.hpp"
#include "interface/IEncoder.hpp"
#include <Arduino.h>

/**
 * @brief Desk class
 */
class Desk
{
  public:
    /**
     * @brief Construct a new Desk object
     *
     * @param controller Controller object
     * @param display Display object
     * @param buttons Buttons object
     * @param left_encoder Left encoder object
     * @param right_encoder Right encoder object
     */
    Desk(IController &controller, IDisplay &display, IButtons &buttons,
         IEncoder &left_encoder, IEncoder &right_encoder);
    ~Desk();

    /**
     * @brief Display a number
     *
     * @param number Number to be displayed
     */
    void displayNumber(int16_t number);

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
                           Btcb held_cb = nullptr);

    /**
     * @brief Rotate the motor in a specific direction at a specific speed
     *
     * @param pin The pin number to set the PWM value
     * @param value The value to set the PWM (0-639)
     * @param direction The direction to rotate the motor (0 - clockwise, 1 -
     * counter-clockwise)
     */
    void rotateMotor(uint8_t pin, int value, int direction);

    /**
     * @brief Stop the motor
     *
     * @param pin The pin number
     */
    void stopMotor(uint8_t pin);

  private:
    IController &m_controller; // Controller object
    IDisplay &m_display;       // Display object
    IButtons &m_buttons;       // Buttons object
    IEncoder &m_left_encoder;  // Left encoder object
    IEncoder &m_right_encoder; // Right encoder object
};

#endif // DESK_HPP