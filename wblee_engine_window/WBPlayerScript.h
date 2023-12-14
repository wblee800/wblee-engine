#pragma once
#include "..\wblee_engine_source\WBScript.h"

namespace wb
{
	namespace graphics
	{
		class WBTexture;
	}
	class WBAnimator;
	class WBPlayerScript : public WBScript
	{
	public:
		enum class eState
		{
			Idle,
			Move,
			Attack,
			SwingAnAxe,
			Pickaxe,
			Hoe,
			Scythe,
			Irrigate,
			LoadOnHisHead,
			FindASomething,
			BeExhausted
		};

		enum class eDirection
		{
			Front,
			Right,
			Back,
			Left,
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
		void attack();
		void swingAnAxe();
		void pickaxe();
		void hoe();
		void scythe();
		void irrigate();
		void loadOnHisHead();
		void findASomething();
		void beExhausted();

	private:
		eState mState;
		eDirection mDirection;
		WBAnimator* mAnimator;
	};
}