#pragma once
#include "..\wblee_engine_source\WBScript.h"

namespace wb
{
	class WBAnimator;
	class WBCatScript : public WBScript
	{
	public:
		enum class eState
		{
			SitDown,
			Groom,
			Sleep,
			Move,
		};

		WBCatScript();
		~WBCatScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void sitDown();
		void move();

	private:
		eState mState;
		WBAnimator* mAnimator;
	};
}