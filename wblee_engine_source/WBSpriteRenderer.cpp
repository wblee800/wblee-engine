#include "WBSpriteRenderer.h"
#include "WBGameObject.h"
#include "WBTransform.h"
#include "WBTexture.h"
#include "WBRenderer.h"

namespace wb
{
	WBSpriteRenderer::WBSpriteRenderer()
		: WBComponent(enums::eComponentType::SpriteRenderer)
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
				mTexture->GetWidth() * mSize.x * scale.x, 
				mTexture->GetHeight() * mSize.y * scale.y, 
				mTexture->GetHdc(), 
				0, 0,
				mTexture->GetWidth(), mTexture->GetHeight(), 
				RGB(255, 0, 255));
		}
		else if (mTexture->GetTextureType()
			== graphics::WBTexture::eTextureType::Png)
		{
			// 내가 원하는 픽셀을 투명화 시킬 때,
			Gdiplus::ImageAttributes imgAtt = {};

			// 투명화 시킬 픽셀의 범위
			imgAtt.SetColorKey(Gdiplus::Color(200, 200, 200), Gdiplus::Color(255, 255, 255));

			Gdiplus::Graphics graphics(hdc);
			graphics.DrawImage(mTexture->GetImage()
				, Gdiplus::Rect
				(
					pos.x, pos.y
					, mTexture->GetWidth() * mSize.x * scale.x
					, mTexture->GetHeight() * mSize.y * scale.y
				)
				, 0, 0
				// AlphaBlend와 달리 오른쪽 아래 좌표값을 필요로 한다.
				, mTexture->GetWidth(), mTexture->GetHeight()
				, Gdiplus::UnitPixel
				, nullptr
			);
		}
	}

	void WBSpriteRenderer::SetTexture(graphics::WBTexture* texture)
	{
		mTexture = texture;
	}
}