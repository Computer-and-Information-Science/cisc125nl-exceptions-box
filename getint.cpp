#include "getint.h"
#include <iostream>
#include <string>
using namespace std;

int get_int(string prompt) {
	int value; // for input of an integer value
	// Prompt for and input an integer
	cout << prompt;
	cin >> value;
	// Check for input error
	while (cin.fail()) {
		// Clear error on cin, flush input stream
		cin.clear();
		cin.ignore(1000, '\n');
		// Issue error message and re-input
		cout << "ERROR: An integer was expected, try again: ";
		cin >> value;
	}
	// Check for extra characters in input
	if (cin.peek() != '\n')
		cout << "WARNING: Extra characters after integer ignored.\n";
	cin.ignore(1000, '\n');
	// Return the value that was input  
	return value;
}

int get_int_range(string prompt, int min_value, int max_value) {
	int value; // for integer input
	// Prompt for and get input value
	value = get_int(prompt);
	// Check input value against acceptable range
	while (value < min_value || value > max_value) {
		// Issue error message and re-input
		cout << "ERROR: An integer from " << min_value << " to " << max_value << " was expected. ";
		value = get_int("Try again: ");
	}
	return value;
}
