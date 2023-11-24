#pragma once
#include "WBEntity.h"
#include "WBComponent.h"

namespace wb
{
	class WBSpriteRenderer : public	WBComponent
	{
	public:
		WBSpriteRenderer();
		~WBSpriteRenderer();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;

		void ImageLoad(const std::wstring& path);

	private:
		/*BITMAP mBitmap;
		HDC mHdc;*/
		Gdiplus::Image* mImage;
		UINT mWidth;
		UINT mHeight;
	};
}