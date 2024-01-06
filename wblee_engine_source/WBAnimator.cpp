#include "WBAnimator.h"
#include "WBAnimation.h"
#include "WBTexture.h"

namespace wb
{
	WBAnimator::WBAnimator()
		: WBComponent(enums::eComponentType::Animator)
		, mAnimations{}
		, mActiveAnimation(nullptr)
		, mbLoop(false)
	{
	}

	WBAnimator::~WBAnimator()
	{
	}

	void WBAnimator::Initialize()
	{
	}

	void WBAnimator::Update()
	{
		if (mActiveAnimation)
		{
			mActiveAnimation->Update();
			if (mActiveAnimation->isComplete() == true
				&& mbLoop == true)
			{
				mActiveAnimation->Reset();
			}
		}
	}

	void WBAnimator::LateUpdate()
	{
	}

	void WBAnimator::Render(HDC hdc)
	{
		if (mActiveAnimation)
			mActiveAnimation->Render(hdc);
	}

	void WBAnimator::CreateAnimation(const std::wstring& name, 
		graphics::WBTexture* spriteSheet, 
		math::Vector2 leftTop, 
		math::Vector2 size, 
		math::Vector2 offset, 
		UINT spriteLength, 
		float duration)
	{
		WBAnimation* animation = nullptr;
		
		// ���� ������� �ִϸ��̼��� �̹� �����ϴ��� Ȯ��
		animation = FindAnimation(name);
		// �̹� �����ϴ� �ִϸ��̼��� �� ������� �Ѵٸ�,
		if (animation != nullptr)
			return;

		animation = new WBAnimation();
		animation->SetName(name);
		animation->CreateAnimation(name, spriteSheet,
			leftTop, size,
			offset, spriteLength,
			duration);

		// WBAnimation�� ����ϴ� Animator�� �������� �� �� �ְ� ����
		animation->SetAnimator(this);

		mAnimations.insert(make_pair(name, animation));
	}

	WBAnimation* WBAnimator::FindAnimation(const std::wstring& name)
	{
		auto itr = mAnimations.find(name);
		if (itr == mAnimations.end())
			return nullptr;

		return itr->second;
	}

	void WBAnimator::PlayAnimation(const std::wstring& name, bool loop)
	{
		WBAnimation* animation = FindAnimation(name);
		if (animation == nullptr)
			return;

		mActiveAnimation = animation;
		mActiveAnimation->Reset();
		mbLoop = loop;
	}
}