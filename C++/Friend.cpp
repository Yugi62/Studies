#include "stdafx.h"
#include <iostream>

using namespace std;

//Friend
////////////////////

/*
Friend : 지정한 대상이 자신의 모든 멤버에 접근 가능하게 하는 키워드

유의 사항)
1. 전역함수, 클래스, 멤버함수 3가지 수준에서 지정할 수 있다
2. 프렌드 지정은 단방향이다
3. 프렌드 지정은 전이되지 않으며 친구의 친구 관계는 인정하지 않는다
4. 복수의 대상에 대해 동시에 프렌드 지정을 할 수 있지만 한 번에 하나씩만 가능하다
5. 프렌드 관계는 상속되지 않는다, 다만 부모를 통해 엑세스하는 것은 가능하다
*/

//전역 함수
class A
{
	friend void Display(A &a);

private:
	int num;

public:
	A(int _num) : num(_num) {}
};

void Display(A &a)
{
	cout << a.num << endl;
}

///////////////////////////////

//클래스
class C;
class B
{
	friend C;
private:
	int x;
	int y;
};

class C
{
public:
	void Display(B &b)
	{
		cout << b.x << endl;
		cout << b.y << endl;
	}
};

///////////////////////////////

//멤버 함수
/*
순서 지킬 것)
1. 클래스 E에서 D를 알기 위해서는 위에 D가 있어야 하므로 'class D'를 맨 위에 선언
2. 클래스 D에서 E를 friend 하기 위해서는 E가 위에 있어야 하므로 'class E'를 그 뒤에 선언
3. 클래스 D를 그 뒤에 선언
4. void Display(D &d)에서 d라는 객체를 만들기 위해서는 D클래스의 원형이 필요하므로 display 정의부는 그 뒤에 선언  
*/
class D;
class E
{
public:
	void Display(D &d);
};

class D
{
	friend void E::Display(D &d);
private:
	int num;
};

void E::Display(D &d)
{
	cout << d.num << endl;
}
