#include "pch.h"

HWND	  windowInstance = 0;
LPCTSTR   wndName = "window";
const int wndWidth = 1920;
const int wndHeight = 1080;

bool InitializeWindow(HINSTANCE instanceHandle, int display, int width, int height, bool windowed)
{
	WNDCLASS windowClass;
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = WndProc;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = instanceHandle;
	windowClass.hIcon = LoadIcon(0, IDI_APPLICATION);
	windowClass.hCursor = LoadCursor(0, IDC_ARROW);
	windowClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	windowClass.lpszMenuName = 0;
	windowClass.lpszClassName = "BasicWndClass";

	if (!RegisterClass(&windowClass)) 
	{
		MessageBox(0, "RegisterClass- FAILED", 0, 0);
		return false;
	}

	windowInstance = CreateWindow(
		"BasicWndClass", 
		"d3d11boilerplate", 
		WS_OVERLAPPEDWINDOW, 
		CW_USEDEFAULT, 
		CW_USEDEFAULT, 
		CW_USEDEFAULT, 
		CW_USEDEFAULT, 
		0,
		0,
		instanceHandle, 
		0);
	if (windowInstance == 0) 
	{
		MessageBox(0, "CreateWindow FAILED", 0, 0);
		return false;
	}
	ShowWindow(windowInstance, display);
	UpdateWindow(windowInstance);
	return true;
}

int RunMessageLoop() {

	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	BOOL bRet = 1;
	while ((bRet = GetMessage(&msg, 0, 0, 0)) != 0)
	{
		if (bRet == -1)
		{
			MessageBox(0, "GetMessage FAILED", "Error", MB_OK);
			break;
		}
		else
		{
			DrawScene();
			UpdateScene();
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)  
{
	switch (msg)
	{
	case WM_LBUTTONDOWN:
		MessageBox(0, "Hello, World", "Hello", MB_OK);
		return 0;
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
			DestroyWindow(windowInstance);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

