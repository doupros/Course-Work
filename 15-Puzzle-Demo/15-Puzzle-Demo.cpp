#include "PuzzleTools.h"
#include"CreativeArray.h"
#include "PuzzleFile.h"
#include"PuzzleCalculation.h"
#include <windows.h>
/*coded by Hemi li*/
int get_level();
void menu();




CreateArray NewCreateArray; PuzzleFile NewFile; PuzzleCalculation NewCalculate;
int main()
{
	/*int* arrayptr = new int [16];
	for (int i = 1; i < 16; i++)
	{
		arrayptr[i-1] = i;
	}
	arrayptr[15] = 0;*/
	int* arrayptr= NewCreateArray.random_array(PUZZLENUM);
	NewCreateArray.print_single_map(arrayptr, PUZZLENUM);
	cout << NewCalculate.check_2partial_of_array(arrayptr, PUZZLENUM) << endl;
	cout << NewCalculate.check_3partial_of_array(arrayptr, PUZZLENUM) << endl;
	arrayptr = NewCalculate.sort_array_by_set(arrayptr, PUZZLENUM);
	NewCreateArray.print_single_map(arrayptr,PUZZLENUM);
	cout << NewCalculate.check_3partial_of_array(arrayptr, PUZZLENUM) << endl;
	cout << NewCalculate.check_partial_of_array(arrayptr, PUZZLENUM)<<endl;
	cout << NewCalculate.calculate_result(arrayptr,PUZZLENUM) << endl;

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
		case	1:
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
				system("cls");
				NewFile.write_in_file(array, PUZZLENUM );
				cout << "arrays was saved in file" << endl;
				break;
			}
			else break;
		}
		case 2: 
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
			cout << "do you want to write them in a file?(Y/N)" << endl;
			cin >> input;
			if (input=="Y"||input=="y")
			{
				NewFile.write_in_file(&num, 1);
				for (int i = 0; i < num; i++)
				{
					NewFile.write_fill_file(NewCreateArray.random_array(PUZZLENUM), PUZZLENUM );
				}
			}
			else if (input =="N"||input=="n")
			{
				for (int i = 0; i < num; i++)
				{
					cout << num << endl;
					NewCreateArray.print_single_map(NewCreateArray.random_array(PUZZLENUM), PUZZLENUM);
				}
			}
		}
		case 3:
		{
			string input;
			NewFile.read_and_print_puzzle_file();
			cout << "do you want to calculate it (Y/N)?" << endl;
			cin >> input;
			if (input == "Y" || input == "y")
			{
				NewFile.write_result_in_file(NewFile.read_from_file(), PUZZLENUM);
			}
			else if (input == "N" || input == "n")
			{
				break;
			}
		}
		case 4: 
		{
			system("cls");
			NewFile.read_and_print_solution_file();
		}
		case 5: {}
		case 6: {}


		default:
			break;
		}
	}
	
}