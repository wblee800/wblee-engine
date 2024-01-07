#pragma once
#include "common_include.h"
#include "..\\external\\include\\fmod\fmod_studio.hpp"
#include "..\\external\\include\\fmod\\fmod.hpp"
#include "..\\external\\include\\fmod\\fmod_common.h"
#include "..\\external\\include\\fmod\\fmod_codec.h"

#ifdef _DEBUG
#pragma comment(lib, "..\\external\\library\\fmod\\debug\\fmodL_vc.lib")
#pragma comment(lib, "..\\external\\library\\fmod\\debug\\fmodstudioL_vc.lib")
#else
#pragma comment(lib, "..\\external\\library\\fmod\\debug\\fmod_vc.lib")
#pragma comment(lib, "..\\external\\library\\fmod\\release\\fmodstudio_vc.lib")
#endif

namespace wb
{
	class WBFMOD
	{
	public:
		static void Initialize();
		static bool CreateSound(const std::string& path, FMOD::Sound** sound);
		static void SoundPlay(FMOD::Sound* sound, FMOD::Channel** channel);
		static void Set3DListenerAttributes(const math::Vector2* pos);
		static void Release();

	private:
		static FMOD::Studio::System* mSystem;
		static FMOD::System* mCoreSystem;
	};
}