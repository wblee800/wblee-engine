#include "WBSceneManager.h"
#include "WBScene.h"

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