#include "stdafx.h"
#include <iostream>

using namespace std;

//StaticMemberVariable
////////////////////

/*
정적 멤버 변수 : 클래스에 종속되는 정적 변수

유의 사항)
1. 클래스는 선언 시 메모리 할당이 되지 않기에 내부에 선언을 하되 정의는 외부에서 한다
2. 외부에서 정의 시 자료형도 같이 선언해 준다
3. 단 한번만 초기화된다
*/

class A
{
public:
	static int Num;
};

int A::Num = 10;

int main()
{
	cout << A::Num << endl;
}