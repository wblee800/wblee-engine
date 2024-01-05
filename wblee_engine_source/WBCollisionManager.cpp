#include "WBCollisionManager.h"

namespace wb
{
	std::bitset<(UINT)enums::eLayerType::Max> WBCollisionManager::mCollisionLayerMatrix[(UINT)enums::eLayerType::Max] = {};

	void WBCollisionManager::Initialize()
	{

	}

	void WBCollisionManager::Update()
	{
	}

	void WBCollisionManager::LateUpdate()
	{
	}

	void WBCollisionManager::Render(HDC hdc)
	{
	}

	void WBCollisionManager::CollisionLayerCheck(enums::eLayerType left, enums::eLayerType right, bool enable)
	{
		UINT row = 0;
		UINT col = 0;

		if (left <= right)
		{
			row = (UINT)left;
			col = (UINT)right;
		}
		else
		{
			row = (UINT)right; 
			col = (UINT)left;
		}
	}
}