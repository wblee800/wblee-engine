#pragma once
#include "..\wblee_engine_source\WBScene.h"

namespace wb
{
	class WBGameObject;
	class WBZuzuCityScene : public WBScene
	{
	public:
		WBZuzuCityScene();
		~WBZuzuCityScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:
		WBGameObject* mCamera;
	};
}