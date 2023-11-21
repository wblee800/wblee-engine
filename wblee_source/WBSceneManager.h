#pragma once
#include "common_include.h"

namespace wb
{
	class WBScene;

	class WBSceneManager
	{
	public:
		template <typename T>
		static WBScene* CreateScene(const std::wstring& name)
		{
			T* scene = new T();
			scene->SetName(name);
			scene->Initialize();

			mScene.insert(std::make_pair(name, scene));

			return scene;
		}

		static WBScene* LoadScene(const std::wstring& name)
		{
			std::map<const std::wstring, WBScene*>::iterator itr 
				= mScene.find(name);

			if (itr == mScene.end())
				return nullptr;

			mActiveScene = itr->second;

			return itr->second;
		}

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

	private:
		static std::map<const std::wstring, WBScene*> mScene;
		static WBScene* mActiveScene;
	};
} 