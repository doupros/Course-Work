#pragma once
#include "PuzzleTools.h"
#include "PuzzleCalculation.h"
class PuzzleFile :public PuzzleCalculation
{
public:
	void write_in_file(int* array, int length);
	void write_fill_file(int* array, int length);
	void write_result_in_file(int* array, int length,bool input);
	void write_result_in_file(int* array, int length);
	void read_and_print_puzzle_file();
	void read_and_print_solution_file();
	int* read_from_file();
	int* read_from_file_plus_calculation(int length);


private:

};
