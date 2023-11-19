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
		// Back Buffer�� �ִ� �����͸� ���� Buffer�� ����
		// (��, Back Buffer�� �׸��� ���� Buffer�� �Ű� �׸���.)
		BitBlt(dest, 0, 0, mWidth, mHeight,
			source, 0, 0, SRCCOPY);
	}

	void WBApplication::adjustWindowRect(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		// �簢�� ũ�� ����
		RECT rect = { 0, 0, width, height };
		// ������ �۾� ���� ũ�� ����
		// 1. ������ ũ��
		// 2. ������ ��Ÿ��
		// 3. �޴���
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		// ������ ���� ��ġ ����
		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		// ������ ����
		ShowWindow(mHwnd, true);
	}

	void WBApplication::createBuffer(UINT width, UINT height)
	{
		// ������ �ػ󵵿� �´� Back Buffer ����
		// (�׸����� ���� ��� ��ȭ��)
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		// Back Buffer�� ����ų DC ����
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