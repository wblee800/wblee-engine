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
		// sprite�� ũ�⸦ ���� Ű��ų�, ȸ���� �� �� ������,
		// sprite�� collider�� �ִ� ��츦 ����� transfrom���� ������ �� �ְ�
		// mScale�� mRotation ����
		Vector2 mScale;
		float mRotation;
	};
}