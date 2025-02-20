// box.h

#pragma once

#include <string>

class Box {
	private:
		bool tiles[10]; // Using indexes 1 through 9
	public:
		Box(); // Constructor
		bool close (int tile1, int tile2, int tile3); // Close tiles
		int score () const; // Calculate score
		std::string str () const;
};
