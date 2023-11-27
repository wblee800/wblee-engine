#include "WBLayer.h"
#include "WBGameObject.h"

wb::WBLayer::WBLayer()
	:mGameObjects{}
{
}

wb::WBLayer::~WBLayer()
{
}

void wb::WBLayer::Initialize()
{
	for (WBGameObject* gameObj : mGameObjects)
	{
		if (gameObj == nullptr)
			continue;

		gameObj->Initialize();
	}
}

void wb::WBLayer::Update()
{
	for (WBGameObject* gameObj : mGameObjects)
	{
		if (gameObj == nullptr)
			continue;

		gameObj->Update();
	}
}

void wb::WBLayer::LateUpdate()
{
	for (WBGameObject* gameObj : mGameObjects)
	{
		if (gameObj == nullptr)
			continue;

		gameObj->LateUpdate();
	}
}

void wb::WBLayer::Render(HDC hdc)
{
	for (WBGameObject* gameObj : mGameObjects)
	{
		if (gameObj == nullptr)
			continue;

		gameObj->Render(hdc);
	}
}

void wb::WBLayer::AddGameObject(WBGameObject* gameObject)
{
	if (gameObject == nullptr)
		return;

	mGameObjects.push_back(gameObject);
}
