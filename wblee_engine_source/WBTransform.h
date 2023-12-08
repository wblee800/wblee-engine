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

		void SetPos(Vector2 pos) { mPosition.x = pos.x; mPosition.y = pos.y; }
		Vector2 GetPos() { return mPosition; }

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