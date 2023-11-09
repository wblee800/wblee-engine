#include "WBGameObject.h"

namespace wb
{
	WBGameObject::WBGameObject()
	{
	}

	WBGameObject::~WBGameObject()
	{
	}

	void WBGameObject::Update()
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x80000)
		{
			mX -= 0.01f;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x80000)
		{
			mX += 0.01f;
		}

		if (GetAsyncKeyState(VK_UP) & 0x80000)
		{
			mY -= 0.01f;
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x80000)
		{
			mY += 0.01f;
		}
	}

	void WBGameObject::LateUpdate()
	{

	}

	void WBGameObject::Render(HDC hdc)
	{
		// Select a red brush
		HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));

		// Select a red brush in DC and return a white brush
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, redBrush);

		// Draw a rectangle
		float x = GetPositionX();
		float y = GetPositionY();
		Rectangle(hdc, 100 + x, 100 + y, 200 + x, 200 + y);

		// Select the origin white brush again
		SelectObject(hdc, oldBrush);

		// Delete the red brush
		DeleteObject(redBrush);
	}
}