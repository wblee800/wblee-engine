#include "WBTilemapRenderer.h"
#include "WBGameObject.h"
#include "WBTransform.h"
#include "WBTexture.h"
#include "WBRenderer.h"

namespace wb
{
	WBTilemapRenderer::WBTilemapRenderer()
		:WBComponent(enums::eComponentType::SpriteRenderer),
		mTexture(nullptr),
		mSize(math::Vector2::One),
		mIndex(math::Vector2::One),
		mTileSize(Vector2(16.0f, 16.0f))
	{
	}

	WBTilemapRenderer::~WBTilemapRenderer()
	{
	}

	void WBTilemapRenderer::Initialize()
	{
	}

	void WBTilemapRenderer::Update()
	{
	}

	void WBTilemapRenderer::LateUpdate()
	{
	}

	void WBTilemapRenderer::Render(HDC hdc)
	{
		// If you don't set texture, assert error.
		if (mTexture == nullptr)
			assert(false);

		WBTransform* tr = GetOwner()->GetComponent<WBTransform>();
		Vector2 pos = tr->GetPosition();

		if (renderer::mainCamera)
			pos = renderer::mainCamera->CalculatePos(pos);

		Vector2 scale = tr->GetScale();
		float rotation = tr->GetRotation();

		if (mTexture->GetTextureType()
			== graphics::WBTexture::eTextureType::Bmp)
		{
			TransparentBlt(hdc, 
				pos.x, 
				pos.y, 
				mTileSize.x * mSize.x * scale.x,
				mTileSize.y * mSize.y * scale.y,
				mTexture->GetHdc(), 
				mIndex.x * mTileSize.x, mIndex.y * mTileSize.y,
				mTileSize.x, mTileSize.y,
				RGB(255, 0, 255));
		}
	}

	void WBTilemapRenderer::SetTexture(graphics::WBTexture* texture)
	{
		mTexture = texture;
	}
}