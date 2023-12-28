#include "WBJojaMartScene.h"
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
#include "WBCat.h"
#include "WBCatScript.h"

namespace wb
{
	WBJojaMartScene::WBJojaMartScene()
		:mPlayer(nullptr)
		,mCamera(nullptr)
	{
	}

	WBJojaMartScene::~WBJojaMartScene()
	{
	}

	void WBJojaMartScene::Initialize()
	{
		// Camera
		mCamera = object::Instantiate<WBGameObject>(enums::eLayerType::None);
		renderer::mainCamera = mCamera->AddComponent<WBCamera>();

		// Before loading a game object, load resources.
		// Joja Mart Map
		WBGameObject* map = object::Instantiate<WBGameObject>
			(enums::eLayerType::Map, Vector2(240.0f, -623.0f));
		WBSpriteRenderer* mapSr = map->AddComponent<WBSpriteRenderer>();

		graphics::WBTexture* mapTexture = WBResources::Find<graphics::WBTexture>(L"Joja_Mart");
		mapSr->SetTexture(mapTexture);
		mapSr->SetSize(Vector2(4.0f, 3.9f));

		// CEO of Joja Mart
		WBGameObject* ceo = object::Instantiate<WBGameObject>
			(enums::eLayerType::NPC, Vector2(1458.0f, 813.0f));
		WBSpriteRenderer* ceoSr = ceo->AddComponent<WBSpriteRenderer>();

		graphics::WBTexture* ceoTexture = WBResources::Find<graphics::WBTexture>(L"CEO_Of_Joja_Mart");
		ceoSr->SetTexture(ceoTexture);

		// Employee of Joja Mart
		WBGameObject* employee = object::Instantiate<WBGameObject>
			(enums::eLayerType::NPC, Vector2(757.0f, 767.0f));
		WBSpriteRenderer* employeeSr = employee->AddComponent<WBSpriteRenderer>();

		graphics::WBTexture* employeeTexture = WBResources::Find<graphics::WBTexture>(L"Employee_Of_Joja_Mart");
		employeeSr->SetTexture(employeeTexture);

		// Instantiate player
		mPlayer = object::Instantiate<WBPlayer>(enums::eLayerType::Player);
		mPlayer->AddComponent<WBPlayerScript>();

		mPlayer->GetComponent<WBTransform>()->SetPosition(Vector2(1135.0f, 1170.0f));
		
		// Set textures of player
		graphics::WBTexture* playerTexture = WBResources::Find<graphics::WBTexture>(L"Player");
		graphics::WBTexture* playerMoveDownTexture = WBResources::Find<graphics::WBTexture>(L"Player_Move_Down");
		graphics::WBTexture* playerSitDownTexture = WBResources::Find<graphics::WBTexture>(L"Player_Sit_Down");
		graphics::WBTexture* playerStandUpTexture = WBResources::Find<graphics::WBTexture>(L"Player_Stand_Up");
		graphics::WBTexture* playerSwingAnAxeRightTexture = WBResources::Find<graphics::WBTexture>(L"Player_Swing_An_Axe_Right");
		graphics::WBTexture* playerPickaxeLeftTexture = WBResources::Find<graphics::WBTexture>(L"Player_Pickaxe_Left");
		graphics::WBTexture* playerIsExhaustedTexture = WBResources::Find<graphics::WBTexture>(L"Player_Is_Exhausted");
		WBAnimator* playerAnimator = mPlayer->AddComponent<WBAnimator>();

		// Set a camera target
		renderer::mainCamera->SetTarget(mPlayer);

		// Player idle
		playerAnimator->CreateAnimation(L"PlayerIdleRight", playerTexture,
			Vector2(0.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 1, 0.3f);
		playerAnimator->CreateAnimation(L"PlayerIdleLeft", playerTexture,
			Vector2(250.0f * 6, 0.0f), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 1, 0.3f);
		playerAnimator->CreateAnimation(L"PlayerIdleUp", playerTexture,
			Vector2(0.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 1, 0.3f);
		playerAnimator->CreateAnimation(L"PlayerIdleDown", playerTexture,
			Vector2(250.0f * 11, 250.0f), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 1, 0.3f);

		// Player move
		playerAnimator->CreateAnimation(L"PlayerMoveRight", playerTexture,
			Vector2(250.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 4, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerMoveLeft", playerTexture,
			Vector2(250.0f * 7, 0.0f), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 4, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerMoveUp", playerTexture,
			Vector2(250.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 7, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerMoveDown", playerMoveDownTexture,
			Vector2(0.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 6, 0.1f);

		// 1 : Player attack
		playerAnimator->CreateAnimation(L"PlayerAttackDown", playerTexture,
			Vector2(0.0f, 250.0f * 12), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 4, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerAttackRight", playerTexture,
			Vector2(250.0f * 6, 250.0f * 12), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 6, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerAttackLeft", playerTexture,
			Vector2(0.0f, 250.0f * 13), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 6, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerAttackUp", playerTexture,
			Vector2(250.0f * 6, 250.0f * 13), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 3, 0.1f);

		// 2 : Player swing an axe
		playerAnimator->CreateAnimation(L"PlayerSwingAnAxeDown", playerTexture,
			Vector2(250.0f * 3, 250.0f * 2), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 6, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerSwingAnAxeRight", playerSwingAnAxeRightTexture,
			Vector2(0.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 5, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerSwingAnAxeLeft", playerTexture,
			Vector2(250.0f * 2, 250.0f * 3), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 5, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerSwingAnAxeUp", playerTexture,
			Vector2(250.0f * 7, 250.0f * 3), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 4, 0.1f);

		// 3 : Player pickaxe
		playerAnimator->CreateAnimation(L"PlayerPickaxeDown", playerTexture,
			Vector2(0.0f, 250.0f * 14), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 7, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerPickaxeUp", playerTexture,
			Vector2(250.0f * 7, 250.0f * 14), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 5, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerPickaxeRight", playerTexture,
			Vector2(0.0f, 250.0f * 15), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 5, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerPickaxeLeft", playerPickaxeLeftTexture,
			Vector2(0.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 5, 0.1f);

		// 4 : Hoe
		playerAnimator->CreateAnimation(L"PlayerHoeDown", playerTexture,
			Vector2(0.0f, 250.0f * 4), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 3, 0.15f);
		playerAnimator->CreateAnimation(L"PlayerHoeUp", playerTexture,
			Vector2(250.0f * 3, 250.0f * 4), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 4, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerHoeRight", playerTexture,
			Vector2(250.0f * 7, 250.0f * 4), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 5, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerHoeLeft", playerTexture,
			Vector2(0.0f, 250.0f * 5), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 5, 0.1f);

		// 5 : Scythe
		playerAnimator->CreateAnimation(L"PlayerScytheDown", playerTexture,
			Vector2(250.0f * 5, 250.0f * 5), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 6, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerScytheRight", playerTexture,
			Vector2(0.0f, 250.0f * 6), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 6, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerScytheLeft", playerTexture,
			Vector2(250.0f * 6, 250.0f * 6), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 6, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerScytheUp", playerTexture,
			Vector2(0.0f, 250.0f * 7), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 6, 0.1f);

		// 6 : Player irrigate
		playerAnimator->CreateAnimation(L"PlayerIrrigateRight", playerTexture,
			Vector2(250.0f * 6, 250.0f * 7), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 5, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerIrrigateDown", playerTexture,
			Vector2(0.0f, 250.0f * 8), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 12, 0.05f);
		playerAnimator->CreateAnimation(L"PlayerIrrigateLeft", playerTexture,
			Vector2(0.0f, 250.0f * 9), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 5, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerIrrigateUp", playerTexture,
			Vector2(250.0f * 5, 250.0f * 9), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 3, 0.15f);

		// 7 : Player load on his head
		playerAnimator->CreateAnimation(L"PlayerLoadOnHisHeadLeft", playerTexture,
			Vector2(0.0f, 250.0f * 10), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 5, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerLoadOnHisHeadRight", playerTexture,
			Vector2(250.0f * 5, 250.0f * 10), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 5, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerLoadOnHisHeadUp", playerTexture,
			Vector2(0.0f, 250.0f * 11), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 6, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerLoadOnHisHeadDown", playerTexture,
			Vector2(250.0f * 7, 250.0f * 11), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 5, 0.1f);

		// 8 : Player find a something
		playerAnimator->CreateAnimation(L"PlayerFindASomething", playerTexture,
			Vector2(250.0f * 8, 250.0f * 9), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 1, 0.1f);

		// 9 : Player is hungry
		playerAnimator->CreateAnimation(L"PlayerIsHungry", playerTexture,
			Vector2(250.0f * 6, 250.0f * 16), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 4, 0.1f);

		// 0 : Player has some food
		playerAnimator->CreateAnimation(L"PlayerHasSomeFood", playerTexture,
			Vector2(0.0f, 250.0f * 16), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 6, 0.1f);

		// f1 : Player sit down
		playerAnimator->CreateAnimation(L"PlayerSitDown", playerSitDownTexture,
			Vector2(0.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 5, 0.05f);

		// f2 : Player stand up
		playerAnimator->CreateAnimation(L"PlayerStandUp", playerStandUpTexture,
			Vector2(0.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 5, 0.05f);

		// f3 : Player is exhausted
		playerAnimator->CreateAnimation(L"PlayerIsExhausted", playerIsExhaustedTexture,
			Vector2(0.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2(-94.0f, -64.0f), 1, 0.1f);

		// f4 : Player ride a horse
		/*playerAnimator->CreateAnimation(L"PlayerRideAHorse", ,
			Vector2(0.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 5, 0.05f);*/

		// f5 : Player play a mini harp
		/*playerAnimator->CreateAnimation(L"PlayerPlayAMiniHarp", ,
			Vector2(0.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 5, 0.05f);*/

		// f6 : Player dozes off
		/*playerAnimator->CreateAnimation(L"PlayerDozesOff", ,
			Vector2(0.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 5, 0.05f);*/

		playerAnimator->PlayAnimation(L"PlayerIdleUp", false);

		// _______________________________________________________

		// Cat
		WBCat* cat = object::Instantiate<WBCat>(enums::eLayerType::Animal);
		cat->AddComponent<WBCatScript>();

		graphics::WBTexture* catTexture = WBResources::Find<graphics::WBTexture>(L"Cat");
		WBAnimator* catAnimator = cat->AddComponent<WBAnimator>();
		catAnimator->CreateAnimation(L"CatMoveDown", catTexture,
			Vector2(0.0f, 32.0f * 0), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.3f);
		catAnimator->CreateAnimation(L"CatMoveRight", catTexture,
			Vector2(0.0f, 32.0f * 1), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.3f);
		catAnimator->CreateAnimation(L"CatMoveUp", catTexture,
			Vector2(0.0f, 32.0f * 2), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.3f);
		catAnimator->CreateAnimation(L"CatMoveLeft", catTexture,
			Vector2(0.0f, 32.0f * 3), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.3f);
		catAnimator->CreateAnimation(L"CatSitDown", catTexture,
			Vector2(0.0f, 32.0f * 4), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.3f);
		catAnimator->CreateAnimation(L"CatGroom", catTexture,
			Vector2(0.0f, 32.0f * 5), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.3f);
		catAnimator->CreateAnimation(L"CatSleep", catTexture,
			Vector2(0.0f, 32.0f * 6), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.3f);

		catAnimator->PlayAnimation(L"CatSitDown");

		// _______________________________________________________

		// Tool
		/*WBGameObject* tool = object::Instantiate<WBGameObject>
			(enums::eLayerType::Equipment, Vector2(800.0f, 350.0f));
		WBSpriteRenderer* toolSr = tool->AddComponent<WBSpriteRenderer>();

		graphics::WBTexture* toolTexture = WBResources::Find<graphics::WBTexture>(L"Tools");
		toolSr->SetTexture(toolTexture);*/

		// _______________________________________________________

		// Weapon
		/*WBGameObject* weapon = object::Instantiate<WBGameObject>
			(enums::eLayerType::Equipment, Vector2(600.0f, 350.0f));
		WBSpriteRenderer* weaponSr = weapon->AddComponent<WBSpriteRenderer>();

		graphics::WBTexture* weaponTexture = WBResources::Find<graphics::WBTexture>(L"Weapons");
		weaponSr->SetTexture(weaponTexture);*/

		// _______________________________________________________

		// Skill
		/*WBGameObject* skill = object::Instantiate<WBGameObject>
			(enums::eLayerType::Skill, Vector2(16.0f, 16.0f));
		WBAnimator* skillAnimator = skill->AddComponent<WBAnimator>();

		graphics::WBTexture* skillTex = WBResources::Find<graphics::WBTexture>(L"Fireball");
		skillAnimator->CreateAnimation(L"ShootFireball", skillTex
			, Vector2::Zero, Vector2(32.0f, 32.0f)
			, Vector2::Zero, 4, 0.1f);

		skillAnimator->PlayAnimation(L"ShootFireball");*/

		// After creating a game object, call an Initialize() of WBLayer and WBGameObject
		WBScene::Initialize();
	}

	void WBJojaMartScene::Update()
	{
		WBScene::Update();
	}

	void WBJojaMartScene::LateUpdate()
	{
		WBScene::LateUpdate();

		if (WBInput::GetKeyDown(eKeyCode::S))
		{
			WBSceneManager::LoadScene(L"PelicanTownScene");
		}
	}

	void WBJojaMartScene::Render(HDC hdc)
	{
		HBRUSH blackBrush = CreateSolidBrush(RGB(5, 3, 4));
		HBRUSH originBrush = (HBRUSH)SelectObject(hdc, blackBrush);
		Rectangle(hdc, -1, -1, 1921, 1081);

		SelectObject(hdc, originBrush);
		DeleteObject(blackBrush);

		WBScene::Render(hdc);

		wchar_t str[100] = L"1:공격 2:나무 베기 3:채광 4:밭 일구기 5:풀 베기 6:물 주기 7:아이템 들기 8:무언가를 찾았음 9:배고픔 0:먹기 f1:의자에 앉기 f2:의자에서 일어서기 f3:탈진";
		TextOut(hdc, 0, 0, str, 99);
	}

	void WBJojaMartScene::OnEnter()
	{
		renderer::mainCamera = mCamera->GetComponent<WBCamera>();
	}

	void WBJojaMartScene::OnExit()
	{
	}
}