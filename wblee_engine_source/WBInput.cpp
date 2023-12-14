#include "WBInput.h"
#include "WBApplication.h"

extern wb::WBApplication application;

namespace wb
{
	std::vector<WBInput::Key> WBInput::Keys = {};
	math::Vector2 WBInput::mMousePosition = math::Vector2::One;

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
		VK_LBUTTON, VK_MBUTTON, VK_RBUTTON,
		VK_NUMPAD1, VK_NUMPAD2, VK_NUMPAD3, VK_NUMPAD4, VK_NUMPAD5, VK_NUMPAD6, VK_NUMPAD7, VK_NUMPAD8, VK_NUMPAD9, VK_NUMPAD0,
	};

	void WBInput::Initialize()
	{
		createKeys();
	}

	void WBInput::Update()
	{
		updateKeys();
	}

	void WBInput::createKeys()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			Keys.push_back(key);
		}
	}

	void WBInput::updateKeys()
	{
		std::for_each(Keys.begin(), Keys.end(),
			[](Key& key) -> void
			{
				updateKey(key);
			});
	}

	void WBInput::updateKey(WBInput::Key& key)
	{
		// when a client window is activated
		if (GetFocus())
		{
			if (isKeyDown(key.keyCode))
			{
				updateKeyDown(key);
			}
			else
			{
				updateKeyUp(key);
			}

			getMousePositionByClientWindow();
		}
		// when a client window is deactivated
		else
		{
			clearKeys();
		}
	}

	bool WBInput::isKeyDown(eKeyCode code)
	{
		// GetAsyncKeyState() : Return 0x8000 when a key is down
		return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
	}

	void WBInput::updateKeyDown(WBInput::Key& key)
	{
		if (key.bPressed == true)
			key.state = eKeyState::Pressed;
		else
			key.state = eKeyState::Down;

		key.bPressed = true;
	}

	void WBInput::updateKeyUp(WBInput::Key& key)
	{
		if (key.bPressed == true)
			key.state = eKeyState::Up;
		else
			key.state = eKeyState::None;

		key.bPressed = false;
	}

	void WBInput::clearKeys()
	{
		for (Key& key : Keys)
		{
			// If a key is pressed now or before
			if (key.state == eKeyState::Down || key.state == eKeyState::Pressed)
			{
				// the key should not be pressed b/c the client window is closed
				key.state == eKeyState::Up;
			}
			else if (key.state == eKeyState::Up)
			{
				key.state == eKeyState::None;
			}

			key.bPressed = false;
		}
	}

	void WBInput::getMousePositionByClientWindow()
	{
		// mouse cursor position in Windows screen
		POINT mousePosition = {};
		// Get LPPOINT
		// 'LP' in Windows API is a pointer
		GetCursorPos(&mousePosition);
		// Switch the full screen to a client program window
		ScreenToClient(application.GetHwnd(), &mousePosition);

		mMousePosition.x = mousePosition.x;
		mMousePosition.y = mousePosition.y;
	}
}