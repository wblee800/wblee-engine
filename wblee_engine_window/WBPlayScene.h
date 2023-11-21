#pragma once
#include "..\wblee_source\WBScene.h"

namespace wb
{
	class WBPlayScene : public WBScene
	{
	public:
		WBPlayScene();
		~WBPlayScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;

	private:

	};
}