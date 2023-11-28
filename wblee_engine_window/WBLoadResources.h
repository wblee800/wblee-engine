#pragma once
#include "..\wblee_engine_source\WBResources.h"
#include "..\wblee_engine_source\WBTexture.h"

namespace wb
{
	void LoadResources()
	{
		WBResources::Load<graphics::WBTexture>(L"BG", L"..\\resources\\sprites\\miscellaneous\\Cloudy Ocean.png");
	}
}