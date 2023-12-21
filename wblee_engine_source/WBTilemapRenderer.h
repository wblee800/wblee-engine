#pragma once
#include "WBEntity.h"
#include "WBComponent.h"

namespace wb
{
	namespace graphics
	{
		class WBTexture;
	}

	class WBTilemapRenderer : public WBComponent
	{
	public:
		WBTilemapRenderer();
		~WBTilemapRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTexture(graphics::WBTexture* texture);
		void SetSize(math::Vector2 size) { mSize = size; }
		void SetTileSize(math::Vector2 tileSize) { mTileSize = tileSize; }

	private:
		graphics::WBTexture* mTexture;
		math::Vector2 mSize;
		std::pair<int, int> mIndex;
		math::Vector2 mTileSize;
	};
}