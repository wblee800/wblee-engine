#pragma once
#include "../wblee_engine_source/WBGameObject.h"

namespace wb
{
	class WBSewerMonster : public WBGameObject
	{
	public:
		WBSewerMonster();
		~WBSewerMonster();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}