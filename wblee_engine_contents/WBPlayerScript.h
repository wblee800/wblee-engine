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
			BeHungry,
			HasSomeFood,
			SitDown,
			StandUp,
			BeExhausted,
			RideAHorse,
			PlayAMiniHarp,
			DozesOff
		};

		enum class eDirection
		{
			Down,
			Right,
			Up,
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
		void beHungry();
		void hasSomeFood();
		void sitDown();
		void standUp();
		void beExhausted();
		void rideAHorse();
		void playAMiniHarp();
		void dozesOff();

	private:
		eState mState;
		eDirection mDirection;
		WBAnimator* mAnimator;
	};
}