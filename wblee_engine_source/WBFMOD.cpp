#include "WBFMOD.h"

namespace wb
{
	FMOD::Studio::System* WBFMOD::mSystem = nullptr;
	FMOD::System* WBFMOD::mCoreSystem = nullptr;

	void WBFMOD::Initialize()
	{
		void* extraDriverData = nullptr;

		FMOD::Studio::System::create(&mSystem);

		mSystem->getCoreSystem(&mCoreSystem);
		mCoreSystem->setSoftwareFormat(0, FMOD_SPEAKERMODE_5POINT1, 0);

		mSystem->initialize(1024, FMOD_STUDIO_INIT_NORMAL, FMOD_INIT_NORMAL, extraDriverData);
	}

	bool WBFMOD::CreateSound(const std::string& path, FMOD::Sound** sound)
	{
		if (FMOD_OK != mCoreSystem->createSound(path.c_str(), FMOD_3D, 0, sound))
			return false;

		return true;
	}

	void WBFMOD::SoundPlay(FMOD::Sound* sound, FMOD::Channel** channel)
	{
		mCoreSystem->playSound(sound, 0, false, channel);
	}

	void WBFMOD::Set3DListenerAttributes(const math::Vector2* pos)
	{
		//-1 ~ 1
		FMOD_VECTOR fmodPos(0.0f, 0.0f, 0.3f);
		FMOD_VECTOR fmodVel(0.0f, 0.0f, 0.0f);
		FMOD_VECTOR fmodForward(0.0f, 0.0f, 1.0f);
		FMOD_VECTOR fmodUp(0.0f, 1.0f, 0.0f);

		mCoreSystem->set3DListenerAttributes(0, &fmodPos, &fmodVel, &fmodForward, &fmodUp);
	}

	void WBFMOD::Release()
	{
		mSystem->release();
		mSystem = nullptr;
	}
}