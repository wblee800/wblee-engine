#pragma once
#include "WBCollider.h"

namespace wb
{
	class WBBoxCollider2D : public WBCollider
	{
	public:
		WBBoxCollider2D();
		~WBBoxCollider2D();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetSize(math::Vector2 size) { mSize = size; }

	private:
		math::Vector2 mSize;
	};
}