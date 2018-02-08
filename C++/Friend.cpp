#include "stdafx.h"
#include <iostream>

using namespace std;

//Friend
////////////////////

/*
Friend : ������ ����� �ڽ��� ��� ����� ���� �����ϰ� �ϴ� Ű����

���� ����)
1. �����Լ�, Ŭ����, ����Լ� 3���� ���ؿ��� ������ �� �ִ�
2. ������ ������ �ܹ����̴�
3. ������ ������ ���̵��� ������ ģ���� ģ�� ����� �������� �ʴ´�
4. ������ ��� ���� ���ÿ� ������ ������ �� �� ������ �� ���� �ϳ����� �����ϴ�
5. ������ ����� ��ӵ��� �ʴ´�, �ٸ� �θ� ���� �������ϴ� ���� �����ϴ�
*/

//���� �Լ�
class A
{
	friend void Display(A &a);

private:
	int num;

public:
	A(int _num) : num(_num) {}
};

void Display(A &a)
{
	cout << a.num << endl;
}

///////////////////////////////

//Ŭ����
class C;
class B
{
	friend C;
private:
	int x;
	int y;
};

class C
{
public:
	void Display(B &b)
	{
		cout << b.x << endl;
		cout << b.y << endl;
	}
};

///////////////////////////////

//��� �Լ�
/*
���� ��ų ��)
1. Ŭ���� E���� D�� �˱� ���ؼ��� ���� D�� �־�� �ϹǷ� 'class D'�� �� ���� ����
2. Ŭ���� D���� E�� friend �ϱ� ���ؼ��� E�� ���� �־�� �ϹǷ� 'class E'�� �� �ڿ� ����
3. Ŭ���� D�� �� �ڿ� ����
4. void Display(D &d)���� d��� ��ü�� ����� ���ؼ��� DŬ������ ������ �ʿ��ϹǷ� display ���Ǻδ� �� �ڿ� ����  
*/
class D;
class E
{
public:
	void Display(D &d);
};

class D
{
	friend void E::Display(D &d);
private:
	int num;
};

void E::Display(D &d)
{
	cout << d.num << endl;
}
