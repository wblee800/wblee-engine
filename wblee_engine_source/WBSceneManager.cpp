#include "WBSceneManager.h"
#include "WBDontDestroyOnLoad.h"
#include "WBLayer.h"

namespace wb
{
	std::map<const std::wstring, WBScene*> WBSceneManager::mScene = {};
	WBScene* WBSceneManager::mActiveScene = nullptr;
	WBScene* WBSceneManager::mDontDestroyOnLoad = nullptr;

	WBScene* WBSceneManager::LoadScene(const std::wstring& name)
	{
		if (mActiveScene)
			mActiveScene->OnExit();

		std::map<std::wstring, WBScene*>::iterator iter
			= mScene.find(name);

		if (iter == mScene.end())
			return nullptr;

		mActiveScene = iter->second;
		mActiveScene->OnEnter();

		return iter->second;
	}

	std::vector<WBGameObject*> WBSceneManager::GetGameObjects(enums::eLayerType layer)
	{
		std::vector<WBGameObject*> gameObjects
			= mActiveScene->GetLayer(layer)->GetGameObjects();
		std::vector<WBGameObject*> dontDestroyOnLoad
			= mDontDestroyOnLoad->GetLayer(layer)->GetGameObjects();

		gameObjects.insert(gameObjects.end()
			, dontDestroyOnLoad.begin(), dontDestroyOnLoad.end());

		return gameObjects;
	}

	void WBSceneManager::Initialize()
	{
		mDontDestroyOnLoad = CreateScene<WBDontDestroyOnLoad>(L"DontDestroyOnLoad");
	}

	void WBSceneManager::Update()
	{
		mActiveScene->Update();
		mDontDestroyOnLoad->Update();
	}

	void WBSceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
		mDontDestroyOnLoad->LateUpdate();
	}

	void WBSceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
		mDontDestroyOnLoad->Render(hdc);
	}

	void WBSceneManager::Destroy()
	{
		mActiveScene->Destroy();
		mDontDestroyOnLoad->Destroy();
	}

	void WBSceneManager::Release()
	{
		for (auto& iter : mScene)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}
}