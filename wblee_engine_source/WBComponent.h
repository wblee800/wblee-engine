#pragma once
#include "WBEntity.h"

namespace wb
{
	class WBGameObject;
	class WBComponent : public WBEntity
	{
	public:
		WBComponent();
		~WBComponent();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetOwner(WBGameObject* owner) { mOwner = owner; }
		WBGameObject* GetOwner() { return mOwner; }
	private:
		// 전방선언
		WBGameObject* mOwner;
	};
}