#include "WBTitleScene.h"
#include "..\wblee_engine_source\WBInput.h"
#include "..\wblee_engine_source\WBSceneManager.h"

wb::WBTitleScene::WBTitleScene()
{
}

wb::WBTitleScene::~WBTitleScene()
{
}

void wb::WBTitleScene::Initialize()
{
	WBScene::Initialize();
}

void wb::WBTitleScene::Update()
{
	WBScene::Update();
}

void wb::WBTitleScene::LateUpdate()
{
	WBScene::LateUpdate();

	if (WBInput::GetKeyDown(eKeyCode::N))
	{
		WBSceneManager::LoadScene(L"WBPlayScene");
	}
}

void wb::WBTitleScene::Render(HDC hdc)
{
	WBScene::Render(hdc);

	wchar_t str[12] = L"Title Scene";
	TextOut(hdc, 0, 0, str, 11);
}

void wb::WBTitleScene::OnEnter()
{
}

void wb::WBTitleScene::OnExit()
{
}
