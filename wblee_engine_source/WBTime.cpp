#include "WBTime.h"

namespace wb
{
	// .h���� ������ ���� ������ �ڷ����� �ٽ� cpp���� �ۼ��� �־�� �ϴ� ����
	//  
	LARGE_INTEGER WBTime::CpuFrequency = {};
	LARGE_INTEGER WBTime::PrevFrequency = {};
	LARGE_INTEGER WBTime::CurrentFrequency = {};
	float WBTime::DeltaTimeValue = 0.0f;

	void WBTime::Initialize()
	{
		//CPU�� ���� ������
		QueryPerformanceFrequency(&CpuFrequency);

		// ���α׷��� �������� ���� ���� ��
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

		// �ʴ� ������ ����
		float fps = 1.0f / DeltaTimeValue;

		wchar_t str[50] = L"";
		// swprintf_s(str, 50, L"Time : %f", time);
		swprintf_s(str, 50, L"FPS : %d", (int)fps);
		int len = wcsnlen_s(str, 50);

		TextOut(hdc, 0, 0, str, len);
	}
}