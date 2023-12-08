#include "WBTransform.h"

wb::WBTransform::WBTransform()
	: WBComponent(enums::eComponentType::Transform)
	, mPosition(Vector2::Zero)
	, mScale(Vector2(1.0f, 1.0f))
	, mRotation(0.0f)
{
}

wb::WBTransform::~WBTransform()
{
}

void wb::WBTransform::Initialize()
{
}

void wb::WBTransform::Update()
{
}

void wb::WBTransform::LateUpdate()
{
}

void wb::WBTransform::Render()
{
}
