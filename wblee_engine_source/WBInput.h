#pragma once
#include "common_include.h"

namespace wb
{
	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None,
	};

	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		LEFT, RIGHT, DOWN, UP,
		LButton, MButton, RButton,
		ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, ZERO,
		End,
	};

	class WBInput
	{
	public:
		struct Key
		{
			eKeyCode keyCode;
			eKeyState state;
			bool bPressed;
		};

		static void Initialize();
		static void Update();

		__forceinline static bool GetKeyDown(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Down; }
		__forceinline static bool GetKeyUp(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Up; }
		__forceinline static bool GetKey(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Pressed; }
		__forceinline static math::Vector2 GetMousePosition() { return mMousePosition; }

	private:
		static void createKeys();
		static void updateKeys();
		static void updateKey(WBInput::Key& key);
		static bool isKeyDown(eKeyCode code);
		static void updateKeyDown(WBInput::Key& key);
		static void updateKeyUp(WBInput::Key& key);
		static void clearKeys();
		static void getMousePositionByClientWindow();

	private:
		static std::vector<Key> Keys;
		static math::Vector2 mMousePosition;
	};
}