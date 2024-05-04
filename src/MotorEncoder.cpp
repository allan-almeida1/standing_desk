#include "MotorEncoder.hpp"

MotorEncoder::MotorEncoder(uint8_t pin, uint16_t encoderResolution)
    : m_pin(pin), m_encoderResolution(encoderResolution)
{
}

MotorEncoder::~MotorEncoder() {}

float MotorEncoder::getSpeed() { return m_speed; }

void MotorEncoder::interrupt(unsigned long current_time)
{
    // Calculate the speed in RPM
    unsigned long time_diff = current_time - m_lastTime;
    m_speed = (60000.0 / time_diff) / m_encoderResolution;
    m_lastTime = current_time;
}