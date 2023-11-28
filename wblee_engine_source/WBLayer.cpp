#include "WBLayer.h"
#include "WBGameObject.h"

namespace wb
{
	WBLayer::WBLayer()
		:mGameObjects{}
	{
	}

	WBLayer::~WBLayer()
	{
	}

	void WBLayer::Initialize()
	{
		for (WBGameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Initialize();
		}
	}

	void WBLayer::Update()
	{
		for (WBGameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Update();
		}
	}

	void WBLayer::LateUpdate()
	{
		for (WBGameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->LateUpdate();
		}
	}

	void WBLayer::Render(HDC hdc)
	{
		for (WBGameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Render(hdc);
		}
	}

	void WBLayer::AddGameObject(WBGameObject* gameObject)
	{
		if (gameObject == nullptr)
			return;

		mGameObjects.push_back(gameObject);
	}

}