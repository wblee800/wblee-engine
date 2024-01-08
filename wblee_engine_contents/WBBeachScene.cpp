#include "WBBeachScene.h"
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
	WBBeachScene::WBBeachScene()
		:mPlayer(nullptr)
	{
	}

	WBBeachScene::~WBBeachScene()
	{
	}

	void WBBeachScene::Initialize()
	{
		// Before loading a game object, load resources.
		// Bus Stop Map
		WBGameObject* map = object::Instantiate<WBGameObject>
			(enums::eLayerType::Map, Vector2(121.5f, 99.5f));
		WBSpriteRenderer* mapSr = map->AddComponent<WBSpriteRenderer>();

		graphics::WBTexture* mapTexture = WBResources::Find<graphics::WBTexture>(L"Beach");
		mapSr->SetTexture(mapTexture);

		// _______________________________________________________

		// Player
		mPlayer = object::Instantiate<WBPlayer>
			(enums::eLayerType::Player);
		mPlayer->AddComponent<WBPlayerScript>();

		WBAnimator* playerAnimator = mPlayer->AddComponent<WBAnimator>();
		graphics::WBTexture* playerTexture = WBResources::Find<graphics::WBTexture>(L"Cat");
		playerAnimator->CreateAnimation(L"CatMoveUp", playerTexture,
			Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.3f);
		playerAnimator->CreateAnimation(L"CatMoveRight", playerTexture,
			Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.3f);
		playerAnimator->CreateAnimation(L"CatMoveDown", playerTexture,
			Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.3f);
		playerAnimator->CreateAnimation(L"CatMoveLeft", playerTexture,
			Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.3f);
		playerAnimator->CreateAnimation(L"CatSitDown", playerTexture,
			Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.3f);
		playerAnimator->CreateAnimation(L"CatGroom", playerTexture,
			Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.3f);

		playerAnimator->PlayAnimation(L"CatSitDown", false);

		// After creating a game object, call an Initialize() of WBLayer and WBGameObject
		WBScene::Initialize();
	}

	void WBBeachScene::Update()
	{
		WBScene::Update();
	}

	void WBBeachScene::LateUpdate()
	{
		WBScene::LateUpdate();

		if (WBInput::GetKeyDown(eKeyCode::W))
		{
			WBSceneManager::LoadScene(L"PelicanTownScene");
		}
	}

	void WBBeachScene::Render(HDC hdc)
	{
		WBScene::Render(hdc);

		/*wchar_t str[12] = L"Title Scene";
		TextOut(hdc, 0, 0, str, 11);*/
	}

	void WBBeachScene::OnEnter()
	{
	}

	void WBBeachScene::OnExit()
	{
	}
}