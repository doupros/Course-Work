#include "PuzzleFile.h"

//cover old files
void PuzzleFile::write_in_file(int* array, int length)
{
	ofstream newfile;
	newfile.open("15-File.txt", ios::out);
	for (int i = 0; i < length*length; i++)
	{
		if (array[i] == 0)
		{
			newfile << " " << "\t";
			if (i == length - 1 || i == length * 2 - 1 || i == length * 3 - 1 || i == length * 4 - 1)
			{
				newfile << endl;
			}
		}
		else if ((i + 1) % length != 0)
		{
			newfile << array[i] << "\t";
		}
		else
		{
			newfile << array[i] << endl;
		}
	}
	newfile.close();
}

//write new things in old file
void PuzzleFile::write_fill_file(int* array, int length)
{
	ofstream newfile;
	newfile.open("15-File.txt", ios::app);
	for (int i = 0; i < length*length; i++)
	{
		if (array[i] == 0)
		{
			newfile << " " << "\t";
			if (i == length - 1 || i == length * 2 - 1 || i == length * 3 - 1 || i == length * 4 - 1)
			{
				newfile << endl;
			}
		}
		else if ((i + 1) % length != 0)
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

void PuzzleFile::write_result_in_file(int* array, int length, bool input) 
{
	unsigned long long  result = sort_and_calculate_result(array, length);
	ofstream newfile;
	newfile.open("Solution-File.txt", ios::out);
	for (int i = 0; i < length * length; i++)
	{
		if (array[i] == 0)
		{
			newfile << " " << "\t";
			if (i == length - 1 || i == length * 2 - 1 || i == length * 3 - 1 || i == length * 4 - 1)
			{
				newfile << endl;
			}
		}
		else if ((i + 1) % length != 0)
		{
			newfile << array[i] << "\t";
		}
		else
		{
			newfile << array[i] << endl;
		}
	}
	newfile << "row = " << result << endl;
	newfile << "column = " << result << endl;
	newfile << "reverse row = " << result << endl;
	newfile << "reverse column = " << result << endl;
	newfile << "(total for row & column, including reverse, in this configuration)" << endl;
	newfile << "2 = " << check_2partial_of_array(array, length) << endl;
	newfile << "3 = " << check_3partial_of_array(array, length) << endl;
	newfile << "4 = " << check_4partial_of_array(array, length) << endl;
	newfile << "(total for row and column, including reverse, for all valid turns)" << endl;
	newfile << "2 = " << check_2partial_of_array(sort_array_by_set(array, length), length) << endl;
	newfile << "3 = " << check_3partial_of_array(sort_array_by_set(array, length), length) << endl;
	newfile << "4 = " << check_4partial_of_array(sort_array_by_set(array, length), length) << endl;
	newfile << endl;
	newfile.close();
}

void PuzzleFile::write_result_in_file(int* array17, int length) 
{
	int num = array17[0];
	int *array = new int[16];
	for (int i = 0; i < 16; i++)
	{
		array[i] = array17[i + 1];
	}
	array[15] = 0;
	unsigned long long  result = sort_and_calculate_result(array,length);
	ofstream newfile;
	newfile.open("Solution-File.txt", ios::out);
	newfile << num<<endl;
	for (int i = 0; i < length * length; i++)
	{
		if (array[i] == 0)
		{
			newfile << " " << "\t";
			if (i == length - 1 || i == length * 2 - 1 || i == length * 3 - 1 || i == length * 4 - 1)
			{
				newfile << endl;
			}
		}
		else if ((i + 1) % length != 0)
		{
			newfile << array[i] << "\t";
		}
		else
		{
			newfile << array[i] << endl;
		}
	}
	newfile << "row = " << result << endl;
	newfile << "column = " << result << endl;
	newfile << "reverse row = " << result << endl;
	newfile << "reverse column = " << result << endl;
	newfile << "(total for row & column, including reverse, in this configuration)" << endl;
	newfile << "2 = " << check_2partial_of_array(array,length)<< endl;
	newfile << "3 = " << check_3partial_of_array(array, length) << endl;
	newfile << "4 = " << check_4partial_of_array(array, length) << endl;
	newfile << "(total for row and column, including reverse, for all valid turns)" << endl;
	newfile << "2 = " << get_all_cases_2partial_of_array(array,length) << endl;
	newfile << "3 = " << get_all_cases_3partial_of_array(array, length) << endl;
	newfile << "4 = " << get_all_cases_4partial_of_array(array, length) << endl;
	newfile << endl;
	newfile.close();
}

void PuzzleFile::read_and_print_puzzle_file() 
{
	string newstring;
	vector<string>strvector;
	ifstream newfile;
	int* readarray = new int[17];
	newfile.open("15-File.txt", ios::in);
	
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

void PuzzleFile::read_and_print_solution_file() 
{
	string newstring;
	vector<string>strvector;
	ifstream newfile;
	int* readarray = new int[17];
	newfile.open("Solution-File.txt", ios::in);
	if (!newfile.is_open())
	{
		cout << "open file failed" << endl;
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

int* PuzzleFile::read_from_file()
{

	ifstream newfile;
	int *readarray= new int [17];
	newfile.open("15-File.txt", ios::in);
	if (!newfile.is_open())
	{
		cout << "open file failed" << endl;
		return NULL;
	}

	if (!newfile.eof())
	{
		for (int i = 0; i < 17; i++)
			{
				newfile >> readarray[i];
			}
	}
	newfile.close();
	return readarray;
}
