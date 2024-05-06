/**
 * @brief MotorController class
 * @author Allan Souza Almeida
 * @version 0.1
 * @date 2024-05-05
 */

#ifndef MOTOR_CONTROLLER_HPP
#define MOTOR_CONTROLLER_HPP

#include "interface/IController.hpp"
#include <Arduino.h>

/**
 * @brief MotorController class. This class implements the IController
 * interface.
 */
class MotorController final : public IController
{
  public:
    /**
     * @brief Construct a new Motor Controller object
     *
     * @param rot_dir_pin Pin for the rotation direction
     */
    MotorController(uint8_t rot_dir_pin);

    /**
     * @brief Destroy the Motor Controller object
     */
    ~MotorController();

    /**
     * @brief Setup the PWM for the controller. Setup the registers
     * for 25kHz PWM operation.
     */
    void setupPWM() override;

    /**
     * @brief Set the PWM value for a specific pin.
     *
     * @param pin The pin number to set the PWM value
     * @param value The value to set the PWM (0-639)
     */
    void pwm(uint8_t pin, int value);

    /**
     * @brief Rotate the motor in a specific direction at a specific speed
     *
     * @param pin The pin number to set the PWM value
     * @param value The value to set the PWM (0-639)
     * @param direction The direction to rotate the motor (0 - clockwise, 1 -
     * counter-clockwise)
     */
    void rotateMotor(uint8_t pin, int value, int direction) override;

    /**
     * @brief Stop the motor
     *
     * @param pin The pin number
     */
    void stopMotor(uint8_t pin) override;

  private:
    uint8_t m_pwm_pin_left;  // Pin for the left motor
    uint8_t m_pwm_pin_right; // Pin for the right motor
    uint8_t m_rot_dir_pin;   // Pin for the rotation direction
};

#endif // MOTOR_CONTROLLER_HPP