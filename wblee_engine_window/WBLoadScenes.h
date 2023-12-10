#pragma once
#include "..\wblee_engine_source\WBSceneManager.h"
#include "WBJojaMartScene.h"
#include "WBTitleScene.h"
#include "WBIntroScene.h"

namespace wb
{
	void LoadScenes()
	{
		WBSceneManager::CreateScene<WBTitleScene>(L"WBTitleScene");
		WBSceneManager::CreateScene<WBJojaMartScene>(L"WBJojaMartScene");
		WBSceneManager::CreateScene<WBJojaMartScene>(L"WBIntroScene");

		WBSceneManager::LoadScene(L"WBTitleScene");
	}
}