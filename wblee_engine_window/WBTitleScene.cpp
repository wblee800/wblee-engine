#include "WBTitleScene.h"
#include "..\wblee_engine_source\WBInput.h"
#include "..\wblee_engine_source\WBSceneManager.h"

namespace wb
{
	WBTitleScene::WBTitleScene()
	{
	}

	WBTitleScene::~WBTitleScene()
	{
	}

	void WBTitleScene::Initialize()
	{
		WBScene::Initialize();
	}

	void WBTitleScene::Update()
	{
		WBScene::Update();
	}

	void WBTitleScene::LateUpdate()
	{
		WBScene::LateUpdate();

		if (WBInput::GetKeyDown(eKeyCode::N))
		{
			WBSceneManager::LoadScene(L"WBPlayScene");
		}
	}

	void WBTitleScene::Render(HDC hdc)
	{
		WBScene::Render(hdc);

		wchar_t str[12] = L"Title Scene";
		TextOut(hdc, 0, 0, str, 11);
	}

	void WBTitleScene::OnEnter()
	{
	}

	void WBTitleScene::OnExit()
	{
	}
}