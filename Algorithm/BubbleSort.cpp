#include "stdafx.h"
#include <iostream>

//Bubble Sort
////////////////////

/*
해설)

버블정렬은 현재 값과 옆의 값을 비교 및 스왑을 하면서 숫자를 하나씩 정렬하는 배열이다.
결국 한바퀴 순회할 때마다 반드시 숫자 하나는 정렬되기 때문에 (요소의 총 개수 - 1) 바퀴를 돌면 정렬이 된다

1. x번째와 x+1번째 값을 비교하여 조건에 충족하면 둘을 스왑한다
2. x를 1 증가시킨 후 (요소의 총 개수 - 1 - 정렬된 숫자 수)이 될 때까지 1을 반복한다
3. 최종적으로 (요소의 총 개수 - 1)만큼 1,2를 반복한다
*/

//오름차순
inline bool Ascend(int x, int y) { return (x > y) ? true : false; }
//내림차순
inline bool Descend(int x, int y) { return (x < y) ? true : false; }

void BubbleSort(int* arr, int size, bool (*Func) (int,int))
{
	size--;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			if (Func(arr[j], arr[j + 1]))
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void Display(int *arr, int size)
{
	for(int i = 0; i < size; i++)
	std::cout << arr[i] << std::endl;
}

int main()
{
	int arr[10] = { 10,1,2,4,5,8,7,9,6,1 };
	BubbleSort(arr, sizeof(arr) / sizeof(int), Ascend);
	Display(arr, sizeof(arr) / sizeof(int));

	return 0;
}