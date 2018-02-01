#include "stdafx.h"
#include <iostream>

//Bubble Sort
////////////////////

/*
�ؼ�)

���������� ���� ���� ���� ���� �� �� ������ �ϸ鼭 ���ڸ� �ϳ��� �����ϴ� �迭�̴�.
�ᱹ �ѹ��� ��ȸ�� ������ �ݵ�� ���� �ϳ��� ���ĵǱ� ������ (����� �� ���� - 1) ������ ���� ������ �ȴ�

1. x��°�� x+1��° ���� ���Ͽ� ���ǿ� �����ϸ� ���� �����Ѵ�
2. x�� 1 ������Ų �� (����� �� ���� - 1 - ���ĵ� ���� ��)�� �� ������ 1�� �ݺ��Ѵ�
3. ���������� (����� �� ���� - 1)��ŭ 1,2�� �ݺ��Ѵ�
*/

//��������
inline bool Ascend(int x, int y) { return (x > y) ? true : false; }
//��������
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