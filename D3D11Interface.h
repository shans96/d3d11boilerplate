#pragma once
#include "pch.h"

extern HRESULT				d3d11hResult; 
extern DXGI_MODE_DESC		dxgiBufferDesc; 
extern DXGI_SWAP_CHAIN_DESC	dxgiSwapChainDesc; 
bool						InitializeDirect3d11App(HINSTANCE hInstance);
void						ReleaseObjects(); 
bool						InitializeScene(); 
bool						UpdateScene(); 
bool						DrawScene(); 

struct _DXGI_MODE_DESC {
  UINT                     Width;
  UINT                     Height;
  DXGI_RATIONAL            RefreshRate;
  DXGI_FORMAT              Format; 
  DXGI_MODE_SCANLINE_ORDER ScanlineOrdering;
  DXGI_MODE_SCALING        Scaling;
};

struct _DXGI_SWAP_CHAIN_DESC {
	_DXGI_MODE_DESC  BufferDesc;
	DXGI_SAMPLE_DESC SampleDesc; 
	DXGI_USAGE       BufferUsage; 
	UINT             BufferCount; 
	HWND             OutputWindow; 
	BOOL             Windowed;
	DXGI_SWAP_EFFECT SwapEffect; 
	UINT             Flags; 
};

