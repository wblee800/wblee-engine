#pragma once
#include "WBScene.h"

namespace wb
{
	class WBDontDestroyOnLoad : public WBScene
	{
	public:
		WBDontDestroyOnLoad();
		~WBDontDestroyOnLoad();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit()  override;
	};
}