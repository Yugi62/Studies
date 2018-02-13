#include "stdafx.h"
#include <iostream>

using namespace std;

//Polymorphism
////////////////////

/*
상속 관계에서 자식 객체에 부모 객체가 대입이 안 되는 것처럼
포인터 또한 자식 포인터에서 부모 포인터의 주소를 대입할 수 없다

정적 타입 : 포인터를 선언 했을 때의 타입
동적 타입 : 포인터가 가르키는 객체의 타입

정적 결합 : 컴파일하는 시점(정확하게는 링크 시점)에 미리 호출할 주소를 넣어서 빠르게 호출하는 결합 (컴파일할 때 호출할 번지가 결정된다)
동적 결합 : 프로그램 시작 후 객체에 따라 함수의 호출을 달라지게 하는 결합 (멤버함수를 포인터로 호출할 때만 동작)


1. 포인터에서도 일반적인 객체에 대입하는 문법이 적용된다
2. 부모는 자식을 가르킬 수 있다, 단 가상 시반 클래스가 아닌 다중 상속의 경우 해당하지 않는다
3. 컴파일러는 동적 타입을 우선적으로 보기에 부모 객체로 자식 객체를 가르켜 재정된 함수 실행 시 부모 객체의 함수를 실행
4. virtual은 외부 정의부에서 사용할 수 없다
5. virtual을 붙이면 동적 타입을 따르게 된다


동적 결합을 하기 위해 실제 컴파일러는 가상 함수 테이블이란 것을 만드는데
이것이 객체에 따라 호출하는 함수를 지정해 주는 것이다

포인터로 상속 객체 접근 시 소멸자에 virtual을 선언해야 하는데
만약 부모 포인터로 자식 객체에 접근한 상태에서 delete를 해버리면
부모 포인터의 소멸자만 실행되기 때문이다

가상함수는 재정의를 무조건 해야되는 것은 아니지만
순수가상함수는 반드시 재정의를 해야한다(추상화 클래스)
순수가상함수는 선언 시 '=0'을 붙이고 정의는 하지 않아야 한다 또한 순수가상함수가
포함된 클래스는 인스턴스로 만드는 것이 불가능하다
단 포인터로는 선언할 수는 있다 (당연하지만 동적할당은 불가능하다)

순수가상함수로 정의를 할 순 있긴 하다 이때는 모든 자식이 공통으로 할 일을 할때
주로 쓰인다 위와 같이 쓸 것
*/


class A
{
public:
	A()
	{

	}

	A(int x)
	{

	}
};

class B : public A
{
public:
	B(int x)
	{

	}
};

class Device
{
public:
	virtual void Display() = 0
	{
		cout << "Start" << endl;
	}
};

class Computer : public Device
{
public:
	void Display()
	{
		Device::Display();
		cout << "Computer" << endl;
	}
};

class Phone : public Device
{
public:
	void Display()
	{
		Device::Display();
		cout << "Phone" << endl;
	}
};

int main()
{
	Phone  ph;
	ph.Display();
}

