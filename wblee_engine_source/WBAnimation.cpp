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

		if (renderer::mainCamera)
			pos = renderer::mainCamera->CalculatePos(pos);

		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = AC_SRC_ALPHA;
		// 0(transparent) ~ 255(Opaque)
		func.SourceConstantAlpha = 255; 

		Sprite sprite = mAnimationSheet[mIndex];
		HDC imgHdc = mTexture->GetHdc();

		// 
		AlphaBlend(hdc
		, pos.x, pos.y
		, sprite.size.x * 2.5
		, sprite.size.y * 2.5
		, imgHdc
		, sprite.leftTop.x
		, sprite.leftTop.y
		, sprite.size.x
		, sprite.size.y
		, func);
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