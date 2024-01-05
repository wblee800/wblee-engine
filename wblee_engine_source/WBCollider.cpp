#include "WBCollider.h"

namespace wb
{
	WBCollider::WBCollider()
		: WBComponent(enums::eComponentType::Collider),
		mOffset(math::Vector2::Zero),
		mID(CollisionID++)
	{
	}

	WBCollider::~WBCollider()
	{
	}

	void WBCollider::Initialize()
	{
	}

	void WBCollider::Update()
	{
	}

	void WBCollider::LateUpdate()
	{
	}

	void WBCollider::Render(HDC hdc)
	{
	}
}