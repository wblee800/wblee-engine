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
			(enums::eLayerType::Player, Vector2(0.f, 0.f));
		WBSpriteRenderer* playerSr = mPlayer->AddComponent<WBSpriteRenderer>();
		playerSr->SetSize(Vector2(2.0f, 2.0f));
		mPlayer->AddComponent<WBPlayerScript>();

		graphics::WBTexture* playerTex = WBResources::Find<graphics::WBTexture>(L"Player");
		playerSr->SetTexture(playerTex);

		// Before loading a game object, load resources.
		WBGameObject* bg = object::Instantiate<WBGameObject>
			(enums::eLayerType::Background, Vector2(0.f, 0.f));	
		WBSpriteRenderer* bgSr = bg->AddComponent<WBSpriteRenderer>();
		bgSr->SetSize(Vector2(2.0f, 2.0f));

		graphics::WBTexture* bgTex = WBResources::Find<graphics::WBTexture>(L"BG");
		bgSr->SetTexture(bgTex);

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
		/*WBTransform* tr = bg->AddComponent<WBTransform>();
		tr->SetPos(Vector2(0, 0));*/
	}
}