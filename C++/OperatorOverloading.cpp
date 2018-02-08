#include "stdafx.h"
#include <iostream>

using namespace std;

//OperatorOverloading
////////////////////

/*
연산자 오버로딩 : 연산자를 오버로딩한 것

하는 방법)
1. 클래스의 멤버 함수로 작성한다
2. 전역 함수로 작성한다

유의 사항)
1. 피연산자 중 하나는 반드시 사용자 정의형이어야 된다
*/

//멤버 덧셈 연산자 오버로딩
class A
{
private:
	int num;

public:
	A(int _num) : num(_num) {}
	A operator + (A &a);

	int GetNumber()
	{
		return num;
	}
};

A A::operator+(A &a)
{
	return A(num + a.GetNumber());
}

//전역 뺄샘 연산자 오버로딩
class B
{
	friend B operator - (B& a1, B& a2);

private:
	int num;

public:
	B(int _num) : num(_num) {}

	int GetNumber()
	{
		return num;
	}
};

B operator - (B& a1, B& a2)
{
	return B(a1.num - a2.num);
}

//멤버 대입 연산자 오버로딩

class C
{
private:
	int Num;
public:
	C(int _Num) : Num(_Num) {}
	C &operator=(C &Other);
};

C& C::operator=(C& Other)
{
	this->Num = Other.Num;
	return *this;
}

int main()
{
	A a1(20);
	A a2(10);

	A a3 = a1 + a2; // = a1.operator + (a2);

	B b1(20);
	B b2(10);

	B b3 = b1 - b2; // = operator - (b1 - b2);

	C c1(5);
	C c2(8);

	c1 = c2;		// = c1.operator = (c2);
}