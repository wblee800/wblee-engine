#pragma once
#include "..\wblee_engine_source\WBScene.h"

namespace wb
{
	class WBPlayScene : public WBScene
	{
	public:
		WBPlayScene();
		~WBPlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:
		class WBPlayer* mPlayer;
	};
}