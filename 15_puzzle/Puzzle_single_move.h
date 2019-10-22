#include <iostream>
#include "Puzzle_tools.h"
using namespace std;

class PuzzleSingleMove : public PuzzleTools
{
public:
	void move_single_up(int arr[], int length);
	void move_single_down(int arr[], int length);
	void move_single_left(int arr[], int length);
	void move_single_right(int arr[], int length);
};