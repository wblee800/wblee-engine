#include "WBDontDestroyOnLoad.h"

namespace wb
{
	WBDontDestroyOnLoad::WBDontDestroyOnLoad()
	{
	}

	WBDontDestroyOnLoad::~WBDontDestroyOnLoad()
	{
	}

	void WBDontDestroyOnLoad::Initialize()
	{
		WBScene::Initialize();
	}

	void WBDontDestroyOnLoad::Update()
	{
		WBScene::Update();
	}

	void WBDontDestroyOnLoad::LateUpdate()
	{
		WBScene::LateUpdate();
	}

	void WBDontDestroyOnLoad::Render(HDC hdc)
	{
		WBScene::Render(hdc);
	}

	void WBDontDestroyOnLoad::OnEnter()
	{
		WBScene::OnEnter();
	}

	void WBDontDestroyOnLoad::OnExit()
	{
		WBScene::OnExit();
	}
}