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

		static bool GetKeyDown(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Down; };
		static bool GetKeyUp(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Up; };
		static bool GetKey(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Pressed; };

	private:
		static void createKeys();
		static void updateKeys();
		static void updateKey(WBInput::Key& key);
		static bool isKeyDown(eKeyCode code);
		static void updateKeyDown(WBInput::Key& key);
		static void updateKeyUp(WBInput::Key& key);

	private:
		// eKeyState mState = eKeyState::Up;
		static std::vector<Key> Keys;
	};
}