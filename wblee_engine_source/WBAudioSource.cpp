#include "WBGameObject.h"
#include "WBAudioSource.h"
#include "WBTransform.h"

namespace wb
{
	WBAudioSource::WBAudioSource()
		:WBComponent(enums::eComponentType::AudioSource),
		mAudioClip()
	{
	}

	WBAudioSource::~WBAudioSource()
	{
	}

	void WBAudioSource::Initialize()
	{
	}

	void WBAudioSource::Update()
	{
	}

	void WBAudioSource::LateUpdate()
	{
		WBTransform* tr = GetOwner()->GetComponent<WBTransform>();
		Vector2 pos = tr->GetPosition();

		mAudioClip->Set3DAttributes(pos);
	}

	void WBAudioSource::Render(HDC hdc)
	{
	}

	void WBAudioSource::Play()
	{
		mAudioClip->Play();
	}

	void WBAudioSource::Stop()
	{
		mAudioClip->Stop();
	}

	void WBAudioSource::SetLoop(bool loop)
	{
		mAudioClip->SetLoop(loop);
	}
}