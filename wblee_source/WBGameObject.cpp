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
		if (WBInput::GetKey(eKeyCode::A))
		{
			mX -= 0.01f;
		}

		if (WBInput::GetKey(eKeyCode::D))
		{
			mX += 0.01f;
		}

		if (WBInput::GetKey(eKeyCode::W))
		{
			mY -= 0.01f;
		}

		if (WBInput::GetKey(eKeyCode::S))
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
		HBRUSH greenBrush = CreateSolidBrush(RGB(255, 0, 0));

		// Select a red brush in DC and return a white brush
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, greenBrush);

		// Draw a rectangle
		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		// Select the origin white brush again
		SelectObject(hdc, oldBrush);

		// Delete the red brush
		DeleteObject(greenBrush);
	}
}