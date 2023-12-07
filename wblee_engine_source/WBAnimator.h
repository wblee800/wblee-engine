#pragma once
#include "WBComponent.h"

namespace wb
{
	class WBAnimation;
	namespace graphics
	{
		class WBTexture;
	}
	class WBAnimator :public WBComponent
	{
	public:
		WBAnimator();
		~WBAnimator();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void CreateAnimation(const std::wstring& name
			, graphics::WBTexture* spriteSheet
			, math::Vector2 leftTop
			, math::Vector2 size
			, math::Vector2 offset
			, UINT spriteLength
			, float duration);

		WBAnimation* FindAnimation(const std::wstring& name);

		// loop 매개변수에 인자 값을 넣어주지 않으면, true가 default가 되게끔
		// 함수 선언과 동시에 매개변수를 초기화
		void PlayAnimation(const std::wstring& name, bool loop = true);
	private:
		std::map<std::wstring, WBAnimation*> mAnimations;
		// Now playing animation
		WBAnimation* mActiveAnimation;
		bool mbLoop;
	};
}