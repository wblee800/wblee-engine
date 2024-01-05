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
		enum class eState
		{
			Active,
			Paused,
			Dead,
			End
		};

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
			comp->Initialize();
			comp->SetOwner(this);

			mComponents[(UINT)comp->GetType()] = comp;

			return comp;
		}

		template <typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (WBComponent* comp : mComponents)
			{
				// dynamic_cast : 부모-자식 간의 형변환
				component = dynamic_cast<T*> (comp);

				if (component)
					break;
			}

			return component;
		}

		eState GetState() { return mState; }
		void SetActive(bool power)
		{
			if (power == true) mState = eState::Active;
			if (power == false) mState = eState::Paused;
		}
		bool IsActive() { return mState == eState::Active; }
		bool IsDead() { return mState == eState::Dead; }
		void SetLayerType(enums::eLayerType layerType) { mLayerType = layerType; }
		enums::eLayerType GetLayerType() { return mLayerType; }

	private:
		void initializeTransform();

	private:
		eState mState;
		std::vector<WBComponent*> mComponents;
		enums::eLayerType mLayerType;
	};
}