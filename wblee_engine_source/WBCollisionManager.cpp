#include "WBCollisionManager.h"
#include "WBScene.h"
#include "WBSceneManager.h"
#include "WBCollider.h"
#include "WBGameObject.h"
#include "WBTransform.h"

namespace wb
{
	// bit 단위로 값을 저장하는 배열
	std::bitset<(UINT)enums::eLayerType::Max> WBCollisionManager::mCollisionLayerMatrix[(UINT)enums::eLayerType::Max] = {};
	// 누구와 충돌 중인지 체크
	std::unordered_map<UINT64, bool> WBCollisionManager::mCollisionMap = {};

	void WBCollisionManager::Initialize()
	{

	}

	void WBCollisionManager::Update()
	{
		// 어떤 레이어들이 서로 충돌하는지 체크
		WBScene* scene = WBSceneManager::GetActiveScene();
		for (UINT row = 0; row < (UINT)enums::eLayerType::Max; row++)
		{
			for (UINT col = 0; col < (UINT)enums::eLayerType::Max; col++)
			{
				if (mCollisionLayerMatrix[row][col] == true)
				{
					LayerCollision((enums::eLayerType)row, (enums::eLayerType)col);
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

	// 어떤 레이어끼리 충돌할 것인지 설정한다.
	void WBCollisionManager::CollisionLayerCheck(enums::eLayerType left, enums::eLayerType right, bool enable)
	{
		UINT row = 0;
		UINT col = 0;

		// a와 b가 충돌하나 b와 a가 충돌하나 같은 충돌이므로, 배열의 절반만 사용한다.
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

	// 충돌 설정한 layer의 game object들 중 충돌한 것이 있는지 판단한다.
	void WBCollisionManager::LayerCollision(enums::eLayerType left, enums::eLayerType right)
	{
		// left와 right는 서로 같은 오브젝트들을 가져온다.
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
				// left = right => 똑같은 object들이므로 충돌 비교할 필요가 없다.
				if (left == right)
					continue;

				// 두 충돌체가 충돌하는지 체크
				ColliderCollision(leftCol, rightCol);
			}
		}
	}

	// 충돌 정보 세팅 + 충돌 종류에 따른 함수 실행
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
			// 최초 충돌(CollisionEnter)이면,
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
		WBTransform* leftTr = left->GetOwner()->GetComponent<WBTransform>();
		WBTransform* rightTr = right->GetOwner()->GetComponent<WBTransform>();

		Vector2 leftPos = leftTr->GetPosition() + left->GetOffset();
		Vector2 rightPos = rightTr->GetPosition() + right->GetOffset();

		Vector2 leftSize = left->GetSize() * 100.0f;
		Vector2 rightSize = right->GetSize() * 100.0f;

		// fabs() : 부동 소수점 절댓값 연산
		// AABB 충돌
		if (fabs(leftPos.x - rightPos.x) < fabs(leftSize.x / 2.0f + rightSize.x / 2.0f)
			|| fabs(leftPos.y - rightPos.y) < fabs(leftSize.y / 2.0f - rightSize.y / 2.0f))
		{
			return true;
		}

		return false;
	}
}