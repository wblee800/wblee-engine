#include "WBTexture.h"
#include "WBApplication.h"

extern wb::WBApplication application;

namespace wb
{
	namespace graphics
	{
		WBTexture::WBTexture()
			: WBResource(enums::eResourceType::Texture),
			mType(),
			mImage(),
			mBitmap(),
			mHdc(),
			mWidth(),
			mHeight()
		{
		}

		WBTexture::~WBTexture()
		{
		}

		HRESULT WBTexture::Load(const std::wstring& path)
		{
			std::wstring ext = path.substr(path.find_last_of(L".") + 1);

			if (ext == L"bmp")
			{
				mType = eTextureType::Bmp;
				mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP
				, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

				if (mBitmap == nullptr)
					return S_FALSE;

				BITMAP info = {};
				GetObject(mBitmap, sizeof(BITMAP), &info);

				mWidth = info.bmWidth;
				mHeight = info.bmHeight;

				HDC mainDC = application.GetHDC();
				mHdc = CreateCompatibleDC(mainDC);

				// 원래 가지고 있었던, 안 쓰는 bitmap을 반환한다.
				HBITMAP oldBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
				DeleteObject(oldBitmap);
			}
			else if (ext == L"png")
			{
				mType = eTextureType::Png;
				mImage = Gdiplus::Image::FromFile(path.c_str());

				if (mImage == nullptr)
					return S_FALSE;

				mWidth = mImage->GetWidth();
				mHeight = mImage->GetHeight();
			}

			return S_OK;
		}
	}
}