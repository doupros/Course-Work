#include <fstream>
#include "MoveBlank.h"
#include <string>
#include <vector>

using namespace std;

const int global_number = 4;
const int global_single_number = 16;

class Arrays
{
public:
	int array[global_number][global_number];
};

vector<Arrays> possiable_Cases;

//int* inputArray() 
//{
//	int *array_from_input[global_number][global_number];
//
//	int inputed_number;
//
//	for (int i = 0; i < global_number; i++)
//	{
//		for (int j = 0; j < global_number; j++)
//		{
//			if (i == 3 && j == 3)
//				return array_from_input[global_number][global_number];
//			for (;;)
//			{
//				cout << "please input the No.(" << i+j << ") number of the array:" << endl;
//				cin >> inputed_number;
//				if (cin.fail() || inputed_number < 0 || inputed_number>20)
//				{
//					cin.clear();
//					cin.ignore(1024, '\n');
//				}
//				else
//				{
//					array_from_input[i][j];
//					break;
//				}
//			}
//		}
//	}
//	return array_from_input[global_number][global_number];
//}

bool compaire_array_and_num(int* arr, int arr_length, int num)
{
	for (int i = 0; i < arr_length; i++)
	{
		if (arr[i] == num) return true;
		else
			continue;
	}
	return false;
}


int* inputArray() 
{
	int num;
	int array[global_single_number];
	for (int i = 0; i < global_single_number-1; i++)
	{
		for (;;)
		{
			cout << "please input the No.(" << i + 1 << ") number" << endl;
			cin >> num;
			if (cin.fail() || num <= 0 || num>20)
			{
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "incorrect input, please input again!" << endl;
			}
			else if (compaire_array_and_num(array,global_single_number,num))
			{
				cout << "the number is already inputed, please input again!" << endl;
			}
			else {
				array[i] = num;
				break;
			}
		}
	}
	array[global_single_number-1] = 0;
	return &array[global_single_number];
}

void createArray() 
{
	int num;
	for (;;)
	{
		cout << "please input a number(1-20):" << endl;
		cin >> num;
		if (cin.fail() || num < 0 || num>20)
		{
			cin.clear();
			cin.ignore(1024,'\n');
		}
		else
		break;
	}
	cout << num;

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

void writeFile() {
	ofstream newfile;
	newfile.open("texe.txt", ios::out);
	for (size_t k = 0; k < possiable_Cases.size() ;k++)
	{
		for (int i = 0; i < global_number; i++)
		{
			for (int j = 0; j < global_number; j++)
			{
				if (possiable_Cases[k].array[i][j]==0)
				{
					cout << " " << "\t";
				}
				else
				{
					cout << possiable_Cases[k].array[i][j]  << "\t";
				}

			}
			cout << endl;
		}
		cout << endl;
	}
	newfile.close();

};

void readFile() {};

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

void movement(int arr[global_number][global_number])
{
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


int main()
{
	/*= { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,0} }*/;

	int* array = inputArray();

	return 0;
}
