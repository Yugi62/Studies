#include "stdafx.h"
#include <iostream>

using namespace std;

//ConstMemberFunction
////////////////////

/*
상수 멤버 함수 : 클래스 내부에서 선언하는 함수로 멤버 변수를 변경할 수 없는 함수
mutable        : 상수 멤버 함수를 무시하고 값을 변경하는 것을 허락하는 키워드

유의 사항)
1. const 또한 함수의 원형의 일부로 취급되어 인수가 같더라도 오버로딩이 된다
*/

class Point
{
private:
	int x;
	int y;

	mutable int z;

public:
	void Display() const;
	void Display();
};

void Point::Display() const //상수 객체일 때 실행
{
	cout << x << endl;
	cout << y << endl;

	cin >> z;
}

void Point::Display()      //상수 객체가 아닐때 실행
{
	cout << x << endl;
	cout << y << endl;
}
