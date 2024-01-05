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

			if (gameObj->IsActive() == false)
				continue;

			gameObj->Render(hdc);
		}
	}

	void WBLayer::Destroy()
	{
		std::vector<WBGameObject*> deleteObjects = {};
		findDeadGameObjects(deleteObjects);
		eraseDeadGameObject();
		deleteGameObjects(deleteObjects);
	}

	void WBLayer::AddGameObject(WBGameObject* gameObject)
	{
		if (gameObject == nullptr)
			return;

		mGameObjects.push_back(gameObject);
	}

	void WBLayer::EraseGameObject(WBGameObject* eraseGameObj)
	{
		// std::erase() iter넣어줘서 해당 이터레이와 같은 객체 삭제
		std::erase_if(mGameObjects,
			[=](WBGameObject* gameObj)
			{
				return gameObj == eraseGameObj;
			});
	}

	void WBLayer::findDeadGameObjects(OUT std::vector<WBGameObject*>& gameObjs)
	{
		for (WBGameObject* gameObj : mGameObjects)
		{
			WBGameObject::eState active = gameObj->GetState();
			if (active == WBGameObject::eState::Dead)
				gameObjs.push_back(gameObj);
		}
	}

	void WBLayer::deleteGameObjects(std::vector<WBGameObject*> deleteObjs)
	{
		for (WBGameObject* obj : deleteObjs)
		{
			delete obj;
			obj = nullptr;
		}
	}

	void WBLayer::eraseDeadGameObject()
	{
		std::erase_if(mGameObjects,
			[](WBGameObject* gameObj)
			{
				return (gameObj)->IsDead();
			});
	}
}