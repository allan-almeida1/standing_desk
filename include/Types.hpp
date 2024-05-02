/**
 * @brief Define types for usage in classes to match Arduino types
 * @author Allan Almeida
 * @date 2024-05-01
 */

#define HIGH 1
#define LOW 0

typedef signed int int8_t __attribute__((__mode__(__QI__)));
typedef unsigned int uint8_t __attribute__((__mode__(__QI__)));
typedef signed int int16_t __attribute__((__mode__(__HI__)));
typedef unsigned int uint16_t __attribute__((__mode__(__HI__)));