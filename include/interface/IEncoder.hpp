/**
 * @file IEncoder.hpp
 * @brief Abstract class for motor encoder
 * @author Allan Souza Almeida
 * @version 0.1
 * @date 2024-05-01
 */

#ifndef IENCODER_HPP
#define IENCODER_HPP

#include "Types.hpp"

/**
 * @brief Abstract class for motor encoder
 *
 */
class IEncoder
{
  public:
    /**
     * @brief Get the speed value in RPM
     *
     * @return Speed value
     */
    virtual float getSpeed() = 0;
};

#endif // IENCODER_HPP