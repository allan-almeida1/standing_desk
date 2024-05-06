/**
 * @file IController.cpp
 * @brief Interface for the Controller class
 * @author Allan Souza Almeida
 * @version 0.1
 * @date 2024-05-05
 */

#ifndef ICONTROLLER_H
#define ICONTROLLER_H

#include "Types.hpp"

class IController
{
  public:
    /**
     * @brief Setup the PWM for the controller. Setup the registers
     * for correct PWM operation.
     */
    virtual void setupPWM() = 0;

    /**
     * @brief Rotate the motor in a specific direction at a specific speed
     *
     * @param pin The pin number to set the PWM value
     * @param value The value to set the PWM
     * @param direction The direction to rotate the motor
     */
    virtual void rotateMotor(uint8_t pin, int value, int direction) = 0;

    /**
     * @brief Stop the motor
     *
     * @param pin The pin number to stop the motor
     */
    virtual void stopMotor(uint8_t pin) = 0;

    /**
     * @brief Destroy the IController object
     */
    virtual ~IController() {}
};

#endif // ICONTROLLER_H