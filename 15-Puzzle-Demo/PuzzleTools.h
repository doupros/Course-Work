#pragma once
#include <iostream>
#include <random>
#include <vector>
#include <fstream>
#include <string>
#define PUZZLENUM 4
using namespace std;

 class  PuzzleTools
{
public:
	virtual int get_random_number();
	virtual bool compare_array_and_num(int* arr, int arr_length, int num);
	virtual bool compare_elemrnt_in_vector_and_num(vector<int> vecArray, int num);
	virtual void print_single_map(int* array, int length);
	
private:

};

