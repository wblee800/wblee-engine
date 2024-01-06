#include "WBCollider.h"

namespace wb
{
	UINT32 WBCollider::CollisionID = 1;

	WBCollider::WBCollider()
		: WBComponent(enums::eComponentType::Collider),
		mOffset(math::Vector2::Zero),
		mID(CollisionID++),
		mSize(math::Vector2::One)
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

	void WBCollider::OnCollisionEnter(WBCollider* other)
	{
	}

	void WBCollider::OnCollisionStay(WBCollider* other)
	{
	}

	void WBCollider::OnCollisionExit(WBCollider* other)
	{
	}
}