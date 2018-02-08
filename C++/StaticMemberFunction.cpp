#include "stdafx.h"
#include <iostream>

using namespace std;

//StaticMemberFunction
////////////////////

/*
정적 멤버 함수 : 클래스에 종속 되는 정적 함수

유의 사항)
1. 외부에서 정의할 때는 'static' 키워드를 뺀다
2. 인자로 받지 않는 이상 오직 정적 멤버만 사용 가능하다 
*/

class Point
{
public:
	static void Display();

private:
	static int x;
	static int y;
};

void Point::Display()	//'static' 예약어를 붙이지 않음
{
	cout << Point::x << endl;
	cout << Point::y << endl;
}