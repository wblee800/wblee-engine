#pragma once
#include "WBResource.h"

namespace wb
{
	class WBResources
	{
	public:
		template <typename T>
		static T* Find(const std::wstring& key)
		{
			auto itr = mResources.find(key);
			if (itr == mResources.begin())
				return nullptr;

			return dynamic_cast<T*>(itr->second);
		}

		template <typename T>
		static T* Load(const std::wstring& key, const std::wstring& path)
		{
			T* resource = WBResources::Find<T>(key);
			if (resource != nullptr)
				return resource;

			resource = new T();
			if (FAILED(resource->Load(path)))
				assert(false);

			resource->SetName(key);
			resource->SetPath(path);
			mResources.insert(std::make_pair(key, resource));

			return resource;
		}

	private:
		static std::map<std::wstring, WBResource*> mResources;
	};
}