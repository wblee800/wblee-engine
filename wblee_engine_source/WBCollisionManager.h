#pragma once
#include "common_include.h"

namespace wb
{
	// union(공용체) : 데이터를 나눠서 사용할 수 있게 해주는 문법
	union CollisionID
	{
		struct
		{
			UINT32 left;
			UINT32 right;
		};

		UINT64 id;
	};

	class WBScene;
	class WBCollider;
	class WBCollisionManager
	{
	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

		static void CollisionLayerCheck(enums::eLayerType left, enums::eLayerType right, bool enable);
		static void LayerCollision(enums::eLayerType row, enums::eLayerType col);
		static void ColliderCollision(WBCollider* left, WBCollider* right);\
		static bool Intersect(WBCollider* left, WBCollider* right);

	private:
		// bit 단위로 값을 저장하는 배열
		static std::bitset<(UINT)enums::eLayerType::Max> mCollisionLayerMatrix[(UINT)enums::eLayerType::Max];
		// 누구와 충돌 중인지 체크
		static std::unordered_map<UINT64, bool> mCollisionMap;
	};
}