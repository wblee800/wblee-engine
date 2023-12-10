#pragma once
#include "..\\wblee_engine_source\WBResources.h"
#include "..\wblee_engine_source\WBTexture.h"

namespace wb
{
	void LoadResources()
	{
		WBResources::Load<graphics::WBTexture>(L"Joja_Mart", L"..\\resources\\sprites\\maps\\JojaMart.png");
		WBResources::Load<graphics::WBTexture>(L"Player", L"..\\resources\\sprites\\characters\\npcs\\Bouncer.png");
		WBResources::Load<graphics::WBTexture>(L"Cat", L"..\\resources\\sprites\\characters\\animals\\CatAlpha.bmp");
		WBResources::Load<graphics::WBTexture>(L"Title", L"..\\resources\\sprites\\miscellaneous\\Title_Screen.bmp");
		WBResources::Load<graphics::WBTexture>(L"Cloudy_Night_Ocean", L"..\\resources\\sprites\\miscellaneous\\Cloudy_Night_Ocean.bmp");
		WBResources::Load<graphics::WBTexture>(L"Logo", L"..\\resources\\sprites\\miscellaneous\\Logo.bmp");
	}
}