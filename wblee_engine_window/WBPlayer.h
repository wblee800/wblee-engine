#pragma once
#include "..\wblee_engine_source\WBGameObject.h"

namespace wb
{
	class WBPlayer : public WBGameObject
	{
	public:
		WBPlayer();
		~WBPlayer();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;

	private:

	};
}