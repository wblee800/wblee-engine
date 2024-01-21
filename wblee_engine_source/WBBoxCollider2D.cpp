#include "WBBoxCollider2D.h"
#include "WBGameObject.h"
#include "WBTransform.h"
#include "WBRenderer.h"
#include "WBCamera.h"

namespace wb
{
	WBBoxCollider2D::WBBoxCollider2D()
		:mSize(math::Vector2(10.0f, 10.0f))
	{
	}

	WBBoxCollider2D::~WBBoxCollider2D()
	{
	}

	void WBBoxCollider2D::Initialize()
	{
	}

	void WBBoxCollider2D::Update()
	{
	}

	void WBBoxCollider2D::LateUpdate()
	{
	}

	void WBBoxCollider2D::Render(HDC hdc)
	{
		WBTransform* tr = GetOwner()->GetComponent<WBTransform>();
		Vector2 pos = tr->GetPosition();

		if (renderer::mainCamera)
			pos = renderer::mainCamera->CalculatePos(pos);

		Vector2 offset = GetOffset();

		HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH originalBrush = (HBRUSH)SelectObject(hdc, transparentBrush);

		HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		HPEN originalPen = (HPEN)SelectObject(hdc, greenPen);

		Rectangle(hdc,
			pos.x + offset.x - ((mSize.x * GetSize().x) / 2.0f),
			pos.y + offset.y - ((mSize.y * GetSize().y) / 2.0f),
			pos.x + offset.x + ((mSize.x * GetSize().x) / 2.0f),
			pos.y + offset.y + ((mSize.y * GetSize().y) / 2.0f));

		SelectObject(hdc, originalBrush);
		SelectObject(hdc, originalPen);
		DeleteObject(greenPen);
	}
}