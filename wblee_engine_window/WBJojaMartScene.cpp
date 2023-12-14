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
		:mPlayer{}
	{
	}

	WBJojaMartScene::~WBJojaMartScene()
	{
	}

	void WBJojaMartScene::Initialize()
	{
		// Before loading a game object, load resources.
		// Joja Mart Map
		WBGameObject* map = object::Instantiate<WBGameObject>
			(enums::eLayerType::Map, Vector2(240.0f + 500.0f, 240.0f));
		WBSpriteRenderer* mapSr = map->AddComponent<WBSpriteRenderer>();

		graphics::WBTexture* mapTexture = WBResources::Find<graphics::WBTexture>(L"Joja_Mart");
		mapSr->SetTexture(mapTexture);
		mapSr->SetSize(Vector2(2.0f, 1.7f));

		// _______________________________________________________

		// Instantiate player
		mPlayer = object::Instantiate<WBPlayer>(enums::eLayerType::Player, Vector2(1000.0f, 830.0f));
		mPlayer->AddComponent<WBPlayerScript>();

		mPlayer->GetComponent<WBTransform>()->SetScale(Vector2(0.6f, 0.6f));

		graphics::WBTexture* playerTexture = WBResources::Find<graphics::WBTexture>(L"Player");
		graphics::WBTexture* playerMoveFrontTexture = WBResources::Find<graphics::WBTexture>(L"Player_Move_Front");
		WBAnimator* playerAnimator = mPlayer->AddComponent<WBAnimator>();
		
		// Player idle
		playerAnimator->CreateAnimation(L"PlayerIdleRight", playerTexture,
			Vector2(0.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.3f);
		playerAnimator->CreateAnimation(L"PlayerIdleLeft", playerTexture,
			Vector2(250.0f * 6, 0.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.3f);
		playerAnimator->CreateAnimation(L"PlayerIdleBack", playerTexture,
			Vector2(0.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.3f);
		playerAnimator->CreateAnimation(L"PlayerIdleFront", playerTexture,
			Vector2(250.0f * 11, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.3f);

		// Player move
		playerAnimator->CreateAnimation(L"PlayerMoveRight", playerTexture,
			Vector2(250.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 4, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerMoveLeft", playerTexture,
			Vector2(250.0f * 7, 0.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 4, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerMoveBack", playerTexture,
			Vector2(250.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 7, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerMoveFront", playerMoveFrontTexture,
			Vector2(0.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 6, 0.1f);

		// 1. Player attack
		playerAnimator->CreateAnimation(L"PlayerAttackFront", playerTexture,
			Vector2(0.0f, 250.0f * 12), Vector2(250.0f, 250.0f), Vector2::Zero, 4, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerAttackRight", playerTexture,
			Vector2(250.0f * 6, 250.0f * 12), Vector2(250.0f, 250.0f), Vector2::Zero, 6, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerAttackLeft", playerTexture,
			Vector2(0.0f, 250.0f * 13), Vector2(250.0f, 250.0f), Vector2::Zero, 6, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerAttackBack", playerTexture,
			Vector2(250.0f * 6, 250.0f * 13), Vector2(250.0f, 250.0f), Vector2::Zero, 3, 0.1f);

		// 2. Player swing an axe
		playerAnimator->CreateAnimation(L"PlayerSwingAnAxeFront", playerTexture,
			Vector2(250.0f * 3, 250.0f * 2), Vector2(250.0f, 250.0f), Vector2::Zero, 6, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerSwingAnAxeRight", playerTexture,
			Vector2(250.0f * 9, 250.0f * 2), Vector2(250.0f, 250.0f), Vector2::Zero, 3, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerSwingAnAxeLeft", playerTexture,
			Vector2(250.0f * 2, 250.0f * 3), Vector2(250.0f, 250.0f), Vector2::Zero, 5, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerSwingAnAxeBack", playerTexture,
			Vector2(250.0f * 7, 250.0f * 3), Vector2(250.0f, 250.0f), Vector2::Zero, 4, 0.1f);

		// 3. Player pickaxe
		playerAnimator->CreateAnimation(L"PlayerPickaxeFront", playerTexture,
			Vector2(0.0f, 250.0f * 14), Vector2(250.0f, 250.0f), Vector2::Zero, 7, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerPickaxeBack", playerTexture,
			Vector2(250.0f * 7, 250.0f * 14), Vector2(250.0f, 250.0f), Vector2::Zero, 5, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerPickaxeRight", playerTexture,
			Vector2(0.0f, 250.0f * 15), Vector2(250.0f, 250.0f), Vector2::Zero, 5, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerPickaxeLeft", playerTexture,
			Vector2(250.0f * 5, 250.0f * 15), Vector2(250.0f, 250.0f), Vector2::Zero, 5, 0.1f);

		// 4. Hoe
		playerAnimator->CreateAnimation(L"PlayerHoeFront", playerTexture,
			Vector2(0.0f, 250.0f * 4), Vector2(250.0f, 250.0f), Vector2::Zero, 3, 0.15f);
		playerAnimator->CreateAnimation(L"PlayerHoeBack", playerTexture,
			Vector2(250.0f * 3, 250.0f * 4), Vector2(250.0f, 250.0f), Vector2::Zero, 4, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerHoeRight", playerTexture,
			Vector2(250.0f * 7, 250.0f * 4), Vector2(250.0f, 250.0f), Vector2::Zero, 5, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerHoeLeft", playerTexture,
			Vector2(0.0f, 250.0f * 5), Vector2(250.0f, 250.0f), Vector2::Zero, 5, 0.1f);

		// 5. Scythe
		playerAnimator->CreateAnimation(L"PlayerScytheFront", playerTexture,
			Vector2(250.0f * 5, 250.0f * 5), Vector2(250.0f, 250.0f), Vector2::Zero, 6, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerScytheRight", playerTexture,
			Vector2(0.0f, 250.0f * 6), Vector2(250.0f, 250.0f), Vector2::Zero, 6, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerScytheLeft", playerTexture,
			Vector2(250.0f * 6, 250.0f * 6), Vector2(250.0f, 250.0f), Vector2::Zero, 6, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerScytheBack", playerTexture,
			Vector2(0.0f, 250.0f * 7), Vector2(250.0f, 250.0f), Vector2::Zero, 6, 0.1f);

		// 6. Player irrigate
		playerAnimator->CreateAnimation(L"PlayerIrrigateRight", playerTexture,
			Vector2(250.0f * 6, 250.0f * 7), Vector2(250.0f, 250.0f), Vector2::Zero, 5, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerIrrigateFront", playerTexture,
			Vector2(0.0f, 250.0f * 8), Vector2(250.0f, 250.0f), Vector2::Zero, 12, 0.05f);
		playerAnimator->CreateAnimation(L"PlayerIrrigateLeft", playerTexture,
			Vector2(0.0f, 250.0f * 9), Vector2(250.0f, 250.0f), Vector2::Zero, 5, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerIrrigateBack", playerTexture,
			Vector2(250.0f * 5, 250.0f * 9), Vector2(250.0f, 250.0f), Vector2::Zero, 3, 0.15f);

		// 7. Player load on his head
		playerAnimator->CreateAnimation(L"PlayerLoadOnHisHeadLeft", playerTexture,
			Vector2(0.0f, 250.0f * 10), Vector2(250.0f, 250.0f), Vector2::Zero, 5, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerLoadOnHisHeadRight", playerTexture,
			Vector2(250.0f * 5, 250.0f * 10), Vector2(250.0f, 250.0f), Vector2::Zero, 5, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerLoadOnHisHeadBack", playerTexture,
			Vector2(0.0f, 250.0f * 11), Vector2(250.0f, 250.0f), Vector2::Zero, 6, 0.1f);
		playerAnimator->CreateAnimation(L"PlayerLoadOnHisHeadFront", playerTexture,
			Vector2(250.0f * 7, 250.0f * 11), Vector2(250.0f, 250.0f), Vector2::Zero, 5, 0.1f);

		// 8. Player find a something
		playerAnimator->CreateAnimation(L"PlayerFindASomething", playerTexture,
			Vector2(250.0f * 8, 250.0f * 9), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);

		// 9. Player is exhausted
		playerAnimator->CreateAnimation(L"PlayerIsExhausted", playerTexture,
			Vector2(250.0f * 6, 250.0f * 16), Vector2(250.0f, 250.0f), Vector2::Zero, 4, 0.1f);

		playerAnimator->PlayAnimation(L"PlayerIdleBack", false);

		// _______________________________________________________

		// Cat
		WBCat* cat = object::Instantiate<WBCat>(enums::eLayerType::Animal);
		cat->AddComponent<WBCatScript>();
		
		graphics::WBTexture* catTexture = WBResources::Find<graphics::WBTexture>(L"Cat");
		WBAnimator* catAnimator = cat->AddComponent<WBAnimator>();
		catAnimator->CreateAnimation(L"CatMoveFront", catTexture,
			Vector2(0.0f, 32.0f * 0), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.3f);
		catAnimator->CreateAnimation(L"CatMoveRight", catTexture,
			Vector2(0.0f, 32.0f * 1), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.3f);
		catAnimator->CreateAnimation(L"CatMoveBack", catTexture,
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

		if (WBInput::GetKeyDown(eKeyCode::A))
		{
			WBSceneManager::LoadScene(L"PelicanTownScene");
		}
	}

	void WBJojaMartScene::Render(HDC hdc)
	{
		HBRUSH blackBrush = CreateSolidBrush(RGB(0, 0, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blackBrush);
		Rectangle(hdc, -1, -1, 1921, 1081);

		SelectObject(hdc, oldBrush);
		DeleteObject(blackBrush);

		WBScene::Render(hdc);

		wchar_t str[64] = L"1.공격 2.나무 베기 3.채광 4.밭 일구기 5.풀 베기 6.물 주기 7.아이템 들기 8.무언가를 찾음 9.지침";
		TextOut(hdc, 0, 0, str, 63);
	}

	void WBJojaMartScene::OnEnter()
	{
	}

	void WBJojaMartScene::OnExit()
	{
	}
}