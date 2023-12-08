#include "WBPlayScene.h"
#include "../wblee_engine_source/WBGameObject.h"
#include "WBPlayer.h"
#include "../wblee_engine_source/WBTransform.h"
#include "../wblee_engine_source/WBSpriteRenderer.h"
#include "../wblee_engine_source/WBInput.h"
#include "../wblee_engine_source/WBSceneManager.h"
#include "../wblee_engine_source/WBObject.h"
#include "../wblee_engine_source/WBTexture.h"
#include "../wblee_engine_source/WBResources.h"
#include "WBPlayerScript.h"
#include "..\wblee_engine_source\WBCamera.h"
#include "..\wblee_engine_source\WBRenderer.h"
#include "..\wblee_engine_source\WBAnimator.h"

namespace wb
{
	WBPlayScene::WBPlayScene()
		:mPlayer{}
	{
	}

	WBPlayScene::~WBPlayScene()
	{
	}

	void WBPlayScene::Initialize()
	{
		// Main camera
		WBGameObject* camera = object::Instantiate<WBGameObject>(enums::eLayerType::None, Vector2(480.0f, 480.0f));
		WBCamera* cameraComp = camera->AddComponent<WBCamera>();
		renderer::mainCamera = cameraComp;

		// Before loading a game object, load resources.
		mPlayer = object::Instantiate<WBPlayer>
			(enums::eLayerType::Player, Vector2(16.0f, 16.0f));
		mPlayer->AddComponent<WBPlayerScript>();

		graphics::WBTexture* playerTex = WBResources::Find<graphics::WBTexture>(L"Cat");
		WBAnimator* playerAnimator = mPlayer->AddComponent<WBAnimator>();

		// Move
		playerAnimator->CreateAnimation(L"CatFrontMove", playerTex
			, Vector2::Zero,Vector2(32.0f, 32.0f)
			, Vector2::Zero, 4, 0.5f);
		playerAnimator->CreateAnimation(L"CatRightMove", playerTex
			, Vector2::Zero, Vector2(32.0f, 64.0f)
			, Vector2::Zero, 4, 0.5f);
		playerAnimator->CreateAnimation(L"CatBackMove", playerTex
			, Vector2::Zero, Vector2(32.0f, 96.0f)
			, Vector2::Zero, 4, 0.5f);
		playerAnimator->CreateAnimation(L"CatLeftMove", playerTex
			, Vector2::Zero, Vector2(32.0f, 128.0f)
			, Vector2::Zero, 4, 0.5f);

		// Sit down
		playerAnimator->CreateAnimation(L"CatSitDown", playerTex
			, Vector2::Zero, Vector2(32.0f, 160.0f)
			, Vector2::Zero, 4, 0.5f);

		// Groom
		playerAnimator->CreateAnimation(L"CatGroom", playerTex
			, Vector2::Zero, Vector2(32.0f, 192.0f)
			, Vector2::Zero, 4, 0.5f);

		// _______________________________________________________

		// Before loading a game object, load resources.
		WBGameObject* bg = object::Instantiate<WBGameObject>
			(enums::eLayerType::Background, Vector2(240.f, 240.f));	
		WBSpriteRenderer* bgSr = bg->AddComponent<WBSpriteRenderer>();

		graphics::WBTexture* bgTex = WBResources::Find<graphics::WBTexture>(L"Map");
		bgSr->SetTexture(bgTex);

		// _______________________________________________________

		// Before loading a game object, load resources.
		WBGameObject* skill = object::Instantiate<WBGameObject>
			(enums::eLayerType::Skill, Vector2(16.0f, 16.0f));
		WBAnimator* skillAnimator = skill->AddComponent<WBAnimator>();

		graphics::WBTexture* skillTex = WBResources::Find<graphics::WBTexture>(L"Fireball");
		skillAnimator->CreateAnimation(L"ShootFireball", skillTex
			, Vector2::Zero, Vector2(32.0f, 32.0f)
			, Vector2::Zero, 4, 0.1f);

		skillAnimator->PlayAnimation(L"ShootFireball");
		// _______________________________________________________

		// After creating a game object, call an Initialize() of WBLayer and WBGameObject
		WBScene::Initialize();
	}

	void WBPlayScene::Update()
	{
		WBScene::Update();
	}

	void WBPlayScene::LateUpdate()
	{
		WBScene::LateUpdate();

		if (WBInput::GetKeyDown(eKeyCode::N))
		{
			WBSceneManager::LoadScene(L"WBTitleScene");
		}
	}

	void WBPlayScene::Render(HDC hdc)
	{
		WBScene::Render(hdc);

		wchar_t str[12] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 10);
	}

	void WBPlayScene::OnEnter()
	{
	}

	void WBPlayScene::OnExit()
	{
	}
}