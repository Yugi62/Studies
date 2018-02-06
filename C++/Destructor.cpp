#include "stdafx.h"
#include <iostream>

using namespace std;

//Destructor
////////////////////

/*
�Ҹ��� : �ν��Ͻ��� �����Ǵ� ���ÿ� ����Ǵ� �Լ� (delete Ȥ�� �߰�ȣ Ż��)

���� ����)
 -�Լ����� Ŭ������� ������, �̸� �տ� '~'�� �ٴ´�
 -�Ű������� ������ �Ѵ� ���� ���Ѵ�
 -free �Լ��δ� ������� �ʴ´�
 -static, friend�� ������� �������� virtual�� ����� �� �ִ�
 -��� �Ҹ��ڵ� ������� ���� �� ����ִ� ���·� ���������
 -Ư���� ��찡 �ƴ� �̻� public���� �����ؾ� �Ѵ�
*/

class Destructor
{
public:
	Destructor();  //������
	~Destructor(); //�Ҹ���
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
	Destructor *D = new Destructor(); //������ ����
	
	delete D;                         //�Ҹ��� ����

	/*
	����)
	 1. D�� �޸𸮸� �Ҵ�
	 2. ������ ����
	 3. �Ҹ��� ����
	 4. D�� �޸� �Ҵ� ����
	*/
}