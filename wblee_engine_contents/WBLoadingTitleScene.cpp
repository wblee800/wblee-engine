#include "WBLoadingTitleScene.h"
#include "..\wblee_engine_source\WBInput.h"
#include "..\wblee_engine_source\WBSceneManager.h"

#include "..\\wblee_engine_source\\WBGameObject.h"
#include "WBPlayer.h"
#include "..\\wblee_engine_source\\WBTransform.h"
#include "..\\wblee_engine_source\\WBSpriteRenderer.h"
#include "..\\wblee_engine_source\\WBInput.h"
#include "..\\wblee_engine_source\\WBSceneManager.h"
#include "..\\wblee_engine_source\\WBObject.h"
#include "..\\wblee_engine_source\\WBTexture.h"
#include "..\\wblee_engine_source\\WBResources.h"
#include "WBPlayerScript.h"
#include "..\\wblee_engine_source\\WBCamera.h"
#include "..\\wblee_engine_source\\WBRenderer.h"
#include "..\\wblee_engine_source\\WBAnimator.h"
#include "..\\wblee_engine_source\\WBAudioSource.h"
#include "..\\wblee_engine_source\\WBAudioClip.h"
#include "..\\wblee_engine_source\\WBAudioListener.h"

namespace wb
{
	WBLoadingTitleScene::WBLoadingTitleScene()
		: mCamera(nullptr)
	{
	}

	WBLoadingTitleScene::~WBLoadingTitleScene()
	{
	}

	void WBLoadingTitleScene::Initialize()
	{
		// Main camera
		mCamera = object::Instantiate<WBGameObject>(enums::eLayerType::None, Vector2(960.0f, 540.0f));
		WBCamera* cameraComp = mCamera->AddComponent<WBCamera>();
		renderer::mainCamera = cameraComp;

		mCamera->AddComponent<WBAudioListener>();
		WBAudioSource* cameraAudioSource = mCamera->AddComponent<WBAudioSource>();
		WBAudioClip* audioClip = WBResources::Load<WBAudioClip>(L"BGM", L"..\\resources\\sounds\\environment\\spring_night.wav");
		cameraAudioSource->SetClip(audioClip);
		// cameraAudioSource->Play();

		// A emoji of a creator
		WBGameObject* emojiOfCreator = object::Instantiate<WBGameObject>
			(enums::eLayerType::Background, Vector2(600.0f, 250.0f));
		WBSpriteRenderer* emojiOfCreatorSr = emojiOfCreator->AddComponent<WBSpriteRenderer>();

		graphics::WBTexture* emojiOfCreatorTex = WBResources::Find<graphics::WBTexture>(L"Emoji_Of_Creator");
		emojiOfCreatorSr->SetTexture(emojiOfCreatorTex);
		emojiOfCreatorSr->SetSize(Vector2(3.0f, 3.0f));

		// A nickname of a creator
		WBGameObject* nicknameOfCreator = object::Instantiate<WBGameObject>
			(enums::eLayerType::Background, Vector2(1000.0f, 270.0f));
		WBSpriteRenderer* nicknameOfCreatorSr = nicknameOfCreator->AddComponent<WBSpriteRenderer>();

		graphics::WBTexture* nicknameOfCreatorTex = WBResources::Find<graphics::WBTexture>(L"Nickname_Of_Creator");
		nicknameOfCreatorSr->SetTexture(nicknameOfCreatorTex);
		nicknameOfCreatorSr->SetSize(Vector2(3.0f, 3.0f));

		// An emoji of a modifier
		WBGameObject* emojiOfModifier = object::Instantiate<WBGameObject>
			(enums::eLayerType::Background, Vector2(600.0f, 550.0f));
		WBSpriteRenderer* emojiOfModifierSr = emojiOfModifier->AddComponent<WBSpriteRenderer>();

		graphics::WBTexture* emojiOfModifierTex = WBResources::Find<graphics::WBTexture>(L"Emoji_Of_Modifier");
		emojiOfModifierSr->SetTexture(emojiOfModifierTex);
		emojiOfModifierSr->SetSize(Vector2(3.0f, 3.0f));

		// a name of a modifier
		WBGameObject* nameOfModifier = object::Instantiate<WBGameObject>
			(enums::eLayerType::Background, Vector2(1000.0f, 570.0f));
		WBSpriteRenderer* nameOfModifierSr = nameOfModifier->AddComponent<WBSpriteRenderer>();

		graphics::WBTexture* nameOfModifierTex = WBResources::Find<graphics::WBTexture>(L"Name_Of_Modifier");
		nameOfModifierSr->SetTexture(nameOfModifierTex);
		nameOfModifierSr->SetSize(Vector2(3.0f, 3.0f));

		// After creating a game object, call an Initialize() of WBLayer and WBGameObject
		WBScene::Initialize();
	}

	void WBLoadingTitleScene::Update()
	{
		WBScene::Update();
	}

	void WBLoadingTitleScene::LateUpdate()
	{
		WBScene::LateUpdate();

		if (WBInput::GetKeyDown(eKeyCode::N))
		{
			WBSceneManager::LoadScene(L"TitleScene");
		}
	}

	void WBLoadingTitleScene::Render(HDC hdc)
	{
		HBRUSH blackBrush = CreateSolidBrush(RGB(5, 3, 4));
		HBRUSH originBrush = (HBRUSH)SelectObject(hdc, blackBrush);
		Rectangle(hdc, -1, -1, 1281, 721);

		SelectObject(hdc, originBrush);
		DeleteObject(blackBrush);

		WBScene::Render(hdc);
	}

	void WBLoadingTitleScene::OnEnter()
	{
		renderer::mainCamera = mCamera->GetComponent<WBCamera>();
	}

	void WBLoadingTitleScene::OnExit()
	{
	}
}