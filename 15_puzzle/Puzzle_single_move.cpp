#include "Puzzle_single_move.h"

void PuzzleSingleMove::move_single_up(int arr[], int length) 
{
	int zero_posiztion = NULL;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] == 0)
		{
			zero_posiztion = i;
		}
	}
	if (zero_posiztion < sqrt(global_single_number))
	{
		return;
	}
	else
	{
		mySwap(arr[zero_posiztion], arr[zero_posiztion - sqrt_global_single_number]);
	}
}
void PuzzleSingleMove::move_single_down(int arr[], int length) 
{
	int zero_posiztion = NULL;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] == 0)
		{
			zero_posiztion = i;
		}
	}
	if (zero_posiztion > sqrt(global_single_number)* (sqrt(global_single_number) - 1) - 1)
	{
		return;
	}
	else
	{
		mySwap(arr[zero_posiztion], arr[zero_posiztion + sqrt_global_single_number]);
	}
}
void PuzzleSingleMove::move_single_left(int arr[], int length) 
{
	int zero_posiztion = NULL;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] == 0)
		{
			zero_posiztion = i;
		}
	}
	if (zero_posiztion == 0 * sqrt(global_single_number) || zero_posiztion == 1 * sqrt(global_single_number) || zero_posiztion == 2 * sqrt(global_single_number) || zero_posiztion == 3 * sqrt(global_single_number))
	{
		return;
	}
	else
	{
		mySwap(arr[zero_posiztion], arr[zero_posiztion - 1]);
	}
}
void PuzzleSingleMove::move_single_right(int arr[], int length)
{
	int zero_posiztion = NULL;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] == 0)
		{
			zero_posiztion = i;
		}
	}
	if (zero_posiztion == 1 * sqrt(global_single_number) - 1 || zero_posiztion == 2 * sqrt(global_single_number) - 1 || zero_posiztion == 3 * sqrt(global_single_number) - 1 || zero_posiztion == 4 * sqrt(global_single_number) - 1)
	{
		return;
	}
	else
	{
		mySwap(arr[zero_posiztion], arr[zero_posiztion + 1]);
	}
}