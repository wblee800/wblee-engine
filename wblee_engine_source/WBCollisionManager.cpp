#include "WBCollisionManager.h"
#include "WBScene.h"
#include "WBSceneManager.h"
#include "WBCollider.h"
#include "WBGameObject.h"

namespace wb
{
	std::bitset<(UINT)enums::eLayerType::Max> WBCollisionManager::mCollisionLayerMatrix[(UINT)enums::eLayerType::Max] = {};
	std::unordered_map<UINT64, bool> WBCollisionManager::mCollisionMap = {};

	void WBCollisionManager::Initialize()
	{

	}

	void WBCollisionManager::Update()
	{
		// 각각의 콜라이더들이 서로 충돌했는지 체크
		WBScene* scene = WBSceneManager::GetActiveScene();
		for (UINT row = 0; row < (UINT)enums::eLayerType::Max; row++)
		{
			for (UINT col = 0; col < (UINT)enums::eLayerType::Max; col++)
			{
				if (mCollisionLayerMatrix[row][col] == true)
				{
					LayerCollision(scene, (enums::eLayerType)row, (enums::eLayerType)col);
				}
			}
		}
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

	void WBCollisionManager::LayerCollision(WBScene* scene, enums::eLayerType left, enums::eLayerType right)
	{
		// left right는 같은 오브젝트들을 가져온다.
		const std::vector<WBGameObject*>& lefts = WBSceneManager::GetGameObjects(left);
		const std::vector<WBGameObject*>& rights = WBSceneManager::GetGameObjects(right);

		// 한 충돌체마다 다른 충돌체를 모두 체크한다.
		for (WBGameObject* left : lefts)
		{
			if (left->IsActive() == false)
				continue;
			WBCollider* leftCol = left->GetComponent<WBCollider>();
			if (leftCol == nullptr)
				continue;

			for (WBGameObject* right : rights)
			{
				if (right->IsActive() == false)
					continue;
				WBCollider* rightCol = right->GetComponent<WBCollider>();
				if (rightCol == nullptr)
					continue;
				// left와 right가 같은 경우는 같은 object이므로 비교할 필요가 없다.
				if (left == right)
					continue;

				// 두 충돌체가 충돌하는지 체크
				ColliderCollision(leftCol, rightCol);
			}
		}
	}

	// 두 충돌체가 충돌하는지 체크
	void WBCollisionManager::ColliderCollision(WBCollider* left, WBCollider* right)
	{
		// 두 충돌체 번호로 사용될 ID를 가져와서 CollisionID 세팅
		CollisionID id = {};
		id.left = left->GetID();
		id.right = right->GetID();

		// 이전 충돌 정보를 검색한다.
		// 만약에 충돌정보가 없는 상태라면,
		auto iter = mCollisionMap.find(id.id);
		if (iter == mCollisionMap.end())
		{
			// 충돌정보를 생성해준다.
			mCollisionMap.insert(std::make_pair(id.id, false));
			iter = mCollisionMap.find(id.id);
		}

		// 충돌 체크를 해준다
		if (Intersect(left, right))
		{
			// 최초 충돌(CollisionEnter)
			if (iter->second == false)
			{
				left->OnCollisionEnter(right);
				right->OnCollisionEnter(left);
				iter->second = true;
			}
			// 이미 충돌 중(CollisionStay)이면,
			else
			{
				left->OnCollisionStay(right);
				right->OnCollisionStay(left);
			}
		}
		else
		{
			// 충돌을 하지 않고 있는 상태(CollisionExit)면,
			if (iter->second == true)
			{
				left->OnCollisionExit(right);
				right->OnCollisionExit(left);

				iter->second = false;
			}
		}
	}

	// 충돌 체크 (AABB)
	bool WBCollisionManager::Intersect(WBCollider* left, WBCollider* right)
	{
		return false;
	}
}