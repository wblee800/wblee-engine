#pragma once
#include "..\wblee_source\WBSceneManager.h"
#include "WBPlayScene.h"

namespace wb
{
	void LoadScenes()
	{
		WBSceneManager::CreateScene<WBPlayScene>(L"PlayScene");

		WBSceneManager::LoadScene(L"PlayScene");
	}
}