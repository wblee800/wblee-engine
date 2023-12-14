#include "WBPlayerScript.h"
#include "../wblee_engine_source/WBInput.h"
#include "../wblee_engine_source/WBTransform.h"
#include "../wblee_engine_source/WBTime.h"
#include "../wblee_engine_source/WBGameObject.h"
#include "../wblee_engine_source/WBAnimator.h"
#include "../wblee_engine_source/WBTexture.h"

namespace wb
{
	WBPlayerScript::WBPlayerScript()
		:mState(eState::Idle)
		, mDirection()
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
		case wb::WBPlayerScript::eState::Idle:
			idle();
			break;
		case wb::WBPlayerScript::eState::Move:
			move();
			break;
		case wb::WBPlayerScript::eState::Attack:
			attack();
			break;
		case wb::WBPlayerScript::eState::SwingAnAxe:
			swingAnAxe();
			break;
		case wb::WBPlayerScript::eState::Pickaxe:
			pickaxe();
			break;
		case wb::WBPlayerScript::eState::Hoe:
			hoe();
			break;
		case wb::WBPlayerScript::eState::Scythe:
			scythe();
			break;
		case wb::WBPlayerScript::eState::Irrigate:
			irrigate();
			break;
		case wb::WBPlayerScript::eState::LoadOnHisHead:
			loadOnHisHead();
			break;
		case wb::WBPlayerScript::eState::FindASomething:
			findASomething();
			break;
		case wb::WBPlayerScript::eState::BeExhausted:
			beExhausted();
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
			mDirection = eDirection::Back;
			mAnimator->PlayAnimation(L"PlayerMoveBack");
		}
		if (WBInput::GetKey(eKeyCode::LEFT))
		{
			mState = eState::Move;
			mDirection = eDirection::Left;
			mAnimator->PlayAnimation(L"PlayerMoveLeft");
		}
		if (WBInput::GetKey(eKeyCode::DOWN))
		{
			mState = eState::Move;
			mDirection = eDirection::Front;
			mAnimator->PlayAnimation(L"PlayerMoveFront");
		}
		if (WBInput::GetKey(eKeyCode::RIGHT))
		{
			mState = eState::Move;
			mDirection = eDirection::Right;
			mAnimator->PlayAnimation(L"PlayerMoveRight");
		}

		// If you click a mouse left button,
		if (WBInput::GetKeyDown(eKeyCode::ONE))
		{
			attack();
		}

		// If you click a mouse left button,
		if (WBInput::GetKeyDown(eKeyCode::TWO))
		{
			swingAnAxe();
		}

		// If you click a mouse left button,
		if (WBInput::GetKeyDown(eKeyCode::THREE))
		{
			pickaxe();
		}

		// If you click a mouse left button,
		if (WBInput::GetKeyDown(eKeyCode::FOUR))
		{
			hoe();
		}

		// If you click a mouse left button,
		if (WBInput::GetKeyDown(eKeyCode::FIVE))
		{
			scythe();
		}

		// If you click a mouse left button,
		if (WBInput::GetKeyDown(eKeyCode::SIX))
		{
			irrigate();
		}

		// If you click a mouse left button,
		if (WBInput::GetKeyDown(eKeyCode::SEVEN))
		{
			loadOnHisHead();
		}

		// If you click a mouse left button,
		if (WBInput::GetKeyDown(eKeyCode::EIGHT))
		{
			findASomething();
		}

		// If you click a mouse left button,
		if (WBInput::GetKeyDown(eKeyCode::NINE))
		{
			beExhausted();
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

		if (WBInput::GetKeyUp(eKeyCode::UP))
		{
			mState = eState::Idle;
			mDirection = eDirection::Back;
			mAnimator->PlayAnimation(L"PlayerIdleBack", false);
		}
		else if (WBInput::GetKeyUp(eKeyCode::LEFT))
		{
			mState = eState::Idle;
			mDirection = eDirection::Left;
			mAnimator->PlayAnimation(L"PlayerIdleLeft", false);
		}
		else if (WBInput::GetKeyUp(eKeyCode::DOWN))
		{
			mState = eState::Idle;
			mDirection = eDirection::Front;
			mAnimator->PlayAnimation(L"PlayerIdleFront", false);
		}
		else if (WBInput::GetKeyUp(eKeyCode::RIGHT))
		{
			mState = eState::Idle;
			mDirection = eDirection::Right;
			mAnimator->PlayAnimation(L"PlayerIdleRight", false);
		}
	}

	void WBPlayerScript::attack()
	{
		switch (mDirection)
		{
		case eDirection::Front:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerAttackFront");
			break;
		case eDirection::Right:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerAttackRight");
			break;
		case eDirection::Back:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerAttackBack");
			break;
		case eDirection::Left:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerAttackLeft");
			break;
		default:
			break;
		}
	}

	void WBPlayerScript::swingAnAxe()
	{
		switch (mDirection)
		{
		case eDirection::Front:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerSwingAnAxeFront");
			break;
		case eDirection::Right:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerSwingAnAxeRight");
			break;
		case eDirection::Back:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerSwingAnAxeBack");
			break;
		case eDirection::Left:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerSwingAnAxeLeft");
			break;
		default:
			break;
		}
	}

	void WBPlayerScript::pickaxe()
	{
		switch (mDirection)
		{
		case eDirection::Front:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerPickaxeFront");
			break;
		case eDirection::Right:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerPickaxeRight");
			break;
		case eDirection::Back:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerPickaxeBack");
			break;
		case eDirection::Left:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerPickaxeLeft");
			break;
		default:
			break;
		}
	}

	void WBPlayerScript::hoe()
	{
		switch (mDirection)
		{
		case eDirection::Front:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerHoeFront");
			break;
		case eDirection::Right:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerHoeRight");
			break;
		case eDirection::Back:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerHoeBack");
			break;
		case eDirection::Left:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerHoeLeft");
			break;
		default:
			break;
		}
	}

	void WBPlayerScript::scythe()
	{
		switch (mDirection)
		{
		case eDirection::Front:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerScytheFront");
			break;
		case eDirection::Right:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerScytheRight");
			break;
		case eDirection::Back:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerScytheBack");
			break;
		case eDirection::Left:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerScytheLeft");
			break;
		default:
			break;
		}
	}

	void WBPlayerScript::irrigate()
	{
		switch (mDirection)
		{
		case eDirection::Front:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerIrrigateFront");
			break;
		case eDirection::Right:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerIrrigateRight");
			break;
		case eDirection::Back:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerIrrigateBack");
			break;
		case eDirection::Left:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerIrrigateLeft");
			break;
		default:
			break;
		}
	}

	void WBPlayerScript::loadOnHisHead()
	{
		switch (mDirection)
		{
		case eDirection::Front:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerLoadOnHisHeadFront");
			break;
		case eDirection::Right:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerLoadOnHisHeadRight");
			break;
		case eDirection::Back:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerLoadOnHisHeadBack");
			break;
		case eDirection::Left:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerLoadOnHisHeadLeft");
			break;
		default:
			break;
		}
	}

	void WBPlayerScript::findASomething()
	{
		mState = eState::Idle;
		mAnimator->PlayAnimation(L"PlayerFindASomething");
	}

	void WBPlayerScript::beExhausted()
	{
		mState = eState::Idle;
		mAnimator->PlayAnimation(L"PlayerIsExhausted");
	}
}