#include "WBScene.h"
#include "WBGameObject.h"

namespace wb
{
	WBScene::WBScene()
	{
	}

	WBScene::~WBScene()
	{
	}

	void WBScene::Initialize()
	{
	}

	void WBScene::Update()
	{
		for (WBGameObject* gameObj : mGameObjects)
		{
			gameObj->Update();
		}
	}

	void WBScene::LateUpdate()
	{
		for (WBGameObject* gameObj : mGameObjects)
		{
			gameObj->LateUpdate();
		}
	}

	void WBScene::Render(HDC hdc)
	{
		for (WBGameObject* gameObj : mGameObjects)
		{
			gameObj->Render(hdc);
		}
	}
}