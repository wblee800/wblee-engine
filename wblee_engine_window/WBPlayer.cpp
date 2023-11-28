#include "WBPlayer.h"
#include "..\wblee_engine_source\WBInput.h"
#include "..\wblee_engine_source\WBTransform.h"
#include "..\wblee_engine_source\WBTime.h"

namespace wb
{
	WBPlayer::WBPlayer()
	{
	}

	WBPlayer::~WBPlayer()
	{
	}

	void WBPlayer::Initialize()
	{
		WBGameObject::Initialize();
	}

	void WBPlayer::Update()
	{
		WBGameObject::Update();
	}

	void WBPlayer::LateUpdate()
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

	void WBPlayer::Render(HDC hdc)
	{
		WBGameObject::Render(hdc);
	}

}