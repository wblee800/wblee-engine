#pragma once
#include "..\\wblee_engine_source\WBResources.h"
#include "..\wblee_engine_source\WBTexture.h"

namespace wb
{
	void LoadResources()
	{
		// ----Title----
		WBResources::Load<graphics::WBTexture>(L"Title", L"..\\resources\\sprites\\miscellaneous\\Title_Screen.bmp");
		WBResources::Load<graphics::WBTexture>(L"Cloudy_Night_Ocean", L"..\\resources\\sprites\\miscellaneous\\Cloudy_Night_Ocean.bmp");
		WBResources::Load<graphics::WBTexture>(L"Logo", L"..\\resources\\sprites\\miscellaneous\\Logo.bmp");

		// ----Tile Maps----
		

		// ----Maps----
		// Farm
		WBResources::Load<graphics::WBTexture>(L"Standard_Farm_Up", L"..\\resources\\sprites\\maps\\Standard_Farm_Up.png");
		WBResources::Load<graphics::WBTexture>(L"Standard_Farm_Down", L"..\\resources\\sprites\\maps\\Standard_Farm_Down.png");
		WBResources::Load<graphics::WBTexture>(L"Farmhouse", L"..\\resources\\sprites\\maps\\Farmhouse.png");
		WBResources::Load<graphics::WBTexture>(L"Bed_In_Farmhouse", L"..\\resources\\sprites\\maps\\Bed_In_Farmhouse.png");
		WBResources::Load<graphics::WBTexture>(L"Shop_Of_Carpenter", L"..\\resources\\sprites\\maps\\Shop_Of_Carpenter.bmp");
		WBResources::Load<graphics::WBTexture>(L"Ranch_Of_Marnie", L"..\\resources\\sprites\\maps\\Ranch_Of_Marnie.bmp");
		WBResources::Load<graphics::WBTexture>(L"Secret_Woods", L"..\\resources\\sprites\\maps\\Secret_Woods.bmp");

		// Sewer
		WBResources::Load<graphics::WBTexture>(L"Gate_Sewer", L"..\\resources\\sprites\\maps\\Gate_Sewer.png");
		WBResources::Load<graphics::WBTexture>(L"Sewer", L"..\\resources\\sprites\\maps\\Sewer.bmp");

		// Bus Stop
		WBResources::Load<graphics::WBTexture>(L"Bus_Stop", L"..\\resources\\sprites\\maps\\Bus_Stop.png");

		// Calico Desert
		WBResources::Load<graphics::WBTexture>(L"Calico_Desert", L"..\\resources\\sprites\\maps\\Calico_Desert.png");
		WBResources::Load<graphics::WBTexture>(L"Skull_Cavern_Entrance", L"..\\resources\\sprites\\maps\\Skull_Cavern_Entrance.png");
		WBResources::Load<graphics::WBTexture>(L"Skull_Cavern", L"..\\resources\\sprites\\maps\\Skull_Cavern.bmp");

		// Pelican Town
		WBResources::Load<graphics::WBTexture>(L"Pelican_Town", L"..\\resources\\sprites\\maps\\Pelican_Town.png");
		WBResources::Load<graphics::WBTexture>(L"Joja_Mart", L"..\\resources\\sprites\\maps\\Joja_Mart.bmp");
		WBResources::Load<graphics::WBTexture>(L"General_Store_Of_Pierre", L"..\\resources\\sprites\\maps\\General_Store_Of_Pierre.bmp");
		WBResources::Load<graphics::WBTexture>(L"Restored_Community_Center_Indoor", L"..\\resources\\sprites\\maps\\Restored_Community_Center_Indoor.bmp");
		WBResources::Load<graphics::WBTexture>(L"Theater_Box_Office", L"..\\resources\\sprites\\maps\\Theater_Box_Office.bmp");
		WBResources::Load<graphics::WBTexture>(L"Theater_Screen", L"..\\resources\\sprites\\maps\\Theater_Screen.bmp");
		WBResources::Load<graphics::WBTexture>(L"Blacksmith", L"..\\resources\\sprites\\maps\\Blacksmith.bmp");
		WBResources::Load<graphics::WBTexture>(L"Stardrop_Saloon", L"..\\resources\\sprites\\maps\\Stardrop_Saloon.bmp");

		// Beach
		WBResources::Load<graphics::WBTexture>(L"Beach", L"..\\resources\\sprites\\maps\\Beach.bmp");

		// ----Buildings----
		WBResources::Load<graphics::WBTexture>(L"Restored_Community_Center", L"..\\resources\\sprites\\buildings\\Restored_Community_Center.bmp");

		// ----Equipments----
		WBResources::Load<graphics::WBTexture>(L"Tools", L"..\\resources\\sprites\\equipments\\Tools.bmp");
		WBResources::Load<graphics::WBTexture>(L"Weapons", L"..\\resources\\sprites\\equipments\\Weapons.bmp");

		// ----Animals----
		WBResources::Load<graphics::WBTexture>(L"Cat", L"..\\resources\\sprites\\characters\\animals\\CatAlpha.bmp");

		// ----Player----
		WBResources::Load<graphics::WBTexture>(L"Player", L"..\\resources\\sprites\\characters\\players\\Player.bmp");
		WBResources::Load<graphics::WBTexture>(L"Player_Move_Down", L"..\\resources\\sprites\\characters\\players\\Player_Move_Down.bmp");
		WBResources::Load<graphics::WBTexture>(L"Player_Sit_Down", L"..\\resources\\sprites\\characters\\players\\Player_Sit_Down.bmp");
		WBResources::Load<graphics::WBTexture>(L"Player_Stand_Up", L"..\\resources\\sprites\\characters\\players\\Player_Stand_Up.bmp");
		WBResources::Load<graphics::WBTexture>(L"Player_Swing_An_Axe_Right", L"..\\resources\\sprites\\characters\\players\\Player_Swing_An_Axe_Right.bmp");
		WBResources::Load<graphics::WBTexture>(L"Player_Pickaxe_Left", L"..\\resources\\sprites\\characters\\players\\Player_Pickaxe_Left.bmp");
		WBResources::Load<graphics::WBTexture>(L"Player_Is_Exhausted", L"..\\resources\\sprites\\characters\\players\\Player_Is_Exhausted.bmp");

		// ----Skills----
		WBResources::Load<graphics::WBTexture>(L"Fireball", L"..\\resources\\sprites\\miscellaneous\\Fireball.bmp");
	}
}