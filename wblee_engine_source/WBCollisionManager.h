#pragma once
#include "common_include.h"

namespace wb
{
	union CollisionID
	{
		struct
		{
			UINT32 left;
			UINT32 right;
		};

		UINT64 id;
	};

	class WBCollider;
	class WBScene;
	class WBCollisionManager
	{
	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
		static void Clear();

		static void CollisionLayerCheck(enums::eLayerType left, enums::eLayerType right, bool enable);
		static void LayerCollision(WBScene* scene, enums::eLayerType left, enums::eLayerType right);
		static void ColliderCollision(WBCollider* left, WBCollider* right);
		static bool Intersect(WBCollider* left, WBCollider* right);

	private:
		static std::bitset<(UINT)enums::eLayerType::Max> mCollisionLayerMatrix[(UINT)enums::eLayerType::Max];
		static std::unordered_map<UINT64, bool> mCollisionMap;
	};
}