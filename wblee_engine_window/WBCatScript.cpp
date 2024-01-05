#include "WBCatScript.h"
#include "../wblee_engine_source/WBInput.h"
#include "../wblee_engine_source/WBTransform.h"
#include "../wblee_engine_source/WBTime.h"
#include "../wblee_engine_source/WBGameObject.h"
#include "../wblee_engine_source/WBAnimator.h"

namespace wb
{
	WBCatScript::WBCatScript()
		:mState(eState::SitDown)
		, mAnimator(nullptr)
		, mDirection()
		, mTime(0.0f)
	{
	}

	WBCatScript::~WBCatScript()
	{
	}

	void WBCatScript::Initialize()
	{
	}

	void WBCatScript::Update()
	{
		if (mAnimator == nullptr)
			mAnimator = GetOwner()->AddComponent<WBAnimator>();

		switch (mState)
		{
		case eState::SitDown:
			sitDown();
			break;
		case eState::Move:
			playMoveAnimationByDirection(mDirection);
			break;
		case eState::Groom:
			groom();
			break;
		case eState::LayDown:
			layDown();
			break;
		case eState::Sleep:
			sleep();
			break;
		default:
			break;
		}
	}

	void WBCatScript::LateUpdate()
	{
	}

	void WBCatScript::Render(HDC hdc)
	{
	}

	void WBCatScript::sitDown()
	{
		mState = (eState)(rand() % 4 + 1);
		mTime += WBTime::DeltaTime();

		if (mTime > 3.0f)
		{
			mDirection = (eDirection)(rand() % 4);

			playMoveAnimationByDirection(mDirection);

			mTime = 0.0f;
		}
	}

	void WBCatScript::playMoveAnimationByDirection(eDirection direction)
	{
		switch (direction)
		{
		case eDirection::Left:
			mAnimator->PlayAnimation(L"CatMoveLeft");
			break;
		case eDirection::Right:
			mAnimator->PlayAnimation(L"CatMoveRight");
			break;
		case eDirection::Up:
			mAnimator->PlayAnimation(L"CatMoveUp");
			break;
		case eDirection::Down:
			mAnimator->PlayAnimation(L"CatMoveDown");
			break;
		default:
			break;
		}

		mState = eState::SitDown;
	}

	void WBCatScript::groom()
	{
		mAnimator->PlayAnimation(L"CatGroom");

		mState = eState::SitDown;
	}

	void WBCatScript::layDown()
	{
		mAnimator->PlayAnimation(L"CatLayDown");

		mState = eState::SitDown;
	}

	void WBCatScript::sleep()
	{
		mAnimator->PlayAnimation(L"CatSleep");

		mState = eState::SitDown;
	}
}