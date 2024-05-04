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

/**
 * @brief Abstract class for buttons
 *
 */
class IButtons
{
  public:
    /**
     * @brief Handle up button press events
     *
     * @param press_cb Button press callback function
     * @param release_cb Button release callback function
     * @param short_press_cb Short press callback function
     * @param long_press_cb Long press (>= 3s) callback function
     * @param held_cb Button held callback function
     */
    virtual void handleUpButton(Btcb press_cb = nullptr,
                                Btcb release_cb = nullptr,
                                Btcb short_press_cb = nullptr,
                                Btcb long_press_cb = nullptr,
                                Btcb held_cb = nullptr) = 0;

    /**
     * @brief Handle down button press events
     *
     * @param press_cb Button press callback function
     * @param release_cb Button release callback function
     * @param short_press_cb Short press callback function
     * @param long_press_cb Long press (>= 3s) callback function
     * @param held_cb Button held callback function
     */
    virtual void handleDownButton(Btcb press_cb = nullptr,
                                  Btcb release_cb = nullptr,
                                  Btcb short_press_cb = nullptr,
                                  Btcb long_press_cb = nullptr,
                                  Btcb held_cb = nullptr) = 0;

    /**
     * @brief Handle memory button press events
     *
     * @param press_cb Button press callback function
     * @param release_cb Button release callback function
     * @param short_press_cb Short press callback function
     * @param long_press_cb Long press (>= 3s) callback function
     * @param held_cb Button held callback function
     */
    virtual void handleMemButton(Btcb press_cb = nullptr,
                                 Btcb release_cb = nullptr,
                                 Btcb short_press_cb = nullptr,
                                 Btcb long_press_cb = nullptr,
                                 Btcb held_cb = nullptr) = 0;

    /**
     * @brief Handle button 1 press events
     *
     * @param press_cb Button press callback function
     * @param release_cb Button release callback function
     * @param short_press_cb Short press callback function
     * @param long_press_cb Long press (>= 3s) callback function
     * @param held_cb Button held callback function
     */
    virtual void handleButton1(Btcb press_cb = nullptr,
                               Btcb release_cb = nullptr,
                               Btcb short_press_cb = nullptr,
                               Btcb long_press_cb = nullptr,
                               Btcb held_cb = nullptr) = 0;

    /**
     * @brief Handle button 2 press events
     *
     * @param press_cb Button press callback function
     * @param release_cb Button release callback function
     * @param short_press_cb Short press callback function
     * @param long_press_cb Long press (>= 3s) callback function
     * @param held_cb Button held callback function
     */
    virtual void handleButton2(Btcb press_cb = nullptr,
                               Btcb release_cb = nullptr,
                               Btcb short_press_cb = nullptr,
                               Btcb long_press_cb = nullptr,
                               Btcb held_cb = nullptr) = 0;

    /**
     * @brief Handle button 3 press events
     *
     * @param press_cb Button press callback function
     * @param release_cb Button release callback function
     * @param short_press_cb Short press callback function
     * @param long_press_cb Long press (>= 3s) callback function
     * @param held_cb Button held callback function
     */
    virtual void handleButton3(Btcb press_cb = nullptr,
                               Btcb release_cb = nullptr,
                               Btcb short_press_cb = nullptr,
                               Btcb long_press_cb = nullptr,
                               Btcb held_cb = nullptr) = 0;

    virtual ~IButtons() {}
};

#endif // IBUTTONS_HPP