#include <fstream>
#include "MoveBlank.h"

using namespace std;

struct Numbers 
{
	int array[4][4];
	int firstNum;
	int secondNum;
};

void createArray() {};

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

int main1()
{
	int arr[4][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,0} };
	moveUp(arr, 4, 4);
	printMap(arr, 4, 4);
}
