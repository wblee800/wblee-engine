#include "WBCatScript.h"
#include "WBInput.h"
#include "WBTransform.h"
#include "WBTime.h"
#include "WBGameObject.h"
#include "WBAnimator.h"
#include "WBObject.h"
#include "..\wblee_engine_source\WBEnum.h"
#include "..\wblee_engine_source\WBCollider.h"

namespace wb
{
	WBCatScript::WBCatScript()
		: mState(WBCatScript::eState::SitDown)
		, mAnimator(nullptr)
		, mTime(0.0f)
		, mDirection()
		, mNextTime(0.0f)
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
			mAnimator = GetOwner()->GetComponent<WBAnimator>();
		
		switch (mState)
		{
		case wb::WBCatScript::eState::SitDown:
			sitDown();
			break;
		case wb::WBCatScript::eState::Move:
			move();
			break;
		case wb::WBCatScript::eState::Groom:
			groom();
			break;
		case wb::WBCatScript::eState::LayDown:
			break;
		case wb::WBCatScript::eState::Sleep:
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

	void WBCatScript::OnCollisionEnter(WBCollider* other)
	{
		
	}

	void WBCatScript::sitDown()
	{
		mTime += WBTime::DeltaTime();

		if (mTime > mNextTime)
		{
			mState = eState::Move;

			int direction = rand() % 4;
			mDirection = (eDirection)direction;
			mNextTime = rand() % 3 + 2;
			playMoveAnimationByDirection(mDirection);
			mTime = 0.0f;
		}
	}

	void WBCatScript::move()
	{
		mTime += WBTime::DeltaTime();
		if (mTime > mNextTime)
		{
			int isLayDown = rand() % 2;
			mNextTime = rand() % 5 + 4;
			
			if (isLayDown)
			{
				mState = eState::LayDown;
				mAnimator->PlayAnimation(L"CatLayDown", false);
			}
			else
			{
				mState = eState::SitDown;
				mAnimator->PlayAnimation(L"CatSitDown", false);
			}
		}

		WBTransform* tr = GetOwner()->GetComponent<WBTransform>();
		translate(tr);
	}

	void WBCatScript::layDown()
	{
	}

	void WBCatScript::sleep()
	{
	}

	void WBCatScript::playMoveAnimationByDirection(eDirection dir)
	{
		switch (dir)
		{
		case wb::WBCatScript::eDirection::Left:
			mAnimator->PlayAnimation(L"CatMoveLeft", true);
			break;
		case wb::WBCatScript::eDirection::Right:
			mAnimator->PlayAnimation(L"CatMoveRight", true);
			break;
		case wb::WBCatScript::eDirection::Down:
			mAnimator->PlayAnimation(L"CatMoveDown", true);
			break;
		case wb::WBCatScript::eDirection::Up:
			mAnimator->PlayAnimation(L"CatMoveUp", true);
			break;
		default:
			assert(false);
			break;
		}
	}

	void WBCatScript::translate(WBTransform* tr)
	{
		Vector2 pos = tr->GetPosition();
		switch (mDirection)
		{
		case wb::WBCatScript::eDirection::Left:
			pos.x -= 50.0f * WBTime::DeltaTime();
			break;
		case wb::WBCatScript::eDirection::Right:
			pos.x += 50.0f * WBTime::DeltaTime();
			break;
		case wb::WBCatScript::eDirection::Down:
			pos.y += 50.0f * WBTime::DeltaTime();
			break;
		case wb::WBCatScript::eDirection::Up:
			pos.y -= 50.0f * WBTime::DeltaTime();
			break;
		default:
			assert(false);
			break;
		}

		tr->SetPosition(pos);
	}

	void WBCatScript::groom()
	{
	}
}