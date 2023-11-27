#pragma once
#include "WBEntity.h"
#include "common_include.h"

namespace wb
{
	class WBGameObject;
	class WBLayer : public WBEntity
	{
	public:
		WBLayer();
		~WBLayer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(WBGameObject* gameObject);

	private:
		// eLayerType mLayerType;
		std::vector<WBGameObject*> mGameObjects;
	};
}