#include <iostream>
using namespace std;


void mySwap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}


void moveUp(int arr[4][4], int columnLength, int rowLength)
{
	int firstArrNum, secondArrNum;
	for (int i = 0; i < rowLength; i++)
	{
		for (int j = 0; j < columnLength; j++)
		{
			if (arr[i][j] == 0)
			{
				firstArrNum = i, secondArrNum = j;
			}
		}
	}
	if (firstArrNum == 0)
	{
		return;
	}
	else
	{
		mySwap(arr[firstArrNum][secondArrNum], arr[firstArrNum - 1][secondArrNum]);
	}
}

void moveDown(int arr[4][4], int columnLength, int rowLength)
{
	int firstArrNum, secondArrNum;
	for (int i = 0; i < rowLength; i++)
	{
		for (int j = 0; j < columnLength; j++)
		{
			if (arr[i][j] == 0)
			{
				firstArrNum = i, secondArrNum = j;
			}
		}
	}
	if (firstArrNum == 3)
	{
		return;
	}
	else
	{
		mySwap(arr[firstArrNum][secondArrNum], arr[firstArrNum + 1][secondArrNum]);
	}
}

void moveLeft(int arr[4][4], int columnLength, int rowLength)
{
	int firstArrNum, secondArrNum;
	for (int i = 0; i < rowLength; i++)
	{
		for (int j = 0; j < columnLength; j++)
		{
			if (arr[i][j] == 0)
			{
				firstArrNum = i, secondArrNum = j;
			}
		}
	}
	if (secondArrNum == 0)
	{
		return;
	}
	else
	{
		mySwap(arr[firstArrNum][secondArrNum], arr[firstArrNum][secondArrNum - 1]);
	}

}

void moveRight(int arr[4][4], int columnLength, int rowLength)
{
	int firstArrNum, secondArrNum;
	for (int i = 0; i < rowLength; i++)
	{
		for (int j = 0; j < columnLength; j++)
		{
			if (arr[i][j] == 0)
			{
				firstArrNum = i, secondArrNum = j;
			}
		}
	}
	if (secondArrNum == 3)
	{
		return;
	}
	else
	{
		mySwap(arr[firstArrNum][secondArrNum], arr[firstArrNum][secondArrNum + 1]);
	}

}