#pragma once
#include "..\wblee_engine_source\WBGameObject.h"

namespace wb
{
	class WBCat : public WBGameObject
	{
	public:
		WBCat();
		~WBCat();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;

	private:
	};
}