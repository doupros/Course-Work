#include "PuzzleTools.h"
#include"CreativeArray.h"
#include "PuzzleFile.h"
#include"PuzzleCalculation.h"
#include <windows.h>
/*coded by Hemi li*/
int get_level();
void menu();

auto get_factorial = [](int num)
{
	unsigned long long result = 0;
	result = num;
	for (int i = num - 1; i > 0; i--)
	{
		result *= i;
	}
	return result;
};

template<class T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

CreateArray NewCreateArray; PuzzleFile NewFile; PuzzleCalculation NewCalculate;
int main()
{
	//cout << get_factorial(5) <<endl;
	//int* arrayptr= NewCreateArray.random_array(PUZZLENUM);
	//NewCreateArray.print_single_map(arrayptr, PUZZLENUM);
	//cout << NewCalculate.check_2partial_of_array(arrayptr, PUZZLENUM) << endl;
	//cout << NewCalculate.check_3partial_of_array(arrayptr, PUZZLENUM) << endl;
	//arrayptr = NewCalculate.sort_array_by_set(arrayptr, PUZZLENUM);
	//NewCreateArray.print_single_map(arrayptr,PUZZLENUM);
	//cout << NewCalculate.check_2partial_of_array(arrayptr, PUZZLENUM) << endl;
	//cout << NewCalculate.check_3partial_of_array(arrayptr, PUZZLENUM) << endl;
	//cout << NewCalculate.check_4partial_of_array(arrayptr, PUZZLENUM) << endl;
	//cout << NewCalculate.check_partial_of_array(arrayptr, PUZZLENUM)<<endl;
	//cout << NewCalculate.calculate_result(arrayptr,PUZZLENUM) << endl;
	//delete arrayptr;
	//arrayptr = NULL;
	//NewFile.write_result_in_file(NewFile.read_from_file(), PUZZLENUM);
	menu();
	return 0;
}

int get_level()
{
	int newinput;
	for (;;)
	{
		cout << "please input the level:" << endl;
		cin >> newinput;
		if (cin.fail() || newinput <= 1)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "incorrect input, please input again!" << endl;
		}
		else
		{
			return newinput;
		}
	}
}


void menu() 
{
	for (;;)
	{
		cout << "---	1. input a 4*4 array manually" << endl;
		cout << "---	2. randomly create some array automaticlly" << endl;
		cout << "---	3. read & calculate the array in file" << endl;
		cout << "---	4. read the solution from file" << endl;
		cout << "---	5. open the file" << endl;
		cout << "---	6. create an array (1~15)" << endl;

		cout << "---	0. exit" << endl;
		int num;
		for (;;)
		{
			cout << "please input your choise" << endl;
			cin >> num;
			if (cin.fail() || num < 0 || num > 10)
			{
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "incorrect input, please input again!" << endl;
			}
			else break;
		}
		switch (num)
		{
		case 0:
			exit(0);
		case	1://input array
		{
			int* array = NewCreateArray.input_array();
			string input;
			cout << "do you want to save the array you inputed to file?(Y/N)" << endl;
			cin >> input;
			if (input == "N" || input == "n")
			{
				system("cls");
				NewCreateArray.print_single_map(array, PUZZLENUM);
				break;
			}
			else if (input == "Y" || input == "y")
			{
				int num = 1;
				system("cls");
				NewFile.write_in_file(&num, 1);
				NewFile.write_fill_file(array, PUZZLENUM );
				cout << "arrays was saved in file" << endl;
				break;
			}
			else break;
		}
		case 2: //random array
		{
			int num;
			string input;
			for (;;)
			{
				cout << "how many arrays do you want to create: " << endl;
				cin >> num;
				if (cin.fail() || num <= 0 )
				{
					cin.clear();
					cin.ignore(1024, '\n');
					cout << "incorrect input, please input again!" << endl;
				}
				else break;
			}
			cout << "do you want to sort them in order or not(Y/N)" << endl;
			cin >> input;
			if (input == "Y" || input == "y")
			{
				cout << "do you want to write them in a file?(Y/N)" << endl;
				cin >> input;
				if (input == "Y" || input == "y")
				{
					NewFile.write_in_file(&num, 1);
					for (int i = 0; i < num; i++)
					{
						NewFile.write_fill_file(NewFile.sort_array_by_set(NewCreateArray.random_array(PUZZLENUM),PUZZLENUM), PUZZLENUM);
					}
					system("cls");
					cout << "write in file finished input 3 to read it" << endl;
					break;
				}
				else if (input == "N" || input == "n")
				{
					cout << num << endl;
					for (int i = 0; i < num; i++)
					{
						NewCreateArray.print_single_map(NewFile.sort_array_by_set(NewCreateArray.random_array(PUZZLENUM), PUZZLENUM), PUZZLENUM);
					}
					break;
				}
				else break;

				break;
			}
			else if (input == "N" || input == "n")
			{
				cout << "do you want to write them in a file?(Y/N)" << endl;
				cin >> input;
				if (input == "Y" || input == "y")
				{
					NewFile.write_in_file(&num, 1);
					for (int i = 0; i < num; i++)
					{
						NewFile.write_fill_file(NewCreateArray.random_array(PUZZLENUM), PUZZLENUM);
					}
					break;
				}
				else if (input == "N" || input == "n")
				{
					cout << num << endl;
					for (int i = 0; i < num; i++)
					{
						NewCreateArray.print_single_map(NewCreateArray.random_array(PUZZLENUM), PUZZLENUM);
					}
					break;
				}
				else break;
				break;
			}
			else break; 

		}
		case 3://read & calculate the result
		{
			system("cls");
			string input;
			NewFile.read_and_print_puzzle_file();
			int* arrayptr = NewFile.read_from_file();
			if (arrayptr==NULL){break;}
			cout << "do you want to calculate it (Y/N)?" << endl;
			cin >> input;
			if (input == "Y" || input == "y")
			{
				NewFile.write_result_in_file(arrayptr, PUZZLENUM);
				system("cls");
				cout << "calculated finshed, input 4 to read the solution" << endl;
				break;
			}
			else if (input == "N" || input == "n")
			{
				break;
			}
			else break;
		}
		case 4: //read the solution from file
		{
			system("cls");
			NewFile.read_and_print_solution_file();
			break;
		}
		case 5: 
		{
			int num;
			cout << "--	which file do you want to open?" << endl;
			cout << "1. open 15-File.txt		2. open Solution-File.txt	3.back" << endl;
			cin >> num;
			if (num==1)
			{
				cout << "press any key to close the file" << endl;
				system("start 15-File.txt");
				system("pause");
				system("taskkill /f /im notepad.exe");
				system("cls");
				break;
			}
			else if (num==2)
			{
				cout << "press any key to close the file"<< endl;
				system("start Solution-File.txt");
				system("pause");
				system("taskkill /f /im notepad.exe");
				system("cls");
				break;
			}
			else 
			{
				system("cls"); 
				break;
			}
		}
		case 6: 
		{
			int* arrayptr = new int[16];
			for (int i = 1; i < 16; i++)
			{
				arrayptr[i - 1] = i;
			}
			arrayptr[15] = 0;
			NewCreateArray.print_single_map(arrayptr, PUZZLENUM);
			string input;
			cout << "do you want to save the array you inputed to file?(Y/N)" << endl;
			cin >> input;
			if (input == "N" || input == "n")
			{
				system("cls");
				NewCreateArray.print_single_map(arrayptr, PUZZLENUM);
				break;
			}
			else if (input == "Y" || input == "y")
			{
				int num = 1;
				system("cls");
				NewFile.write_in_file(&num, 1);
				NewFile.write_fill_file(arrayptr, PUZZLENUM);
				cout << "arrays was saved in file" << endl;
				break;
			}
			else break;

			
		}


		default:
			break;
		}
	}
	
}