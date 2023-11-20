#pragma once
#include "WBSceneManager.h"
#include "WBPlayScene.h"

namespace wb
{
	void LoadScenes()
	{
		WBSceneManager::CreateScene<WBPlayScene>(L"PlayScene");
	}
}