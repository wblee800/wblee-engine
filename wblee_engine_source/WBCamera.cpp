#include "WBCamera.h"
#include "WBGameObject.h"
#include "WBTransform.h"
#include "WBApplication.h"

extern wb::WBApplication application;

namespace wb
{
	math::Vector2 WBCamera::CalculatePos(math::Vector2 pos)
	{
		return pos - mDistance;
	}

	WBCamera::WBCamera()
		:WBComponent(enums::eComponentType::Camera)
		, mDistance(Vector2::Zero)
		, mResolution(Vector2::Zero)
		, mLookPos(Vector2::Zero)
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
		if (mTarget)
		{
			WBTransform* tr = mTarget->GetComponent<WBTransform>();
			// Ư�� ������Ʈ�� ȭ���� �߽��� �ǰ� ����
			mLookPos = tr->GetPos();
		}

		WBTransform* cameraTr = GetOwner()->GetComponent<WBTransform>();
		mLookPos = cameraTr->GetPos();

		// Moving distance in Windows axis
		mDistance = mLookPos - (mResolution / 2.0f);
	}

	void WBCamera::LateUpdate()
	{
	}

	void WBCamera::Render(HDC hdc)
	{
	}

}