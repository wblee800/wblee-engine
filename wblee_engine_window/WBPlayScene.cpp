#include "WBPlayScene.h"
#include "../wblee_engine_source/WBGameObject.h"
#include "WBPlayer.h"
#include "../wblee_engine_source/WBTransform.h"
#include "../wblee_engine_source/WBSpriteRenderer.h"
#include "../wblee_engine_source/WBInput.h"
#include "../wblee_engine_source/WBSceneManager.h"
#include "../wblee_engine_source/WBObject.h"
#include "../wblee_engine_source/WBTexture.h"
#include "../wblee_engine_source/WBResources.h"
// #include "WBLoadResources.h"

namespace wb
{
	WBPlayScene::WBPlayScene()
		:bg{}
	{
	}

	WBPlayScene::~WBPlayScene()
	{
	}

	void WBPlayScene::Initialize()
	{
		// Before loading a game object, load resources.
		bg = object::Instantiate<WBPlayer>
			(enums::eLayerType::Background, Vector2(0.f, 0.f));	
		WBSpriteRenderer* sr = bg->AddComponent<WBSpriteRenderer>();

		graphics::WBTexture* bg = WBResources::Find<graphics::WBTexture>(L"BG");
		sr->SetTexture(bg);

		// After creating a game object, call an Initialize() of WBLayer and WBGameObject
		WBScene::Initialize();
	}

	void WBPlayScene::Update()
	{
		WBScene::Update();
	}

	void WBPlayScene::LateUpdate()
	{
		WBScene::LateUpdate();

		if (WBInput::GetKeyDown(eKeyCode::N))
		{
			WBSceneManager::LoadScene(L"WBTitleScene");
		}
	}

	void WBPlayScene::Render(HDC hdc)
	{
		WBScene::Render(hdc);

		wchar_t str[12] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 10);
	}

	void WBPlayScene::OnEnter()
	{
	}

	void WBPlayScene::OnExit()
	{
		/*WBTransform* tr = bg->AddComponent<WBTransform>();
		tr->SetPos(Vector2(0, 0));*/
	}
}