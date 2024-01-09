#include "WBZuzuCityScene.h"
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
	WBZuzuCityScene::WBZuzuCityScene()
		:mCamera(nullptr)
	{
	}

	WBZuzuCityScene::~WBZuzuCityScene()
	{
	}

	void WBZuzuCityScene::Initialize()
	{
		// Main camera
		mCamera = object::Instantiate<WBGameObject>(enums::eLayerType::None, Vector2(960.0f, 540.0f));
		WBCamera* cameraComp = mCamera->AddComponent<WBCamera>();
		renderer::mainCamera = cameraComp;

		// Before loading a game object, load resources.
		// Background
		WBGameObject* bg = object::Instantiate<WBGameObject>
			(enums::eLayerType::Background, Vector2(300.0f, 150.0f));

		graphics::WBTexture* bgTex = WBResources::Find<graphics::WBTexture>(L"Zuzu_City");

		WBSpriteRenderer* bgSr = bg->AddComponent<WBSpriteRenderer>();
		bgSr->SetTexture(bgTex);
		bgSr->SetSize(Vector2(2.1f, 1.7f));

		// After creating a game object, call an Initialize() of WBLayer and WBGameObject
		WBScene::Initialize();
	}

	void WBZuzuCityScene::Update()
	{
		WBScene::Update();
	}

	void WBZuzuCityScene::LateUpdate()
	{
		WBScene::LateUpdate();

		if (WBInput::GetKeyDown(eKeyCode::N))
		{
			WBSceneManager::LoadScene(L"FarmUpScene");
		}
	}

	void WBZuzuCityScene::Render(HDC hdc)
	{
		WBScene::Render(hdc);

		/*wchar_t str[12] = L"Title Scene";
		TextOut(hdc, 0, 0, str, 11);*/
	}

	void WBZuzuCityScene::OnEnter()
	{
		renderer::mainCamera = mCamera->GetComponent<WBCamera>();
	}

	void WBZuzuCityScene::OnExit()
	{
	}
}