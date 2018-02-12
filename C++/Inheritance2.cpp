#include "stdafx.h"
#include <iostream>

using namespace std;

//Inheritance
////////////////////

/*
다중 상속        : 다대일로 함수하는 것

유의사항)

1. 다중 상속 상태에서 멤버 이니셜라이저 순이 아닌 부모 클래스 지정 순으로 생성자가 실행된다
2. A->B / A->C / B,C->D 이렇게 상속할 경우 D에서 A를 두 번 상속받아 그 결과 A의 멤버를 구별하지 못하는 모호성으로 오류가 생긴다 (다이아몬드 상속)


가상 기반 클래스)
A(virtual)->B
A(virtual)->C
B,C->D

이 상태에서 D를 만들 시 B와 C생성자에서 A 생성자를 실행하지 않는다는 뜻
그리고 B와 C 둘다 vitual을 선언해야 놓아야 함
B,C에서 A의 생성자를 실행하지 않았으므로 D에서 따로 실행해야 함
*/

//다중 상속
class Apple
{
private:
	int apple;

public:
	Apple(int _apple) : apple(_apple) {}
};

class Pen
{
private:
	int pen;

public:
	Pen(int _pen) : pen(_pen) {}
};

class ApplePen : public Pen, public Apple                        //Pen-> Apple 순으로 생성자 실행
{
public:
	ApplePen(int _apple, int _pen) : Apple(_apple), Pen(_pen) {} //Apple이 먼저지만 Pen부터 실행
};

//다이아몬드 상속
class A
{
private:
	int number;

public:
	A(int _number) : number(_number) {}
};

class B : virtual public A
{
public:
	B(int _number) : A(_number) {}                         //virtual 선언으로 A생성자를 호출하지 않는다
};

class C : virtual public A
{
public:
	C(int _number) : A(_number) {}                         //virtual 선언으로 A생성자를 호출하지 않는다
};

class D : public B, public C
{
public:
	D(int _number) : A(_number), B(_number), C(_number) {} //A 생성자를 B,C에서 호출하지 않아 따로 호출해야 한다
};


void main()
{
	ApplePen ap(10, 20);

	D d(10);
}