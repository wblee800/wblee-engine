#pragma once
#include "WBComponent.h"
#include "WBGameObject.h"
#include "WBLayer.h"
#include "WBScene.h"
#include "WBSceneManager.h"
#include "WBTransform.h"

namespace wb
{
	namespace object
	{
		template <typename T>
		static T* Instantiate(wb::enums::eLayerType layerType)
		{
			T* gameObject = new T();
			WBScene* activeScene = WBSceneManager::GetActiveScene();
			WBLayer* layer = activeScene->GetLayer(layerType);
			layer->AddGameObject(gameObject);

			return gameObject;
		}

		template <typename T>
		static T* Instantiate(wb::enums::eLayerType layerType, Vector2 position)
		{
			T* gameObject = new T();
			WBScene* activeScene = WBSceneManager::GetActiveScene();
			WBLayer* layer = activeScene->GetLayer(layerType);
			layer->AddGameObject(gameObject);

			WBTransform* tr = gameObject->GetComponent<WBTransform>();
			tr->SetPos(position);

			return gameObject;
		}
	}
}