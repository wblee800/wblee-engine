#include "WBTitleScene.h"
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
	WBTitleScene::WBTitleScene()
	{
	}

	WBTitleScene::~WBTitleScene()
	{
	}

	void WBTitleScene::Initialize()
	{
		// Main camera
		WBGameObject* camera = object::Instantiate<WBGameObject>(enums::eLayerType::None, Vector2(540.0f, 360.0f));
		WBCamera* cameraComp = camera->AddComponent<WBCamera>();
		renderer::mainCamera = cameraComp;

		// _______________________________________________________

		// Before loading a game object, load resources.
		// Background
		WBGameObject* bg = object::Instantiate<WBGameObject>
			(enums::eLayerType::Background, Vector2(750.f, 260.f));
		WBSpriteRenderer* bgSr = bg->AddComponent<WBSpriteRenderer>();

		graphics::WBTexture* bgTex = WBResources::Find<graphics::WBTexture>(L"Cloudy_Night_Ocean");
		bgSr->SetTexture(bgTex);
		bgSr->SetSize(Vector2(1.5f, 1.9f));

		// _______________________________________________________

		// Title Logo
		WBGameObject* title = object::Instantiate<WBGameObject>
			(enums::eLayerType::Particle, Vector2(200.f + 650.f, 93.5f + 100.f));
		WBSpriteRenderer* titleSr = title->AddComponent<WBSpriteRenderer>();

		graphics::WBTexture* titleTex = WBResources::Find<graphics::WBTexture>(L"Logo");
		titleSr->SetTexture(titleTex);
		titleSr->SetSize(Vector2(1.7f, 1.7f));

		// After creating a game object, call an Initialize() of WBLayer and WBGameObject
		WBScene::Initialize();
	}

	void WBTitleScene::Update()
	{
		WBScene::Update();
	}

	void WBTitleScene::LateUpdate()
	{
		WBScene::LateUpdate();

		if (WBInput::GetKeyDown(eKeyCode::N))
		{
			WBSceneManager::LoadScene(L"WBJojaMartScene");
		}
	}

	void WBTitleScene::Render(HDC hdc)
	{
		WBScene::Render(hdc);

		/*wchar_t str[12] = L"Title Scene";
		TextOut(hdc, 0, 0, str, 11);*/
	}

	void WBTitleScene::OnEnter()
	{
	}

	void WBTitleScene::OnExit()
	{
	}
}