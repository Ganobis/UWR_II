#include <windows.h>
#include <string.h>

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
char szClassName[] = "zad2";

int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance,
	LPSTR lpszArgument, int nFunsterStil)
{
	HWND hwnd;
	MSG messages;
	WNDCLASSEX wincl;


	wincl.hInstance = hThisInstance;
	wincl.lpszClassName = szClassName;
	wincl.lpfnWndProc = WindowProcedure;
											
	wincl.style = CS_DBLCLKS;
	wincl.cbSize = sizeof(WNDCLASSEX);


	wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
	wincl.lpszMenuName = NULL;
	wincl.cbClsExtra = 0;
	wincl.cbWndExtra = 0;

	wincl.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);


	if (!RegisterClassEx(&wincl)) return 0;


	hwnd = CreateWindowEx(
		0,
		szClassName,
		"zad2",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		1024,
		100,
		HWND_DESKTOP,
		NULL,
		hThisInstance,
		NULL
	);

	ShowWindow(hwnd, nFunsterStil);
	SetTimer(hwnd, 1, 4, NULL);
	while (GetMessage(&messages, NULL, 0, 0))
	{
		TranslateMessage(&messages);
		DispatchMessage(&messages);
	}

	return messages.wParam;
}

int xSize, ySize, xPos = 50, yPos = 50, yDir = 1, xDir = 1, radius = 5;
RECT r;


LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	char sText[] = "circle";
	HDC         hdc; 
	int         i;
	PAINTSTRUCT ps;

	HPEN   hPen;
	HBRUSH hBrush;

	switch (message)
	{
	case WM_TIMER:
		if (xPos - radius <= 0) xDir = 1;
		if (xPos + radius >= xSize) xDir = -1;
		if (yPos - radius <= 0) yDir = 1;
		if (yPos + radius >= ySize) yDir = -1;
		xPos += xDir * 2;
		yPos += yDir * 2;
		hdc = GetDC(hwnd);
		FillRect(hdc, &r, (HBRUSH)GetStockObject(WHITE_BRUSH));

		hPen = CreatePen(PS_SOLID, 10, RGB(0, 125, 125));
		SelectObject(hdc, hPen);
		Ellipse(hdc, xPos - radius, yPos - radius, xPos + radius, yPos + radius);
		ReleaseDC(hwnd, hdc);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_SIZE:
		xSize = LOWORD(lParam);
		ySize = HIWORD(lParam);

		GetClientRect(hwnd, &r);
		InvalidateRect(hwnd, &r, 1);

		break;


	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}