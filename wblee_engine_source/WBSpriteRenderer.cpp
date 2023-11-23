#include "WBSpriteRenderer.h"
#include "WBGameObject.h"
#include "WBTransform.h"

wb::WBSpriteRenderer::WBSpriteRenderer()
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
	HBRUSH redBrush
		= CreateSolidBrush(RGB(255, 0, 255));

	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, redBrush);

	HPEN bluePen = CreatePen(PS_SOLID, 2, RGB(rand(), rand(), rand()));
	HPEN oldPen = (HPEN)SelectObject(hdc, bluePen);
	SelectObject(hdc, oldPen);

	WBTransform* tr = GetOwner()->GetComponent<WBTransform>();
	Ellipse(hdc, tr->GetX(), tr->GetY(),
		100 + tr->GetX(), 100 + tr->GetY());

	SelectObject(hdc, oldBrush);
	DeleteObject(redBrush);
	DeleteObject(bluePen);
}
