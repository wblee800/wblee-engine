#pragma once
#include "WBComponent.h"

namespace wb
{
	class WBSpriteRenderer : public	WBComponent
	{
	public:
		WBSpriteRenderer();
		~WBSpriteRenderer();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;
	};
}