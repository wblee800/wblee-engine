#include "WBCamera.h"
#include "WBGameObject.h"
#include "WBTransform.h"

namespace wb
{
	math::Vector2 WBCamera::CalculatePos(math::Vector2 pos)
	{
		return pos - mDistance;
	}

	WBCamera::WBCamera()
		:WBComponent(enums::eComponentType::Camera)
		, mDistance(Vector2::Zero)
		, mResolution(Vector2(1600.0f, 900.0f))
		, mLookPos(Vector2::Zero)
		, mTarget(nullptr)
	{
	}

	WBCamera::~WBCamera()
	{
	}

	void WBCamera::Initialize()
	{
	}

	void WBCamera::Update()
	{
		if (mTarget)
		{
			WBTransform* tr = mTarget->GetComponent<WBTransform>();
			// 특정 오브젝트가 화면의 중심이 되게 설정
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