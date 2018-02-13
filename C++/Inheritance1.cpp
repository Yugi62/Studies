#include "stdafx.h"
#include <iostream>

using namespace std;

//Inheritance1
////////////////////

/*
���        : Ư�� Ŭ������ �Ӽ��� �״�� �����޾� ����� �� �ִ� �� (Ŭ������ ������ �� Ȯ���ϴ� ��)

�θ��� ���� �����ڿ� �ڽİ��� ����)
 public    : public�� �θ��� ����� �ڽ� Ŭ�������� ������ �� �ִ�   (����, �Ļ�, �ܺ�) = ���� ����
 private   : private�� �θ��� ����� �ڽ� Ŭ�������� ������ �� ����  (���� ) = ���� ����
 protected : protected�� �θ��� ����� �ڽ� Ŭ������ ������ �� �ִ�  (����, �Ļ�) = ���� ����

��� ���� ������)
 B : public A    = A���� ��� ������ ������� B���� 'public'�� ���� �� A�� ��ӹްڴ�
 B : private A   = A���� ��� ������ ������� B���� 'private'�� ���� �� A�� ��ӹްڴ�
 B : protected A = A���� ��� ������ ������� B���� 'protected'�� ���� �� A�� ��ӹްڴ�
 ->�������� ���� �� �⺻���� 'private'�� �����ȴ�

��� ���)
 �ϴ��
 �ٴ���

���ǻ���)
1. �θ� Ŭ������ �����ڰ� ���ǵǾ��� ��� �ݵ�� �ڽ� Ŭ������ ��� �̴ϼȶ������� �θ� �����ڸ� ȣ���ؾ� �Ѵ�
2. �ڽ� Ŭ�������� �θ�� ������ �Լ��� Ȥ�� �������� ���� �� �ڽ� ��ü�κ��� �� ����� ������ �� �ڽ� ���� �� �켱�� �Ѵ� (������)
3. ������ ���¶�� �ϴ��� �θ��� �Ϳ� �����ϴ� ���� �����ϴ�
4. �ڽ� Ŭ������ ��� �̴ϼȶ��������� �θ� Ŭ������ ȣ������ ���� �� �⺻ �����ڰ� �ڵ����� ȣ��ȴ�

��ӵ��� �ʴ� ��)
 1. �����ڿ� �ı���
 2. ���� ������
 3. ���� ��� ������ ���� ��� �Լ�
 4. ������ ���� ����
*/

class A
{
private:
	int x;

public:
	A(int _x) : x(_x)
	{
		cout << "A" << endl;
	}

	~A()
	{

	}
};

class B : public A
{
private: 
	int y;

public :
	B(int _x, int _y) : A(_x), y(_y)
	{
		cout << "B" << endl;
	}

	~B()
	{

	}
};

class C : public B
{
private:
	int z;

public:
	C(int _x, int _y, int _z) : B(_x, _y), z(_z)
	{
		cout << "C" << endl;
	}

	~C()
	{

	}
};



class D
{
public:
	int x;
	D(int _dx) : x(_dx) {}

	void Display()
	{
		cout << "D" << endl;
	}
};

class E : public D
{
public:
	int x;
	E(int _dx, int _ex) : D(_dx), x(_ex) {}

	void Display()
	{
		cout << "E" << endl;
	}
};


int main()
{
   C *c = new C(1, 2, 3);
  /*
    ��� ��ü�� ��������� ����)
    1. C Ÿ���� c ����� ���ÿ� C �����ڿ� ���ڸ� 3�� ����
    2. C�� ��� �̴ϼȶ������� B �����ڿ� ���� 2�� ������ ȣ��
    3. B�� ��� �̴ϼȶ������� A �����ڿ� ���� 1�� ������ ȣ��
    4. A�� ��� �̴ϼȶ������� x �ʱ�ȭ
    5. A ������ ����
    6. B�� ��� �̴ϼȶ������� y �ʱ�ȭ
    7. B ������ ����
    8. C�� ��� �̴ϼȶ������� z �ʱ�ȭ
    9. C ������ ����
	10. ��ü �ϼ�
  */

   delete c;
  /*
    ��� ��ü�� ���ŵǴ� ����)
	1. delete Ȥ�� �߰�ȣ�� Ż��
	2. c�� C �Ҹ��� ȣ��
	3. B �Ҹ��� ȣ��
	4. A �Ҹ��� ȣ��
  */
   
 

  /*
   �ڽ� ��ü�� ���� �� �ڽİ� �θ��� ���� �̸��� ���� Ȥ�� �Լ��� ���� �� �ڽ��� 
   Ŭ������ �ִ� ���� �� �켱���Ѵ� ���� �����⸸ �ϴ� ���̱⿡ �θ��� ������ ������ 
   �����ϴ� �̷��� ������ ������(overriding)�̶�� �Ѵ�
  */
   E e(1,2);

   cout << e.x << endl;  //e ��ü�� ��� �� D�κ��� ��ӹ��� ��� x 
   e.Display();

   cout << e.D::x << endl;
   e.D::Display();
}
