#include "WBSceneManager.h"
#include "WBScene.h"
#include "WBLayer.h"

namespace wb
{
	std::map<const std::wstring, WBScene*> WBSceneManager::mScene = {};
	WBScene* WBSceneManager::mActiveScene = nullptr;

	WBScene* WBSceneManager::LoadScene(const std::wstring& name)
	{
		if (mActiveScene)
			mActiveScene->OnExit();

		std::map<const std::wstring, WBScene*>::iterator itr
			= mScene.find(name);

		if (itr == mScene.end())
			return nullptr;

		mActiveScene = itr->second;
		mActiveScene->OnEnter();

		return itr->second;
	}

	std::vector<WBGameObject*> WBSceneManager::GetGameObjects(enums::eLayerType layer)
	{
		std::vector<WBGameObject*> gameObjects
			= mActiveScene->GetLayer(layer)->GetGameObjects();

		return gameObjects;
	}

	void wb::WBSceneManager::Initialize()
	{
	}

	void wb::WBSceneManager::Update()
	{
		mActiveScene->Update();
	}

	void wb::WBSceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}

	void wb::WBSceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}
}