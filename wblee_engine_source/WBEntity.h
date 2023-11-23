#pragma once
#include "common_include.h"

namespace wb
{
	class WBEntity
	{
	public:
		WBEntity();
		// 상속받아 사용하기 때문에 virtual
		virtual ~WBEntity();

		void SetName(const std::wstring& name) { mName = name; };
		std::wstring& GetName() { return mName; }

	private:
		// Game Object들을 구분하기 위해 만든 이름을 담을 변수
		std::wstring mName;
	};
}