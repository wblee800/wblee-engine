#include "WBGameObject.h"
#include "WBInput.h"
#include "WBTime.h"

namespace wb
{
	WBGameObject::WBGameObject()
		: mX(0), mY(0)
	{
	}

	WBGameObject::~WBGameObject()
	{
	}

	void WBGameObject::Update()
	{
		const float speed = 100.0f;
		if (WBInput::GetKey(eKeyCode::A))
		{
			mX -= speed * WBTime::DeltaTime();
		}

		if (WBInput::GetKey(eKeyCode::D))
		{
			mX += speed * WBTime::DeltaTime();
		}

		if (WBInput::GetKey(eKeyCode::W))
		{
			mY -= speed * WBTime::DeltaTime();
		}

		if (WBInput::GetKey(eKeyCode::S))
		{
			mY += speed * WBTime::DeltaTime();
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