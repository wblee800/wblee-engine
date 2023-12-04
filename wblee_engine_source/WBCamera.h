#pragma once
#include "WBComponent.h"

namespace wb
{
	class WBGameObject;
	class WBCamera : public WBComponent
	{
	public:
		math::Vector2 CalculatePos(math::Vector2 pos);

		WBCamera();
		~WBCamera();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
	private:
		// std::vector<WBGameObject*> mGameObjects;
		math::Vector2 mDistance;
		math::Vector2 mResolution;
		math::Vector2 mLookPos;
		WBGameObject* mTarget;
	};
}