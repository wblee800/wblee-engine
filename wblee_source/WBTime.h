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
		// �� pc�� cpu�� ���� ������
		static LARGE_INTEGER CpuFrequency;
		// ���� ������
		static LARGE_INTEGER PrevFrequency;
		// ���� ������
		static LARGE_INTEGER CurrentFrequency;
		// (���� ������ - ���� ������) / ���� ������
		static float DeltaTimeValue;
	};
}