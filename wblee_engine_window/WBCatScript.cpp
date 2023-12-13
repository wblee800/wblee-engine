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
			move();
			break;
		case eState::Sleep:
			sleep();
			break;
		case eState::Groom:
			groom();
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
		mTime += WBTime::DeltaTime();
		if (mTime > 3.0f)
		{
			mState = eState::Move;
			int direction = (rand() % 4);
			mDirection = (eDirection)direction;

			playMoveAnimationByDirection(mDirection);

			mTime = 0.0f;
		}
	}

	void WBCatScript::move()
	{
	}

	void WBCatScript::playMoveAnimationByDirection(eDirection direction)
	{
		switch (direction)
		{
		case eDirection::Left:
			mAnimator->PlayAnimation(L"CatLeft");
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
	}

	void WBCatScript::groom()
	{
	}

	void WBCatScript::sleep()
	{
	}
}