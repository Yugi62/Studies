#include "stdafx.h"
#include <iostream>

using namespace std;

//ConstMemberFunction
////////////////////

/*
��� ��� �Լ� : Ŭ���� ���ο��� �����ϴ� �Լ��� ��� ������ ������ �� ���� �Լ�
mutable        : ��� ��� �Լ��� �����ϰ� ���� �����ϴ� ���� ����ϴ� Ű����

���� ����)
1. const ���� �Լ��� ������ �Ϻη� ��޵Ǿ� �μ��� ������ �����ε��� �ȴ�
*/

class Point
{
private:
	int x;
	int y;

	mutable int z;

public:
	void Display() const;
	void Display();
};

void Point::Display() const //��� ��ü�� �� ����
{
	cout << x << endl;
	cout << y << endl;

	cin >> z;
}

void Point::Display()      //��� ��ü�� �ƴҶ� ����
{
	cout << x << endl;
	cout << y << endl;
}
