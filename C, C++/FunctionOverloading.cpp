#include "stdafx.h"
#include <iostream>

using namespace std;

//FunctionOverloading
////////////////////

/*
�Լ� �����ε� : �Լ����� ���� �� ä �Ű������� �� Ȥ�� Ÿ���� �ٸ����Ͽ� �ߺ� �����ϴ� ��

���ǻ���)
1. �Լ� ���� �� ���Ե� �Ű������� ���� �ٻ��� �Լ��� ������ �ǰ� �ȴ�
2. �����ε� �� �Լ����� ���ƾ� �ϸ� �� �ܿ��� �ּ� �� ���� �̻��� �޶�� �Ѵ� (�Ű������� ��, �Ű������� Ÿ��)
*/

void Display()
{
	cout << " " << endl;
}

void Display(int x)
{
	cout << x << endl;
}

void Display(int x, int y)
{
	cout << x << endl;
	cout << y << endl;
}

void Display(double x)
{
	cout << x << endl;
}

void Display(double x, double y)
{
	cout << x << endl;
	cout << y << endl;
}

int main()
{
	Display();			//Display()
	Display(1);			//Display(int)
	Display(1,2);		//Display(int, int)
	Display(1.5);		//Display(double)
	Display(1.5, 2.5);	//Dispaly(double, double)

}