#pragma once
#include"PuzzleTools.h"
#include <set>

class PuzzleCalculation
{
public:
	int* sort_array_by_set(int* array, int length);
	int check_partial_of_array(int* array, int length);
	int check_4partial_of_array(int* array, int length);
	int check_3partial_of_array(int* array, int length);
	int check_2partial_of_array(int* array, int length);
	unsigned long long get_factorial(int num);
	unsigned long long calculate_result(int* array, int length);
	unsigned long long sort_and_calculate_result(int* array, int length);
private:

};

