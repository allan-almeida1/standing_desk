/**
 * @brief Define types for usage in classes to match Arduino types
 * @author Allan Almeida
 * @date 2024-05-01
 */

#ifndef TYPES_HPP
#define TYPES_HPP

typedef signed int int8_t __attribute__((__mode__(__QI__)));
typedef unsigned int uint8_t __attribute__((__mode__(__QI__)));
typedef signed int int16_t __attribute__((__mode__(__HI__)));
typedef unsigned int uint16_t __attribute__((__mode__(__HI__)));

#endif // TYPES_HPP