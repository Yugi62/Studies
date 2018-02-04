#include "stdafx.h"
#include <iostream>

using namespace std;

//DefaultParameter
////////////////////

/*
디폴트 매개변수 : 인자를 전달받지 못했을 때 그 값을 대신해주기 위해 미리 설정되어 있는 변수
*/

void Display(int x = 0)	//매개변수에 값을 대입하면 디폴트 매개변수가 된다
{
	cout << x << endl;
}

int main()
{
	Display();		//인자를 넣지않아 미리 설정된 0 출력
	Display(5);		//인자를 넣어 5 출력
}