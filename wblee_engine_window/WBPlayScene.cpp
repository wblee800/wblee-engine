#include "WBPlayScene.h"
#include "WBGameObject.h"

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
		WBGameObject* obj = new WBGameObject();
		AddGameObject(obj);
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