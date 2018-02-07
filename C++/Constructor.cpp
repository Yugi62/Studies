#include "stdafx.h"
#include <iostream>

using namespace std;

//Constructor
////////////////////

/*
생성자 : 인스턴스가 생성되는 동시에 실행되는 함수


생성자 종류)
1. 기본 생성자      : 인자가 없는 생성자로 클래스에 어떠한 생성자도 없을 시에는 비어있는 상태로 컴파일러가 자동으로 선언
2. 인자 생성자      : 인자가 있는 생성자

3. 기본 복사 생성자 : 복사 생성자를 정의하지 않을 시 선언 되는 복사 생성자
   -객체간의 필드의 값을 대입
   -깊은 복사가 아니기에 동적으로 할당된 변수가 있을 경우 같은 값을 2개의 변수가 가르키므로 소멸자가 2번 실행되어 오류

4. 복사 생성자      : 동일한 타입의 객체를 초기화와 동시에 대입받을 시 실행되는 생성자
   -인자는 반드시 자신의 타입으로 이루어진 레퍼런스를 정의

   복사 생성자 실행 기준)
   1. 객체가 인수로 전달될 때
   2. 객체를 초기화할 때 같은 타입의 또다른 객체를 대입할 때
   3. 동적 객체를 대상으로는 복사 생성자가 실행되지 않는다


유의 사항)
 -클래스와 함수명이 같아야 한다
 -매개변수는 있지만 리턴형이 없다
 -friend, static, virtual 을 사용할 수 없다

 -객체 생성과 동시에만 사용이 가능하다
 -특별한 경우가 아닌 이상 public으로 선언해야 한다
 -malloc 함수로는 실행이 되지 않는다

 -생성자 또한 '오버로딩'을 하는 것이 가능하다
*/

class Constructor
{
public:
	Constructor();                   //기본 생성자 선언

	Constructor(int x);              //인자 생성자 선언
	Constructor(Constructor &Other); //복사 생성자 선언
};

Constructor::Constructor()
{

}

Constructor::Constructor(int x)
{

}

Constructor::Constructor(Constructor &Other)
{

}

void main()
{
  //Constructor a(); = 함수
  //위 코드는 객체를 선언하는 것이 아닌 함수를 선언하는 것이므로 주의
	
    Constructor a;  //기본 생성자

  //Constructor a = Constructor();
  //복사 생성자 인해 위 Constructor()를 잘못 인식해 사용하려면 복사생성자를 지워야한다


    Constructor b(10);  //인자 생성자
    Constructor c = a;  //복사 생성자




    Constructor *d = new Constructor;     //기본 생성자
    Constructor *e = new Constructor();   //기본 생성자
    Constructor *f = new Constructor(10); //인자 생성자

    Constructor *g = f;  //복사 생성자가 실행되지 않는다

    Constructor h[2];                //객체 배열 선언
    Constructor i[2] = { {1},{2} };  //객체 배열 선언 및 초기화

  //Constructor j[2] = { Constructor(1), Constructor(2)};
  //복사 생성자 인해 위 Constructor()를 잘못 인식해 사용하려면 복사생성자를 지워야한다
}