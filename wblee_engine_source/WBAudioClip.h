#pragma once
#include "WBFMOD.h"
#include "WBResource.h"

namespace wb
{
	class WBAudioClip : public WBResource
	{
	public:
		WBAudioClip();
		virtual ~WBAudioClip();

		virtual HRESULT Load(const std::wstring& path) override;

		void Play();
		void Stop();
		void Set3DAttributes(const math::Vector2 pos);
		void SetLoop(bool loop) { mbLoop = loop; }

	private:
		FMOD::Sound* mSound;
		FMOD::Channel* mChannel;
		float mMinDistance;
		float mMaxDistance;
		bool mbLoop;
	};
}