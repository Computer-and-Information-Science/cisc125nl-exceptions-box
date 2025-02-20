// box.cpp

#include "box.h"

using namespace std;

Box::Box () {
	// Initialize all tiles to true (meaning open or up)
	for (int i = 1; i <= 9; i++)
		tiles[i] = true;
}

bool Box::close (int tile1, int tile2, int tile3) {

	// Ensure all tiles numbers are valid or zero
	if (tile1 < 0 || tile2 < 0 || tile3 < 0)
		return false;
	if (tile1 > 9 || tile2 > 9 || tile3 > 9)
		return false;

	// Ensure that not all tiles are zero
	if (!tile1 && !tile2 && !tile3)
		return false;

	// Ensure no two non-zero tiles are equal
	if (tile1 && (tile1 == tile2 || tile1 == tile3))
		return false;
	if (tile2 && (tile2 == tile3))
		return false;

	// Ensure all non-zero tiles are open (up)
	tiles[0] = true; // so we don't error on zero
	if (!tiles[tile1] || !tiles[tile2] || !tiles[tile3])
		return false;

	// Close tiles (no harm to set tiles[0] to false)
	tiles[tile1] = false;
	tiles[tile2] = false;
	tiles[tile3] = false;

	// Indicate success
	return true;
}

int Box::score () const {
	// Add up all tile numbers in the up position
	int total = 0;
	for (int i = 1; i <= 9; i++)
		if (tiles[i])
			total += i;
	return total;
}

string Box::str () const {
	// Initialize output to show all tiles up
	string s = "1 2 3 4 5 6 7 8 9";
	// For each tile that is down, replace with '*'
	for (int i = 1; i <= 9; i++)
		if (!tiles[i])
			s[(i - 1) * 2] = '*';
	return s;
}
