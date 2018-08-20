#pragma once
#include "pch.h"

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	if (!InitializeWindow(hInstance, SW_SHOW, wndWidth, wndHeight, true))
	{
		MessageBox(0, "Create Window- FAILED", "Error", MB_OK);
		return 0;
	}
	if (!InitializeDirect3d11App(hInstance))
	{
		MessageBox(0, "Initialize Direct3D 11- FAILED", "Error", MB_OK);
		return 0;
	}
	if (!InitializeScene()) 
	{
		MessageBox(0, "Initialize Scene- FAILED", "Error", MB_OK);
		return 0;
	}

	RunMessageLoop();

	ReleaseObjects();
	return 0;
}