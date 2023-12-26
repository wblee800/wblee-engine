#include "WBCamera.h"
#include "WBGameObject.h"
#include "WBTransform.h"
#include "WBApplication.h"

extern wb::WBApplication application;

namespace wb
{
	math::Vector2 WBCamera::CalculatePos(math::Vector2 position)
	{
		return position - mDistance;
	}

	WBCamera::WBCamera()
		:WBComponent(enums::eComponentType::Camera)
		, mDistance(Vector2::Zero)
		, mResolution(Vector2::Zero)
		, mLookPosition(Vector2::Zero)
		, mTarget(nullptr)
	{
	}

	WBCamera::~WBCamera()
	{
	}

	void WBCamera::Initialize()
	{
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();
	}

	void WBCamera::Update()
	{
		// If a target exists,
		if (mTarget)
		{
			WBTransform* tr = mTarget->GetComponent<WBTransform>();
			// Ư�� ������Ʈ�� ȭ���� �߽��� �ǰ� ����
			mLookPosition = tr->GetPosition();
		}
		else
		{
			WBTransform* cameraTr = GetOwner()->GetComponent<WBTransform>();
			mLookPosition = cameraTr->GetPosition();
		}

		// Moving distance in Windows axis
		mDistance = mLookPosition - (mResolution / 2.0f);
	}

	void WBCamera::LateUpdate()
	{
	}

	void WBCamera::Render(HDC hdc)
	{
	}
}