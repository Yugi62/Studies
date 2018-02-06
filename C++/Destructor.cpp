#include "stdafx.h"
#include <iostream>

using namespace std;

//Destructor
////////////////////

/*
소멸자 : 인스턴스가 삭제되는 동시에 실행되는 함수 (delete 혹은 중괄호 탈출)

유의 사항)
 -함수명이 클래스명과 같으며, 이름 앞에 '~'가 붙는다
 -매개변수와 리턴형 둘다 갖지 못한다
 -free 함수로는 실행되지 않는다
 -static, friend를 사용하지 못하지만 virtual은 사용할 수 있다
 -어떠한 소멸자도 선언되지 않을 시 비어있는 상태로 만들어진다
 -특별한 경우가 아닌 이상 public으로 선언해야 한다
*/

class Destructor
{
public:
	Destructor();  //생성자
	~Destructor(); //소멸자
};

Destructor::Destructor()
{
	cout << "Constructor" << endl;
}

Destructor::~Destructor()
{
	cout << "Destructor" << endl;
}

void main()
{
	Destructor *D = new Destructor(); //생성자 실행
	
	delete D;                         //소멸자 실행

	/*
	순서)
	 1. D의 메모리를 할당
	 2. 생성자 실행
	 3. 소멸자 실행
	 4. D의 메모리 할당 해제
	*/
}