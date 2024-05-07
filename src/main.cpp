#include "Desk.hpp"
#include "Display7Seg.hpp"
#include "MotorController.hpp"
#include "MotorEncoder.hpp"
#include "TactileButtons.hpp"
#include <Arduino.h>

#define ADJUST_MOTOR_POSITION
// #define DEBUG_ENCODER
// unsigned long last_time = 0;

// ================== PIN DEFINITIONS ==================
#define DATA_PIN 6
#define SHIFT_PIN 7
#define LATCH_PIN 8
#define EN_DISP_1 12
#define UP_BUTTON A3
#define DOWN_BUTTON A2
#define MEM_BUTTON A1
#define BT1_BUTTON A0
#define BT2_BUTTON 13
#define BT3_BUTTON 4
#define LEFT_ENCODER 3
#define RIGHT_ENCODER 2
#define PWM_LEFT 10
#define PWM_RIGHT 9
#define ROT_DIR 11

// ================== CONSTANTS ==================

#define ENCODER_RESOLUTION 20

// ================== OBJECTS ==================

Display7Seg display(DATA_PIN, SHIFT_PIN, LATCH_PIN, EN_DISP_1);
TactileButtons buttons(UP_BUTTON, DOWN_BUTTON, MEM_BUTTON, BT1_BUTTON,
                       BT2_BUTTON, BT3_BUTTON);
MotorEncoder left_encoder(LEFT_ENCODER, ENCODER_RESOLUTION);
MotorEncoder right_encoder(RIGHT_ENCODER, ENCODER_RESOLUTION);
MotorController controller(ROT_DIR);
Desk desk(controller, display, buttons, left_encoder, right_encoder);

// ================== CALLBACK FUNCTIONS ==================

void updateLeftEncoder() { left_encoder.interrupt(); }

void updateRightEncoder() { right_encoder.interrupt(); }

bool enable = 0;

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
    pinMode(PWM_LEFT, OUTPUT);
    pinMode(PWM_RIGHT, OUTPUT);
    pinMode(ROT_DIR, OUTPUT);

    // Attach interrupts for encoder pins
    attachInterrupt(digitalPinToInterrupt(LEFT_ENCODER), updateLeftEncoder,
                    FALLING);
    attachInterrupt(digitalPinToInterrupt(RIGHT_ENCODER), updateRightEncoder,
                    FALLING);

    // ************ DEBUG ONLY ************
    Serial.begin(9600);
    // ************************************
}

void moveUp()
{
    Serial.println("Moving up");
    desk.rotateMotor(PWM_LEFT, 400, 0);
    desk.rotateMotor(PWM_RIGHT, 400, 0);
}

void moveDown()
{
    Serial.println("Moving down");
    desk.rotateMotor(PWM_LEFT, 400, 1);
    desk.rotateMotor(PWM_RIGHT, 400, 1);
}

void stopMotors()
{
    Serial.println("Stopping motors");
    desk.stopMotor(PWM_LEFT);
    desk.stopMotor(PWM_RIGHT);
}

void loop()
{

#ifdef DEBUG_MOTOR
    for (int i = 0; i < 640; i += 10)
    {
        desk.rotateMotor(PWM_LEFT, i, 0);
        desk.rotateMotor(PWM_RIGHT, i, 0);
        delay(1);
    }
    delay(3000);
    for (int i = 639; i >= 0; i -= 10)
    {
        desk.rotateMotor(PWM_LEFT, i, 0);
        desk.rotateMotor(PWM_RIGHT, i, 0);
        delay(1);
    }
#endif

#ifdef ADJUST_MOTOR_POSITION
    desk.handleButtonEvent(ButtonIndex::BUTTON3, &moveUp, &stopMotors, nullptr,
                           nullptr, nullptr);
    desk.handleButtonEvent(ButtonIndex::BUTTON2, &moveDown, &stopMotors,
                           nullptr, nullptr, nullptr);

#ifdef DEBUG_ENCODER
    desk.checkEncoderTimeout();
    if (millis() - last_time > 1000)
    {
        Serial.println("Left encoder: " + String(desk.getLeftEncoderSpeed()));
        Serial.println("Right encoder: " + String(desk.getRightEncoderSpeed()));
        last_time = millis();
    }
#endif
#endif
}
