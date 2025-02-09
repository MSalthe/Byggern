#ifndef JOYSTICK_H
#define JOYSTICK_H

#define F_CPU 8e6// Clock Speed

#include <stdint.h>
#include <stdlib.h>
#include "sram.h"
#include <util/delay.h>
#include <avr.h>

struct JoystickVoltage
{
    uint8_t xValue;
    uint8_t yValue;
};
volatile struct JoystickVoltage joystickVoltage;

struct SliderVoltage
{
    uint8_t sliderA;
    uint8_t sliderB;
};
volatile struct SliderVoltage sliderVoltage;

struct JoystickState
{
    // State is_active
    int isJoystickActuatedX;
    int isJoystickActuatedY;
    // State is_active_prev
    int isJoystickActuatedXPrev;
    int isJoystickActuatedYPrev;
    // State is_button_pressed
    int isButtonPressed;
    // State is_button_pressed_prev
    int isButtonPressedPrev;

    // Is rising edge
    int isJoystickActuatedXRisingEdge;
    int isJoystickActuatedYRisingEdge;
    int isButtonPressedRisingEdge;
};
volatile struct JoystickState joystickState;

/**
 * @brief Sample the joystick position and button
 * 
 * @param pJoystickVoltage 
 * @param pSliderVoltage 
 * @param pJoystickState 
 */
void joystick_update(struct JoystickVoltage* pJoystickVoltage, struct SliderVoltage* pSliderVoltage, struct JoystickState* pJoystickState);

/**
 * @brief Compute the joytick angle in the X direction as a percentage
 * 
 * @return int 
 */
int get_joystick_angle_x();

/**
 * @brief Compute the joytick angle in the Y direction as a percentage
 * 
 * @return int 
 */
int get_joystick_angle_y();

/**
 * @brief Get the slider pos position as a percentage
 * 
 * @param voltage 
 * @return int 
 */
int get_slider_pos(uint8_t voltage);

/**
 * @brief Returns whether the joystick position is exceeding a threshold
 * 
 * @param positionPercentage 
 * @return 1 if is exceeding pos, -1 if exceeding neg
 * @return 0 if is not exceeding
 */
int joystick_detect_actuation(int positionPercentage);

/**
 * @brief Returns whether the button is pressed
 * 
 * @param buttonInput 
 * @return 1 if is pressed, 0 otherwise 
 */
int8_t joystick_detect_button_pressed(int buttonInput);

/**
 * @brief Return direction of joystick in x direction
 */
int8_t joystick_get_direction_x();

/**
 * @brief Return direction of joystick in y direction
 */
int8_t joystick_get_direction_y();

/**
 * @brief Perform joystick initialization
 * 
 */
void joystick_init();

/**
 * @brief Transmit joystick position over CAN. Interval is 0-200 for both directions.
 * 
 */
void joystick_transmit_position_over_can();

#endif // JOYSTICK_H