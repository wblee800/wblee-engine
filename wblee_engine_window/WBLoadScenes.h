#pragma once
#include "..\wblee_engine_source\WBSceneManager.h"
#include "WBJojaMartScene.h"
#include "WBTitleScene.h"
#include "WBIntroScene.h"
#include "WBBusStopScene.h"
#include "WBFarmScene.h"
#include "WBPelicanTownScene.h"
#include "WBCalicoDesertScene.h"
#include "WBGateSewerScene.h"
#include "WBSewerScene.h"
#include "WBBeachScene.h"
#include "WBSkullCavernEntranceScene.h"
#include "WBSkullCavernScene.h"
#include "WBGeneralStoreOfPierreScene.h"
#include "WBCommunityCenterScene.h"
#include "WBTheaterBoxOfficeScene.h"
#include "WBTheaterScreenScene.h"
#include "WBBlacksmithScene.h"
#include "WBRanchOfMarnieScene.h"
#include "WBShopOfCarpenterScene.h"
#include "WBToolScene.h"

namespace wb
{
	void LoadScenes()
	{
		// Tool Scene
		WBSceneManager::CreateScene<WBToolScene>(L"ToolScene");

		// Title Scene
		WBSceneManager::CreateScene<WBTitleScene>(L"TitleScene");

		// Play Scene
		WBSceneManager::CreateScene<WBJojaMartScene>(L"JojaMartScene");
		WBSceneManager::CreateScene<WBBusStopScene>(L"BusStopScene");
		WBSceneManager::CreateScene<WBFarmScene>(L"FarmScene");
		WBSceneManager::CreateScene<WBPelicanTownScene>(L"PelicanTownScene");
		WBSceneManager::CreateScene<WBCalicoDesertScene>(L"CalicoDesertScene");
		WBSceneManager::CreateScene<WBGateSewerScene>(L"GateSewerScene");
		WBSceneManager::CreateScene<WBSewerScene>(L"SewerScene");
		WBSceneManager::CreateScene<WBBeachScene>(L"BeachScene");
		WBSceneManager::CreateScene<WBSkullCavernEntranceScene>(L"SkullCavernEntranceScene");
		WBSceneManager::CreateScene<WBSkullCavernScene>(L"SkullCavernScene");
		WBSceneManager::CreateScene<WBGeneralStoreOfPierreScene>(L"GeneralStoreOfPierreScene");
		WBSceneManager::CreateScene<WBCommunityCenterScene>(L"CommunityCenterScene");
		WBSceneManager::CreateScene<WBTheaterBoxOfficeScene>(L"TheaterBoxOfficeScene");
		WBSceneManager::CreateScene<WBTheaterScreenScene>(L"TheaterScreenScene");
		WBSceneManager::CreateScene<WBBlacksmithScene>(L"BlacksmithScene");
		WBSceneManager::CreateScene<WBRanchOfMarnieScene>(L"RanchOfMarnieScene");
		WBSceneManager::CreateScene<WBShopOfCarpenterScene>(L"ShopOfCarpenterScene");

		// WBSceneManager::LoadScene(L"JojaMartScene");
		// WBSceneManager::LoadScene(L"FarmScene");
		WBSceneManager::LoadScene(L"GeneralStoreOfPierreScene");
		// WBSceneManager::LoadScene(L"ToolScene");
	}
}