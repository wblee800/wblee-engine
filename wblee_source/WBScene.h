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

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(WBGameObject* gameObject);

	private:
		std::vector<WBGameObject*> mGameObjects;
	};
}