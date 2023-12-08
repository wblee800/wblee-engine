#pragma once
#include "..\\wblee_engine_source\WBResources.h"
#include "..\wblee_engine_source\WBTexture.h"

namespace wb
{
	void LoadResources()
	{
		WBResources::Load<graphics::WBTexture>(L"Map", L"..\\resources\\sprites\\maps\\JojaMart.png");
		WBResources::Load<graphics::WBTexture>(L"Player", L"..\\resources\\sprites\\characters\\npcs\\Bouncer.png");
		WBResources::Load<graphics::WBTexture>(L"Cat", L"..\\resources\\sprites\\characters\\animals\\CatAlpha.bmp");
		WBResources::Load<graphics::WBTexture>(L"Fireball", L"..\\resources\\sprites\\miscellaneous\\Fireball.png");
	}
}