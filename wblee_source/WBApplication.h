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

		void Initialize(HWND hwnd);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		float mSpeed;
		
		// float mX;
		// float mY;
		WBGameObject mPlayer;
	};
}