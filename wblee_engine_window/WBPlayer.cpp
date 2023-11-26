#include "WBPlayer.h"
#include "..\wblee_engine_source\WBInput.h"
#include "..\wblee_engine_source\WBTransform.h"
#include "..\wblee_engine_source\WBTime.h"

wb::WBPlayer::WBPlayer()
{
}

wb::WBPlayer::~WBPlayer()
{
}

void wb::WBPlayer::Initialize()
{
	WBGameObject::Initialize();
}

void wb::WBPlayer::Update()
{
	WBGameObject::Update();
}

void wb::WBPlayer::LateUpdate()
{
	WBGameObject::LateUpdate();

	if (WBInput::GetKeyDown(eKeyCode::RIGHT))
	{
		WBTransform* tr = GetComponent<WBTransform>();
		Vector2 pos = tr->GetPos();
		pos.x += 100.0f * WBTime::DeltaTime();
		tr->SetPos(pos);
	}
}

void wb::WBPlayer::Render(HDC hdc)
{
	WBGameObject::Render(hdc);
}
