#pragma once
#include "WBComponent.h"

namespace wb
{
	class WBCollider : public WBComponent
	{
	public:
		WBCollider();
		~WBCollider();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		math::Vector2 GetOffset() { return mOffset; }
		void SetOffset(math::Vector2 offset) { mOffset = offset; }

	private:
		math::Vector2 mOffset;
	};
}