#pragma once
#include "WBComponent.h"

namespace wb
{
	using namespace math;
	class WBTransform : public WBComponent
	{
	public:
		WBTransform();
		~WBTransform();

		void Initialize();
		void Update();
		void LateUpdate();
		void Render();

		void SetPosition(Vector2 position) { mPosition.x = position.x; mPosition.y = position.y; }
		Vector2 GetPosition() { return mPosition; }

		void SetScale(Vector2 scale) { mScale = scale; }
		Vector2 GetScale() { return mScale; }

		void SetRotation(float rotation) { mRotation = rotation; }
		float GetRotation() { return mRotation; }

	private:
		Vector2 mPosition;
		// sprite의 크기를 직접 키우거나, 회전을 할 수 있지만,
		// sprite에 collider가 있는 경우를 고려해 transfrom에서 조절할 수 있게
		// mScale과 mRotation 생성
		Vector2 mScale;
		float mRotation;
	};
}