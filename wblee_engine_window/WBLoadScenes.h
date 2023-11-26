#pragma once
#include "..\wblee_engine_source\WBSceneManager.h"
#include "WBPlayScene.h"
#include "WBTitleScene.h"

namespace wb
{
	void LoadScenes()
	{
		WBSceneManager::CreateScene<WBTitleScene>(L"WBTitleScene");
		WBSceneManager::CreateScene<WBPlayScene>(L"WBPlayScene");

		WBSceneManager::LoadScene(L"WBPlayScene");
	}
}