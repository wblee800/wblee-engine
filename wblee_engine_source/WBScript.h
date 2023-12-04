#pragma once
#include "WBComponent.h"

namespace wb
{
	class WBScript : public WBComponent
	{
	public:
		WBScript();
		~WBScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}