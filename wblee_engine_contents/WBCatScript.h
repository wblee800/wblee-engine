#pragma once
#include "..\wblee_engine_source\WBScript.h"

namespace wb
{
	class WBAnimator;
	class WBTransform;
	class WBCollider;
	class WBCatScript : public WBScript
	{
	public:
		enum class eState
		{
			SitDown,
			Move,
			Groom,
			LayDown,
			Sleep,
		};

		enum class eDirection
		{
			Left,
			Right,
			Down,
			Up,
		};

		WBCatScript();
		~WBCatScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnCollisionEnter(WBCollider* other);
		void OnCollisionStay(WBCollider* other);
		void OnCollisionExit(WBCollider* other);

	private:
		void sitDown();
		void move();
		void translate(WBTransform* tr);
		void playMoveAnimationByDirection(eDirection direction);
		void groom();
		void layDown();
		void sleep();

	private:
		eState mState;
		WBAnimator* mAnimator;
		eDirection mDirection;
		float mTime;
		float mNextTime;
	};
}