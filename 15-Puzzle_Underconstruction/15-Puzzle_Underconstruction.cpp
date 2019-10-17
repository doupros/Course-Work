#include <fstream>
#include "MoveBlank.h"
#include <string>
#include <vector>

using namespace std;


struct Arrays
{
	int array[4][4];
};
int  num;

void createArray() 
{
	 
}

void fillAllCase() {};

void printMap(int arr[4][4] , int column,int row) 
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

void writeFile() {};

void readFile() {};

int main()
{
	int arr[4][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,0} };
	createArray();
	return 0;
}

vector<Arrays> Cases;

bool check(Arrays arrays) 
{
	bool checkRepeat;
	
		for (int i = 0; i < Cases.size; i++)
		{
			for (int j = 0; j <16; j++)
			{
				if (arrays.array[][]== Cases.)
				{

				}
			}
		}
	
}

int movement(int arr[4][4]) {
	Arrays* UpSelArray = new Arrays;
	moveUp(UpSelArray->array, 4, 4);
	if (check(*UpSelArray))
	{
		Cases.push_back(*UpSelArray);
	} 
	else
	{
		delete UpSelArray;
		UpSelArray = NULL;
	}

}