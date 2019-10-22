#include "PuzzleTools.h"
#include"CreativeArray.h"
#include <fstream>
#include <string>
#include <windows.h>


int get_level();
void menu() ;


class PuzzleFile
{
public:
	PuzzleFile();
	~PuzzleFile();
	void write_in_file(int* array, int length);
	void read_from_file();

private:

};

PuzzleFile::PuzzleFile()
{
}

PuzzleFile::~PuzzleFile()
{
}


void PuzzleFile::write_in_file(int* array, int length)
{
	ofstream newfile;
	newfile.open("15-File.txt", ios::app);
	for (int i = 0; i < length; i++)
	{
		if (array[i] == 0)
		{
			newfile << " " << "\t";
			if (i == PUZZLESZE - 1 || i == PUZZLESZE * 2 - 1 || i == PUZZLESZE * 3 - 1 || i == PUZZLESZE * 4 - 1)
			{
				newfile << endl;
			}
		}
		else if ((i + 1) % PUZZLESZE != 0)
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
}

void PuzzleFile::read_from_file() 
{
	string newstring;
	vector<string>strvector;
	ifstream newfile;
	newfile.open("15-File.txt", ios::in);
	if (!newfile.is_open())
	{
		cout << "open file failed" << endl;
		return;
	}
	while (getline(newfile, newstring))
	{
		strvector.push_back(newstring);
	}
	for (unsigned int i = 0; i < strvector.size(); i++)
	{
		cout << strvector[i] << endl;
	}
	newfile.close();
}

CreateArray NewArray; PuzzleFile NewFile;

int main()
{
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
		cout << "*************************************************************" << endl;
		cout << "***	1. input a 4*4 array manually***" << endl;
		cout << "***	2. randomly create some array automaticlly***" << endl;
		cout << "*************************************************************" << endl;
		cout << "*************************************************************" << endl;
		cout << "*************************************************************" << endl;

		int num;
		for (;;)
		{
			cout << "please input your choise" << endl;
			cin >> num;
			if (cin.fail() || num < 0 || num > 4)
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
			int* array = NewArray.input_array();
			string input;
			cout << "do you want to see the array you inputed?(Y/N)" << endl;
			cin >> input;
			if (input == "Y"||input=="y")
			{
				NewArray.print_single_map(array, PUZZLESZE);
			}
			else if (input=="N"||input=="n")
			{
				system("cls");
			}
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
				for (int i = 0; i < num; i++)
				{
					NewFile.write_in_file(NewArray.random_array(PUZZLESZE), PUZZLESZE * PUZZLESZE);
				}
			}
			else if (input =="N"||input=="n")
			{
				for (int i = 0; i < num; i++)
				{
					cout << num << endl;
					NewArray.print_single_map(NewArray.random_array(PUZZLESZE), PUZZLESZE);
				}
			}
		}
		default:
			break;
		}
	}
	
}