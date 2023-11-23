#pragma once
#include "common_include.h"
#include "WBComponent.h"

namespace wb
{
	// Unity : Object
	// Unreal : Actor (is same above)
	class WBGameObject
	{
	public:
		WBGameObject();
		~WBGameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		template<typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->SetOwner(this);
			mComponents.push_back(comp);

			return comp;
		}

		template <typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (WBComponent* comp : mComponents)
			{
				// dynamic_cast : �θ�-�ڽ� ���� ����ȯ
				component = dynamic_cast<T*> (comp);

				if (component)
					break;
			}

			return component;
		}

	private:
		std::vector<WBComponent*> mComponents;
	};
}