#include "PuzzleCalculation.h"

int* PuzzleCalculation::sort_array_by_set(int* array, int length)
{
	int count = 0;
	int* newarray = new int[16];
	set<int> setarray;
	for (int i = 0; i < length * length; i++)
	{
		setarray.insert(array[i]);
	}
	setarray.erase(setarray.begin());

	for (set<int>::iterator it = setarray.begin(); it != setarray.end(); it++)
	{
		newarray[count++] = *it;
	}
	newarray[length * length - 1] = 0;
	return  newarray;
}

int PuzzleCalculation::check_partial_of_array(int* array, int length)
{
	int count = 0;
	for (int i = 0; i < length * length - length + 1; i++)
	{
		if (array[i]+(length-1)==array[i+(length-1)])
		{
			count++;
		}
		else continue;
	}
	return count;
}

int PuzzleCalculation::check_4partial_of_array(int* array, int length)
{
	int count = 0;
	for (int i = 0; i < length * length - length + 1; i++)
	{
		if (array[i+3]-array[i+2]== array[i + 2] - array[i + 1] == array[i + 1] - array[i ] == 1)
		{
			count++;
		}
		else continue;
	}
	return count;
}


int PuzzleCalculation::check_3partial_of_array(int* array, int length)
{
	int count = 0;
	for (int i = 0; i < length * length - 3; i++)//checking row partial
	{
		if (array[i+2] - array[i + 1] == array[i + 1] - array[i] ==1)
		{
			count++;
		}
		else continue;
	}
	for (int i = length*length; i >1 ; i--)//checking reverse row partial
	{
		if (array[i] - array[i - 1] == array[i - 1] - array[i - 2])
		{
			count++;
		}
		else continue;
	}
	for (int i = 0; i < length*(length-2); i++)//checking column
	{
		if (array[i+2*length]-array[i+length]==array[i+length]-array[i]==1)
		{
			count++;
		}
		else continue;
	}
	for (int i = 0; i < length * (length - 2); i++)//checking reverse column
	{
		if (array[i]-array[i+length]==array[i+length]-array[i+2*length])
		{
			count++;
		}
		else continue;
	}
	return count;
}

int PuzzleCalculation::check_2partial_of_array(int* array, int length)
{
	int count = 0;
	for (int i = 0; i < length * length - 2; i++)//checking row
	{
		if (array[i+1] - array[i]==1)
		{
			count++;
		}
		else continue;
	}
	for (int i = 0; i < length * length - 2; i++)//checking reverse row
	{
		if (array[i] - array[i+1] == 1)
		{
			count++;
		}
		else continue;
	}
	for (int i = 0; i < length; i++)//checking column
	{
		if (array[i+length]-array[i]==1)
		{
			count++;
		}
		else continue;
	}
	for (int i = 0; i < length; i++)//checking reverse column
	{
		if (array[i ] - array[i + length] == 1)
		{
			count++;
		}
		else continue;
	}


	return count;
}

unsigned long long PuzzleCalculation::get_factorial(int num)
{
	unsigned long long result = 0;
	result = num;
	for (int i = num - 1; i > 0; i--)
	{
		result *= i;
	}
	return result;
}

unsigned long long PuzzleCalculation::calculate_result(int* array,int length)
{
	unsigned long long result = 0;
	result = ((unsigned long long)check_partial_of_array(array, length)) * (length - 1) * (get_factorial((length * length - length - 1)) / 2);
	return result;
}

unsigned long long PuzzleCalculation::sort_and_calculate_result(int* array, int length)
{
	return calculate_result(sort_array_by_set(array, length), length);
}