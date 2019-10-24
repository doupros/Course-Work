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
	ofstream outputfile;
	outputfile.open("Solution-File.txt", ios::app);
	for (int i = 0; i < length * length; i++)
	{
		if (array[i] == 0)
		{
			outputfile << " " << "\t";
			if (i == length - 1 || i == length * 2 - 1 || i == length * 3 - 1 || i == length * 4 - 1)
			{
				outputfile << endl;
			}
		}
		else if ((i + 1) % length != 0)
		{
			outputfile << array[i] << "\t";
		}
		else
		{
			outputfile << array[i] << endl;
		}
	}
	outputfile << "row = " << result << endl;
	outputfile << "column = " << result << endl;
	outputfile << "reverse row = " << result << endl;
	outputfile << "reverse column = " << result << endl;
	outputfile << "(total for row & column, including reverse, in this configuration)" << endl;
	outputfile << "2 = " << check_2partial_of_array(array, length) << endl;
	outputfile << "3 = " << check_3partial_of_array(array, length) << endl;
	outputfile << "4 = " << check_4partial_of_array(array, length) << endl;
	outputfile << "(total for row and column, including reverse, for all valid turns)" << endl;
	outputfile << "2 = " << get_all_cases_2partial_of_array(array, length) << endl;
	outputfile << "3 = " << get_all_cases_3partial_of_array(array, length) << endl;
	outputfile << "4 = " << get_all_cases_4partial_of_array(array, length) << endl;
	outputfile << endl;
}

void PuzzleFile::write_result_in_file(int* array17, int length) 
{
	int num = array17[0];
	int *array = new int[length*length];
	for (int i = 0; i < length*length; i++)
	{
		array[i] = array17[i + 1];
	}
	array[length*length-1] = 0;
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

int* PuzzleFile::read_from_file_plus_calculation(int length)
{
	ifstream newfile;
	vector<int*> arrayVector;
	int num=0;
	newfile.open("15-File.txt", ios::in);
	if (!newfile.is_open())
	{
		cout << "open file failed" << endl;
		return NULL;
	}

	if (!newfile.eof())
	{
		newfile >> num;
		for (int j = 0; j < num; j++)
		{
			int *readarray= new int[length*length];
			for (int i = 0; i < length*length-1; i++)
			{
				newfile >> readarray[i];
			}
			readarray[length*length-1] = 0;
			arrayVector.push_back(readarray);
		}
	}
	newfile.close();
	int *newarray= new int[length*length];
	ofstream outputfile;
	outputfile.open("Solution-File.txt", ios::out);
	outputfile << num<<endl;
	outputfile.close();
	for (int j =0;j< arrayVector.size();j ++)
	{
		newarray = arrayVector[j];
		/*for (int i = 0; i < 16; i++)
		{
			cout << newarray[i]<<"\t";
		}*/
		//for (int i = 0; i < length * length; i++)
		//{
		//	if (newarray[i] == 0)
		//	{
		//		outputfile << " " << "\t";
		//		if (i == length - 1 || i == length * 2 - 1 || i == length * 3 - 1 || i == length * 4 - 1)
		//		{
		//			outputfile << endl;
		//		}
		//	}
		//	else if ((i + 1) % length != 0)
		//	{
		//		outputfile << newarray[i] << "\t";
		//	}
		//	else
		//	{
		//		outputfile << newarray[i] << endl;
		//	}
		//}
		unsigned long long  result = sort_and_calculate_result(newarray, length);
		outputfile.open("Solution-File.txt", ios::app);
		for (int i = 0; i < length * length; i++)
		{
			if (newarray[i] == 0)
			{
				outputfile << " " << "\t";
				if (i == length - 1 || i == length * 2 - 1 || i == length * 3 - 1 || i == length * 4 - 1)
				{
					outputfile << endl;
				}
			}
			else if ((i + 1) % length != 0)
			{
				outputfile << newarray[i] << "\t";
			}
			else
			{
				outputfile << newarray[i] << endl;
			}
		}
		outputfile << endl;
		outputfile << "row = " << result << endl;
		outputfile << "column = " << result << endl;
		outputfile << "reverse row = " << result << endl;
		outputfile << "reverse column = " << result << endl;
		outputfile << "(total for row & column, including reverse, in this configuration)" << endl;
		outputfile << "2 = " << check_2partial_of_array(newarray, length) << endl;
		outputfile << "3 = " << check_3partial_of_array(newarray, length) << endl;
		outputfile << "4 = " << check_4partial_of_array(newarray, length) << endl;
		outputfile << "(total for row and column, including reverse, for all valid turns)" << endl;
		outputfile << "2 = " << get_all_cases_2partial_of_array(newarray, length) << endl;
		outputfile << "3 = " << get_all_cases_3partial_of_array(newarray, length) << endl;
		outputfile << "4 = " << get_all_cases_4partial_of_array(newarray, length) << endl;
		outputfile << endl;
		outputfile.close();
	}
	outputfile.close();
	return newarray;
}