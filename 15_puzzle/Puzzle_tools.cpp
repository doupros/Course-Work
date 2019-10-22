#include "Puzzle_tools.h"


void PuzzleTools::set_global_single_number(int new_global_single_number)
{
	global_single_number = new_global_single_number;
}

void PuzzleTools::set_global_number(int new_global_number) 
{
	global_number = new_global_number;
}

void PuzzleTools::mySwap(int& x, int& y) 
{
	int temp = x;
	x = y;
	y = temp;
}

int* PuzzleTools::bubbleSort(int* array, int length_of_array) 
{
	for (int i = 0; i < length_of_array - 1; i++)
	{
		for (int j = 0; j < length_of_array - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				mySwap(array[j], array[j + 1]);
			}
		}
	}
	static int array_after_sort[global_single_number];
	for (int i = 0; i < global_single_number - 1; i++)
	{
		array_after_sort[i] = array[i + 1];
	}
	array_after_sort[global_single_number - 1] = 0;
	return array_after_sort;
}

bool PuzzleTools::compare_array_and_num(int* arr, int arr_length, int num)
{
	for (int i = 0; i < arr_length; i++)
	{
		if (arr[i] == num) return true;
		else
			continue;
	}
	return false;
}

void PuzzleTools::printMap(int arr[global_number][global_number], int column, int row) 
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (arr[i][j] == 0)
			{
				cout << "\t" << "\t";
			}
			else
			{
				cout << arr[i][j] << "\t";
			}

		}
		cout << endl;
	}
	cout << endl;
};

void PuzzleTools::print_single_map(int* array, int length) 
{
	for (int i = 0; i < length; i++)
	{
		if (array[i] == 0)
		{
			cout << " " << "\t";
			if (i == sqrt(global_single_number) - 1 || i == sqrt(global_single_number) * 2 - 1 || i == sqrt(global_single_number) * 3 - 1 || i == sqrt(global_single_number) * 4 - 1)
			{
				cout << endl;
			}
		}
		else if ((i + 1) % sqrt_global_single_number != 0)
		{
			cout << array[i] << "\t";
		}
		else
		{
			cout << array[i] << endl;
		}
	}
	cout << endl;
}