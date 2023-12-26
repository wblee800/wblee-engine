#pragma once
#include "WBCollider.h"

namespace wb
{
	class WBCircleCollider2D : public WBCollider
	{
	public:
		WBCircleCollider2D();
		~WBCircleCollider2D();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		math::Vector2 mSize;
	};
}