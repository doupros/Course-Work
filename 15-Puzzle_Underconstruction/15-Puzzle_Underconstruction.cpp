#include <fstream>
#include "MoveBlank.h"
#include <string>
#include <vector>

using namespace std;

const int global_number = 4;

struct Arrays
{
	int array[global_number][global_number];
};
int  num;

void createArray() 
{
	 
}

void fillAllCase() {};

void printMap(int arr[global_number][global_number] , int column,int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (arr[i][j] == 0)
			{
				cout << " " << "\t";
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

void writeFile() {};

void readFile() {};

int main()
{
	int arr[global_number][global_number] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,0} };
	createArray();
	return 0;
}

vector<Arrays> possiable_Cases;

bool check(Arrays arrays) 
{
	bool checkRepeat;
		for (int possiable_cases_size = 0; possiable_cases_size < possiable_Cases.size(); possiable_cases_size++)
		{
			for (int first_num_in_array = 0; first_num_in_array < global_number; first_num_in_array++)
			{
				for (int second_num_in_array = 0; second_num_in_array < global_number; second_num_in_array++)
				{
					if (arrays.array[first_num_in_array][second_num_in_array]!=possiable_Cases[possiable_cases_size].array[first_num_in_array][second_num_in_array] && arrays.array[global_number-1][global_number-1]==0)
					{
						return true;
					}
				}
			}
		}
}


void movement(int arr[4][4]) {
	Arrays* Up_Seleted_Array = new Arrays;
	moveUp(Up_Seleted_Array->array, global_number, global_number);
	if (check(*Up_Seleted_Array))
	{
		possiable_Cases.push_back(*Up_Seleted_Array);
	} 
	else
	{
		delete Up_Seleted_Array;
		Up_Seleted_Array = NULL;
	}

	Arrays* Down_Seleted_Array = new Arrays;
	moveDown(Down_Seleted_Array->array, global_number, global_number);
		if (check(*Down_Seleted_Array))
		{
			possiable_Cases.push_back(*Down_Seleted_Array);
		}
		else
		{
			delete Down_Seleted_Array;
			Down_Seleted_Array = NULL;
		}

		Arrays* Left_Seleted_Array = new Arrays;
		moveDown(Left_Seleted_Array->array, global_number, global_number);
		if (check(*Left_Seleted_Array))
		{
			possiable_Cases.push_back(*Left_Seleted_Array);
		}
		else
		{
			delete Left_Seleted_Array;
			Left_Seleted_Array = NULL;
		}

		Arrays* Right_Seleted_Array = new Arrays;
		moveDown(Right_Seleted_Array->array, global_number, global_number);
		if (check(*Right_Seleted_Array))
		{
			possiable_Cases.push_back(*Right_Seleted_Array);
		}
		else
		{
			delete Right_Seleted_Array;
			Right_Seleted_Array = NULL;
		}


}