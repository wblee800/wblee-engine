#include "WBSpriteRenderer.h"
#include "WBGameObject.h"
#include "WBTransform.h"

wb::WBSpriteRenderer::WBSpriteRenderer()
	:mImage(nullptr)
	, mWidth(0)
	, mHeight(0)
{
}

wb::WBSpriteRenderer::~WBSpriteRenderer()
{
}

void wb::WBSpriteRenderer::Initialize()
{
}

void wb::WBSpriteRenderer::Update()
{
}

void wb::WBSpriteRenderer::LateUpdate()
{
}

void wb::WBSpriteRenderer::Render(HDC hdc)
{
	WBTransform* tr = GetOwner()->GetComponent<WBTransform>();
	Vector2 pos = tr->GetPos();

	Gdiplus::Graphics graphics(hdc);
	graphics.DrawImage(mImage,Gdiplus::Rect(pos.x, pos.y, 1600, 900));
}

void wb::WBSpriteRenderer::ImageLoad(const std::wstring& path)
{
	mImage = Gdiplus::Image::FromFile(path.c_str());
	mWidth = mImage->GetWidth();
	mHeight = mImage->GetHeight();
}
