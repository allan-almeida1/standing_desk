#include "Desk.hpp"
#include "Display7Seg.hpp"
#include "MotorEncoder.hpp"
#include "TactileButtons.hpp"
#include <Arduino.h>

// ================== PIN DEFINITIONS ==================
#define DATA_PIN 7
#define SHIFT_PIN 8
#define LATCH_PIN 9
#define EN_DISP_1 12
#define UP_BUTTON A3
#define DOWN_BUTTON A2
#define MEM_BUTTON A1
#define BT1_BUTTON A0
#define BT2_BUTTON 13
#define BT3_BUTTON 4
#define LEFT_ENCODER 3
#define RIGHT_ENCODER 2
#define PWM_LEFT_1 6
#define PWM_LEFT_2 5
#define PWM_RIGHT_1 11
#define PWM_RIGHT_2 10

// ================== CONSTANTS ==================

#define ENCODER_RESOLUTION 20

// ================== OBJECTS ==================

Display7Seg display(DATA_PIN, SHIFT_PIN, LATCH_PIN, EN_DISP_1, &digitalWrite);
TactileButtons buttons(UP_BUTTON, DOWN_BUTTON, MEM_BUTTON, BT1_BUTTON,
                       BT2_BUTTON, BT3_BUTTON, &digitalRead, &millis);
MotorEncoder left_encoder(LEFT_ENCODER, ENCODER_RESOLUTION);
MotorEncoder right_encoder(RIGHT_ENCODER, ENCODER_RESOLUTION);
Desk desk(PWM_LEFT_1, PWM_LEFT_2, PWM_RIGHT_1, PWM_RIGHT_2, &digitalWrite,
          &digitalRead, &analogWrite, display, buttons, left_encoder,
          right_encoder);

// ================== CALLBACK FUNCTIONS ==================

void updateLeftEncoder() { left_encoder.interrupt(millis()); }

void updateRightEncoder() { right_encoder.interrupt(millis()); }

void setup()
{
    // Pin configurations
    pinMode(DATA_PIN, OUTPUT);
    pinMode(SHIFT_PIN, OUTPUT);
    pinMode(LATCH_PIN, OUTPUT);
    pinMode(EN_DISP_1, OUTPUT);
    pinMode(UP_BUTTON, INPUT);
    pinMode(DOWN_BUTTON, INPUT);
    pinMode(MEM_BUTTON, INPUT);
    pinMode(BT1_BUTTON, INPUT);
    pinMode(BT2_BUTTON, INPUT_PULLUP);
    pinMode(BT3_BUTTON, INPUT_PULLUP);
    pinMode(LEFT_ENCODER, INPUT_PULLUP);
    pinMode(RIGHT_ENCODER, INPUT_PULLUP);
    pinMode(PWM_LEFT_1, OUTPUT);
    pinMode(PWM_LEFT_2, OUTPUT);
    pinMode(PWM_RIGHT_1, OUTPUT);
    pinMode(PWM_RIGHT_2, OUTPUT);

    // Change PWM frequencies. This is necessary to avoid motor whining
    // TCCR0B = (TCCR0B & 0b11111000) | 0x04; // Pins 5 and 6 - 244.14 Hz
    TCCR1B = (TCCR1B & 0b11111000) | 0x04; // Pins 9 and 10 - 122.07 Hz
    TCCR2B = (TCCR2B & 0b11111000) | 0x06; // Pins 3 and 11 - 122.07 Hz

    // Attach interrupts for encoder pins
    attachInterrupt(digitalPinToInterrupt(3), updateLeftEncoder, FALLING);
    attachInterrupt(digitalPinToInterrupt(2), updateRightEncoder, FALLING);

    // ************ DEBUG ONLY ************
    Serial.begin(9600);
}

void buttonPressed() { Serial.println("BUTTON PRESSED"); }

void buttonReleased() { Serial.println("BUTTON RELEASED"); }

void buttonShortPressed() { Serial.println("BUTTON SHORT PRESSED"); }

void buttonLongPressed() { Serial.println("BUTTON LONG PRESSED"); }

void buttonHeld() { Serial.println("BUTTON HELD"); }

void loop()
{
    // Serial.println("millis: " + String(millis()));
    desk.handleButton3(nullptr, nullptr, nullptr, nullptr, &buttonHeld);
}
