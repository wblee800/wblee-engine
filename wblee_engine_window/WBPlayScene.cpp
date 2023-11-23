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
			WBPlayer* pl = new WBPlayer();
			WBTransform* tr = pl->AddComponent<WBTransform>();
			tr->SetPos(800, 450);

			tr->SetName(L"Transfrom");

			WBSpriteRenderer* sr
				= pl->AddComponent<WBSpriteRenderer>();
			sr->SetName(L"Sprite");

			AddGameObject(pl);
		}

		{
			WBPlayer* pl = new WBPlayer();
			WBTransform* tr = pl->AddComponent<WBTransform>();
			tr->SetPos(200, 450);

			tr->SetName(L"Transfrom");

			WBSpriteRenderer* sr
				= pl->AddComponent<WBSpriteRenderer>();
			sr->SetName(L"Sprite");

			AddGameObject(pl);
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