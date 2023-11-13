#pragma once
#include "common_include.h"

namespace wb
{
	class WBTime
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		static float DeltaTime() { return DeltaTimeValue; }

	private:
		// 내 pc의 cpu의 고유 진동수
		static LARGE_INTEGER CpuFrequency;
		// 이전 진동수
		static LARGE_INTEGER PrevFrequency;
		// 현재 진동수
		static LARGE_INTEGER CurrentFrequency;
		// (현재 진동수 - 이전 진동수) / 고유 진동수
		static float DeltaTimeValue;
	};
}