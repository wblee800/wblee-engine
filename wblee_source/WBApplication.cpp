#include "WBApplication.h"
#include "wBInput.h"
#include "wBTime.h"

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

		WBInput::Initialize();
		WBTime::Initialize();
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
		WBInput::Update();
		WBTime::Update();

		mPlayer.Update();
	}

	void WBApplication::LateUpdate()
	{

	}

	// Draw a updated logic
	void WBApplication::Render()
	{
		WBTime::Render(mHdc);
		mPlayer.Render(mHdc);
	}
}