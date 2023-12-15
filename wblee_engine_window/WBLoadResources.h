#pragma once
#include "..\\wblee_engine_source\WBResources.h"
#include "..\wblee_engine_source\WBTexture.h"

namespace wb
{
	void LoadResources()
	{
		// Title
		WBResources::Load<graphics::WBTexture>(L"Title", L"..\\resources\\sprites\\miscellaneous\\Title_Screen.bmp");
		WBResources::Load<graphics::WBTexture>(L"Cloudy_Night_Ocean", L"..\\resources\\sprites\\miscellaneous\\Cloudy_Night_Ocean.bmp");
		WBResources::Load<graphics::WBTexture>(L"Logo", L"..\\resources\\sprites\\miscellaneous\\Logo.bmp");

		// Maps
		WBResources::Load<graphics::WBTexture>(L"Joja_Mart", L"..\\resources\\sprites\\maps\\Joja_Mart.bmp");
		WBResources::Load<graphics::WBTexture>(L"Bus_Stop", L"..\\resources\\sprites\\maps\\Bus_Stop.bmp");
		WBResources::Load<graphics::WBTexture>(L"Standard_Farm", L"..\\resources\\sprites\\maps\\Standard_Farm.bmp");
		WBResources::Load<graphics::WBTexture>(L"Pelican_Town", L"..\\resources\\sprites\\maps\\Pelican_Town.bmp");
		WBResources::Load<graphics::WBTexture>(L"Calico_Desert", L"..\\resources\\sprites\\maps\\Calico_Desert.bmp");
		WBResources::Load<graphics::WBTexture>(L"Gate_Sewer", L"..\\resources\\sprites\\maps\\Gate_Sewer.bmp");
		WBResources::Load<graphics::WBTexture>(L"Sewer", L"..\\resources\\sprites\\maps\\Sewer.bmp");
		WBResources::Load<graphics::WBTexture>(L"Beach", L"..\\resources\\sprites\\maps\\Beach.bmp");
		WBResources::Load<graphics::WBTexture>(L"Skull_Cavern_Entrance", L"..\\resources\\sprites\\maps\\Skull_Cavern_Entrance.bmp");
		WBResources::Load<graphics::WBTexture>(L"Skull_Cavern", L"..\\resources\\sprites\\maps\\Skull_Cavern.bmp");
		WBResources::Load<graphics::WBTexture>(L"General_Store_Of_Pierre", L"..\\resources\\sprites\\maps\\General_Store_Of_Pierre.bmp");
		WBResources::Load<graphics::WBTexture>(L"Community_Center", L"..\\resources\\sprites\\maps\\Community_Center.bmp");
		WBResources::Load<graphics::WBTexture>(L"Theater_Box_Office", L"..\\resources\\sprites\\maps\\Theater_Box_Office.bmp");
		WBResources::Load<graphics::WBTexture>(L"Theater_Screen", L"..\\resources\\sprites\\maps\\Theater_Screen.bmp");
		WBResources::Load<graphics::WBTexture>(L"Blacksmith", L"..\\resources\\sprites\\maps\\Blacksmith.bmp");
		WBResources::Load<graphics::WBTexture>(L"Ranch_Of_Marnie", L"..\\resources\\sprites\\maps\\Ranch_Of_Marnie.bmp");
		WBResources::Load<graphics::WBTexture>(L"Shop_Of_Carpenter", L"..\\resources\\sprites\\maps\\Shop_Of_Carpenter.bmp");

		// Equipments
		WBResources::Load<graphics::WBTexture>(L"Tools", L"..\\resources\\sprites\\equipments\\Tools.bmp");
		WBResources::Load<graphics::WBTexture>(L"Weapons", L"..\\resources\\sprites\\equipments\\Weapons.bmp");

		// Animals
		WBResources::Load<graphics::WBTexture>(L"Cat", L"..\\resources\\sprites\\characters\\animals\\CatAlpha.bmp");

		// Players
		WBResources::Load<graphics::WBTexture>(L"Player", L"..\\resources\\sprites\\characters\\players\\Player.bmp");
		WBResources::Load<graphics::WBTexture>(L"Player_Move_Front", L"..\\resources\\sprites\\characters\\players\\Player_Move_Front.bmp");
		WBResources::Load<graphics::WBTexture>(L"Player_Sit_Down", L"..\\resources\\sprites\\characters\\players\\Player_Sit_Down.bmp");
		WBResources::Load<graphics::WBTexture>(L"Player_Stand_Up", L"..\\resources\\sprites\\characters\\players\\Player_Stand_Up.bmp");
		WBResources::Load<graphics::WBTexture>(L"Player_Swing_An_Axe_Right", L"..\\resources\\sprites\\characters\\players\\Player_Swing_An_Axe_Right.bmp");
		WBResources::Load<graphics::WBTexture>(L"Player_Pickaxe_Left", L"..\\resources\\sprites\\characters\\players\\Player_Pickaxe_Left.bmp");

		// Skills
		WBResources::Load<graphics::WBTexture>(L"Fireball", L"..\\resources\\sprites\\miscellaneous\\Fireball.bmp");
	}
}