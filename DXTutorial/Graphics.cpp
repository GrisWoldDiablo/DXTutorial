#include "Graphics.h"

Graphics::Graphics() : 
	factory(NULL), 
	renderTarget(NULL),
	brush(NULL)
{
	// Constructor code
}

Graphics::~Graphics()
{
	if (factory)
	{
		factory->Release();
	}

	if (renderTarget)
	{
		renderTarget->Release();
	}

	if (brush)
	{
		brush->Release();
	}
}

bool Graphics::Init(HWND windowHandle)
{
	HRESULT res = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &factory);
	if (res != S_OK)
	{
		return false;
	}

	RECT rect;
	GetClientRect(windowHandle, &rect);

	res = factory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(
			windowHandle, D2D1::SizeU(rect.right, rect.bottom)),
		&renderTarget);

	if (res != S_OK)
	{
		return false;
	}

	res = renderTarget->CreateSolidColorBrush(D2D1::ColorF(0, 0, 0, 0), &brush);

	if (res != S_OK)
	{
		return false;
	}

	return true;
}

void Graphics::ClearScreen(float r, float g, float b)
{
	renderTarget->Clear(D2D1::ColorF(r, g, b));
}

void Graphics::DrawCircle(float x, float y, float radius, float r, float g, float b, float a, float brushSize, bool fill)
{
	brush->SetColor(D2D1::ColorF(r, g, b, a));
	if (fill)
	{
		renderTarget->FillEllipse(D2D1::Ellipse(D2D1::Point2F(x, y), radius, radius), brush);
	}
	else
	{
		renderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(x, y), radius, radius), brush, brushSize);
	}
}

void Graphics::DrawRectangle(float x, float y, float height, float width, float r, float g, float b, float a, float brushSize, bool fill)
{
	brush->SetColor(D2D1::ColorF(r, g, b, a));
	if (fill)
	{
		renderTarget->FillRectangle(D2D1::Rect(x, y, x + width, y + height), brush);
	}
	else
	{
		renderTarget->DrawRectangle(D2D1::Rect(x, y, x + width, y + height), brush, brushSize);
	}
}

