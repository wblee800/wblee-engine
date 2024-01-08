#pragma once
#include "WBComponent.h"
#include "WBAudioClip.h"

namespace wb
{
	class WBAudioSource : public WBComponent
	{
	public:
		WBAudioSource();
		~WBAudioSource();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void Play();
		void Stop();
		void SetLoop(bool loop);

		void SetClip(WBAudioClip* clip) { mAudioClip = clip; }
		WBAudioClip* GetClip() { return mAudioClip; }

	private:
		WBAudioClip* mAudioClip;
	};
}