#pragma once
#include "WBComponent.h"

namespace wb
{
	class WBAudioListener : public WBComponent
	{
	public:
		WBAudioListener();
		~WBAudioListener();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	};
}