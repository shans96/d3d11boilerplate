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
