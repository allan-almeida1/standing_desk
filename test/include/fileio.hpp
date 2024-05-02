/**
 * @file fileio.hpp
 * @brief File I/O interface. This file contains the file I/O methods.
 * It is necessary because arduino methods passed as parameters cannot be
 * non-static class methods, and we need to mock them for testing and be able
 * to verify the results afterwards.
 * @author Allan Souza Almeida
 * @version 0.1
 * @date 2024-05-01
 */

#ifndef FILEIO_HPP
#define FILEIO_HPP

#include "Types.hpp"
#include <fstream>
#include <iostream>
#include <string>

/**
 * @brief Write to a file
 *
 * @param file_name File name
 * @param data Data to be written
 */
void writeToFile(const std::string &file_name, const std::string &data)
{
    std::ofstream file(file_name, std::ios::app);
    if (file.is_open())
    {
        file << data;
        file.close();
    }
    else
    {
        std::cerr << "Error opening file " << file_name << std::endl;
    }
}

/**
 * @brief Read from a file
 *
 * @param file_name File name
 * @return std::string Data read from the file
 */
std::string readFromFile(const std::string &file_name)
{
    std::ifstream file(file_name);
    std::string data;
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            data += line;
        }
        file.close();
    }
    else
    {
        std::cerr << "Error opening file " << file_name << std::endl;
    }
    return data;
}

#endif // FILEIO_HPP