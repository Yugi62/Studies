#include "stdafx.h"
#include <iostream>

using namespace std;

//DefaultParameter
////////////////////

/*
����Ʈ �Ű����� : ���ڸ� ���޹��� ������ �� �� ���� ������ֱ� ���� �̸� �����Ǿ� �ִ� ����
*/

void Display(int x = 0)	//�Ű������� ���� �����ϸ� ����Ʈ �Ű������� �ȴ�
{
	cout << x << endl;
}

int main()
{
	Display();		//���ڸ� �����ʾ� �̸� ������ 0 ���
	Display(5);		//���ڸ� �־� 5 ���
}