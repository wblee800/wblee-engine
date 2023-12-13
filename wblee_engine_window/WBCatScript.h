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
			Move,
			Groom,
			Sleep,
		};

		enum class eDirection
		{
			Left,
			Right,
			Down,
			Up,
			End
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
		void playMoveAnimationByDirection(eDirection direction);
		void groom();
		void sleep();

	private:
		eState mState;
		WBAnimator* mAnimator;
		eDirection mDirection;
		float mTime;
	};
}