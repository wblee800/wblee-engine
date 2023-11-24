#include "WBPlayScene.h"
#include "../wblee_engine_source/WBGameObject.h"
#include "WBPlayer.h"
#include "../wblee_engine_source/WBTransform.h"
#include "../wblee_engine_source/WBSpriteRenderer.h"

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
		{
			WBPlayer* bg = new WBPlayer();
			WBTransform* tr = bg->AddComponent<WBTransform>();
			tr->SetPos(Vector2(0, 0));

			tr->SetName(L"Transfrom");

			WBSpriteRenderer* sr
				= bg->AddComponent<WBSpriteRenderer>();
			sr->SetName(L"Sprite");
			sr->ImageLoad(L"C:\\Users\\wonbi\\source\\repos\\wblee800\\wblee-engine\\resources\\sprites\\maps\\JojaMart.bmp");

			AddGameObject(bg);
		}
	}

	void WBPlayScene::Update()
	{
		WBScene::Update();
	}

	void WBPlayScene::LateUpdate()
	{
		WBScene::LateUpdate();
	}

	void WBPlayScene::Render(HDC hdc)
	{
		WBScene::Render(hdc);
	}
}