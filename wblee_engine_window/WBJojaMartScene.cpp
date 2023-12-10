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
		// Main camera
		WBGameObject* camera = object::Instantiate<WBGameObject>(enums::eLayerType::None, Vector2(540.0f, 360.0f));
		WBCamera* cameraComp = camera->AddComponent<WBCamera>();
		renderer::mainCamera = cameraComp;

		// _______________________________________________________

		// Before loading a game object, load resources.
		// Background
		WBGameObject* bg = object::Instantiate<WBGameObject>
			(enums::eLayerType::Background, Vector2(240.f + 510.f, 240.f + 100.f));
		WBSpriteRenderer* bgSr = bg->AddComponent<WBSpriteRenderer>();

		graphics::WBTexture* bgTex = WBResources::Find<graphics::WBTexture>(L"Joja_Mart");
		bgSr->SetTexture(bgTex);
		bgSr->SetSize(Vector2(2.0f, 1.7f));

		// _______________________________________________________

		// Player
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

		if (WBInput::GetKeyDown(eKeyCode::N))
		{
			WBSceneManager::LoadScene(L"WBTitleScene");
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