#include "WBPlayerScript.h"
#include "../wblee_engine_source/WBInput.h"
#include "../wblee_engine_source/WBTransform.h"
#include "../wblee_engine_source/WBTime.h"
#include "../wblee_engine_source/WBGameObject.h"
#include "../wblee_engine_source/WBAnimator.h"

namespace wb
{
	WBPlayerScript::WBPlayerScript()
		:mState(eState::Idle)
		, mAnimator(nullptr)
	{
	}

	WBPlayerScript::~WBPlayerScript()
	{
	}

	void WBPlayerScript::Initialize()
	{
	}

	void WBPlayerScript::Update()
	{
		if (mAnimator == nullptr)
			mAnimator = GetOwner()->GetComponent<WBAnimator>();

		switch (mState)
		{
		case eState::Idle:
			idle();
			break;
		case eState::Move:
			move();
			break;
		case eState::Attack:
			break;
		case eState::Irrigate:
			break;
		default:
			break;
		}
	}

	void WBPlayerScript::LateUpdate()
	{
	}

	void WBPlayerScript::Render(HDC hdc)
	{
	}

	void WBPlayerScript::idle()
	{
		if (WBInput::GetKey(eKeyCode::UP))
		{
			mState = eState::Move;
			mAnimator->PlayAnimation(L"PlayerMoveFront");
		}
		if (WBInput::GetKey(eKeyCode::LEFT))
		{
			mState = eState::Move;
			mAnimator->PlayAnimation(L"PlayerMoveLeft");
		}
		if (WBInput::GetKey(eKeyCode::DOWN))
		{
			mState = eState::Move;
			mAnimator->PlayAnimation(L"PlayerMoveBack");
		}
		if (WBInput::GetKey(eKeyCode::RIGHT))
		{
			mState = eState::Move;
			mAnimator->PlayAnimation(L"PlayerMoveRight");
		}

		if (WBInput::GetKeyDown(eKeyCode::LButton))
		{
			mState = eState::Move;
			mAnimator->PlayAnimation(L"PlayerMoveRight");

			Vector2 mousePos = WBInput::GetMousePosition();
		}
	}

	void WBPlayerScript::move()
	{
		WBTransform* tr = GetOwner()->GetComponent<WBTransform>();
		Vector2 pos = tr->GetPos();

		if (WBInput::GetKey(eKeyCode::UP))
			pos.y -= 100 * WBTime::DeltaTime();

		if (WBInput::GetKey(eKeyCode::LEFT))
			pos.x -= 100 * WBTime::DeltaTime();

		if (WBInput::GetKey(eKeyCode::DOWN))
			pos.y += 100 * WBTime::DeltaTime();

		if (WBInput::GetKey(eKeyCode::RIGHT))
			pos.x += 100 * WBTime::DeltaTime();

		tr->SetPos(pos);

		if (WBInput::GetKeyUp(eKeyCode::UP) || WBInput::GetKeyUp(eKeyCode::LEFT)
			|| WBInput::GetKeyUp(eKeyCode::DOWN) || WBInput::GetKeyUp(eKeyCode::RIGHT))
		{
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerIdle", false);
		}
	}
}