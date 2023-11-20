#include "WBSceneManager.h"
#include "WBScene.h"

namespace wb
{
	std::map<const std::wstring, WBScene*> WBSceneManager::mScene = {};
	WBScene* WBSceneManager::mActiveScene = nullptr;

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