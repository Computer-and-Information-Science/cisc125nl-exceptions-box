# Shut The Box - Part 1

For this assignment you will build a class called *Box* to incorporate into
a program that plays a variant of the game
[Shut The Box](https://en.wikipedia.org/wiki/Shut_the_Box).
You will only create and test the class to represent the box for the game;
part 2 of this assignment will complete the game.

For our game, there is a
box that contains 9 tiles numbered 1 through 9 with all tiles initially in the
up-facing position.
Over several rounds of the game, a player will choose one, two, or three
up-facing tiles to "close" or place into the down-facing position.

Build a class called *Box*, placing your code in the header and implementation
files *box.h* and *box.cpp*.
Your class must support the following methods:

- Constructor, no parameters.
- *close* - accepts three *int* parameters, returns *bool*. Mutator.
- *score* - no parameters, returns *int*. Accessor.
- *str* - no parameters, return *std::string*. Accessor.

The constructor initializes the object such that all tiles are in
the up-facing position.

The *close* method places one, two, or three up-facing tiles to the
down-facing position, or indicates an error if any parameters are invalid.
For the parameters to be valid, each of the three parameters must
be either an up-facing tile or zero, and no two non-zero parameter values
may be the same. If the parameters are valid, the tiles indicated by the
non-zero parameters are to be changed to the down-facing position
and the function returns *true*.
If the parameter values are not valid, the function returns *false*
with no change to the tiles.
This method may assume that all parameter values given are in the range
of 0 through 9.

The *score* method returns the sum of all up-facing tiles, thus representing
the current score of the box.

The *str* method returns a string representation of the current state of the box.
The string returned is to include the numbers 1 through 9, with the numbers
of the down-facing tiles replaced with asterisks. For example, if tiles
3 and 7 are down-facing, this function returns the string `1 2 * 4 5 6 * 8 9`.

None of these methods produce any output; user interaction will be handled by
the game program that uses the *Box* object. An error condition detected by
the *close* method is indicated solely by the return value.

A *main* function is given in this repository for purposes of testing your
*Box* class. It is a menu-driven program with portions related to the *Box*
object commented out. Use this program to test your class.
Remove comment indicators as needed in order to test the *Box* object.
