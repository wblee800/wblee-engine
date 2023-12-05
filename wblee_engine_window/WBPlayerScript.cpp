#include "WBPlayerScript.h"
#include "../wblee_engine_source/WBInput.h"
#include "../wblee_engine_source/WBTransform.h"
#include "../wblee_engine_source/WBTime.h"
#include "../wblee_engine_source/WBGameObject.h"

wb::WBPlayerScript::WBPlayerScript()
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
}

void wb::WBPlayerScript::LateUpdate()
{
	if (WBInput::GetKey(eKeyCode::RIGHT))
	{
		WBTransform* tr = GetOwner()->GetComponent<WBTransform>();
		Vector2 pos = tr->GetPos();
		pos.x += 100.0f * WBTime::DeltaTime();
		tr->SetPos(pos);
	}

	if (WBInput::GetKey(eKeyCode::LEFT))
	{
		WBTransform* tr = GetOwner()->GetComponent<WBTransform>();
		Vector2 pos = tr->GetPos();
		pos.x -= 100.0f * WBTime::DeltaTime();
		tr->SetPos(pos);
	}

	if (WBInput::GetKey(eKeyCode::UP))
	{
		WBTransform* tr = GetOwner()->GetComponent<WBTransform>();
		Vector2 pos = tr->GetPos();
		pos.y -= 100.0f * WBTime::DeltaTime();
		tr->SetPos(pos);
	}

	if (WBInput::GetKey(eKeyCode::DOWN))
	{
		WBTransform* tr = GetOwner()->GetComponent<WBTransform>();
		Vector2 pos = tr->GetPos();
		pos.y += 100.0f * WBTime::DeltaTime();
		tr->SetPos(pos);
	}
}

void wb::WBPlayerScript::Render(HDC hdc)
{
}
