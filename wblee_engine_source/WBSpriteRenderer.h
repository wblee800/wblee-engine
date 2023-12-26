#pragma once
#include "WBEntity.h"
#include "WBComponent.h"

namespace wb
{
	namespace graphics
	{
		class WBTexture;
	}

	class WBSpriteRenderer : public	WBComponent
	{
	public:
		WBSpriteRenderer();
		~WBSpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTexture(graphics::WBTexture* texture);
		void SetSize(math::Vector2 size) { mSize = size; }

	private:
		graphics::WBTexture* mTexture;
		math::Vector2 mSize;
	};
}