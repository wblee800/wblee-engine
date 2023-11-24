#pragma once
#include "WBComponent.h"

namespace wb
{
	using namespace math;
	class WBTransform : public WBComponent
	{
	public:
		WBTransform();
		~WBTransform();

		void Initialize();
		void Update();
		void LateUpdate();
		void Render();

		void SetPos(Vector2 pos) { mPosition.x = pos.x; mPosition.y = pos.y; }
		Vector2 GetPos() { return mPosition; }

	private:
		Vector2 mPosition;
	};
}