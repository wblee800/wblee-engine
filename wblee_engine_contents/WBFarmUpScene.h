#pragma once
#include "..\wblee_engine_source\WBScene.h"

namespace wb
{
	class WBPlayer;
	class WBCat;
	class WBFarmUpScene : public WBScene
	{
	public:
		WBFarmUpScene();
		~WBFarmUpScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:
		WBPlayer* mPlayer;
		WBCat* mCat;
		WBGameObject* mCamera;
	};
}