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
		: mCamera(nullptr)
	{
	}

	WBTitleScene::~WBTitleScene()
	{
	}

	void WBTitleScene::Initialize()
	{
		// Main camera
		mCamera = object::Instantiate<WBGameObject>(enums::eLayerType::None, Vector2(960.0f, 540.0f));
		WBCamera* cameraComp = mCamera->AddComponent<WBCamera>();
		renderer::mainCamera = cameraComp;

		// Before loading a game object, load resources.
		// Background
		WBGameObject* bg = object::Instantiate<WBGameObject>
			(enums::eLayerType::Background, Vector2(300.0f, 150.0f));
		WBSpriteRenderer* bgSr = bg->AddComponent<WBSpriteRenderer>();

		graphics::WBTexture* bgTex = WBResources::Find<graphics::WBTexture>(L"Cloudy_Night_Ocean");
		bgSr->SetTexture(bgTex);
		bgSr->SetSize(Vector2(1.0f, 1.5f));

		// Title Logo
		WBGameObject* title = object::Instantiate<WBGameObject>
			(enums::eLayerType::Title, Vector2(600.0f, 200.0f));
		WBSpriteRenderer* titleSr = title->AddComponent<WBSpriteRenderer>();

		graphics::WBTexture* titleTex = WBResources::Find<graphics::WBTexture>(L"Logo");
		titleSr->SetTexture(titleTex);
		titleSr->SetSize(Vector2(1.8f, 1.8f));

		// New button
		WBGameObject* newBtn = object::Instantiate<WBGameObject>
			(enums::eLayerType::Title, Vector2(660.0f, 560.0f));
		WBSpriteRenderer* newBtnSr = newBtn->AddComponent<WBSpriteRenderer>();

		graphics::WBTexture* newBtnTex = WBResources::Find<graphics::WBTexture>(L"Title_Button_New");
		newBtnSr->SetTexture(newBtnTex);
		newBtnSr->SetSize(Vector2(2.5f, 2.5f));

		// Load button
		WBGameObject* loadBtn = object::Instantiate<WBGameObject>
			(enums::eLayerType::Title, Vector2(870.0f, 560.0f));
		WBSpriteRenderer* loadBtnSr = loadBtn->AddComponent<WBSpriteRenderer>();

		graphics::WBTexture* loadBtnTex = WBResources::Find<graphics::WBTexture>(L"Title_Button_Load");
		   loadBtnSr->SetTexture(loadBtnTex);
		loadBtnSr->SetSize(Vector2(2.5f, 2.5f));

		// Exit button
		WBGameObject* exitBtn = object::Instantiate<WBGameObject>
			(enums::eLayerType::Title, Vector2(1080.0f, 560.0f));
		WBSpriteRenderer* exitBtnSr = exitBtn->AddComponent<WBSpriteRenderer>();

		graphics::WBTexture* exitBtnTex = WBResources::Find<graphics::WBTexture>(L"Title_Button_Exit");
		exitBtnSr->SetTexture(exitBtnTex);
		exitBtnSr->SetSize(Vector2(2.5f, 2.5f));

		// Sea Monster 1
		WBGameObject* seaMonster1 = object::Instantiate<WBGameObject>
			(enums::eLayerType::Monster, Vector2(600.0f, 700.0f));
		WBAnimator* seaMonster1Animator = seaMonster1->AddComponent<WBAnimator>();
		graphics::WBTexture* seaMonster1Texture = WBResources::Find<graphics::WBTexture>(L"Sea_Monster");
		seaMonster1->GetComponent<WBTransform>()->SetScale(Vector2(1.5f, 1.5f));

		seaMonster1Animator->CreateAnimation(L"Sea_Monster_Swim", seaMonster1Texture, Vector2::Zero, Vector2(32.0f, 32.0f), Vector2::Zero, 16, 0.3f);
		seaMonster1Animator->PlayAnimation(L"Sea_Monster_Swim");

		// Sea Monster 1
		WBGameObject* seaMonster2 = object::Instantiate<WBGameObject>
			(enums::eLayerType::Monster, Vector2(1100.0f, 800.0f));
		WBAnimator* seaMonster2Animator = seaMonster2->AddComponent<WBAnimator>();
		graphics::WBTexture* seaMonster2Texture = WBResources::Find<graphics::WBTexture>(L"Sea_Monster");
		seaMonster2->GetComponent<WBTransform>()->SetScale(Vector2(1.5f, 1.5f));

		seaMonster2Animator->CreateAnimation(L"Sea_Monster_Swim", seaMonster2Texture, Vector2::Zero, Vector2(32.0f, 32.0f), Vector2::Zero, 16, 0.4f);
		seaMonster2Animator->PlayAnimation(L"Sea_Monster_Swim");

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
			WBSceneManager::LoadScene(L"ZuzuCityScene");
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
		renderer::mainCamera = mCamera->GetComponent<WBCamera>();
	}

	void WBTitleScene::OnExit()
	{
	}
}