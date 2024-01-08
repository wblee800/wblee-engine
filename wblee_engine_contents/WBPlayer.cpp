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
	}

	void WBPlayer::Render(HDC hdc)
	{
		WBGameObject::Render(hdc);
	}

}