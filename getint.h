/**
 * @file getint.h
 * @brief Functions for integer input with validation
 * @author N. Lippincott, Northampton Community College
 */

#pragma once
#include <string>

/**
 * Input an integer from the console with validation
 *
 * Issues a prompt to the console and inputs an integer with error
 * checking. If input is provided that is not a valid integer, an
 * error message is issued and the user is re-prompted. Any extra
 * input that is provided following the integer is discarded.
 *
 * @param prompt Input prompt to be issued
 * @return The integer input value
 */
int get_int(std::string prompt);

/**
 * Input an integer from the console with range validation
 *
 * Issues a prompt to the console and inputs an integer with error
 * and range checking. If input is provide that is not a valid
 * integer or is outside the specified range, an error message is
 * issued and the user is re-prompted. Any extra input that is
 * provided following the integer is discarded.
 *
 * @param prompt Input prompt to be issued
 * @param min_value Minimum acceptable input value
 * @param max_value Maximim acceptable input value
 * @return The integer input value
 */
int get_int_range(std::string prompt, int min_value, int max_value);
