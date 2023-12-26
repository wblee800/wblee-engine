#include "WBPelicanTownScene.h"
#include "..\wblee_engine_source\WBInput.h"
#include "..\wblee_engine_source\WBSceneManager.h"

#include "..\\wblee_engine_source\\WBGameObject.h"
#include "WBPlayer.h"
#include "..\\wblee_engine_source\\WBTransform.h"
#include "..\\wblee_engine_source\\WBSpriteRenderer.h"
#include "..\\wblee_engine_source\\WBInput.h"
#include "..\\wblee_engine_source\\WBSceneManager.h"
#include "..\\wblee_engine_source\\WBObject.h"
#include "..\\wblee_engine_source\\WBTexture.h"
#include "..\\wblee_engine_source\\WBResources.h"
#include "WBPlayerScript.h"
#include "..\\wblee_engine_source\\WBCamera.h"
#include "..\\wblee_engine_source\\WBRenderer.h"
#include "..\\wblee_engine_source\\WBAnimator.h"

namespace wb
{
	WBPelicanTownScene::WBPelicanTownScene()
		:mPlayer(nullptr),
		mCamera(nullptr)
	{
	}

	WBPelicanTownScene::~WBPelicanTownScene()
	{
	}

	void WBPelicanTownScene::Initialize()
	{
		// Camera
		mCamera = object::Instantiate<WBGameObject>(enums::eLayerType::None);
		renderer::mainCamera = mCamera->AddComponent<WBCamera>();

		// Before loading a game object, load resources.
		// Pelican Town map
		WBGameObject* map = object::Instantiate<WBGameObject>
			(enums::eLayerType::Map, Vector2(721.5f, 699.5f));
		WBSpriteRenderer* mapSr = map->AddComponent<WBSpriteRenderer>();

		graphics::WBTexture* mapTexture = WBResources::Find<graphics::WBTexture>(L"Pelican_Town");
		mapSr->SetTexture(mapTexture);

		// Restored Community Center
		WBGameObject* restoredCommunityCenter = object::Instantiate<WBGameObject>(enums::eLayerType::Building, Vector2(458.0f, 42.0f));
		graphics::WBTexture* restoredCommunityCenterTexture = WBResources::Find<graphics::WBTexture>(L"Restored_Community_Center");
		WBSpriteRenderer* restoredCommunityCenterSr = restoredCommunityCenter->AddComponent<WBSpriteRenderer>();

		restoredCommunityCenterSr->SetTexture(restoredCommunityCenterTexture);
		restoredCommunityCenterSr->SetSize(Vector2(0.5f, 0.5f));

		// Instantiate player
		mPlayer = object::Instantiate<WBPlayer>(enums::eLayerType::Player);
		mPlayer->AddComponent<WBPlayerScript>();

		mPlayer->GetComponent<WBTransform>()->SetScale(Vector2(0.5f, 0.5f));
		mPlayer->GetComponent<WBTransform>()->SetPosition(Vector2(895.0f, 940.0f));

		graphics::WBTexture* playerTexture = WBResources::Find<graphics::WBTexture>(L"Player");
		graphics::WBTexture* playerMoveDownTexture = WBResources::Find<graphics::WBTexture>(L"Player_Move_Down");
		graphics::WBTexture* playerSitDownTexture = WBResources::Find<graphics::WBTexture>(L"Player_Sit_Down");
		graphics::WBTexture* playerStandUpTexture = WBResources::Find<graphics::WBTexture>(L"Player_Stand_Up");
		graphics::WBTexture* playerSwingAnAxeRightTexture = WBResources::Find<graphics::WBTexture>(L"Player_Swing_An_Axe_Right");
		graphics::WBTexture* playerPickaxeLeftTexture = WBResources::Find<graphics::WBTexture>(L"Player_Pickaxe_Left");
		graphics::WBTexture* playerIsExhaustedTexture = WBResources::Find<graphics::WBTexture>(L"Player_Is_Exhausted");
		WBAnimator* playerAnimator = mPlayer->AddComponent<WBAnimator>();

		// Set target
		renderer::mainCamera->SetTarget(mPlayer);

		// Player idle
		playerAnimator->CreateAnimation(L"PlayerIdleRight", playerTexture,
			Vector2(0.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 1, 0.3f);
		playerAnimator->CreateAnimation(L"PlayerIdleLeft", playerTexture,
			Vector2(250.0f * 6, 0.0f), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 1, 0.3f);
		playerAnimator->CreateAnimation(L"PlayerIdleUp", playerTexture,
			Vector2(0.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 1, 0.3f);
		playerAnimator->CreateAnimation(L"PlayerIdleDown", playerTexture,
			Vector2(250.0f * 11, 250.0f), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 1, 0.3f);

		// Player move
		playerAnimator->CreateAnimation(L"PlayerMoveRight", playerTexture,
			Vector2(250.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 4, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerMoveLeft", playerTexture,
			Vector2(250.0f * 7, 0.0f), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 4, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerMoveUp", playerTexture,
			Vector2(250.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 7, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerMoveDown", playerMoveDownTexture,
			Vector2(0.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 6, 0.1f);

		// 1 : Player attack
		playerAnimator->CreateAnimation(L"PlayerAttackDown", playerTexture,
			Vector2(0.0f, 250.0f * 12), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 4, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerAttackRight", playerTexture,
			Vector2(250.0f * 6, 250.0f * 12), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 6, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerAttackLeft", playerTexture,
			Vector2(0.0f, 250.0f * 13), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 6, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerAttackUp", playerTexture,
			Vector2(250.0f * 6, 250.0f * 13), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 3, 0.1f);

		// 2 : Player swing an axe
		playerAnimator->CreateAnimation(L"PlayerSwingAnAxeDown", playerTexture,
			Vector2(250.0f * 3, 250.0f * 2), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 6, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerSwingAnAxeRight", playerSwingAnAxeRightTexture,
			Vector2(0.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 5, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerSwingAnAxeLeft", playerTexture,
			Vector2(250.0f * 2, 250.0f * 3), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 5, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerSwingAnAxeUp", playerTexture,
			Vector2(250.0f * 7, 250.0f * 3), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 4, 0.1f);

		// 3 : Player pickaxe
		playerAnimator->CreateAnimation(L"PlayerPickaxeDown", playerTexture,
			Vector2(0.0f, 250.0f * 14), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 7, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerPickaxeUp", playerTexture,
			Vector2(250.0f * 7, 250.0f * 14), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 5, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerPickaxeRight", playerTexture,
			Vector2(0.0f, 250.0f * 15), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 5, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerPickaxeLeft", playerPickaxeLeftTexture,
			Vector2(0.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 5, 0.1f);

		// 4 : Hoe
		playerAnimator->CreateAnimation(L"PlayerHoeDown", playerTexture,
			Vector2(0.0f, 250.0f * 4), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 3, 0.15f);
		playerAnimator->CreateAnimation(L"PlayerHoeUp", playerTexture,
			Vector2(250.0f * 3, 250.0f * 4), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 4, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerHoeRight", playerTexture,
			Vector2(250.0f * 7, 250.0f * 4), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 5, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerHoeLeft", playerTexture,
			Vector2(0.0f, 250.0f * 5), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 5, 0.1f);

		// 5 : Scythe
		playerAnimator->CreateAnimation(L"PlayerScytheDown", playerTexture,
			Vector2(250.0f * 5, 250.0f * 5), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 6, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerScytheRight", playerTexture,
			Vector2(0.0f, 250.0f * 6), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 6, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerScytheLeft", playerTexture,
			Vector2(250.0f * 6, 250.0f * 6), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 6, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerScytheUp", playerTexture,
			Vector2(0.0f, 250.0f * 7), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 6, 0.1f);

		// 6 : Player irrigate
		playerAnimator->CreateAnimation(L"PlayerIrrigateRight", playerTexture,
			Vector2(250.0f * 6, 250.0f * 7), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 5, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerIrrigateDown", playerTexture,
			Vector2(0.0f, 250.0f * 8), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 12, 0.05f);
		playerAnimator->CreateAnimation(L"PlayerIrrigateLeft", playerTexture,
			Vector2(0.0f, 250.0f * 9), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 5, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerIrrigateUp", playerTexture,
			Vector2(250.0f * 5, 250.0f * 9), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 3, 0.15f);

		// 7 : Player load on his head
		playerAnimator->CreateAnimation(L"PlayerLoadOnHisHeadLeft", playerTexture,
			Vector2(0.0f, 250.0f * 10), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 5, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerLoadOnHisHeadRight", playerTexture,
			Vector2(250.0f * 5, 250.0f * 10), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 5, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerLoadOnHisHeadUp", playerTexture,
			Vector2(0.0f, 250.0f * 11), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 6, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerLoadOnHisHeadDown", playerTexture,
			Vector2(250.0f * 7, 250.0f * 11), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 5, 0.1f);

		// 8 : Player find a something
		playerAnimator->CreateAnimation(L"PlayerFindASomething", playerTexture,
			Vector2(250.0f * 8, 250.0f * 9), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 1, 0.1f);

		// 9 : Player is hungry
		playerAnimator->CreateAnimation(L"PlayerIsHungry", playerTexture,
			Vector2(250.0f * 6, 250.0f * 16), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 4, 0.1f);

		// 0 : Player has some food
		playerAnimator->CreateAnimation(L"PlayerHasSomeFood", playerTexture,
			Vector2(0.0f, 250.0f * 16), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 6, 0.1f);

		// f1 : Player sit down
		playerAnimator->CreateAnimation(L"PlayerSitDown", playerSitDownTexture,
			Vector2(0.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 5, 0.05f);

		// f2 : Player stand up
		playerAnimator->CreateAnimation(L"PlayerStandUp", playerStandUpTexture,
			Vector2(0.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 5, 0.05f);

		// f3 : Player is exhausted
		playerAnimator->CreateAnimation(L"PlayerIsExhausted", playerIsExhaustedTexture,
			Vector2(0.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2(-47.0f, -32.0f), 1, 0.1f);

		// f4 : Player ride a horse
		/*playerAnimator->CreateAnimation(L"PlayerRideAHorse", ,
			Vector2(0.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 5, 0.05f);*/

			// f5 : Player play a mini harp
			/*playerAnimator->CreateAnimation(L"PlayerPlayAMiniHarp", ,
				Vector2(0.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 5, 0.05f);*/

				// f6 : Player dozes off
				/*playerAnimator->CreateAnimation(L"PlayerDozesOff", ,
					Vector2(0.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 5, 0.05f);*/

		playerAnimator->PlayAnimation(L"PlayerIdleDown", false);

		// _______________________________________________________

		// After creating a game object, call an Initialize() of WBLayer and WBGameObject
		WBScene::Initialize();
	}

	void WBPelicanTownScene::Update()
	{
		WBScene::Update();
	}

	void WBPelicanTownScene::LateUpdate()
	{
		WBScene::LateUpdate();

		if (WBInput::GetKeyDown(eKeyCode::A))
		{
			WBSceneManager::LoadScene(L"BusStopScene");
		}
		else if (WBInput::GetKeyDown(eKeyCode::J))
		{
			WBSceneManager::LoadScene(L"JojaMartScene");
		}
		else if (WBInput::GetKeyDown(eKeyCode::P))
		{
			WBSceneManager::LoadScene(L"GeneralStoreOfPierreScene");
		}
		else if (WBInput::GetKeyDown(eKeyCode::C))
		{
			WBSceneManager::LoadScene(L"CommunityCenterScene");
		}
		else if (WBInput::GetKeyDown(eKeyCode::M))
		{
			WBSceneManager::LoadScene(L"TheaterBoxOfficeScene");
		}
		else if (WBInput::GetKeyDown(eKeyCode::B))
		{
			WBSceneManager::LoadScene(L"BlacksmithScene");
		}
		else if (WBInput::GetKeyDown(eKeyCode::S))
		{
			WBSceneManager::LoadScene(L"StardropSaloonScene");
		}
	}

	void WBPelicanTownScene::Render(HDC hdc)
	{
		WBScene::Render(hdc);

		/*wchar_t str[12] = L"Title Scene";
		TextOut(hdc, 0, 0, str, 11);*/
	}

	void WBPelicanTownScene::OnEnter()
	{
		renderer::mainCamera = mCamera->GetComponent<WBCamera>();
	}

	void WBPelicanTownScene::OnExit()
	{
	}
}