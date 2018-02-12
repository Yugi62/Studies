#include "stdafx.h"
#include <iostream>

using namespace std;

//Inheritance1
////////////////////

/*
상속        : 특정 클래스의 속성을 그대로 물려받아 사용할 수 있는 것 (클래스를 복사한 후 확장하는 것)

부모의 접근 지시자와 자식간의 관계)
 public    : public인 부모의 멤버는 자식 클래스에서 접근할 수 있다   (내부, 파생, 외부) = 접근 가능
 private   : private인 부모의 멤버는 자식 클래스에서 접근할 수 없다  (내부 ) = 접근 가능
 protected : protected인 부모의 멤버는 자식 클래스와 접근할 수 있다  (내부, 파생) = 접근 가능

상속 접근 지시자)
 B : public A    = A에서 상속 가능한 멤버들을 B에서 'public'로 지정 후 A를 상속받겠다
 B : private A   = A에서 상속 가능한 멤버들을 B에서 'private'로 지정 후 A를 상속받겠다
 B : protected A = A에서 상속 가능한 멤버들을 B에서 'protected'로 지정 후 A를 상속받겠다
 ->지정하지 않을 시 기본으로 'private'로 지정된다

상속 방식)
 일대다
 다대일

유의사항)
1. 부모 클래스에 생성자가 정의되었을 경우 반드시 자식 클래스의 멤버 이니셜라이저로 부모 생성자를 호출해야 한다
2. 자식 클래스에서 부모와 동일한 함수명 혹은 변수명을 선언 시 자식 객체로부터 그 멤버를 접근할 때 자식 것을 더 우선시 한다 (재정의)
3. 재정의 상태라고 하더라도 부모의 것에 접근하는 것은 가능하다
4. 자식 클래스의 멤버 이니셜라이져에서 부모 클래스를 호출하지 않을 시 기본 생성자가 자동으로 호출된다

상속되지 않는 것)
 1. 생성자와 파괴자
 2. 대입 연산자
 3. 정적 멤버 변수와 정적 멤버 함수
 4. 프렌드 관계 지정
*/

class A
{
private:
	int x;

public:
	A(int _x) : x(_x)
	{
		cout << "A" << endl;
	}

	~A()
	{

	}
};

class B : public A
{
private: 
	int y;

public :
	B(int _x, int _y) : A(_x), y(_y)
	{
		cout << "B" << endl;
	}

	~B()
	{

	}
};

class C : public B
{
private:
	int z;

public:
	C(int _x, int _y, int _z) : B(_x, _y), z(_z)
	{
		cout << "C" << endl;
	}

	~C()
	{

	}
};



class D
{
public:
	int x;
	D(int _dx) : x(_dx) {}

	void Display()
	{
		cout << "D" << endl;
	}
};

class E : public D
{
public:
	int x;
	E(int _dx, int _ex) : D(_dx), x(_ex) {}

	void Display()
	{
		cout << "E" << endl;
	}
};


int main()
{
   C *c = new C(1, 2, 3);
  /*
    상속 객체가 만들어지는 과정)
    1. C 타입인 c 선언과 동시에 C 생성자에 인자를 3개 삽입
    2. C의 멤버 이니셜라이져로 B 생성자에 인자 2개 삽입후 호출
    3. B의 멤버 이니셜라이져로 A 생성자에 인자 1개 삽입후 호출
    4. A의 멤버 이니셜라이져로 x 초기화
    5. A 생성자 실행
    6. B의 멤버 이니셜라이져로 y 초기화
    7. B 생성자 실행
    8. C의 멤버 이니셜라이져로 z 초기화
    9. C 생성자 실행
	10. 객체 완성
  */

   delete c;
  /*
    상속 객체가 제거되는 과정)
	1. delete 혹은 중괄호를 탈출
	2. c의 C 소멸자 호출
	3. B 소멸자 호출
	4. A 소멸자 호출
  */
   
 

  /*
   자식 객체에 접근 시 자식과 부모간의 같은 이름의 변수 혹은 함수가 있을 때 자식의 
   클래스에 있는 것을 더 우선시한다 물론 가리기만 하는 것이기에 부모의 변수에 접근은 
   가능하다 이러한 행위를 재정의(overriding)이라고 한다
  */
   E e(1,2);

   cout << e.x << endl;  //e 객체의 멤버 중 D로부터 상속받은 멤버 x 
   e.Display();

   cout << e.D::x << endl;
   e.D::Display();
}

