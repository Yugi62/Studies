#include "stdafx.h"
#include <iostream>

using namespace std;

//This
////////////////////

/*
this :ȣ���� ��ü�� ������ ����Ű�� ������ ���


���� Ÿ���� ������ ��ü�� ���� �Լ��� �����ϰ� �ִµ� �� ��� �Լ����� ���
�ڽ��� a1�̳� a2�� ���ӵǾ� �ִ� ���� �� �� �ִ� �ɱ�? ������ '.'���� �Ǵ��Ѵٰ� �����ϰ�����
�װ��� Ʋ���� �����δ� �Ʒ��� ���� �����Ϸ��� ���� ����Ǿ� �Լ��� �μ��� �� ����Ǵ� ���� �� �� �ִ�

A a1(5);
A a2(8);
a1.Display();      = Display(&a1);
a2.Display();      = Display(&a2);

void A::Display()  = void A::Display(A *const this)

�ᱹ �Ź� ��� �Լ��� ������ ������ �ڵ����� 'this'��� ���ڰ� �ϳ� �� ���� �Ǵ� ���̴�
*/

class A
{
private:
	int num;
public:
	A(int num)
	{
		this->num = num;
	}
};

