#include "stdafx.h"
#include <iostream>

using namespace std;

//Struct
////////////////////

/*
구조체 : 다양한 타입들로 이루어진 사용자 정의 타입 (C언어)

부가 설명)
C에서는 타입들을 뭉쳐 새로운 타입을 만들어내는 것이었지만
C++에서는 메서드(기능)을 추가할 수 있게 되면서 사실상 클래스와 똑같아졌다

다른 점이라고 한다면 기본 접근 지시자가 'public'으로 이루어져 있다는 것이지만
이 경우 코딩방식이 살짝 바뀌는 것 외에는 솔직히 큰 차이는 아니다

클래스		= 메서드 + 필드
확장 구조체	= 메서드 + 필드

유의 사항)
1. 기본 접근 지시자가 'public' 외에는 클래스와 동일
*/

struct A	
{
private:
	int x;
	int y;

public:
	A(int _x, int _y) : x(_x), y(_y) {}
	void Display();
};

void A::Display()
{
	cout << x << endl;
	cout << y << endl;
}

int main()
{
	A a(10, 20);
	a.Display();
}

/*
위 코드를 봐도 알지만 생성자, 멤버 이니셜라이저, 접근 지시자 등
클래스에서 사용하는 모든 기능들을 구조체에서 전부 사용할 수 있다
*/