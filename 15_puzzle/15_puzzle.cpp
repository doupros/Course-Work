#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include<math.h>

#include"Puzzle_tools.h"
#include"Puzzle_single_move.h"



#define NUMBER 4;

using namespace std;

const int global_number = 4;
const int global_single_number = 16;
const int sqrt_global_single_number = sqrt(global_single_number);
random_device random_dev;
mt19937 range(random_dev());
uniform_int_distribution<mt19937::result_type>random_number(1, 20);

//void print_single_map(int* array, int length);
//bool compare_array_and_num(int* arr, int arr_length, int num);
//void mySwap(int& x, int& y);
//int* bubbleSort(int* array, int length_of_array);
//void printMap(int arr[global_number][global_number], int column, int row);

int* random_array();

int* inputArray();

void createArray();

void many_random_array(int number);
void movement(int arr[global_number][global_number]);
//void move_single_up(int arr[], int length);
//void move_single_down(int arr[], int length);
//void move_single_left(int arr[], int length);
//void move_single_right(int arr[], int length);

class Class_type_arrays
{
public:
	int array[global_number][global_number];
};

vector<Class_type_arrays> possiable_Cases;

struct struct_type_single_arrays
{
	int array[global_single_number];
};

vector<struct_type_single_arrays> possiable_single_cases;


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



int main()
{
	/*	int array[4][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,0} };*/
	/*int array[] = { 6, 3, 4, 5, 1, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 0 };*/
	int* array = random_array();

	PuzzleTools::print_single_map(array, global_single_number);
	PuzzleSingleMove::move_single_up(array, global_single_number);
	print_single_map(array, global_single_number);
	move_single_left(array, global_single_number);
	print_single_map(array, global_single_number);
	move_single_down(array, global_single_number);
	print_single_map(array, global_single_number);
	move_single_right(array, global_single_number);
	print_single_map(array, global_single_number);

	int* array_inputed = inputArray();
	print_single_map(array_inputed, global_single_number);

	/*int* arrayptr;
	arrayptr = random_array();
	print_single_map(arrayptr, global_single_number);
	int* arrptr1= bubbleSort(arrayptr, global_single_number);
	print_single_map(arrptr1, global_single_number);

	many_random_array(5);

	int* array = inputArray();*/



	return 0;
}

void many_random_array(int number)
{
	cout << number << endl;
	for (int i = 0; i < number; i++)
	{
		int* arrayptr = random_array();
		print_single_map(arrayptr, global_single_number);
	}
}

int* random_array()
{
	static int array[global_single_number];
	int num;
	for (int i = 0; i < global_single_number - 1; )
	{
		num = random_number(range);
		if (compare_array_and_num(array, global_single_number, num))
		{
			continue;
		}
		else
		{
			array[i] = num;
			i++;
		}
	}
	array[global_single_number - 1] = 0;
	return array;
}

//bool compare_array_and_num(int* arr, int arr_length, int num)
//{
//	for (int i = 0; i < arr_length; i++)
//	{
//		if (arr[i] == num) return true;
//		else
//			continue;
//	}
//	return false;
//}

//void mySwap(int& x, int& y) {
//	int temp = x;
//	x = y;
//	y = temp;
//}

//int* bubbleSort(int* array, int length_of_array)
//{
//	for (int i = 0; i < length_of_array - 1; i++)
//	{
//		for (int j = 0; j < length_of_array - i - 1; j++)
//		{
//			if (array[j] > array[j + 1])
//			{
//				mySwap(array[j], array[j + 1]);
//			}
//		}
//	}
//	static int array_after_sort[global_single_number];
//	for (int i = 0; i < global_single_number - 1; i++)
//	{
//		array_after_sort[i] = array[i + 1];
//	}
//	array_after_sort[global_single_number - 1] = 0;
//	return array_after_sort;
//}

int* inputArray()
{
	int num;
	int* array = new int[global_single_number];
	for (int i = 0; i < global_single_number - 1; i++)
	{
		for (;;)
		{
			cout << "please input the No.(" << i + 1 << ") number(0-20)" << endl;
			cin >> num;
			if (cin.fail() || num <= 0 || num > 20)
			{
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "incorrect input, please input again!" << endl;
			}
			else if (compare_array_and_num(array, global_single_number, num))
			{
				cout << "the number is already inputed, please input again!" << endl;
			}
			else {
				array[i] = num;
				break;
			}
		}
	}
	array[global_single_number - 1] = 0;
	return array;
}

void createArray()
{
	int num;
	for (;;)
	{
		cout << "please input a number:" << endl;
		cin >> num;
		if (cin.fail() || num < 0)
		{
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else
			break;
	}
	many_random_array(num);
}

void fillAllCase() {};

//void printMap(int arr[global_number][global_number], int column, int row)
//{
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < column; j++)
//		{
//			if (arr[i][j] == 0)
//			{
//				cout << "\t" << "\t";
//			}
//			else
//			{
//				cout << arr[i][j] << "\t";
//			}
//
//		}
//		cout << endl;
//	}
//	cout << endl;
//};

//void print_single_map(int* array, int length)
//{
//	for (int i = 0; i < length; i++)
//	{
//		if (array[i] == 0)
//		{
//			cout << " " << "\t";
//			if (i == sqrt(global_single_number) - 1 || i == sqrt(global_single_number) * 2 - 1 || i == sqrt(global_single_number) * 3 - 1 || i == sqrt(global_single_number) * 4 - 1)
//			{
//				cout << endl;
//			}
//		}
//		else if ((i + 1) % sqrt_global_single_number != 0)
//		{
//			cout << array[i] << "\t";
//		}
//		else
//		{
//			cout << array[i] << endl;
//		}
//	}
//	cout << endl;
//}

void writeFile() {
	ofstream newfile;
	newfile.open("texe.txt", ios::out);
	for (size_t k = 0; k < possiable_Cases.size(); k++)
	{
		for (int i = 0; i < global_number; i++)
		{
			for (int j = 0; j < global_number; j++)
			{
				if (possiable_Cases[k].array[i][j] == 0)
				{
					cout << " " << "\t";
				}
				else
				{
					cout << possiable_Cases[k].array[i][j] << "\t";
				}

			}
			cout << endl;
		}
		cout << endl;
	}
	newfile.close();

};

void readFile() {};

bool check(Class_type_arrays arrays)
{
	bool checkRepeat;


	for (int possiable_cases_size = 0; possiable_cases_size < possiable_Cases.size(); possiable_cases_size++)
	{
		for (int first_num_in_array = 0; first_num_in_array < global_number; first_num_in_array++)
		{
			for (int second_num_in_array = 0; second_num_in_array < global_number; second_num_in_array++)
			{
				if (arrays.array[first_num_in_array][second_num_in_array] != possiable_Cases[possiable_cases_size].array[first_num_in_array][second_num_in_array] && arrays.array[global_number - 1][global_number - 1] == 0)
				{
					return true;
				}
			}
		}
	}
}



void moveUp(int arr[4][4], int columnLength, int rowLength)
{
	int firstArrNum = NULL, secondArrNum = NULL;
	for (int i = 0; i < rowLength; i++)
	{
		for (int j = 0; j < columnLength; j++)
		{
			if (arr[i][j] == 0)
			{
				firstArrNum = i, secondArrNum = j;
			}
		}
	}
	if (firstArrNum == 0)
	{
		return;
	}
	else
	{
		mySwap(arr[firstArrNum][secondArrNum], arr[firstArrNum - 1][secondArrNum]);
	}
}

void moveDown(int arr[4][4], int columnLength, int rowLength)
{
	int firstArrNum = NULL, secondArrNum = NULL;
	for (int i = 0; i < rowLength; i++)
	{
		for (int j = 0; j < columnLength; j++)
		{
			if (arr[i][j] == 0)
			{
				firstArrNum = i, secondArrNum = j;
			}
		}
	}
	if (firstArrNum == 3)
	{
		return;
	}
	else
	{
		mySwap(arr[firstArrNum][secondArrNum], arr[firstArrNum + 1][secondArrNum]);
	}
}

void moveLeft(int arr[4][4], int columnLength, int rowLength)
{
	int firstArrNum = NULL, secondArrNum = NULL;
	for (int i = 0; i < rowLength; i++)
	{
		for (int j = 0; j < columnLength; j++)
		{
			if (arr[i][j] == 0)
			{
				firstArrNum = i, secondArrNum = j;
			}
		}
	}
	if (secondArrNum == 0)
	{
		return;
	}
	else
	{
		mySwap(arr[firstArrNum][secondArrNum], arr[firstArrNum][secondArrNum - 1]);
	}

}

void moveRight(int arr[4][4], int columnLength, int rowLength)
{
	int firstArrNum = NULL, secondArrNum = NULL;
	for (int i = 0; i < rowLength; i++)
	{
		for (int j = 0; j < columnLength; j++)
		{
			if (arr[i][j] == 0)
			{
				firstArrNum = i, secondArrNum = j;
			}
		}
	}
	if (secondArrNum == 3)
	{
		return;
	}
	else
	{
		mySwap(arr[firstArrNum][secondArrNum], arr[firstArrNum][secondArrNum + 1]);
	}

}

void movement(int arr[global_number][global_number])
{
	Class_type_arrays* Up_Seleted_Array = new Class_type_arrays;
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

	Class_type_arrays* Down_Seleted_Array = new Class_type_arrays;
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

	Class_type_arrays* Left_Seleted_Array = new Class_type_arrays;
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

	Class_type_arrays* Right_Seleted_Array = new Class_type_arrays;
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





bool check_single(struct_type_single_arrays arrays)
{
	for (int i = 0; i < possiable_single_cases.size(); i++)
	{
		if (equal(begin(possiable_single_cases[i].array), end(possiable_single_cases[i].array), begin(arrays.array)))
		{
			return true;
		}
	}
	return false;
}

bool moveable(int zero_posiztion)
{
	if (zero_posiztion < sqrt(global_single_number) ||
		zero_posiztion > sqrt(global_single_number)* (sqrt(global_single_number) - 1) - 1 ||
		zero_posiztion == 0 * sqrt(global_single_number) || zero_posiztion == 1 * sqrt(global_single_number) || zero_posiztion == 2 * sqrt(global_single_number) || zero_posiztion == 3 * sqrt(global_single_number) ||
		zero_posiztion == 1 * sqrt(global_single_number) - 1 || zero_posiztion == 2 * sqrt(global_single_number) - 1 || zero_posiztion == 3 * sqrt(global_single_number) - 1 || zero_posiztion == 4 * sqrt(global_single_number) - 1
		)
	{
		return false;
	}
	else
		return true;
}


//void move_single_up(int arr[], int length)
//{
//	int zero_posiztion = NULL;
//	for (int i = 0; i < length; i++)
//	{
//		if (arr[i] == 0)
//		{
//			zero_posiztion = i;
//		}
//	}
//	if (zero_posiztion < sqrt(global_single_number))
//	{
//		return;
//	}
//	else
//	{
//		mySwap(arr[zero_posiztion], arr[zero_posiztion - sqrt_global_single_number]);
//	}
//}
//
//void move_single_down(int arr[], int length)
//{
//	int zero_posiztion = NULL;
//	for (int i = 0; i < length; i++)
//	{
//		if (arr[i] == 0)
//		{
//			zero_posiztion = i;
//		}
//	}
//	if (zero_posiztion > sqrt(global_single_number)* (sqrt(global_single_number) - 1) - 1)
//	{
//		return;
//	}
//	else
//	{
//		mySwap(arr[zero_posiztion], arr[zero_posiztion + sqrt_global_single_number]);
//	}
//}
//
//void move_single_left(int arr[], int length)
//{
//	int zero_posiztion = NULL;
//	for (int i = 0; i < length; i++)
//	{
//		if (arr[i] == 0)
//		{
//			zero_posiztion = i;
//		}
//	}
//	if (zero_posiztion == 0 * sqrt(global_single_number) || zero_posiztion == 1 * sqrt(global_single_number) || zero_posiztion == 2 * sqrt(global_single_number) || zero_posiztion == 3 * sqrt(global_single_number))
//	{
//		return;
//	}
//	else
//	{
//		mySwap(arr[zero_posiztion], arr[zero_posiztion - 1]);
//	}
//}
//
//void move_single_right(int arr[], int length)
//{
//	int zero_posiztion = NULL;
//	for (int i = 0; i < length; i++)
//	{
//		if (arr[i] == 0)
//		{
//			zero_posiztion = i;
//		}
//	}
//	if (zero_posiztion == 1 * sqrt(global_single_number) - 1 || zero_posiztion == 2 * sqrt(global_single_number) - 1 || zero_posiztion == 3 * sqrt(global_single_number) - 1 || zero_posiztion == 4 * sqrt(global_single_number) - 1)
//	{
//		return;
//	}
//	else
//	{
//		mySwap(arr[zero_posiztion], arr[zero_posiztion + 1]);
//	}
//}

void movement_single(int arr[global_single_number])
{
	struct_type_single_arrays* Up_Selected_Array = new struct_type_single_arrays;
	move_single_up(Up_Selected_Array->array, global_single_number);
	{
		if (check_single == false)
		{
			possiable_single_cases.push_back(*Up_Selected_Array);
		}
		else
		{
			delete Up_Selected_Array;
			Up_Selected_Array = NULL;
		}

	};
}
