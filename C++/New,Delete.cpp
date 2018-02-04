#include "stdafx.h"
#include <iostream>

//New,Delete
////////////////////

/*
new / delete 유의사항

1. malloc은 생성자가 호출되지 않지만 new는 호출된다
2. free는 소멸자가 호출되지 않지만 delete는 호출된다

3. NULL 포인터에 대해서 delete는 동작하지 않는다
4. 할당 해제된 메모리에 대해서 delete를 사용할 수 없다
5. 할당 실패 시 NULL을 리턴한다

6. 초기화 생략 시 쓰레기 값이 저장된다

7. 배열은 선언과 동시에 초기화가 불가능하다
8. 배열 동적 할당 시 반드시 delete [] 로 없에야 한다
9. new로 선언한 객체는 반드시 delete로 없에야 한다
*/

int main()
{
	//변수 하나를 동적으로 할당
	int *p1 = new int;

	//변수 하나를 동적으로 할당과 동시에 초기화
	int *p2 = new int(10);	//(=생성자)

	//배열을 동적으로 할당
	int *p3 = new int[5];

	//사용 종료 후에는 반드시 할당 해제
	delete p1;
	delete p2;

	delete[] p3; //delete로 제거 시 배열의 첫번째 위치만 해제되기 때문에 반드시 delete[]를 사용해야 한다

	return 0;
}
