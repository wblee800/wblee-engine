#pragma once
#include "WBComponent.h"

namespace wb
{
	class WBTransform : public WBComponent
	{
	public:
		WBTransform();
		~WBTransform();

		void Initialize();
		void Update();
		void LateUpdate();
		void Render();

		void SetPos(int x, int y) { mX = x; mY = y; }
		int GetX() { return mX; }
		int GetY() { return mY; }
		
	private:
		int mX;
		int mY;
	};
}