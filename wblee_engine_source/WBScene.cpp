#include "WBScene.h"
#include "WBGameObject.h"
#include "WBLayer.h"

namespace wb
{
	WBScene::WBScene()
		: mLayers{}
	{
		mLayers.resize((UINT)eLayerType::Max);
		for (size_t i = 0; i < (UINT)eLayerType::Max; i++)
		{
			mLayers[i] = new WBLayer;
		}
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

	void WBScene::AddGameObject(WBGameObject * gameObj, const eLayerType layerType)
	{
		mLayers[(UINT)layerType]->AddGameObject(gameObj);
	}
}