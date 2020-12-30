#include "MyGUICalc.h"

template <typename T>
T NUMBER(T x, T y)
{
	if ((x >= 50 && x <= 170) && (y >= 230 && y <= 270))
		return 10;
	else if ((x >= 50 && x <= 100) && (y >= 170 && y <= 220))
		return 1;
	else if ((x >= 110 && x <= 160) && (y >= 170 && y <= 220))
		return 2;
	else if ((x >= 170 && x <= 220) && (y >= 170 && y <= 220))
		return 3;

	else if ((x >= 50 && x <= 100) && (y >= 110 && y <= 160))
		return 4;
	else if ((x >= 110 && x <= 160) && (y >= 110 && y <= 160))
		return 5;
	else if ((x >= 170 && x <= 220) && (y >= 110 && y <= 160))
		return 6;

	else if ((x >= 50 && x <= 100) && (y >= 50 && y <= 100))
		return 7;
	else if ((x >= 110 && x <= 160) && (y >= 50 && y <= 100))
		return 8;
	else if ((x >= 170 && x <= 220) && (y >= 50 && y <= 100))
		return 9;

	else if ((x >= 250 && x <= 300) && (y >= 50 && y <= 100))  // *
		return '*';
	else if ((x >= 250 && x <= 300) && (y >= 110 && y <= 160)) // /
		return '/';
	else if ((x >= 250 && x <= 300) && (y >= 170 && y <= 220)) // +
		return '+';
	else if ((x >= 250 && x <= 300) && (y >= 230 && y <= 280)) // -
		return '-';

	else if ((x >= 200 && x <= 300) && (y >= 300 && y <= 350)) //OK
		return 'o';
	else return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static __int64 operNum = 0;
	static __int64 getNum1 = 0;
	static __int64 getNum2 = 0;

	static char oper=0;
	TCHAR getOper[2] = { 0 }; //oper를 -> TCHAR*로 변환하기 위함
	TCHAR firstNum[1024] = { 0 }; //숫자 -> 스트링형 저장
	TCHAR secondNum[1024] = { 0 };

	static bool isNumber2=false; //두번째 피연산자 설정
	static bool isOK = false;
	static bool isClear = false;

	HBRUSH Brush, oBrush; //그리기
	switch (uMsg) {

	case WM_LBUTTONDOWN: 
		hdc = GetDC(hWnd);
		Brush = (HBRUSH)CreateSolidBrush(RGB(100, 200, 0));
		oBrush = (HBRUSH)SelectObject(hdc, Brush);

		if (NUMBER(LOWORD(lParam), HIWORD(lParam)) == 10) //좌표
		{	
			operNum = 0;
			Rectangle(hdc, 50, 230, 170, 270);
			TextOut(hdc, 110, 250, L"0", 1); 
		}
		else if (NUMBER(LOWORD(lParam), HIWORD(lParam)) == 1) //좌표
		{
			operNum = 1;
			Rectangle(hdc, 50, 170, 100, 220);
			TextOut(hdc, 75, 198, L"1", 1);
		}
		else if (NUMBER(LOWORD(lParam), HIWORD(lParam)) == 2) //좌표
		{
			operNum = 2;
			Rectangle(hdc, 110, 170, 160, 220);
			TextOut(hdc, 135, 195, L"2", 1); 
		}
		else if (NUMBER(LOWORD(lParam), HIWORD(lParam)) == 3) //좌표
		{
			operNum = 3;
			Rectangle(hdc, 170, 170, 220, 220);
			TextOut(hdc, 195, 195, L"3", 1); 
		}
		else if (NUMBER(LOWORD(lParam), HIWORD(lParam)) == 4) //좌표
		{
			operNum = 4;
			Rectangle(hdc, 50, 110, 100, 160);
			TextOut(hdc, 75, 135, L"4", 1);
		}
		else if (NUMBER(LOWORD(lParam), HIWORD(lParam)) == 5) //좌표
		{
			operNum = 5;
			Rectangle(hdc, 110, 110, 160, 160);
			TextOut(hdc, 135, 135, L"5", 1);
		}
		else if (NUMBER(LOWORD(lParam), HIWORD(lParam)) == 6) //좌표
		{
			operNum = 6;
			Rectangle(hdc, 170, 110, 220, 160);
			TextOut(hdc, 195, 135, L"6", 1); 
		}
		else if (NUMBER(LOWORD(lParam), HIWORD(lParam)) == 7) //좌표
		{
			operNum = 7;
			Rectangle(hdc, 50, 50, 100, 100);
			TextOut(hdc, 75, 75, L"7", 1); 
		}
		else if (NUMBER(LOWORD(lParam), HIWORD(lParam)) == 8) //좌표
		{
			operNum = 8;
			Rectangle(hdc, 110, 50, 160, 100);
			TextOut(hdc, 135, 75, L"8", 1);
		}
		else if (NUMBER(LOWORD(lParam), HIWORD(lParam)) == 9) //좌표
		{
			operNum = 9;
			Rectangle(hdc, 170, 50, 220, 100);
			TextOut(hdc, 195, 75, L"9", 1); 
		}
		//사칙연산 처리
		else if ((NUMBER(LOWORD(lParam), HIWORD(lParam)) == '*'|| NUMBER(LOWORD(lParam), HIWORD(lParam)) == '/')||
					(NUMBER(LOWORD(lParam), HIWORD(lParam)) == '+'|| NUMBER(LOWORD(lParam), HIWORD(lParam)) == '-'))
		{
			switch (NUMBER(LOWORD(lParam), HIWORD(lParam)))
			{
			case '*':
				Rectangle(hdc, 250, 50, 300, 100);
				TextOut(hdc, 275, 75, L"*", 1);
				break;
			case '/':
				Rectangle(hdc, 250, 110, 300, 160);
				TextOut(hdc, 275, 135, L"/", 1);
				break;
			case '+':
				Rectangle(hdc, 250, 170, 300, 220);
				TextOut(hdc, 275, 195, L"+", 1);
				break;
			case '-':
				Rectangle(hdc, 250, 230, 300, 280);
				TextOut(hdc, 275, 255, L"-", 1);
				break;
			}
			oper = NUMBER(LOWORD(lParam), HIWORD(lParam));
			isNumber2 = true; //사칙연산 -> 두번째 변수 사용
		}

		else if ((NUMBER(LOWORD(lParam), HIWORD(lParam)) == 'o'))
		{
			isOK = true;
			Rectangle(hdc, 200, 300, 300, 350);
			TextOut(hdc, 250, 325, L"OK", 2);
		}

		else TextOut(hdc, 100, 450, L"사각형을 클릭하세요", 10);

		if (NUMBER(LOWORD(lParam), HIWORD(lParam)) >= 1 && NUMBER(LOWORD(lParam), HIWORD(lParam)) <= 10)
		{
			if (isNumber2)
			{
				getNum2 *= 10; //자리수 곱함
				getNum2 += operNum; //수를 얻고
			}
			else 
			{
				getNum1 *= 10; //자리수 곱함
				getNum1 += operNum; //수를 얻고
			}
		}

		SelectObject(hdc, oBrush);
		DeleteObject(Brush);
		ReleaseDC(hWnd, hdc);
		return 0;

	case WM_LBUTTONUP:
		InvalidateRect(hWnd, NULL, TRUE);

	case WM_PAINT:
		if (isOK) //OK 이벤트
		{
			//char asd = NUMBER(LOWORD(lParam), HIWORD(lParam));
			if (oper == '*')
				getNum1 = getNum1 * getNum2;
			else if (oper == '/')
			{
				if (getNum2 == 0)
					getNum1 = 0;
				else
				getNum1 = getNum1 / getNum2;
				
			}
			else if (oper == '+')
				getNum1 = getNum1 + getNum2;
			else if (oper == '-')
				getNum1 = getNum1 - getNum2;
			
			getNum2 = 0;
			isNumber2 = false;
			isOK = false;
		}
		
		hdc = BeginPaint(hWnd, &ps);
		wsprintf(firstNum, TEXT("%I64d"), getNum1);
		TextOut(hdc, 10, 10, firstNum, lstrlen(firstNum));
		
		if (isNumber2) //연산자 입력이벤트
		{
			wsprintf(getOper, TEXT("%c"), oper);
			TextOut(hdc, 10 + (8 * lstrlen(firstNum)), 10, getOper, lstrlen(getOper));
			wsprintf(secondNum, TEXT("%I64d"), getNum2);
			TextOut(hdc, 16 + (8 * lstrlen(firstNum)), 10, secondNum, lstrlen(secondNum));
		}

		Rectangle(hdc, 50, 50, 100, 100);
		TextOut(hdc, 75, 75, L"7", 1);
		Rectangle(hdc, 110, 50, 160, 100);
		TextOut(hdc, 135, 75, L"8", 1);
		Rectangle(hdc, 170, 50, 220, 100);
		TextOut(hdc, 195, 75, L"9", 1);

		Rectangle(hdc, 50, 110, 100, 160);
		TextOut(hdc, 75, 135, L"4", 1);
		Rectangle(hdc, 110, 110, 160, 160);
		TextOut(hdc, 135, 135, L"5", 1);
		Rectangle(hdc, 170, 110, 220, 160);
		TextOut(hdc, 195, 135, L"6", 1);

		Rectangle(hdc, 50, 170, 100, 220);
		TextOut(hdc, 75, 198, L"1", 1);
		Rectangle(hdc, 110, 170, 160, 220);
		TextOut(hdc, 135, 195, L"2", 1);
		Rectangle(hdc, 170, 170, 220, 220);
		TextOut(hdc, 195, 195, L"3", 1);

		Rectangle(hdc, 50, 230, 170, 270);
		TextOut(hdc, 110, 250, L"0", 1);

		Rectangle(hdc, 250, 50, 300, 100);
		TextOut(hdc, 275, 75, L"*", 1);
		Rectangle(hdc, 250, 110, 300, 160);
		TextOut(hdc, 275, 135, L"/", 1);
		Rectangle(hdc, 250, 170, 300, 220);
		TextOut(hdc, 275, 195, L"+", 1);
		Rectangle(hdc, 250, 230, 300, 280);
		TextOut(hdc, 275, 255, L"-", 1);

		Rectangle(hdc, 200, 300, 300, 350);
		TextOut(hdc, 250, 325, L"OK", 2);

		//Rectangle(hdc, 100, 360, 300, 400);
		//TextOut(hdc, 200, 380, L"Clear", 5);

		EndPaint(hWnd, &ps);
		return 0;
	}

	if (uMsg == WM_DESTROY) PostQuitMessage(0);
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int MyGUICalc::Calculation()
{
	WNDCLASS wc;

	wc.cbClsExtra = NULL;
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = L"계산기";
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW; RegisterClass(&wc);

	RegisterClass(&wc);

	HWND hWnd = CreateWindow(L"계산기", L"MyCalc", WS_OVERLAPPEDWINDOW, 100, 90, 400, 600, NULL, NULL, hInstance, NULL);
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}
