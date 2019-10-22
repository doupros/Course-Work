#include <fstream>
#include "MoveBlank.h"
#include <string>
#include <vector>
#include <random>
#include<math.h>
#include<set>
using namespace std;

const int global_number = 4;
const int global_single_number = 16;
const int sqrt_global_single_number = sqrt(global_single_number);
random_device random_dev;
mt19937 range(random_dev());
uniform_int_distribution<mt19937::result_type>random_number(1, 20);

void print_single_map(int* array, int length);
bool compare_array_and_num(int* arr, int arr_length, int num);
int* random_array();
int* bubbleSort(int* array, int length_of_array);
int* inputArray();
void swap_ref(int& x, int& y);
void createArray();
void printMap(int arr[global_number][global_number], int column, int row);
void many_random_array(int number);
void write_single_array_in_file(int* array, int length);
void readFile();

void sort_by_set(int* array, int length);

class ClassUI
{
public:
	ClassUI();
	~ClassUI();
	void mianpage();

private:

};

ClassUI::ClassUI()
{
}

ClassUI::~ClassUI()
{
}

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
		
	print_single_map(array, global_single_number);
	sort_by_set(array, global_single_number);
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
	static int array [global_single_number];
	int num;
	for (int i = 0; i < global_single_number-1; )
	{
		num = random_number(range);
		if (compare_array_and_num(array,global_single_number,num))
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

bool compare_array_and_num(int* arr, int arr_length, int num)
{
	for (int i = 0; i < arr_length; i++)
	{
		if (arr[i] == num) return true;
		else
			continue;
	}
	return false;
}

void swap_ref(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

int* bubbleSort(int* array,int length_of_array) 
{
	for (int i = 0; i < length_of_array-1; i++)
	{
		for (int j = 0; j < length_of_array-i-1; j++)
		{
			if (array[j]>array[j+1])
			{
				swap_ref(array[j], array[j + 1]);
			}
		}
	}
	static int array_after_sort[global_single_number];
	for (int i = 0; i < global_single_number-1; i++)
	{
		array_after_sort[i] = array[i + 1];
	}
	array_after_sort[global_single_number - 1] = 0;
	return array_after_sort;
}

int* inputArray() 
{
	int num;
	int *array = new int[global_single_number];
	for (int i = 0; i < global_single_number-1; i++)
	{
		for (;;)
		{
			cout << "please input the No.(" << i + 1 << ") number(0-20)" << endl;
			cin >> num;
			if (cin.fail() || num <= 0 || num>20)
			{
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "incorrect input, please input again!" << endl;
			}
			else if (compare_array_and_num(array,global_single_number,num))
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
			cin.ignore(1024,'\n');
		}
		else
		break;
	}
	many_random_array( num);
}

void printMap(int arr[global_number][global_number] , int column,int row)
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

void print_single_map(int* array, int length) 
{
	for (int i = 0; i < length; i++)
	{
		if (array[i]==0)
		{
			cout << " "<<"\t";
			if (i== sqrt(global_single_number) -1||i== sqrt(global_single_number) *2-1||i== sqrt(global_single_number) *3-1||i== sqrt(global_single_number)*4-1)
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
			cout << array[i] << endl ;
		}
	}
	cout << endl;
}

bool check(Class_type_arrays arrays) 
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

bool check_single(struct_type_single_arrays arrays)
{
	for ( int i = 0; i < possiable_single_cases.size(); i++)
	{
		if (equal(begin(possiable_single_cases[i].array),end(possiable_single_cases[i].array),begin(arrays.array)))
		{
			return true;
		}
	}
	return false;
}

bool moveable(int zero_posiztion) 
{
	if (zero_posiztion < sqrt(global_single_number)||
		zero_posiztion > sqrt(global_single_number)* (sqrt(global_single_number) - 1) - 1||
		zero_posiztion == 0 * sqrt(global_single_number) || zero_posiztion == 1 * sqrt(global_single_number) || zero_posiztion == 2 * sqrt(global_single_number) || zero_posiztion == 3 * sqrt(global_single_number) ||
		zero_posiztion == 1 * sqrt(global_single_number) - 1 || zero_posiztion == 2 * sqrt(global_single_number) - 1 || zero_posiztion == 3 * sqrt(global_single_number) - 1 || zero_posiztion == 4 * sqrt(global_single_number) - 1
		)
	{
		return false;
	}
	else
		return true;
}

void write_single_array_in_file(int* array, int length)
{
	ofstream newfile;
	newfile.open("test.txt", ios::out);
	for (int i = 0; i < length; i++)
	{
		if (array[i] == 0)
		{
			newfile << " " << "\t";
			if (i == sqrt(global_single_number) - 1 || i == sqrt(global_single_number) * 2 - 1 || i == sqrt(global_single_number) * 3 - 1 || i == sqrt(global_single_number) * 4 - 1)
			{
				newfile << endl;
			}
		}
		else if ((i + 1) % sqrt_global_single_number != 0)
		{
			newfile << array[i] << "\t";
		}
		else
		{
			newfile << array[i] << endl;
		}
	}
	newfile << endl;
	newfile.close();

};

void readFile()
{
	string newstring;
	vector<string>strvector;
	ifstream newfile;
	newfile.open("test.txt", ios::in);
	if (!newfile.is_open())
	{
		cout << "open file failed" << endl;
		return;
	}
	while (getline(newfile, newstring))
	{
		strvector.push_back(newstring);
	}
	for (int i = 0; i < strvector.size(); i++)
	{
		cout << strvector[i] << endl;
	}

	newfile.close();
}

void sort_by_set(int *array,int length)
{
	int count;
	int counter=0;
	int* newarray = new int[global_single_number];
	set<int> setarray;
	for (int i = 0; i < length; i++)
	{
		setarray.insert(array[i]);
	}
	setarray.erase(setarray.begin());

	for (set<int>::iterator it=setarray.begin();it!=setarray.end();it++)
	{
		cout << *it << endl;
		newarray[counter++] = *it;
	}
	newarray[global_single_number - 1] = 0;
	print_single_map(newarray, global_single_number);
}


void ClassUI::mianpage() 
{
	
}