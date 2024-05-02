/**
 * @file IButtons.hpp
 * @brief Abstract class for buttons
 * @author Allan Souza Almeida
 * @version 0.1
 * @date 2024-05-01
 */

#ifndef IBUTTONS_HPP
#define IBUTTONS_HPP

#include "Types.hpp"

/**
 * @brief Abstract class for buttons
 *
 */
class IButtons
{
  public:
    /**
     * @brief Check if the up button is pressed and execute the callback
     * function
     *
     * @param callback Callback function to be executed
     */
    virtual void upPressed(void (*callback)()) = 0;

    /**
     * @brief Check if the down button is pressed and execute the callback
     * function
     *
     * @param callback Callback function to be executed
     */
    virtual void downPressed(void (*callback)()) = 0;

    /**
     * @brief Check if the memory button is pressed and execute the callback
     * function
     *
     * @param callback Callback function to be executed
     */
    virtual void memPressed(void (*callback)()) = 0;

    /**
     * @brief Check if the button 1 is pressed and execute the callback
     * function
     *
     * @param callback Callback function to be executed
     */
    virtual void bt1Pressed(void (*callback)()) = 0;

    /**
     * @brief Check if the button 2 is pressed and execute the callback
     * function
     *
     * @param callback Callback function to be executed
     */
    virtual void bt2Pressed(void (*callback)()) = 0;

    /**
     * @brief Check if the button 3 is pressed and execute the callback
     * function
     *
     * @param callback Callback function to be executed
     */
    virtual void bt3Pressed(void (*callback)()) = 0;

    virtual ~IButtons() {}
};

#endif // IBUTTONS_HPP