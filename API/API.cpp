#include <Windows.h>

/*
API ���)
 �ڵ�   : 32��Ʈ ���������� ��ü���� ���� �����ϱ� ���� �ʿ��ϴ� (�ּҿ� ����ϴ�)
 �޼��� : ����ڳ� �ý��� �������� ���ۿ� ���� �߻��� ��ü�� ��ȭ�� ���� ����
*/

/*
WndProc)
�޼����� ó���ϴ� �Լ��� ���α׷��� �������� ó���ϴ� �κ��� ����Ѵ�
*/

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); 

/*
WinMain�� ����)
 hInstance     : ���α׷��� �ν��Ͻ� �ڵ�
 hPrevInstance : �ٷ� �տ� ����� ���� ���α׷��� �ν��Ͻ� �ڵ��̸� ���� ��� NULL
 lpCmdLine     : ��������� �Էµ� ���α׷� �μ��̸� ������ argv�μ��� �ش��Ѵ�
 nCmdShow      : ���α׷��� ����� �����̸� �ּ�ȭ, ������ ���� ���޵ȴ�

 ���̸��� �ݵ�� 'WinMain'���� �����̴�
*/

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;

	WndClass.cbClsExtra = 0;                                       //���� ���� (�̻�� �� 0)
	WndClass.cbWndExtra = 0;                                       //���� ���� (�̻�� �� 0)
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);  //����
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);                //Ŀ��
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);              //������
	WndClass.hInstance = hInstance;                                //���α׷� �ν��Ͻ� ��
	WndClass.lpfnWndProc = (WNDPROC)WndProc;                       //�޽��� ó�� �Լ� ����
	WndClass.lpszClassName = TEXT("Windows");                      //������ Ŭ���� �̸�
	WndClass.lpszMenuName = NULL;                                  //������ �޴� ���� (���ҽ� �����Ϳ��� ������� ��)
	WndClass.style = CS_VREDRAW | CS_HREDRAW;

	if (!RegisterClass(&WndClass))
		return 0;

	hWnd = CreateWindow(
		WndClass.lpszClassName, //������ Ŭ���� �̸�
		WndClass.lpszClassName, //������ ����
		WS_OVERLAPPEDWINDOW,    //������ ��Ÿ��
		CW_USEDEFAULT,          //������ ���� ��ǥ X
		CW_USEDEFAULT,          //������ ��� ��ǥ Y
		CW_USEDEFAULT,          //������ ��
		CW_USEDEFAULT,          //������ ����
		NULL,                   //�θ��� �ڵ�
		(HMENU)NULL,            //�޴� �ڵ�
		hInstance,              //���α׷� �ڵ�
		NULL);                  //'CREATESTRUCT' ����ü�� ����

	/*
	nCmdShow)
	 �����츦 ȭ�鿡 ����ϴ� ����� �����Ѵ�

	 SW_HIDE       : �����츦 �����
	 SW_MINIMIZE   : �����츦 �ּ�ȭ��Ű�� Ȱ��ȭ��Ű�� �ʴ´�
	 SW_RESTORE    : �����츦 Ȱ��ȭ��Ų��
	 SW_SHOW       : �����츦 Ȱ��ȭ���� �����ش�
	 SW_SHOWNORMAL : �����츦 Ȱ��ȭ���� �����ش�

	ShowWindow)
	 �����츦 ȭ�鿡 ����Ѵ�
	*/
	ShowWindow(hWnd, nCmdShow);

	/*
    �޼��� ���� ���)
     BOOL GetMessage( LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax);
      �� �Լ��� �޼��� ť���� �޼����� �о�鿩 lpMsg�� �����Ѱ� ���� �޼����� WM_QUIT�� ���
      False�� �����ϸ� �� �ܿ��� ��� True�� �����ϴ� �Լ���. �ڿ� 3���� ���ڴ� �޼��� �д� ���� ������ ����Ѵ�

     BOOL TranslateMessage( CONST MSG *lpMsg);
	  Ű���� �Է� �޽����� �����Ͽ� ���α׷����� ���� �� �� �ֵ��� �� �ش�

     LONG DispatchMessage( CONST MSG *lpmsg);
	  �޼��� ť���� ���� �޼����� 'WndProc'���� �����Ѵ�
	*/
	while (GetMessage(&Message, 0, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}


	//WM_QUIT �޼����κ��� ���޵� Ż���ڵ� return 0�̶� ū ���̴� ����
	return Message.wParam; 


	/*
	�������� ���α׷� ���� ����

	1. WndClass ���� : �������� ����� �Ǵ� Ŭ������ �����Ѵ�
	2. CreateWindow  : �޸𸮻� �����츦 �����
	3. ShowWindow    : �����츦 ȭ�鿡 ǥ���Ѵ�
	4. �޼��� ����   : ����ڷκ��� �޼����� ó���Ѵ�
	*/
}

/*
�޼��� ����ü ����)

typedef struct tagMSG
{
HWND        hwnd;
UINT        message;
WPARAM      wParam;
LPARAM      lParam;
DWORD       time;
POINT       pt;
} MSG;

hwnd    : �޼����� ���� ������ �ڵ�
message : � ������ �޼����ΰ��� ��Ÿ����
wParam  : ���޵� �޼����� ���� �ΰ����� ����
lParam  : ���޵� �޼����� ���� �ΰ����� ����
time    : �޼����� �߻��� �ð�
pt      : �޼����� �߻����� ���� ���콺 ��ġ
*/

/*
�޼��� ����)
 WM_QUIT        : ���α׷��� ���� �� �߻��ϴ� �޼���
 WM_LBUTTONDOWN : ���콺�� ���� ��ư�� ���� ��� �߻�
 WM_CHAR        : Ű����κ��� ���ڰ� �Էµ� �� �߻�
 WM_PAINT       : ȭ���� �ٽ� �׷��� �� �ʿ䰡 ���� �� �߻�
 WM_DESTROY     : �����찡 �޸𸮿��� �ı��� �� �߻��Ѵ�
 WM_CREATE      : �����찡 ó�� ������� �� �߻��Ѵ�
*/

/*
WndProc ����)
 �޼��� ����ü�� �ִ� 4���� ���� ����

WndProc ���� ����)
 1. ���̽����� �޼����� Ȯ���ϰ� ó���� �� �����Ѵ�
 2. ó������ ���� �޼����� DefWindowProc���� �Ѱ� ó���Ѵ�

 WndProc ���� ����)
 1. ���̽����� ó�� �� 'break'�� �ƴ� 'return 0'�� �ݵ�� �ٿ��� �Ѵ�
*/

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;

	switch (iMessage)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}