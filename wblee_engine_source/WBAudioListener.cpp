#include "WBAudioListener.h"
#include "WBTransform.h"
#include "WBGameObject.h"
#include "WBFmod.h"

namespace wb
{
	WBAudioListener::WBAudioListener()
		: WBComponent(enums::eComponentType::AudioListener)
	{
	}

	WBAudioListener::~WBAudioListener()
	{
	}

	void WBAudioListener::Initialize()
	{
	}

	void WBAudioListener::Update()
	{
	}

	void WBAudioListener::LateUpdate()
	{
		WBTransform* tr = GetOwner()->GetComponent<WBTransform>();
		Vector2 pos = tr->GetPosition();

		WBFMOD::Set3DListenerAttributes(&pos);
	}

	void WBAudioListener::Render(HDC hdc)
	{
	}

}