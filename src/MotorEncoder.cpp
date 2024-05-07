#include "MotorEncoder.hpp"

MotorEncoder::MotorEncoder(uint8_t pin, uint16_t encoder_resolution)
    : m_pin(pin), m_encoder_resolution(encoder_resolution)
{
}

MotorEncoder::~MotorEncoder() {}

float MotorEncoder::getSpeed() { return m_speed; }

void MotorEncoder::interrupt()
{
    // Calculate the speed in RPM
    unsigned long time_diff = millis() - m_last_time;
    m_last_time = millis();
    m_speed = 60000.0 / (time_diff + 1e-6) / m_encoder_resolution;
}

void MotorEncoder::checkEncoderTimeout()
{
    if (millis() - m_last_time > MAX_ENCODER_TIMEOUT)
    {
        m_speed = 0;
    }
}