#pragma once
#include "common_include.h"
#include "WBGameObject.h"

namespace wb
{
	class WBApplication
	{
	public:
		WBApplication();
		~WBApplication();

		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		void clearRenderTarget();
		void copyRenderTarget(HDC source, HDC dest);
		void adjustWindowRect(HWND hwnd, UINT width, UINT height);
		void createBuffer(UINT width, UINT height);
		void initializeEtc();

	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;

		float mSpeed;
		UINT mWidth;
		UINT mHeight;
		
		// float mX;
		// float mY;
		WBGameObject mPlayer;
	};
}