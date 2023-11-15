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