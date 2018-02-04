#include "stdafx.h"
#include <iostream>

using namespace std;

//Inline
////////////////////

/*
인라인 함수 : 함수 실행 시 선언부를 찾는 과정 없이 바로 복사되어 사용되는 함수

부가 설명)
함수 호출 시 위에서 아래로 선언부를 찾은 후 정의부를 찾는 과정을 거치게 된다
inline의 경우 그 과정 없이 바로 복사되어 사용할 수 있는데, 그 결과 속도가 일반 함수에 비해 월등히 빠르다

하지만 그것은 어디까지나 짧은 함수의 경우이며 너무 긴 함수를 inline으로 사용하게 되면
그만큼 복사되는 줄이 많아져 오히려 일반 함수를 사용하는 것보다 성능이 떨어질 수 있어 주의해야한다


유의사항)
1. 3줄 이상 함수에는 왠만하면 inline을 안 쓰는 것이 좋다
*/

inline int Max(int x, int y) { return (x > y) ? x : y; }	//inline 함수 선언

int main()
{
	cout << Max(10, 20) << endl; //=cout<< (x > y) ? x : y << endl;
}