#include "WBToolScene.h"
#include "WBTile.h"
#include "..\wblee_engine_source\WBObject.h"
#include "..\wblee_engine_source\WBTilemapRenderer.h"
#include "..\wblee_engine_source\WBResources.h"
#include "..\wblee_engine_source\WBTexture.h"

namespace wb
{
	WBToolScene::WBToolScene()
	{
	}

	WBToolScene::~WBToolScene()
	{
	}

	void WBToolScene::Initialize()
	{
		WBTile* tile = object::Instantiate<WBTile>(enums::eLayerType::Tile);
		WBTilemapRenderer* tilemapRenderer = tile->AddComponent<WBTilemapRenderer>();

		tilemapRenderer->SetTexture(WBResources::Find<graphics::WBTexture>(L"Farmhouse"));

		WBScene::Initialize();
	}

	void WBToolScene::Update()
	{
		WBScene::Update();
	}

	void WBToolScene::LateUpdate()
	{
		WBScene::LateUpdate();
	}

	void WBToolScene::Render(HDC hdc)
	{
		WBScene::Render(hdc);
	}

	void WBToolScene::OnEnter()
	{
	}

	void WBToolScene::OnExit()
	{
	}
}