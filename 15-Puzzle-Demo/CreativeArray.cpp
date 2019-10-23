#include"CreativeArray.h"

int* CreateArray::random_array(int level)
{
	int newnumber;
	vector<int> vecArray;
	for (int i = 0; i < (level * level - 1);)
	{
		newnumber = get_random_number();
		if (compare_elemrnt_in_vector_and_num(vecArray, newnumber))
		{
			continue;
		}
		else
		{
			vecArray.push_back(newnumber);
			i++;
		}
	}
	vecArray.push_back(0);
	int* array = new int[16];
	for (unsigned int i = 0; i < vecArray.size(); i++)
	{
		array[i] = vecArray[i];
	}
	return array;
}

int* CreateArray::input_array()
{
	int num;
	int* array = new int[PUZZLENUM * PUZZLENUM];
	cout << "you choised to input an array manualy(4x4)" << endl;
	for (int i = 0; i < PUZZLENUM * PUZZLENUM - 1; i++)
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
			else if (compare_array_and_num(array, PUZZLENUM * PUZZLENUM, num))
			{
				cout << "the number is already inputed, please input again!" << endl;
			}
			else {
				array[i] = num;
				break;
			}
		}
	}
	array[PUZZLENUM * PUZZLENUM - 1] = 0;
	return array;
}
