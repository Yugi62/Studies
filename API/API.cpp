#include <Windows.h>

/*
API 용어)
 핸들   : 32비트 정수값으로 객체들을 서로 구별하기 위해 필요하다 (주소와 비슷하다)
 메세지 : 사용자나 시스템 내부적인 동작에 의해 발생된 일체의 변화에 대한 정보
*/

/*
WndProc)
메세지를 처리하는 함수로 프로그램의 실질적인 처리하는 부분을 담당한다
*/

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); 

/*
WinMain의 인자)
 hInstance     : 프로그램의 인스턴스 핸들
 hPrevInstance : 바로 앞에 실행된 현재 프로그램의 인스턴스 핸들이며 없을 경우 NULL
 lpCmdLine     : 명령행으로 입력된 프로그램 인수이며 도스의 argv인수에 해당한다
 nCmdShow      : 프로그램이 실행될 형태이며 최소화, 보통모양 등이 전달된다

 ★이름은 반드시 'WinMain'으로 고정이다
*/

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;

	WndClass.cbClsExtra = 0;                                       //예약 영역 (미사용 시 0)
	WndClass.cbWndExtra = 0;                                       //예약 영역 (미사용 시 0)
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);  //배경색
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);                //커서
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);              //아이콘
	WndClass.hInstance = hInstance;                                //프로그램 인스턴스 값
	WndClass.lpfnWndProc = (WNDPROC)WndProc;                       //메시지 처리 함수 지정
	WndClass.lpszClassName = TEXT("Windows");                      //윈도우 클래스 이름
	WndClass.lpszMenuName = NULL;                                  //윈도우 메뉴 지정 (리소스 에디터에서 만들어진 것)
	WndClass.style = CS_VREDRAW | CS_HREDRAW;

	if (!RegisterClass(&WndClass))
		return 0;

	hWnd = CreateWindow(
		WndClass.lpszClassName, //윈도우 클래스 이름
		WndClass.lpszClassName, //윈도우 제목
		WS_OVERLAPPEDWINDOW,    //윈도우 스타일
		CW_USEDEFAULT,          //윈도우 출현 좌표 X
		CW_USEDEFAULT,          //윈도우 출력 좌표 Y
		CW_USEDEFAULT,          //윈도우 폭
		CW_USEDEFAULT,          //윈도우 높이
		NULL,                   //부모의 핸들
		(HMENU)NULL,            //메뉴 핸들
		hInstance,              //프로그램 핸들
		NULL);                  //'CREATESTRUCT' 구조체의 번지

	/*
	nCmdShow)
	 윈도우를 화면에 출력하는 방법을 지정한다

	 SW_HIDE       : 윈도우를 숨긴다
	 SW_MINIMIZE   : 윈도우를 최소화시키고 활성화시키지 않는다
	 SW_RESTORE    : 윈도우를 활성화시킨다
	 SW_SHOW       : 윈도우를 활성화시켜 보여준다
	 SW_SHOWNORMAL : 윈도우를 활성화사켜 보여준다

	ShowWindow)
	 윈도우를 화면에 출력한다
	*/
	ShowWindow(hWnd, nCmdShow);

	/*
    메세지 루프 요소)
     BOOL GetMessage( LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax);
      이 함수는 메세지 큐에서 메세지를 읽어들여 lpMsg에 저장한고 만약 메세지가 WM_QUIT일 경우
      False를 리턴하며 그 외에는 모두 True를 리턴하는 함수다. 뒤에 3개의 인자는 메세지 읽는 범위 지정에 사용한다

     BOOL TranslateMessage( CONST MSG *lpMsg);
	  키보드 입력 메시지를 가공하여 프로그램에서 쉽게 쓸 수 있도록 해 준다

     LONG DispatchMessage( CONST MSG *lpmsg);
	  메세지 큐에서 꺼낸 메세지를 'WndProc'으로 전달한다
	*/
	while (GetMessage(&Message, 0, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}


	//WM_QUIT 메세지로부터 전달된 탈출코드 return 0이랑 큰 차이는 없다
	return Message.wParam; 


	/*
	윈도우즈 프로그렘 실행 과정

	1. WndClass 정의 : 윈도우의 기반이 되는 클래스를 정의한다
	2. CreateWindow  : 메모리상에 윈도우를 만든다
	3. ShowWindow    : 윈도우를 화면에 표시한다
	4. 메세지 루프   : 사용자로부터 메세지를 처리한다
	*/
}

/*
메세지 구조체 설명)

typedef struct tagMSG
{
HWND        hwnd;
UINT        message;
WPARAM      wParam;
LPARAM      lParam;
DWORD       time;
POINT       pt;
} MSG;

hwnd    : 메세지를 받을 윈도우 핸들
message : 어떤 종류의 메세지인가를 나타낸다
wParam  : 전달된 메세지에 대한 부가적인 정보
lParam  : 전달된 메세지에 대한 부가적인 정보
time    : 메세지가 발생한 시간
pt      : 메세지가 발생했을 때의 마우스 위치
*/

/*
메세지 종류)
 WM_QUIT        : 프로그램을 끝낼 때 발생하는 메세지
 WM_LBUTTONDOWN : 마우스의 좌축 버튼을 누를 경우 발생
 WM_CHAR        : 키보드로부터 문자가 입력될 때 발생
 WM_PAINT       : 화면을 다시 그려야 할 필요가 있을 때 발생
 WM_DESTROY     : 윈도우가 메모리에서 파괴될 때 발생한다
 WM_CREATE      : 윈도우가 처음 만들어질 때 발생한다
*/

/*
WndProc 인자)
 메세지 구조체에 있는 4개의 값이 들어간다

WndProc 실행 과정)
 1. 케이스에서 메세지를 확인하고 처리한 후 리턴한다
 2. 처리하지 못한 메세지는 DefWindowProc으로 넘겨 처리한다

 WndProc 유의 사항)
 1. 케이스에서 처리 후 'break'가 아닌 'return 0'을 반드시 붙여야 한다
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