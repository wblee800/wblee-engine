#include "WBGameObject.h"
#include "WBInput.h"
#include "WBTime.h"
#include "WBComponent.h"
#include "WBTransform.h"

namespace wb
{
	WBGameObject::WBGameObject()
	{
		mComponents.resize((UINT)enums::eComponentType::End);
		initTransform();
	}

	WBGameObject::~WBGameObject()
	{
		for (WBComponent* comp : mComponents)
		{
			delete comp;
			comp = nullptr;
		}
	}

	void WBGameObject::Initialize()
	{

	}

	void WBGameObject::Update()
	{
		for (WBComponent* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Update();
		}
	}

	void WBGameObject::LateUpdate()
	{
		for (WBComponent* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->LateUpdate();
		}
	}

	void WBGameObject::Render(HDC hdc)
	{
		for (WBComponent* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Render(hdc);
		}
	}

	void WBGameObject::initTransform()
	{
		AddComponent<WBTransform>();
	}
}