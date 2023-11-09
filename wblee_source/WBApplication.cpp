#include "WBApplication.h"

namespace wb
{
	WBApplication::WBApplication()
		:mHwnd(nullptr),
		mHdc(nullptr),
		mSpeed(0.f)
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

		mPlayer.SetPosition(0.f, 0.f);
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
		mPlayer.Update();
	}

	void WBApplication::LateUpdate()
	{

	}

	// Draw a updated logic
	void WBApplication::Render()
	{
		mPlayer.Render(mHdc);
	}
}