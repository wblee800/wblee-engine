#pragma once
#include "..\wblee_engine_source\WBScene.h"

namespace wb
{
	class WBPlayer;
	class WBJojaMartScene : public WBScene
	{
	public:
		WBJojaMartScene();
		~WBJojaMartScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:
		WBPlayer* mPlayer;
		WBGameObject* mCamera;
	};
}