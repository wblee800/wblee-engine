#include "WBTime.h"

namespace wb
{
	// .h에서 선언한 정적 변수의 자료형을 다시 cpp에서 작성해 주어야 하는 이유
	//  
	LARGE_INTEGER WBTime::CpuFrequency = {};
	LARGE_INTEGER WBTime::PrevFrequency = {};
	LARGE_INTEGER WBTime::CurrentFrequency = {};
	float WBTime::DeltaTimeValue = 0.0f;

	void WBTime::Initialize()
	{
		//CPU의 고유 진동수
		QueryPerformanceFrequency(&CpuFrequency);

		// 프로그램이 시작했을 때의 진동 수
		QueryPerformanceCounter(&PrevFrequency);
	}

	void WBTime::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);

		float differenceFrequency
			= static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);
		DeltaTimeValue = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart);

		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}

	void WBTime::Render(HDC hdc)
	{
		static float time = 0.0f;

		time += DeltaTimeValue;

		// 초당 프레임 측정
		float fps = 1.0f / DeltaTimeValue;

		wchar_t str[50] = L"";
		// swprintf_s(str, 50, L"Time : %f", time);
		swprintf_s(str, 50, L"FPS : %d", (int)fps);
		int len = wcsnlen_s(str, 50);

		TextOut(hdc, 0, 0, str, len);
	}
}