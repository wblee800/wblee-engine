#include "WBAnimation.h"
#include "WBAnimator.h"
#include "WBTime.h"
#include "WBTransform.h"
#include "WBGameObject.h"
#include "WBRenderer.h"
#include "WBTexture.h"

namespace wb
{
	WBAnimation::WBAnimation()
		: WBResource(enums::eResourceType::Animation)
		, mAnimator(nullptr)
		, mTexture(nullptr)
		, mAnimationSheet{}
		, mIndex(-1)
		, mTime(0.0f)
		, mbComplete(false)
	{
	}

	WBAnimation::~WBAnimation()
	{
	}

	HRESULT WBAnimation::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}

	void WBAnimation::Update()
	{
		if (mbComplete)
			return;

		mTime += WBTime::DeltaTime();
		if (mAnimationSheet[mIndex].duration < mTime)
		{
			mTime = 0.0f;

			if (mIndex < mAnimationSheet.size() - 1)
				mIndex++;
			else
				mbComplete = true;
		}
	}

	void WBAnimation::Render(HDC hdc)
	{
		if (mTexture == nullptr)
			return;

		WBGameObject* gameObj = mAnimator->GetOwner();
		WBTransform* tr = gameObj->GetComponent<WBTransform>();
		Vector2 pos = tr->GetPos();

		Vector2 scale = tr->GetScale();
		float rotation = tr->GetRotation();

		if (renderer::mainCamera)
			pos = renderer::mainCamera->CalculatePos(pos);

		Sprite sprite = mAnimationSheet[mIndex];
		graphics::WBTexture::eTextureType type = mTexture->GetTextureType();
		if (type == graphics::WBTexture::eTextureType::Bmp)
		{
			BLENDFUNCTION func = {};
			func.BlendOp = AC_SRC_OVER;
			func.BlendFlags = 0;
			func.AlphaFormat = AC_SRC_ALPHA;
			// 0(transparent) ~ 255(Opaque)
			func.SourceConstantAlpha = 150;

			HDC imgHdc = mTexture->GetHdc();

			AlphaBlend(hdc
				// 메인 카메라 위치
				, pos.x - (sprite.size.x / 2.0f), pos.y - (sprite.size.y / 2.0f)
				// 스프라이트 크기 지정
				, sprite.size.x * scale.x
				, sprite.size.y * scale.y
				, imgHdc
				// 어디서부터
				, sprite.leftTop.x
				, sprite.leftTop.y
				// 얼만큼의 크기로 그릴 건지 설정
				, sprite.size.x
				, sprite.size.y
				, func);
		}
		else if (type == graphics::WBTexture::eTextureType::Png)
		{
			// 내가 원하는 픽셀을 투명화 시킬 때,
			Gdiplus::ImageAttributes imgAtt = {};

			// 투명화 시킬 픽셀의 색 범위
			imgAtt.SetColorKey(Gdiplus::Color(100, 100, 100), Gdiplus::Color(255, 255, 255));

			Gdiplus::Graphics graphics(hdc);
			graphics.DrawImage(mTexture->GetImage()
				, Gdiplus::Rect
				(
					pos.x - (sprite.size.x / 2.0f), pos.y - (sprite.size.y / 2.0f), sprite.size.x * scale.x, sprite.size.y * scale.y
				)
				, sprite.leftTop.x
				, sprite.leftTop.y
				// AlphaBlend와 달리 오른쪽 아래 좌표값을 필요로 한다.
				, sprite.size.x
				, sprite.size.y
				, Gdiplus::UnitPixel
				// https://learn.microsoft.com/en-us/windows/win32/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawimage(image_constpoint_int_int_int_int_int_unit_constimageattributes_drawimageabort_void)
				// 기본값은 NULL, 투명화 하고 싶은 색이 있을 때, Gdiplus::ImageAttributes 사용
				, nullptr
			);
		}
	}

	void WBAnimation::CreateAnimation(const std::wstring& name, graphics::WBTexture* spriteSheet, math::Vector2 leftTop, math::Vector2 size, math::Vector2 offset, UINT spriteLength, float duration)
	{
		mTexture = spriteSheet;
		for (size_t i = 0; i < spriteLength; i++)
		{
			Sprite sprite = {};
			sprite.leftTop.x = leftTop.x + (size.x * i);
			sprite.leftTop.y = leftTop.y;
			sprite.size = size;
			sprite.offset = offset;
			sprite.duration = duration;

			mAnimationSheet.push_back(sprite);
		}
	}

	void WBAnimation::Reset()
	{
		mIndex = 0;
		mTime = 0.0f;
		mbComplete = false;
	}

	void WBAnimation::SetAnimator(WBAnimator* animator)
	{
		mAnimator = animator;
	}
}