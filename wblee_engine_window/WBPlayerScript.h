#pragma once
#include "..\wblee_engine_source\WBScript.h"

namespace wb
{
	class WBPlayerScript : public WBScript
	{
	public:
		WBPlayerScript();
		~WBPlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}