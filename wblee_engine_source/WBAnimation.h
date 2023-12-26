#pragma once
#include "WBResource.h"

namespace wb
{
	class WBAnimator;
	namespace graphics
	{
		class WBTexture;
	}
	class WBAnimation : public WBResource
	{
	public:
		struct Sprite
		{
			math::Vector2 leftTop;
			math::Vector2 size;
			math::Vector2 offset;
			float duration;

			Sprite()
				:leftTop(math::Vector2::Zero)
				, size(math::Vector2::Zero)
				, offset(math::Vector2::Zero)
				, duration(0.0f)
			{

			}
		};

		WBAnimation();
		~WBAnimation();

		HRESULT Load(const std::wstring& path) override;

		void Update();
		void Render(HDC hdc);

		void CreateAnimation(const std::wstring& name
			, graphics::WBTexture* spriteSheet
			, math::Vector2 leftTop
			, math::Vector2 size
			, math::Vector2 offset
			, UINT spriteLength
			, float duration);

		void Reset();

		// �ִϸ��̼��� ��������
		bool isComplete() { return mbComplete; }
		// �ִϸ��̼��� ó�� ���� ��, �ִϸ����Ϳ� �������ִ� �Լ�
		void SetAnimator(WBAnimator* animator);

	private:
		WBAnimator* mAnimator;
		graphics::WBTexture* mTexture;

		std::vector<Sprite> mAnimationSheet;
		int mIndex;
		// ���� ������� �Ѿ�� ������ �ɸ��� �ð�
		float mTime;
		bool mbComplete;
		math::Vector2 mOffset;
	};
}