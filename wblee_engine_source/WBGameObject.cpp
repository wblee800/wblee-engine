#include "WBGameObject.h"
#include "WBInput.h"
#include "WBTime.h"
#include "WBComponent.h"

namespace wb
{
	WBGameObject::WBGameObject()
	{
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
			comp->Update();
		}
	}

	void WBGameObject::LateUpdate()
	{
		for (WBComponent* comp : mComponents)
		{
			comp->LateUpdate();
		}
	}

	void WBGameObject::Render(HDC hdc)
	{
		for (WBComponent* comp : mComponents)
		{
			comp->Render(hdc);
		}
	}
}