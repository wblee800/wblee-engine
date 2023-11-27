#include "WBPlayScene.h"
#include "../wblee_engine_source/WBGameObject.h"
#include "WBPlayer.h"
#include "../wblee_engine_source/WBTransform.h"
#include "../wblee_engine_source/WBSpriteRenderer.h"
#include "../wblee_engine_source/WBInput.h"
#include "../wblee_engine_source/WBSceneManager.h"
#include "../wblee_engine_source/WBObject.h"

namespace wb
{
	WBPlayScene::WBPlayScene()
		:bg{}
	{
	}

	WBPlayScene::~WBPlayScene()
	{
	}

	void WBPlayScene::Initialize()
	{
		WBScene::Initialize();

		{
			bg = object::Instantiate<WBPlayer>
				(enums::eLayerType::Background, Vector2(100.0f, 100.0f));
			WBSpriteRenderer* sr = bg->AddComponent<WBSpriteRenderer>();
			sr->ImageLoad(L"C:\\Users\\wonbi\\source\\repos\\wblee800\\wblee-engine\\resources\\sprites\\miscellaneous\\Cloudy Ocean.png");
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