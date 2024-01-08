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
		case wb::WBPlayerScript::eState::BeHungry:
			beHungry();
			break;
		case wb::WBPlayerScript::eState::HasSomeFood:
			hasSomeFood();
			break;
		case wb::WBPlayerScript::eState::SitDown:
			sitDown();
			break;
		case wb::WBPlayerScript::eState::StandUp:
			standUp();
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
			mDirection = eDirection::Up;
			mAnimator->PlayAnimation(L"PlayerMoveUp");
		}
		else if (WBInput::GetKey(eKeyCode::LEFT))
		{
			mState = eState::Move;
			mDirection = eDirection::Left;
			mAnimator->PlayAnimation(L"PlayerMoveLeft");
		}
		else if (WBInput::GetKey(eKeyCode::DOWN))
		{
			mState = eState::Move;
			mDirection = eDirection::Down;
			mAnimator->PlayAnimation(L"PlayerMoveDown");
		}
		else if (WBInput::GetKey(eKeyCode::RIGHT))
		{
			mState = eState::Move;
			mDirection = eDirection::Right;
			mAnimator->PlayAnimation(L"PlayerMoveRight");
		}

		if (WBInput::GetKeyDown(eKeyCode::ONE))
		{
			mState = eState::Attack;
			attack();
		}
		else if (WBInput::GetKeyDown(eKeyCode::TWO))
		{
			mState = eState::SwingAnAxe;
			swingAnAxe();
		}
		else if (WBInput::GetKeyDown(eKeyCode::THREE))
		{
			mState = eState::Pickaxe;
			pickaxe();
		}
		else if (WBInput::GetKeyDown(eKeyCode::FOUR))
		{
			mState = eState::Hoe;
			hoe();
		}
		else if (WBInput::GetKeyDown(eKeyCode::FIVE))
		{
			mState = eState::Scythe;
			scythe();
		}
		else if (WBInput::GetKeyDown(eKeyCode::SIX))
		{
			mState = eState::Irrigate;
			irrigate();
		}
		else if (WBInput::GetKeyDown(eKeyCode::SEVEN))
		{
			mState = eState::LoadOnHisHead;
			loadOnHisHead();
		}
		else if (WBInput::GetKeyDown(eKeyCode::EIGHT))
		{
			mState = eState::FindASomething;
			findASomething();
		}
		else if (WBInput::GetKeyDown(eKeyCode::NINE))
		{
			mState = eState::BeHungry;
			beHungry();
		}
		else if (WBInput::GetKeyDown(eKeyCode::ZERO))
		{
			mState = eState::HasSomeFood;
			hasSomeFood();
		}
		else if (WBInput::GetKeyDown(eKeyCode::F1))
		{
			mState = eState::SitDown;
			sitDown();
		}
		else if (WBInput::GetKeyDown(eKeyCode::F2))
		{
			mState = eState::StandUp;
			standUp();
		}
		else if (WBInput::GetKeyDown(eKeyCode::F3))
		{
			mState = eState::BeExhausted;
			beExhausted();
		}
	}

	void WBPlayerScript::move()
	{
		WBTransform* tr = GetOwner()->GetComponent<WBTransform>();
		Vector2 pos = tr->GetPosition();

		if (WBInput::GetKey(eKeyCode::UP))
			pos.y -= 170 * WBTime::DeltaTime();

		if (WBInput::GetKey(eKeyCode::LEFT))
			pos.x -= 170 * WBTime::DeltaTime();

		if (WBInput::GetKey(eKeyCode::DOWN))
			pos.y += 170 * WBTime::DeltaTime();

		if (WBInput::GetKey(eKeyCode::RIGHT))
			pos.x += 170 * WBTime::DeltaTime();

		tr->SetPosition(pos);

		if (WBInput::GetKeyUp(eKeyCode::UP))
		{
			mState = eState::Idle;
			mDirection = eDirection::Up;
			mAnimator->PlayAnimation(L"PlayerIdleUp", false);
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
			mDirection = eDirection::Down;
			mAnimator->PlayAnimation(L"PlayerIdleDown", false);
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
		case eDirection::Down:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerAttackDown", false);
			break;
		case eDirection::Right:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerAttackRight", false);
			break;
		case eDirection::Up:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerAttackUp", false);
			break;
		case eDirection::Left:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerAttackLeft", false);
			break;
		default:
			break;
		}
	}

	void WBPlayerScript::swingAnAxe()
	{
		switch (mDirection)
		{
		case eDirection::Down:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerSwingAnAxeDown", false);
			break;
		case eDirection::Right:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerSwingAnAxeRight", false);
			break;
		case eDirection::Up:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerSwingAnAxeUp", false);
			break;
		case eDirection::Left:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerSwingAnAxeLeft", false);
			break;
		default:
			break;
		}
	}

	void WBPlayerScript::pickaxe()
	{
		switch (mDirection)
		{
		case eDirection::Down:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerPickaxeDown", false);
			break;
		case eDirection::Right:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerPickaxeRight", false);
			break;
		case eDirection::Up:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerPickaxeUp", false);
			break;
		case eDirection::Left:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerPickaxeLeft", false);
			break;
		default:
			break;
		}
	}

	void WBPlayerScript::hoe()
	{
		switch (mDirection)
		{
		case eDirection::Down:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerHoeDown", false);
			break;
		case eDirection::Right:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerHoeRight", false);
			break;
		case eDirection::Up:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerHoeUp", false);
			break;
		case eDirection::Left:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerHoeLeft", false);
			break;
		default:
			break;
		}
	}

	void WBPlayerScript::scythe()
	{
		switch (mDirection)
		{
		case eDirection::Down:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerScytheDown", false);
			break;
		case eDirection::Right:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerScytheRight", false);
			break;
		case eDirection::Up:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerScytheUp", false);
			break;
		case eDirection::Left:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerScytheLeft", false);
			break;
		default:
			break;
		}
	}

	void WBPlayerScript::irrigate()
	{
		switch (mDirection)
		{
		case eDirection::Down:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerIrrigateDown", false);
			break;
		case eDirection::Right:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerIrrigateRight", false);
			break;
		case eDirection::Up:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerIrrigateUp", false);
			break;
		case eDirection::Left:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerIrrigateLeft", false);
			break;
		default:
			break;
		}
	}

	void WBPlayerScript::loadOnHisHead()
	{
		switch (mDirection)
		{
		case eDirection::Down:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerLoadOnHisHeadDown", false);
			break;
		case eDirection::Right:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerLoadOnHisHeadRight", false);
			break;
		case eDirection::Up:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerLoadOnHisHeadUp", false);
			break;
		case eDirection::Left:
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"PlayerLoadOnHisHeadLeft", false);
			break;
		default:
			break;
		}
	}

	void WBPlayerScript::findASomething()
	{
		mState = eState::Idle;
		mAnimator->PlayAnimation(L"PlayerFindASomething", false);
	}

	void WBPlayerScript::beHungry()
	{
		mState = eState::Idle;
		mAnimator->PlayAnimation(L"PlayerIsHungry", false);
	}

	void WBPlayerScript::hasSomeFood()
	{
		mState = eState::Idle;
		mAnimator->PlayAnimation(L"PlayerHasSomeFood", false);
	}

	void WBPlayerScript::sitDown()
	{
		mState = eState::Idle;
		mAnimator->PlayAnimation(L"PlayerSitDown", false);
	}

	void WBPlayerScript::standUp()
	{
		mState = eState::Idle;
		mAnimator->PlayAnimation(L"PlayerStandUp", false);
	}

	void WBPlayerScript::beExhausted()
	{
		mState = eState::Idle;
		mAnimator->PlayAnimation(L"PlayerIsExhausted", false);
	}

	void WBPlayerScript::rideAHorse()
	{
		mState = eState::Idle;
		mAnimator->PlayAnimation(L"PlayerRideAHorse", false);
	}

	void WBPlayerScript::playAMiniHarp()
	{
		mState = eState::Idle;
		mAnimator->PlayAnimation(L"PlayerPlayAMiniHarp", false);
	}

	void WBPlayerScript::dozesOff()
	{
		mState = eState::Idle;
		mAnimator->PlayAnimation(L"PlayerDozesOff", false);
	}
}