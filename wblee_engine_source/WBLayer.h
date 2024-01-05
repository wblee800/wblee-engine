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
		virtual void Destroy();

		void AddGameObject(WBGameObject* gameObject);
		void EraseGameObject(WBGameObject* eraseGameObj);
		const std::vector<WBGameObject*> GetGameObjects() { return mGameObjects; }

	private:
		void findDeadGameObjects(OUT std::vector<WBGameObject*>& gameObjs);
		void deleteGameObjects(std::vector<WBGameObject*> deleteObjs);
		void eraseDeadGameObject();

	private:
		std::vector<WBGameObject*> mGameObjects;
	};
}