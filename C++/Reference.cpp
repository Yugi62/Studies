#include "stdafx.h"
#include <iostream>

using namespace std;

//Reference
////////////////////

/*
���۷��� : ������ �����Ͽ� ��ġ ������ ������ ���� �Ͱ� ���� ���� �ٸ� �̸������� �Ȱ��� ���� �ּ��� ��

���ǻ���)
1. ����� ���ÿ� �ݵ�� �ʱ�ȭ
*/

void Swap(int &x, int &y)	//Call by reference
{
	int temp = x;
	x = y;
	y = temp;
}

int main()
{
	int x = 2;
	int y = 3;

	Swap(x, y);

	cout << x << endl;	//3
	cout << y << endl;	//2

	

	int a;		//���� ����
	int &b = a;	//���۷��� ����

	a = 10;

	cout << a << endl;	//10
	cout << b << endl;	//10

	b = 20;

	cout << a << endl;	//20
	cout << b << endl;	//20
}