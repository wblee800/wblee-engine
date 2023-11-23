#pragma once
#include "common_include.h"

namespace wb
{
	class WBEntity
	{
	public:
		WBEntity();
		// ��ӹ޾� ����ϱ� ������ virtual
		virtual ~WBEntity();

		void SetName(const std::wstring& name) { mName = name; };
		std::wstring& GetName() { return mName; }

	private:
		// Game Object���� �����ϱ� ���� ���� �̸��� ���� ����
		std::wstring mName;
	};
}