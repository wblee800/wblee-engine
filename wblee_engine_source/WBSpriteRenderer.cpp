#include "WBSpriteRenderer.h"
#include "WBGameObject.h"
#include "WBTransform.h"
#include "WBTexture.h"

namespace wb
{
	WBSpriteRenderer::WBSpriteRenderer()
		: WBComponent()
		, mTexture(nullptr)
		, mSize(Vector2::One)
	{
	}

	WBSpriteRenderer::~WBSpriteRenderer()
	{
	}

	void WBSpriteRenderer::Initialize()
	{
	}

	void WBSpriteRenderer::Update()
	{
	}

	void WBSpriteRenderer::LateUpdate()
	{
	}

	void WBSpriteRenderer::Render(HDC hdc)
	{
		// If you don't set texture, assert error.
		if (mTexture == nullptr)
			assert(false);

		WBTransform* tr = GetOwner()->GetComponent<WBTransform>();
		Vector2 pos = tr->GetPos();

		if (mTexture->GetTextureType()
			== graphics::WBTexture::eTextureType::Bmp)
		{
			TransparentBlt(hdc, pos.x, pos.y
				, mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y
				, mTexture->GetHdc(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight(), RGB(255, 0, 255));
		}
		else if (mTexture->GetTextureType()
			== graphics::WBTexture::eTextureType::Png)
		{
			Gdiplus::Graphics graphics(hdc);
			graphics.DrawImage(mTexture->GetImage()
				, Gdiplus::Rect(pos.x, pos.y, mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y));
		}
	}

	void WBSpriteRenderer::SetTexture(graphics::WBTexture* texture)
	{
		mTexture = texture;
	}
}