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

		// loop �Ű������� ���� ���� �־����� ������, true�� default�� �ǰԲ�
		// �Լ� ����� ���ÿ� �Ű������� �ʱ�ȭ
		void PlayAnimation(const std::wstring& name, bool loop = true);
	private:
		std::map<std::wstring, WBAnimation*> mAnimations;
		// Now playing animation
		WBAnimation* mActiveAnimation;
		bool mbLoop;
	};
}