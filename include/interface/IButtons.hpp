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

// Pointer to callback function
typedef void (*Btcb)(void);

// Pointer to callback function with integer parameter
typedef void (*BtcbParamInt)(int);

/**
 * @brief Enum class for button index
 */
enum class ButtonIndex : uint8_t
{
    UP = 0,  // Button up index
    DOWN,    // Button down index
    MEM,     // Button memory index
    BUTTON1, // Button 1 index
    BUTTON2, // Button 2 index
    BUTTON3  // Button 3 index
};

/**
 * @brief Abstract class for button
 *
 */
class IButtons
{
  public:
    /**
     * @brief Handle button press events
     *
     * @param button Button index
     * @param press_cb Button press callback function
     * @param release_cb Button release callback function
     * @param short_press_cb Short press callback function
     * @param long_press_cb Long press (>= 3s) callback function
     * @param held_cb Button held callback function
     */
    virtual void handleButtonEvent(ButtonIndex button, Btcb press_cb = nullptr,
                                   Btcb release_cb = nullptr,
                                   Btcb short_press_cb = nullptr,
                                   Btcb long_press_cb = nullptr,
                                   Btcb held_cb = nullptr) = 0;

    /**
     * @brief Handle button press events with a callbacls that
     * receives an integer parameter
     *
     * @param button Button index
     * @param press_cb Button press callback function
     * @param release_cb Button release callback function
     * @param short_press_cb Short press callback function
     * @param long_press_cb Long press (>= 3s) callback function
     * @param held_cb Button held callback function
     * @param param Parameter to be passed to the callback function
     */
    virtual void handleButtonEvent(ButtonIndex button,
                                   BtcbParamInt press_cb = nullptr,
                                   BtcbParamInt release_cb = nullptr,
                                   BtcbParamInt short_press_cb = nullptr,
                                   BtcbParamInt long_press_cb = nullptr,
                                   BtcbParamInt held_cb = nullptr,
                                   int param = 0) = 0;

    virtual ~IButtons() {}
};

#endif // IBUTTONS_HPP