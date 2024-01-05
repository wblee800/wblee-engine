#include "WBCollisionManager.h"
#include "WBScene.h"
#include "WBSceneManager.h"
#include "WBGameObject.h"
#include "WBCollider.h"
#include "WBTransform.h"

namespace wb
{
	std::bitset<(UINT)enums::eLayerType::Max> WBCollisionManager::mCollisionLayerMatrix[(UINT)enums::eLayerType::Max] = {};
	std::unordered_map<UINT64, bool> WBCollisionManager::mCollisionMap;

	void WBCollisionManager::Initialize()
	{

	}

	void WBCollisionManager::Update()
	{
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

	void WBCollisionManager::Clear()
	{
		mCollisionMap.clear();
		mCollisionLayerMatrix->reset();
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

		mCollisionLayerMatrix[row][col] = enable;
	}

	void WBCollisionManager::LayerCollision(WBScene* scene, enums::eLayerType left, enums::eLayerType right)
	{
		const std::vector<WBGameObject*>& lefts = WBSceneManager::GetGameObjects(left);
		const std::vector<WBGameObject*>& rights = WBSceneManager::GetGameObjects(right);

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
				if (left == right)
					continue;

				ColliderCollision(leftCol, rightCol);
			}
		}
	}

	void WBCollisionManager::ColliderCollision(WBCollider* left, WBCollider* right)
	{
		// 두 충돌체 번호로 가져온 ID 확인하여 CollisionID 세팅
		CollisionID id = {};
		id.left = left->GetID();
		id.right = right->GetID();

		// 이전 충돌 정보를 검색한다.
		// 만약에 충돌정보가 없는 상태라면
		// 충돌정보를 생성해준다.

		auto iter = mCollisionMap.find(id.id);
		if (iter == mCollisionMap.end())
		{
			mCollisionMap.insert(std::make_pair(id.id, false));
			iter = mCollisionMap.find(id.id);
		}

		// 충돌 체크를 해준다
		if (Intersect(left, right))
		{
			//최초 충돌할떄
			if (iter->second == false)
			{
				left->OnCollisionEnter(right);
				right->OnCollisionEnter(left);
				iter->second = true;
			}
			else // 이미 충돌 중
			{
				left->OnCollisionStay(right);
				right->OnCollisionStay(left);
			}
		}
		else
		{
			//충돌을 하지 않은 상태
			if (iter->second == true)
			{
				left->OnCollisionExit(right);
				right->OnCollisionExit(left);

				iter->second = false;
			}
		}
	}

	// AABB collision
	bool WBCollisionManager::Intersect(WBCollider* left, WBCollider* right)
	{
		WBTransform* leftTr = left->GetOwner()->GetComponent<WBTransform>();
		WBTransform* rightTr = right->GetOwner()->GetComponent<WBTransform>();

		Vector2 leftPos = leftTr->GetPosition() + left->GetOffset();
		Vector2 rightPos = rightTr->GetPosition() + right->GetOffset();

		// size 1,1 일떄 기본크기가 100픽셀
		Vector2 leftSize = left->GetSize() * 100.0f;
		Vector2 rightSize = right->GetSize() * 100.0f;

		//AABB 충돌
		enums::eColliderType leftType = left->GetColliderType();
		enums::eColliderType rightType = right->GetColliderType();

		if (leftType == enums::eColliderType::Rect2D
			&& rightType == enums::eColliderType::Rect2D)
		{
			if (fabs(leftPos.x - rightPos.x) < fabs(leftSize.x / 2.0f + rightSize.x / 2.0f)
				&& fabs(leftPos.y - rightPos.y) < fabs(leftSize.y / 2.0f + rightSize.y / 2.0f))
			{
				return true;
			}
		}


		if (leftType == enums::eColliderType::Circle2D
			&& rightType == enums::eColliderType::Circle2D)
		{
			//circle -circle
			Vector2 leftCirclePos = leftPos + (leftSize / 2.0f);
			Vector2 rightCirclePos = rightPos + (rightSize / 2.0f);
			float distance = (leftCirclePos - rightCirclePos).length();
			if (distance <= (leftSize.x / 2.0f + rightSize.x / 2.0f))
			{
				return true;
			}
		}

		if ((leftType == enums::eColliderType::Circle2D && rightType == enums::eColliderType::Rect2D)
			|| (leftType == enums::eColliderType::Rect2D && rightType == enums::eColliderType::Circle2D))
		{
			// circle - rect
			// 숙제

		}


		return false;
	}
}