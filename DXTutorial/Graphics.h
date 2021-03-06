#pragma once

#include <Windows.h>
#include <d2d1.h>

class Graphics
{
private:
	ID2D1Factory* factory;
	ID2D1HwndRenderTarget* renderTarget;
	ID2D1SolidColorBrush* brush;
	
public:
	Graphics();
	~Graphics();

	bool Init(HWND windowHandle);

	void BeginDraw() { renderTarget->BeginDraw(); }
	void EndDraw() { renderTarget->EndDraw(); }

	void ClearScreen(float r, float g, float b);
	void DrawCircle(float x, float y, float radius, float r, float g, float b, float a, float brushSize, bool fill = false);
	void DrawRectangle(float x, float y, float height, float width, float r, float g, float b, float a, float brushSize, bool fill = false);

};

