#pragma once
#include "..\wblee_engine_source\WBSceneManager.h"
#include "WBJojaMartScene.h"
#include "WBTitleScene.h"
#include "WBIntroScene.h"
#include "WBBusStopScene.h"
#include "WBFarmUpScene.h"
#include "WBFarmDownScene.h"
#include "WBPelicanTownScene.h"
#include "WBCalicoDesertScene.h"
#include "WBGateSewerScene.h"
#include "WBSewerScene.h"
#include "WBBeachScene.h"
#include "WBSkullCavernEntranceScene.h"
#include "WBSkullCavernScene.h"
#include "WBGeneralStoreOfPierreScene.h"
#include "WBTheaterBoxOfficeScene.h"
#include "WBTheaterScreenScene.h"
#include "WBBlacksmithScene.h"
#include "WBRanchOfMarnieScene.h"
#include "WBShopOfCarpenterScene.h"
#include "WBToolScene.h"
#include "WBStardropSaloonScene.h"
#include "WBSecretWoodsScene.h"
#include "WBFarmhouseScene.h"
#include "WBRestoredCommunityCenterScene.h"
#include "WBIntroScene.h"
#include "WBLoadingTitleScene.h"

namespace wb
{
	void LoadScenes()
	{
		// ----Tool Scene----
		WBSceneManager::CreateScene<WBToolScene>(L"ToolScene");

		// ----Loading Title Scene----
		WBSceneManager::CreateScene<WBLoadingTitleScene>(L"LoadingTitleScene");

		// ----Title Scene----
		WBSceneManager::CreateScene<WBTitleScene>(L"TitleScene");

		// ----Intro Scene----
		WBSceneManager::CreateScene<WBIntroScene>(L"IntroScene");

		// ----Play Scene----
		// Farm
		WBSceneManager::CreateScene<WBFarmUpScene>(L"FarmUpScene");
		WBSceneManager::CreateScene<WBFarmDownScene>(L"FarmDownScene");
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
		WBSceneManager::CreateScene<WBRestoredCommunityCenterScene>(L"RestoredCommunityCenterScene");
		WBSceneManager::CreateScene<WBJojaMartScene>(L"JojaMartScene");
		WBSceneManager::CreateScene<WBGeneralStoreOfPierreScene>(L"GeneralStoreOfPierreScene");
		WBSceneManager::CreateScene<WBBlacksmithScene>(L"BlacksmithScene");
		WBSceneManager::CreateScene<WBTheaterBoxOfficeScene>(L"TheaterBoxOfficeScene");
		WBSceneManager::CreateScene<WBTheaterScreenScene>(L"TheaterScreenScene");
		WBSceneManager::CreateScene<WBStardropSaloonScene>(L"StardropSaloonScene");
		
		// ----Ending Scene----
		WBSceneManager::CreateScene<WBBeachScene>(L"BeachScene");

		WBSceneManager::LoadScene(L"FarmUpScene");
	}
}