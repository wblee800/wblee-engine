#pragma once
#include "WBEntity.h"

namespace wb
{
	class WBResource : public WBEntity
	{
	public:
		WBResource(enums::eResourceType type);
		virtual ~WBResource();

		virtual HRESULT Load(const std::wstring& path) = 0;

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};
}