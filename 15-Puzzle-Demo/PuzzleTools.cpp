#include "PuzzleTools.h"

int PuzzleTools::get_random_number(int length)
{
	random_device random_dev;
	mt19937 range(random_dev());
	uniform_int_distribution<mt19937::result_type>random_number(1, length*length+length);
	return random_number(range);
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

bool PuzzleTools::compare_elemrnt_in_vector_and_num(vector<int> vecArray, int num)
{
	for (unsigned int i = 0; i < vecArray.size(); i++)
	{
		if (vecArray[i] == num)return true;
		else
			continue;
	}
	return false;
}

void PuzzleTools::print_single_map(int* array, int level)
{
	for (int i = 0; i < level * level; i++)
	{
		if (array[i] == 0)
		{
			cout << " " << "\t";
			if (i == level - 1 || i == level * 2 - 1 || i == level * 3 - 1 || i == level * 4 - 1)
			{
				cout << endl;
			}
		}
		else if ((i + 1) % level != 0)
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


