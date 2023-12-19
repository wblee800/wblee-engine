#pragma once
#include "..\wblee_engine_source\WBGameObject.h"

namespace wb
{
	class WBTile : public WBGameObject
	{
	public:
		WBTile();
		~WBTile();

	private:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	};
}