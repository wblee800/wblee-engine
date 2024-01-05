#pragma once
#include "common_include.h"

namespace wb
{
	class WBScene;

	class WBGameObject;
	class WBSceneManager
	{
	public:
		template <typename T>
		static WBScene* CreateScene(const std::wstring& name)
		{
			T* scene = new T();
			scene->SetName(name);
			mActiveScene = scene;
			scene->Initialize();

			mScene.insert(std::make_pair(name, scene));

			return scene;
		}

		static WBScene* LoadScene(const std::wstring& name);
		static WBScene* GetActiveScene() { return mActiveScene; }
		static std::vector<WBGameObject*> GetGameObjects(enums::eLayerType layer);

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

		static void Destroy();
		static void Release();

	private:
		static std::map<const std::wstring, WBScene*> mScene;
		static WBScene* mActiveScene;
		static WBScene* mDontDestroyOnLoad;
	};
}