#include "WBApplication.h"

namespace wb
{
	WBApplication::WBApplication()
		:mHwnd(nullptr),
		mHdc(nullptr),
		mSpeed(0.f),
		mX(0.f),
		mY(0.f)
	{

	}

	WBApplication::~WBApplication()
	{

	}

	// Save a handle's address value and DC's address value
	void WBApplication::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
	}

	// Execute update and render function
	void WBApplication::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	// Update a logic
	void WBApplication::Update()
	{
		mSpeed += 0.01f;

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

	void WBApplication::LateUpdate()
	{

	}

	// Draw a updated logic
	void WBApplication::Render()
	{
		// Select a red brush
		HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));

		// Select a red brush in DC and return a white brush
		HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, redBrush);

		// Draw a rectangle
		Rectangle(mHdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		// Select the origin white brush again
		SelectObject(mHdc, oldBrush);

		// Delete the red brush
		DeleteObject(redBrush);
	}
}