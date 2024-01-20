#pragma once
#include "../wblee_engine_source/WBScript.h"

namespace wb
{
	class WBSewerMonsterScript : public WBScript
	{
	public:
		WBSewerMonsterScript();
		~WBSewerMonsterScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}