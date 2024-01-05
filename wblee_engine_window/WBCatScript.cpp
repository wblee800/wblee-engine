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

	void WBCatScript::move()
	{
		mTime += WBTime::DeltaTime();
		if (mTime > 2.0f)
		{
			int isLayDown = rand() % 2;
			if (isLayDown)
			{
				mState = eState::LayDown;
				mAnimator->PlayAnimation(L"LayDown", false);
			}
			else
			{
				mState = eState::SitDown;
				mAnimator->PlayAnimation(L"SitDown", false);
			}
		}

		WBTransform* tr = GetOwner()->GetComponent<WBTransform>();
		translate(tr);
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

	void WBCatScript::translate(WBTransform* tr)
	{
		Vector2 pos = tr->GetPosition();
		switch (mDirection)
		{
		case eDirection::Left:
			pos.x -= 100.0f * WBTime::DeltaTime();
			break;
		case eDirection::Right:
			pos.x += 100.0f * WBTime::DeltaTime();
			break;
		case eDirection::Down:
			pos.y += 100.0f * WBTime::DeltaTime();
			break;
		case eDirection::Up:
			pos.y -= 100.0f * WBTime::DeltaTime();
			break;
		default:
			assert(false);
			break;
		}
		tr->SetPosition(pos);
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