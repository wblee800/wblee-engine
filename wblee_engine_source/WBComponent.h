#pragma once
#include "WBEntity.h"

namespace wb
{
	class WBGameObject;
	class WBComponent : public WBEntity
	{
	public:
		WBComponent(enums::eComponentType type);
		~WBComponent();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetOwner(WBGameObject* owner) { mOwner = owner; }
		WBGameObject* GetOwner() { return mOwner; }
		enums::eComponentType GetType() { return mType; }
	private:
		// Forward declaration
		WBGameObject* mOwner;
		enums::eComponentType mType;
	};
}