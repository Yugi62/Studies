#include "stdafx.h"
#include <iostream>

using namespace std;

//Class
////////////////////

/*
클래스		: 객체를 프로그램으로 표현할 수 있도록 데이터(필드)와 처리(메서드)를 모아 놓은 설계도
인스턴스		: 클래스를 통해 만들어진 실체

접근 지시자	: 클래스에 속한 멤버들을 대상으로 접근에 제한을 들 수 있는 키워드
 private	: 외부에서 접근 불가
 public		: 어디에서든 접근 가능
 protected	: 외부에서 접근이 불가능하나, 상속된 파생 클래스에 한해 접근이 허용


유의 사항)
1. 기본 접근 지시자는 'private'이다
2. 클래스 선언 시 메모리가 할당되지는 않는다 (static, const 등을 초기화 없이 선언이 가능)
3. 클래스 내부에서 함수 정의 시 자동으로 'inline' 속성이 붙는다
4. 외부에서 멤버 함수 정의 시 '::'로 클래스에 종속되어 있는 것을 표시해야 한다

5. 스택에 저장된 인스턴스는 '.'으로 멤버 변수 또는 함수에 접근할 수 있다
6. 힙에 저장된 인스턴스는 '->'으로 멤버 변수 또는 함수에 접근할 수 있다
*/


class Point				//Point 클래스 선언
{
private:				//접근 지시자 선언 (다른 접근 지시자 선언까지 'private')

	int x = 1;			//멤버 변수 선언
	int y = 2;			//멤버 변수 선언


public:					//접근 지시자 선언 (다른 접근 지시자 선언까지 'public')

	void Display1()			//멤버 함수 선언 및 정의(inline)
	{
		cout << x << endl;
		cout << y << endl;
	}

	void Display2();		//멤버 함수 선언
};

void Point::Display2()			//외부에서 생성자 정의
{
	cout << x << endl;		//내부에서 'private'인 x 접근 
	cout << y << endl;		//내부에서 'private'인 y 접근
}

int main()
{
	Point p1;		//p1 인스턴스 선언

	//p1.x = 10;			외부에서 'private'인 x 접근 불가
	//p1.y = 20;			외부에서 'private'인 y 접근 불가


	p1.Display1();		//외부에서 '.'으로 'public' Display1() 멤버 함수 접근
	p1.Display2();		//외부에서 '.'으로 'public' Display2() 멤버 함수 접근

	Point *p2 = new Point; //p2 인스턴스 동적 할당

	p2->Display1();		//'->'으로 Display1() 멤버 함수 접근
	p2->Display2();		//'->'으로 Display1() 멤버 함수 접근
}