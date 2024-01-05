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
		static void LayerCollision(WBScene* scene, enums::eLayerType row, enums::eLayerType col);
		static void ColliderCollision(WBCollider* left, WBCollider* right);

	private:
		static std::bitset<(UINT)enums::eLayerType::Max> mCollisionLayerMatrix[(UINT)enums::eLayerType::Max];
		static std::unordered_map<UINT64, bool> mCollisionMap;
	};
}