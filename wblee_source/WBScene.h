#pragma once
#include "common_include.h"
#include "WBEntity.h"

namespace wb
{
	class WBGameObject;

	class WBScene : public WBEntity
	{
	public:
		WBScene();
		~WBScene();

		void Initialize();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

	private:
		std::vector<WBGameObject*> mGameObjects;
	};
}