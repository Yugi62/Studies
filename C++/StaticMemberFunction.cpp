#include "stdafx.h"
#include <iostream>

using namespace std;

//StaticMemberFunction
////////////////////

/*
���� ��� �Լ� : Ŭ������ ���� �Ǵ� ���� �Լ�

���� ����)
1. �ܺο��� ������ ���� 'static' Ű���带 ����
2. ���ڷ� ���� �ʴ� �̻� ���� ���� ����� ��� �����ϴ� 
*/

class Point
{
public:
	static void Display();

private:
	static int x;
	static int y;
};

void Point::Display()	//'static' ���� ������ ����
{
	cout << Point::x << endl;
	cout << Point::y << endl;
}