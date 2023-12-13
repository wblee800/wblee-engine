#pragma once
#include "..\wblee_engine_source\WBScript.h"

namespace wb
{
	class WBAnimator;
	class WBPlayerScript : public WBScript
	{
	public:
		enum class eState
		{
			Idle,
			Move,
			Attack,
			Irrigate,
		};

		WBPlayerScript();
		~WBPlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void idle();
		void move();

	private:
		eState mState;
		WBAnimator* mAnimator;
	};
}