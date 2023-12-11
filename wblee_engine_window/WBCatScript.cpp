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
		case eState::Groom:
			break;
		case eState::Sleep:
			break;
		case eState::Move:
			move();
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
		if (WBInput::GetKey(eKeyCode::W))
		{
			mState = eState::Move;
			mAnimator->PlayAnimation(L"CatMoveFront");
		}
		if (WBInput::GetKey(eKeyCode::A))
		{
			mState = eState::Move;
			mAnimator->PlayAnimation(L"CatMoveLeft");
		}
		if (WBInput::GetKey(eKeyCode::S))
		{
			mState = eState::Move;
			mAnimator->PlayAnimation(L"CatMoveBack");
		}
		if (WBInput::GetKey(eKeyCode::D))
		{
			mState = eState::Move;
			mAnimator->PlayAnimation(L"CatMoveRight");
		}
	}

	void WBCatScript::move()
	{
		WBTransform* tr = GetOwner()->GetComponent<WBTransform>();
		Vector2 pos = tr->GetPos();

		if (WBInput::GetKey(eKeyCode::W))
			pos.y -= 100 * WBTime::DeltaTime();

		if (WBInput::GetKey(eKeyCode::A))
			pos.x -= 100 * WBTime::DeltaTime();

		if (WBInput::GetKey(eKeyCode::S))
			pos.y += 100 * WBTime::DeltaTime();

		if (WBInput::GetKey(eKeyCode::D))
			pos.x += 100 * WBTime::DeltaTime();

		tr->SetPos(pos);

		if (WBInput::GetKeyUp(eKeyCode::W) || WBInput::GetKeyUp(eKeyCode::A)
			|| WBInput::GetKeyUp(eKeyCode::S) || WBInput::GetKeyUp(eKeyCode::D))
		{
			mState = eState::SitDown;
			mAnimator->PlayAnimation(L"CatSitDown", false);
		}
	}
}