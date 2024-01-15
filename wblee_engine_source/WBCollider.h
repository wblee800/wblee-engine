#pragma once
#include "WBComponent.h"

namespace wb
{
	class WBCollider : public WBComponent
	{
	public:
		WBCollider();
		~WBCollider();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		virtual void OnCollisionEnter(WBCollider* other);
		virtual void OnCollisionStay(WBCollider* other);
		virtual void OnCollisionExit(WBCollider* other);

		math::Vector2 GetOffset() { return mOffset; }
		void SetOffset(math::Vector2 offset) { mOffset = offset; }
		// �浹ü���� ������ ID Ȯ�� �����ϵ��� GetID() ����
		UINT32 GetID() { return mID; }
		// �浹ü ������ ���� �� ��������
		math::Vector2 GetSize() { return mSize; }
		void SetSize(math::Vector2 size) { mSize = size; }
		// �浹 ���� ���� �� ��������
		enums::eColliderType GetColiiderType() { return mColliderType; }
		void SetColiiderType(enums::eColliderType colliderType)	{ mColliderType = colliderType;	}

	private:
		static UINT32 CollisionID;
		UINT32 mID;
		math::Vector2 mOffset;
		math::Vector2 mSize;
		enums::eColliderType mColliderType;
	};
}