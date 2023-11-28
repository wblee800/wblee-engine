#pragma once
#include "WBResource.h"

namespace wb
{
	namespace graphics
	{
		class WBTexture : public WBResource
		{
		public:
			enum class eTextureType
			{
				Bmp,
				Png,
				None,
			};

			WBTexture();
			~WBTexture();

			HRESULT Load(const std::wstring& path) override;

			UINT GetWidth() { return mWidth; }
			UINT GetHeight() { return mHeight; }
			HDC GetHdc() { return mHdc; }
			eTextureType GetTextureType() { return mType; }
			Gdiplus::Image* GetImage() { return mImage; }

		private:
			eTextureType mType;
			Gdiplus::Image* mImage;
			HBITMAP mBitmap;
			HDC mHdc;

			UINT mWidth;
			UINT mHeight;
		};
	}
}