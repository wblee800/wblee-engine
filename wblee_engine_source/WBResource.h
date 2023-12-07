#pragma once
#include "WBEntity.h"

namespace wb
{
	// Abstract class, can't allocate memory, can only inherit
	class WBResource : public WBEntity
	{
	public:
		WBResource(enums::eResourceType type);
		virtual ~WBResource();

		// Pure virtual function
		virtual HRESULT Load(const std::wstring& path) = 0;

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};
}