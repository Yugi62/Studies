#include "stdafx.h"
#include <iostream>

using namespace std;

//FunctionOverloading
////////////////////

/*
함수 오버로딩 : 함수명을 같게 한 채 매개변수의 수 혹은 타입을 다르게하여 중복 선언하는 것

유의사항)
1. 함수 실행 시 삽입된 매개변수에 가장 근사한 함수가 실행이 되게 된다
2. 오버로딩 시 함수명이 같아야 하며 그 외에는 최소 한 가지 이상이 달라야 한다 (매개변수의 수, 매개변수의 타입)
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
	Display();		//Display()
	Display(1);		//Display(int)
	Display(1,2);		//Display(int, int)
	Display(1.5);		//Display(double)
	Display(1.5, 2.5);	//Dispaly(double, double)

}
