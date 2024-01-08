#include "WBAudioClip.h"

namespace wb
{
	WBAudioClip::WBAudioClip()
		: WBResource(enums::eResourceType::AudioClip)
		, mSound(nullptr)
		, mChannel(nullptr)
		, mMinDistance(1.0f)
		, mMaxDistance(1000.0f)
		, mbLoop(false)
	{
	}

	WBAudioClip::~WBAudioClip()
	{
		mSound->release();
		mSound = nullptr;
	}

	HRESULT WBAudioClip::Load(const std::wstring& path)
	{
		std::string cPath(path.begin(), path.end());
		if (!WBFMOD::CreateSound(cPath, &mSound))
			return S_FALSE;

		mSound->set3DMinMaxDistance(mMinDistance, mMaxDistance);

		return S_OK;
	}

	void WBAudioClip::Play()
	{
		if (mbLoop)
			mSound->setMode(FMOD_LOOP_NORMAL);
		else
			mSound->setMode(FMOD_LOOP_OFF);

		WBFMOD::SoundPlay(mSound, &mChannel);
	}

	void WBAudioClip::Stop()
	{
		mChannel->stop();
	}

	void WBAudioClip::Set3DAttributes(const math::Vector2 pos)
	{
		FMOD_VECTOR fmodPos = { 0.0f, 0.0f, 0.0f };
		FMOD_VECTOR fmodVel = { 0.0f, 0.0f, 0.0f };

		mChannel->set3DAttributes(&fmodPos, &fmodVel);
	}

}