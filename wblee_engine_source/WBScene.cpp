#include "WBScene.h"
#include "WBGameObject.h"
#include "WBLayer.h"

namespace wb
{
	WBScene::WBScene()
		: mLayers{}
	{
		createLayers();
	}

	WBScene::~WBScene()
	{
	}

	void WBScene::Initialize()
	{
	}

	void WBScene::Update()
	{
		for (WBLayer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->Update();
		}
	}

	void WBScene::LateUpdate()
	{
		for (WBLayer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->LateUpdate();
		}
	}

	void WBScene::Render(HDC hdc)
	{
		for (WBLayer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->Render(hdc);
		}
	}

	void WBScene::OnEnter()
	{

	}

	void WBScene::OnExit()
	{

	}

	void WBScene::AddGameObject(WBGameObject * gameObj, const enums::eLayerType layerType)
	{
		mLayers[(UINT)layerType]->AddGameObject(gameObj);
	}

	void WBScene::createLayers()
	{
		mLayers.resize((UINT)enums::eLayerType::Max);
		for (size_t i = 0; i < (UINT)enums::eLayerType::Max; i++)
		{
			mLayers[i] = new WBLayer;
		}
	}
}