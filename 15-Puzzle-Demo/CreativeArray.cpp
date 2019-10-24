#include"CreativeArray.h"

//int* CreateArray::random_array(int level)
//{
//	int newnumber;
//	vector<int> vecArray;
//	for (int i = 0; i < (level * level - 1);)
//	{
//		newnumber = get_random_number(level);
//		if (compare_elemrnt_in_vector_and_num(vecArray, newnumber))
//		{
//			continue;
//		}
//		else
//		{
//			vecArray.push_back(newnumber);
//			i++;
//		}
//	}
//	vecArray.push_back(0);
//	int* array = new int[level*level];
//	for (unsigned int i = 0; i < vecArray.size(); i++)
//	{
//		array[i] = vecArray[i];
//	}
//	return array;
//}

int* CreateArray::random_array(int level) 
{
	int newnumber = 0;
	int* array = new int[level * level];
	for (int i = 0; i < (level * level - 1);)
	{
		newnumber = get_random_number(level);
		if (compare_array_and_num(array, level*level,newnumber))
		{
			continue;
		}
		else
		{
			array[i]=newnumber;
			i++;
		}
	}
	array[level * level-1] = 0;
	return array;

}

int* CreateArray::input_array(int puzzlenum)
{
	int num;
	int* array = new int[puzzlenum * puzzlenum];
	cout << "you choised to input an array manualy" << endl;
	for (int i = 0; i < puzzlenum * puzzlenum - 1; i++)
	{
		for (;;)
		{
			cout << "please input the No.(" << i + 1 << ") number(1-"<<puzzlenum*puzzlenum+puzzlenum<<")" << endl;
			cin >> num;
			if (cin.fail() || num <= 0 || num > puzzlenum* puzzlenum + puzzlenum)
			{
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "incorrect input, please input again!" << endl;
			}
			else if (compare_array_and_num(array, puzzlenum * puzzlenum, num))
			{
				cout << "the number is already inputed, please input again!" << endl;
			}
			else {
				array[i] = num;
				break;
			}
		}
	}
	array[puzzlenum * puzzlenum - 1] = 0;
	return array;
}
