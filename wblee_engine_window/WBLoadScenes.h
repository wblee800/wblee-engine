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
#include "WBStardropSaloonScene.h"
#include "WBSecretWoodsScene.h"
#include "WBFarmhouseScene.h"

namespace wb
{
	void LoadScenes()
	{
		// ----Tool Scene----
		WBSceneManager::CreateScene<WBToolScene>(L"ToolScene");

		// ----Title Scene----
		WBSceneManager::CreateScene<WBTitleScene>(L"TitleScene");

		// ----Play Scene----
		// Farm
		WBSceneManager::CreateScene<WBFarmScene>(L"FarmScene");
		WBSceneManager::CreateScene<WBFarmhouseScene>(L"FarmhouseScene");
		WBSceneManager::CreateScene<WBShopOfCarpenterScene>(L"ShopOfCarpenterScene");
		WBSceneManager::CreateScene<WBRanchOfMarnieScene>(L"RanchOfMarnieScene");
		WBSceneManager::CreateScene<WBSecretWoodsScene>(L"SecretWoodsScene");

		// Sewer
		WBSceneManager::CreateScene<WBGateSewerScene>(L"GateSewerScene");
		WBSceneManager::CreateScene<WBSewerScene>(L"SewerScene");

		// Bus Stop
		WBSceneManager::CreateScene<WBBusStopScene>(L"BusStopScene");

		// Calico Desert
		WBSceneManager::CreateScene<WBCalicoDesertScene>(L"CalicoDesertScene");
		WBSceneManager::CreateScene<WBSkullCavernEntranceScene>(L"SkullCavernEntranceScene");
		WBSceneManager::CreateScene<WBSkullCavernScene>(L"SkullCavernScene");

		// Pelican Town
		WBSceneManager::CreateScene<WBPelicanTownScene>(L"PelicanTownScene");
		WBSceneManager::CreateScene<WBJojaMartScene>(L"JojaMartScene");
		WBSceneManager::CreateScene<WBGeneralStoreOfPierreScene>(L"GeneralStoreOfPierreScene");
		WBSceneManager::CreateScene<WBBlacksmithScene>(L"BlacksmithScene");
		WBSceneManager::CreateScene<WBCommunityCenterScene>(L"CommunityCenterScene");
		WBSceneManager::CreateScene<WBTheaterBoxOfficeScene>(L"TheaterBoxOfficeScene");
		WBSceneManager::CreateScene<WBTheaterScreenScene>(L"TheaterScreenScene");
		WBSceneManager::CreateScene<WBStardropSaloonScene>(L"StardropSaloonScene");
		
		// ----Ending Scene----
		WBSceneManager::CreateScene<WBBeachScene>(L"BeachScene");

		WBSceneManager::LoadScene(L"BusStopScene");
	}
}