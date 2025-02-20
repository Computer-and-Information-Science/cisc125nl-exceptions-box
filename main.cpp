// CISC125 - Shut The Box Part 1
//  A test program for the Box class

#include "box.h"
#include "getint.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void get_tiles (int& tile_a, int& tile_b, int& tile_c);
bool is_valid_tile (int tile);

int main () {
    // Declare a Box object (uncomment below for testing the constructor)
    Box the_box;

    // For input of menu choice
    int menu_choice;

    // For input of tile numbers
    int tile_a, tile_b, tile_c;

    // A loop for testing the Box methods
    do {
        cout << "1. Close tiles\n";
        cout << "2. Get the score\n";
        cout << "3. Show the box\n";
        cout << "9. Exit\n\n";

        // Get menu choice
        menu_choice = get_int("Enter choice: ");

        switch (menu_choice) {
            case 1:
                get_tiles(tile_a, tile_b, tile_c);
                cout << "Closing tiles: " << tile_a << ", " << tile_b << ", " << tile_c << endl;
                // Remove comments below to test close method
                if (the_box.close(tile_a, tile_b, tile_c))
                    cout << "Tiles closed successfully.\n";
                else 
                    cout << "Error trying to close tiles.\n";
                break;
            case 2:
                // Remove comment below to test score method
                cout << "Current box score is " << the_box.score() << ".\n";
                break;
            case 3:
                // Remove comment below to test scr method
                cout << the_box.str() << "\n";
                break;
            case 9:
                break;
            default:
                cout << "Invalid menu choice.\n";
        }

        cout << endl;
    } while (menu_choice != 9);
}

/**
 * Prompt for and input one, two, or three tile numbers
 * 
 * Issues a prompt and inputs up to three valid tile numbers. Valid tile
 * numbers are 1 through 9 (although 0 is allowed as input). Multiple tile
 * numbers are expected to be separated by spaces. At least one (non-zero)
 * tile number must be entered. If only one tile number is entered, tile_b
 * and tile_c are returned as 0. If only two tile numbers are entered, tile_c
 * is returned as 0. Extranneous and non-integer input is ignored.
 * 
 * @param tile_a Returns first tile number
 * @param tile_b Returns second tile number
 * @param tile_c Returns third tile number
 */
void get_tiles (int& tile_a, int& tile_b, int& tile_c) {

    bool err; // Error flag

    do {
        // Initialize tile input values
        tile_a = tile_b = tile_c = 0;

        // Prompt for tiles and get input string
        string s;
        cout << "Enter 1, 2, or 3 tiles to close: ";
        getline(cin, s);

        // Extract up to 3 integers from input string
        istringstream iss(s);
        iss >> tile_a >> tile_b >> tile_c;

        // Validate tile input
        err = !is_valid_tile(tile_a) || !is_valid_tile(tile_b) || !is_valid_tile(tile_c);
        if (err)
            cout << "Valid tile numbers are 1 through 9, try again.\n";
    
    } while (err);
}

/**
 * Checks for a valid tile number
 * 
 * @param tile A tile number
 * @return True if tile number is 0 through 9, otherwise false
 */
bool is_valid_tile (int tile) {
    return tile >= 0 && tile <= 9;
}
