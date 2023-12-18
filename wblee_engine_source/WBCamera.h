#pragma once
#include "WBComponent.h"

namespace wb
{
	class WBGameObject;
	class WBCamera : public WBComponent
	{
	public:
		math::Vector2 CalculatePos(math::Vector2 position);

		WBCamera();
		~WBCamera();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetTarget(WBGameObject* target) { mTarget = target; }
		
	private:
		math::Vector2 mDistance;
		math::Vector2 mResolution;
		math::Vector2 mLookPosition;
		WBGameObject* mTarget;
	};
}