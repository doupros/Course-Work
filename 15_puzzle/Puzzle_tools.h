#include<iostream>
using namespace std;

class PuzzleTools 
{
private:
	int global_number = 4;
	int global_single_number = 16;
public:
	void set_global_single_number(int new_global_number);
	void set_global_number(int new_global_number);
	void print_single_map(int* array, int length);
	bool compare_array_and_num(int* arr, int arr_length, int num);
	void mySwap(int& x, int& y);
	int* bubbleSort(int* array, int length_of_array);
	void printMap(int arr[global_number][global_number], int column, int row);

};