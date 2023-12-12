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

		// Player
		mPlayer = object::Instantiate<WBPlayer>(enums::eLayerType::Player, Vector2(150.0f, 150.0f));
		mPlayer->AddComponent<WBPlayerScript>();

		graphics::WBTexture* playerTexture = WBResources::Find<graphics::WBTexture>(L"Cat");
		WBAnimator* playerAnimator = mPlayer->AddComponent<WBAnimator>();
		playerAnimator->CreateAnimation(L"CatMoveBack", playerTexture,
			Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.3f);
		playerAnimator->CreateAnimation(L"CatMoveRight", playerTexture,
			Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.3f);
		playerAnimator->CreateAnimation(L"CatMoveFront", playerTexture,
			Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.3f);
		playerAnimator->CreateAnimation(L"CatMoveLeft", playerTexture,
			Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.3f);
		playerAnimator->CreateAnimation(L"CatSitDown", playerTexture,
			Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.3f);
		playerAnimator->CreateAnimation(L"CatGroom", playerTexture,
			Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.3f);

		playerAnimator->PlayAnimation(L"CatSitDown", false);

		// _______________________________________________________

		// Cat
		WBCat* cat = object::Instantiate<WBCat>(enums::eLayerType::Animal);
		cat->AddComponent<WBCatScript>();
		
		graphics::WBTexture* catTexture = WBResources::Find<graphics::WBTexture>(L"Cat");


		// _______________________________________________________

		// Tool
		WBGameObject* tool = object::Instantiate<WBGameObject>
			(enums::eLayerType::Equipment, Vector2(800.0f, 350.0f));
		WBSpriteRenderer* toolSr = tool->AddComponent<WBSpriteRenderer>();

		graphics::WBTexture* toolTexture = WBResources::Find<graphics::WBTexture>(L"Tools");
		toolSr->SetTexture(toolTexture);

		// _______________________________________________________

		// Weapon
		WBGameObject* weapon = object::Instantiate<WBGameObject>
			(enums::eLayerType::Equipment, Vector2(600.0f, 350.0f));
		WBSpriteRenderer* weaponSr = weapon->AddComponent<WBSpriteRenderer>();

		graphics::WBTexture* weaponTexture = WBResources::Find<graphics::WBTexture>(L"Weapons");
		weaponSr->SetTexture(weaponTexture);

		// _______________________________________________________

		// Skill
		WBGameObject* skill = object::Instantiate<WBGameObject>
			(enums::eLayerType::Skill, Vector2(16.0f, 16.0f));
		WBAnimator* skillAnimator = skill->AddComponent<WBAnimator>();

		graphics::WBTexture* skillTex = WBResources::Find<graphics::WBTexture>(L"Fireball");
		skillAnimator->CreateAnimation(L"ShootFireball", skillTex
			, Vector2::Zero, Vector2(32.0f, 32.0f)
			, Vector2::Zero, 4, 0.1f);

		skillAnimator->PlayAnimation(L"ShootFireball");

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

		/*wchar_t str[12] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 10);*/
	}

	void WBJojaMartScene::OnEnter()
	{
	}

	void WBJojaMartScene::OnExit()
	{
	}
}