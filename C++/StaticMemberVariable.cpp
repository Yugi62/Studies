#include "stdafx.h"
#include <iostream>

using namespace std;

//StaticMemberVariable
////////////////////

/*
���� ��� ���� : Ŭ������ ���ӵǴ� ���� ����

���� ����)
1. Ŭ������ ���� �� �޸� �Ҵ��� ���� �ʱ⿡ ���ο� ������ �ϵ� ���Ǵ� �ܺο��� �Ѵ�
2. �ܺο��� ���� �� �ڷ����� ���� ������ �ش�
3. �� �ѹ��� �ʱ�ȭ�ȴ�
*/

class A
{
public:
	static int Num;
};

int A::Num = 10;

int main()
{
	cout << A::Num << endl;
}