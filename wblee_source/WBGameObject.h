#pragma once
#include "common_include.h"
#include "WBInput.h"

namespace wb
{
	// Unity : Object
	// Unreal : Actor (is same above)
	class WBGameObject
	{
	public:
		WBGameObject();
		~WBGameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}

		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }

	private:
		// Axis of game object
		float mX;
		float mY;
	};
}