#include "stdafx.h"
#include <iostream>

using namespace std;

//Class
////////////////////

/*
Ŭ����		: ��ü�� ���α׷����� ǥ���� �� �ֵ��� ������(�ʵ�)�� ó��(�޼���)�� ��� ���� ���赵
�ν��Ͻ�	: Ŭ������ ���� ������� ��ü

���� ������	: Ŭ������ ���� ������� ������� ���ٿ� ������ �� �� �ִ� Ű����
 private	: �ܺο��� ���� �Ұ�
 public		: ��𿡼��� ���� ����
 protected	: �ܺο��� ������ �Ұ����ϳ�, ��ӵ� �Ļ� Ŭ������ ���� ������ ���


���� ����)
1. �⺻ ���� �����ڴ� 'private'�̴�
2. Ŭ���� ���� �� �޸𸮰� �Ҵ������ �ʴ´� (static, const ���� �ʱ�ȭ ���� ������ ����)
3. Ŭ���� ���ο��� �Լ� ���� �� �ڵ����� 'inline' �Ӽ��� �ٴ´�
4. �ܺο��� ��� �Լ� ���� �� '::'�� Ŭ������ ���ӵǾ� �ִ� ���� ǥ���ؾ� �Ѵ�

5. ���ÿ� ����� �ν��Ͻ��� '.'���� ��� ���� �Ǵ� �Լ��� ������ �� �ִ�
6. ���� ����� �ν��Ͻ��� '->'���� ��� ���� �Ǵ� �Լ��� ������ �� �ִ�
*/


class Point //Point Ŭ���� ����
{
private:				//���� ������ ���� (�ٸ� ���� ������ ������� 'private')

	int x = 1;			//��� ���� ����
	int y = 2;			//��� ���� ����


public:					//���� ������ ���� (�ٸ� ���� ������ ������� 'public')

	void Display1()		//��� �Լ� ���� �� ����(inline)
	{
		cout << x << endl;
		cout << y << endl;
	}

	void Display2();	//��� �Լ� ����
};

void Point::Display2()	//�ܺο��� ������ ����
{
	cout << x << endl;
	cout << y << endl;
}

int main()
{
	Point p1;			//p1 �ν��Ͻ� ����

	p1.Display1();		//'.'���� Display1() ��� �Լ� ����
	p1.Display2();		//'.'���� Display2() ��� �Լ� ����

	Point *p2 = new Point; //p2 �ν��Ͻ� ���� �Ҵ�

	p2->Display1();		//'->'���� Display1() ��� �Լ� ����
	p2->Display2();		//'->'���� Display1() ��� �Լ� ����
}