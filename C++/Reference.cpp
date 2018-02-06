#include "stdafx.h"
#include <iostream>

using namespace std;

//Reference
////////////////////

/*
레퍼런스 : 변수를 참조하여 마치 변수에 별명을 붙인 것과 같이 서로 다른 이름이지만 똑같은 값과 주소인 것

유의사항)
1. 선언과 동시에 반드시 초기화
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

	

	int a;		//변수 선언
	int &b = a;	//레퍼런스 선언

	a = 10;

	cout << a << endl;	//10
	cout << b << endl;	//10

	b = 20;

	cout << a << endl;	//20
	cout << b << endl;	//20
}