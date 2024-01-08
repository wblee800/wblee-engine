#pragma once
#include "..\wblee_engine_source\WBScene.h"

namespace wb
{
	class WBIntroScene : public WBScene
	{
	public:
		WBIntroScene();
		~WBIntroScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}