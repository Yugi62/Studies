#include "stdafx.h"
#include <iostream>

using namespace std;

//This
////////////////////

/*
this :호출한 객체의 번지를 가르키는 포인터 상수


같은 타입인 각각의 객체는 서로 함수를 공유하고 있는데 이 멤버 함수들은 어떻게
자신이 a1이나 a2에 종속되어 있는 것을 알 수 있는 걸까? 보통은 '.'으로 판단한다고 생각하겠지만
그것은 틀리고 실제로는 아래와 같이 컴파일러로 인해 변경되어 함수에 인수로 들어가 실행되는 것을 볼 수 있다

A a1(5);
A a2(8);
a1.Display();      = Display(&a1);
a2.Display();      = Display(&a2);

void A::Display()  = void A::Display(A *const this)

결국 매번 멤버 함수를 실행할 때마다 자동으로 'this'라는 인자가 하나 더 들어가게 되는 것이다
*/

class A
{
private:
	int num;
public:
	A(int num)
	{
		this->num = num;
	}
};

