#include "WBPlayScene.h"
#include "../wblee_engine_source/WBGameObject.h"
#include "WBPlayer.h"
#include "../wblee_engine_source/WBTransform.h"
#include "../wblee_engine_source/WBSpriteRenderer.h"
#include "../wblee_engine_source/WBInput.h"
#include "../wblee_engine_source/WBSceneManager.h"

namespace wb
{
	WBPlayScene::WBPlayScene()
	{
	}

	WBPlayScene::~WBPlayScene()
	{
	}

	void WBPlayScene::Initialize()
	{
		WBScene::Initialize();

		{
			bg = new WBPlayer();
			WBTransform* tr = bg->AddComponent<WBTransform>();
			tr->SetPos(Vector2(0, 0));

			tr->SetName(L"Transfrom");

			WBSpriteRenderer* sr
				= bg->AddComponent<WBSpriteRenderer>();
			sr->SetName(L"Sprite");
			sr->ImageLoad(L"C:\\Users\\wonbi\\source\\repos\\wblee800\\wblee-engine\\resources\\sprites\\maps\\JojaMart.bmp");

			AddGameObject(bg, eLayerType::Background);
		}
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
		WBTransform* tr = bg->AddComponent<WBTransform>();
		tr->SetPos(Vector2(0, 0));
	}
}