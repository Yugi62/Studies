#include "stdafx.h"
#include <iostream>

using namespace std;

//Inheritance
////////////////////

/*
���� ���        : �ٴ��Ϸ� �Լ��ϴ� ��

���ǻ���)

1. ���� ��� ���¿��� ��� �̴ϼȶ����� ���� �ƴ� �θ� Ŭ���� ���� ������ �����ڰ� ����ȴ�
2. A->B / A->C / B,C->D �̷��� ����� ��� D���� A�� �� �� ��ӹ޾� �� ��� A�� ����� �������� ���ϴ� ��ȣ������ ������ ����� (���̾Ƹ�� ���)


���� ��� Ŭ����)
A(virtual)->B
A(virtual)->C
B,C->D

�� ���¿��� D�� ���� �� B�� C�����ڿ��� A �����ڸ� �������� �ʴ´ٴ� ��
�׸��� B�� C �Ѵ� vitual�� �����ؾ� ���ƾ� ��
B,C���� A�� �����ڸ� �������� �ʾ����Ƿ� D���� ���� �����ؾ� ��
*/

//���� ���
class Apple
{
private:
	int apple;

public:
	Apple(int _apple) : apple(_apple) {}
};

class Pen
{
private:
	int pen;

public:
	Pen(int _pen) : pen(_pen) {}
};

class ApplePen : public Pen, public Apple                        //Pen-> Apple ������ ������ ����
{
public:
	ApplePen(int _apple, int _pen) : Apple(_apple), Pen(_pen) {} //Apple�� �������� Pen���� ����
};

//���̾Ƹ�� ���
class A
{
private:
	int number;

public:
	A(int _number) : number(_number) {}
};

class B : virtual public A
{
public:
	B(int _number) : A(_number) {}                         //virtual �������� A�����ڸ� ȣ������ �ʴ´�
};

class C : virtual public A
{
public:
	C(int _number) : A(_number) {}                         //virtual �������� A�����ڸ� ȣ������ �ʴ´�
};

class D : public B, public C
{
public:
	D(int _number) : A(_number), B(_number), C(_number) {} //A �����ڸ� B,C���� ȣ������ �ʾ� ���� ȣ���ؾ� �Ѵ�
};


void main()
{
	ApplePen ap(10, 20);

	D d(10);
}