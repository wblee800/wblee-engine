#include "WBApplication.h"
#include "WBInput.h"
#include "WBTime.h"

namespace wb
{
	WBApplication::WBApplication()
		:mHwnd(nullptr),
		mHdc(nullptr),
		mSpeed(0.f),
		mWidth(0),
		mHeight(0),
		mBackHdc(NULL),
		mBackBitmap(NULL)
	{

	}

	WBApplication::~WBApplication()
	{

	}

	// Save a handle's address value and DC's address value
	void WBApplication::Initialize(HWND hwnd, UINT width, UINT height)
	{
		adjustWindowRect(hwnd, width, height);
		createBuffer(width, height);
		initializeEtc();

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
		clearRenderTarget();

		WBTime::Render(mBackHdc);
		mPlayer.Render(mBackHdc);

		copyRenderTarget(mBackHdc, mHdc);
	}

	void WBApplication::clearRenderTarget()
	{
		// clear
		Rectangle(mBackHdc, -1, -1, 1601, 901);
	}

	void WBApplication::copyRenderTarget(HDC source, HDC dest)
	{
		// Back Buffer에 있는 데이터를 원본 Buffer에 복사
		// (즉, Back Buffer의 그림을 원본 Buffer에 옮겨 그린다.)
		BitBlt(dest, 0, 0, mWidth, mHeight,
			source, 0, 0, SRCCOPY);
	}

	void WBApplication::adjustWindowRect(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		// 사각형 크기 지정
		RECT rect = { 0, 0, width, height };
		// 윈도우 작업 영역 크기 지정
		// 1. 윈도우 크기
		// 2. 윈도우 스타일
		// 3. 메뉴바
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		// 윈도우 오픈 위치 지정
		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		// 윈도우 오픈
		ShowWindow(mHwnd, true);
	}

	void WBApplication::createBuffer(UINT width, UINT height)
	{
		// 윈도우 해상도에 맞는 Back Buffer 생성
		// (그림으로 예를 들면 도화지)
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		// Back Buffer를 가리킬 DC 생성
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);
	}

	void WBApplication::initializeEtc()
	{
		WBInput::Initialize();
		WBTime::Initialize();
	}
}