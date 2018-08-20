#pragma once
#include "pch.h"

IDXGISwapChain*		    swapChain;
ID3D11Device*		    d3d11Device;
ID3D11DeviceContext*    d3d11DeviceContext;
ID3D11RenderTargetView* d3d11RenderTargetView;
ID3D11Texture2D*		backBuffer; 

bool InitializeDirect3d11App(HINSTANCE hInstance) 
{
	HRESULT				 d3d11hResult; 
	DXGI_MODE_DESC		 dxgiBufferDesc; 
	DXGI_SWAP_CHAIN_DESC dxgiSwapChainDesc;

	ZeroMemory(&dxgiBufferDesc, sizeof(DXGI_MODE_DESC));

	dxgiBufferDesc.Width = wndWidth;
	dxgiBufferDesc.Height = wndHeight;
	dxgiBufferDesc.RefreshRate.Numerator = 60;
	dxgiBufferDesc.RefreshRate.Denominator = 1;
	dxgiBufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM; 
	dxgiBufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	dxgiBufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

	ZeroMemory(&dxgiSwapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC)); 

	dxgiSwapChainDesc.BufferDesc = dxgiBufferDesc;
	dxgiSwapChainDesc.SampleDesc.Count = 1;
	dxgiSwapChainDesc.SampleDesc.Quality = 0;
	dxgiSwapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	dxgiSwapChainDesc.BufferCount = 1;
	dxgiSwapChainDesc.OutputWindow = windowInstance;
	dxgiSwapChainDesc.Windowed = TRUE;
	dxgiSwapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	dxgiSwapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH; 

	d3d11hResult = D3D11CreateDeviceAndSwapChain(NULL, 
		D3D_DRIVER_TYPE_HARDWARE, 
		NULL, 
		NULL, 
		NULL, 
		NULL, 
		D3D11_SDK_VERSION, 
		&dxgiSwapChainDesc, 
		&swapChain, 
		&d3d11Device, 
		NULL, 
		&d3d11DeviceContext);
		
		if (FAILED(d3d11hResult)) {
		MessageBox(NULL, "Create SwapChain- FAILED", "D3D11CreateDeviceAndSwapChain", MB_OK);
		return 0;
		}

	d3d11hResult = swapChain->GetBuffer(0, 
		__uuidof(ID3D11Texture2D),  
		(void**)&backBuffer); 

	d3d11hResult = d3d11Device->CreateRenderTargetView(backBuffer, 
		NULL, 
		&d3d11RenderTargetView); 
	backBuffer->Release();

	d3d11DeviceContext->OMSetRenderTargets(1, 
		&d3d11RenderTargetView, 
		NULL); 

	return true;
}

void ReleaseObjects () 
{
	swapChain->Release();
	d3d11Device->Release();
	d3d11DeviceContext->Release();
}

bool InitializeScene() {
	return true;
}

bool UpdateScene()
{
	return true;
}

bool DrawScene() 
{
	float bgColor [4] = { 0.00005f, 0.00002f, 0.00001f, 1.0f };
	d3d11DeviceContext->ClearRenderTargetView(d3d11RenderTargetView, bgColor);
	swapChain->Present(0, 0);

	return true;
}