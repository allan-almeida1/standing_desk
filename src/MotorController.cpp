#include "MotorController.hpp"

MotorController::MotorController(uint8_t rot_dir_pin)
    : m_rot_dir_pin(rot_dir_pin)
{
    setupPWM();
}

MotorController::~MotorController() {}

void MotorController::setupPWM()
{
    /*  Setup timer 1 for fast PWM at 25KHz
     *
     *  COM1A1=1, COM1B1=1, COM1A0=0, COM1B0=0:
     *  Clear OC1A/OC1B on compare match, set OC1A/OC1B at BOTTOM (non-inverting
     * mode)
     *
     *  WGM13=1, WGM12=1, WGM11=1, WGM10=0:
     *  Waveform Generation mode 14: Fast PWM, TOP = ICR1
     *
     *  CS12=0, CS11=0, CS10=1:
     *  clkI/O/1 (no prescaling)
     *
     *  PWM Frequency = 16000000/(ICR1+1)
     *  e.g.: ICR1 = 639:
     *  PWM Frequency = 16000000/(639+1) = 25kHz
     *
     *  Min value ICR1 = 3, Max value ICR1 = 65535
     */

    TCCR1A = 0;            // Clear TIMER1 setup registers
    TCCR1B = 0;            //
    TCNT1 = 0;             // Reset timer
    TCCR1A = _BV(COM1A1)   // Channel A in non-inverting mode
             | _BV(COM1B1) // Channel B in non-inverting mode
             | _BV(WGM11); // mode 14: Fast PWM, TOP = ICR1
    TCCR1B = _BV(WGM12)    //
             | _BV(WGM13)  //
             | _BV(CS10);  // prescaler = 1
    ICR1 = 639;            // TOP = 639
}

void MotorController::pwm(uint8_t pin, int value)
{
    switch (pin)
    {
    case 9:
        OCR1A = value;
        break;
    case 10:
        OCR1B = value;
        break;
    }
}

void MotorController::rotateMotor(uint8_t pin, int value, int direction)
{
    if (direction == 0)
    {
        digitalWrite(m_rot_dir_pin, LOW);
    }
    else
    {
        digitalWrite(m_rot_dir_pin, HIGH);
    }

    pwm(pin, value);
}

void MotorController::stopMotor(uint8_t pin) { pwm(pin, 0); }