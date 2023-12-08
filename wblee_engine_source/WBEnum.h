#pragma once

namespace wb
{
	namespace enums
	{
		enum class eComponentType
		{
			Transform,
			SpriteRenderer,
			Animator,
			Script,
			Camera,
			End
		};

		enum class eLayerType
		{
			None,
			Background,
			Player,
			Particle,
			Skill,
			Max = 16,
		};

		enum class eResourceType
		{
			Texture,
			AudioClip,
			Animation,
			Prefab,
			End,
		};
	}
}