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

		// 애니메이션이 끝났는지
		bool isComplete() { return mbComplete; }
		// 애니메이션을 처음 만들 때, 애니메이터와 연결해주는 함수
		void SetAnimator(WBAnimator* animator);

	private:
		WBAnimator* mAnimator;
		graphics::WBTexture* mTexture;

		std::vector<Sprite> mAnimationSheet;
		int mIndex;
		// 다음 장면으로 넘어가는 데까지 걸리는 시간
		float mTime;
		bool mbComplete;
		math::Vector2 mOffset;
	};
}