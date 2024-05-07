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
#include <Arduino.h>

#define MAX_ENCODER_TIMEOUT 300 // Maximum time between encoder reads (ms)

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
     */
    void interrupt();

    /**
     * @brief Check time since last encoder read and set speed to 0 if time
     * exceeds maximum time
     */
    void checkEncoderTimeout() override;

  private:
    uint8_t m_pin;                      // Encoder pin
    uint16_t m_encoder_resolution;      // Encoder resolution
    volatile float m_speed;             // Speed value in RPM
    volatile unsigned long m_last_time; // Last time the encoder was read
};

#endif // MOTOR_ENCODER_HPP