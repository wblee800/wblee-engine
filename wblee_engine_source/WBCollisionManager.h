#pragma once
#include "common_include.h"

namespace wb
{
	class WBCollisionManager
	{
	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

		static void CollisionLayerCheck(enums::eLayerType left, enums::eLayerType right, bool enable);

	private:
		static std::bitset<(UINT)enums::eLayerType::Max> mCollisionLayerMatrix[(UINT)enums::eLayerType::Max];
	};
}