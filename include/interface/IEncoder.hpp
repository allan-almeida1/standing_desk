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
 * @note This encoder assumes time-based speed calculation. The speed is
 * calculated based on the time between encoder reads. If the encoder is not
 * read for a certain time, the speed is set to 0.
 */

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

    /**
     * @brief Check time since last encoder read and set speed to 0 if time
     * exceeds maximum time
     */
    virtual void checkEncoderTimeout() = 0;
};

#endif // IENCODER_HPP