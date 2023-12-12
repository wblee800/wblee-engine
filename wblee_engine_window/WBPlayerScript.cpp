#include "WBPlayerScript.h"
#include "../wblee_engine_source/WBInput.h"
#include "../wblee_engine_source/WBTransform.h"
#include "../wblee_engine_source/WBTime.h"
#include "../wblee_engine_source/WBGameObject.h"
#include "../wblee_engine_source/WBAnimator.h"

wb::WBPlayerScript::WBPlayerScript()
	:mState(eState::SitDown)
	, mAnimator(nullptr)
{
}

wb::WBPlayerScript::~WBPlayerScript()
{
}

void wb::WBPlayerScript::Initialize()
{
}

void wb::WBPlayerScript::Update()
{
	if (mAnimator == nullptr)
		mAnimator = GetOwner()->GetComponent<WBAnimator>();

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

void wb::WBPlayerScript::LateUpdate()
{
}

void wb::WBPlayerScript::Render(HDC hdc)
{
}

void wb::WBPlayerScript::sitDown()
{
	if (WBInput::GetKey(eKeyCode::UP))
	{
		mState = eState::Move;
		mAnimator->PlayAnimation(L"CatMoveFront");
	}
	if (WBInput::GetKey(eKeyCode::LEFT))
	{
		mState = eState::Move;
		mAnimator->PlayAnimation(L"CatMoveLeft");
	}
	if (WBInput::GetKey(eKeyCode::DOWN))
	{
		mState = eState::Move;
		mAnimator->PlayAnimation(L"CatMoveBack");
	}
	if (WBInput::GetKey(eKeyCode::RIGHT))
	{
		mState = eState::Move;
		mAnimator->PlayAnimation(L"CatMoveRight");
	}
}

void wb::WBPlayerScript::move()
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
		mState = eState::SitDown;
		mAnimator->PlayAnimation(L"CatSitDown", false);
	}
}