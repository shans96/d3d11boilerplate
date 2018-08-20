#pragma once
#include "pch.h"

extern WNDCLASS	 windowClass;
extern HWND		 windowInstance; 
extern LPCSTR	 wndName;
extern const int wndWidth;
extern const int wndHeight;
bool			 InitializeWindow(HINSTANCE instanceHandle, int showWindow, int width, int height, bool windowed); 
int				 RunMessageLoop();
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
int WINAPI		 WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);

struct _WNDCLASS {
	UINT	cbSize; 
	UINT	style; 
	WNDPROC lpfnWndProc; 
	int		cbClsExtra; 
	int		cbWndExtra; 
	HANDLE	hInstance; 
	HICON	hIcon; 
	HCURSOR hCursor; 
	HBRUSH	hbrBackground; 
	LPCTSTR lpszMenuName; 
	LPCSTR	lpszClassName; 
};

