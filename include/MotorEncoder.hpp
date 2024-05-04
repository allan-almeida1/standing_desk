/**
 * @file MotorEncoder.hpp
 * @brief Class for motor encoder
 * @author Allan Souza Almeida
 * @version 0.1
 * @date 2024-05-01
 */

#ifndef MOTOR_ENCODER_HPP
#define MOTOR_ENCODER_HPP

#include "Types.hpp"
#include "interface/IEncoder.hpp"

/**
 * @brief Class for motor encoder
 *
 */
class MotorEncoder final : public IEncoder
{
  public:
    /**
     * @brief Construct a new Motor Encoder object
     *
     * @param pin Encoder pin (interrupt pin)
     * @param encoderResolution Encoder resolution (number of pulses per
     * revolution)
     */
    MotorEncoder(uint8_t pin, uint16_t encoderResolution);

    ~MotorEncoder();

    /**
     * @brief Get the speed value in RPM
     *
     * @return Speed value
     */
    float getSpeed() override;

    /**
     * @brief Interrupt received on encoder pin
     *
     * @param current_time Current time in milliseconds
     */
    void interrupt(unsigned long current_time);

  private:
    uint8_t m_pin;                     // Encoder pin
    uint16_t m_encoderResolution;      // Encoder resolution
    volatile float m_speed;            // Speed value in RPM
    volatile unsigned long m_lastTime; // Last time the encoder was read
};

#endif // MOTOR_ENCODER_HPP