/**
 * @file IDisplay.hpp
 * @brief Abstract class for display devices
 * @author Allan Souza Almeida
 * @version 0.1
 * @date 2024-05-01
 */

#ifndef IDISPLAY_HPP
#define IDISPLAY_HPP

#include "Types.hpp"

/**
 * @brief Abstract class for display
 *
 */
class IDisplay
{
  public:
    /**
     * @brief Display a number
     *
     * @param number Number to be displayed
     */
    virtual void displayNumber(int16_t number) = 0;
    virtual ~IDisplay() {}
};

#endif // IDISPLAY_HPP