#pragma once
#include "common_include.h"
#include "WBEntity.h"

namespace wb
{
	class WBGameObject;
	class WBLayer;
	class WBScene : public WBEntity
	{
	public:
		WBScene();
		~WBScene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(WBGameObject* gameObj, const eLayerType layerType);

	private:
		std::vector<WBLayer*> mLayers;
	};
}