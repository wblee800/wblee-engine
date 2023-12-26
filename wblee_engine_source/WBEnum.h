#pragma once

namespace wb
{
	namespace enums
	{
		// A sequence followed by Unity
		enum class eComponentType
		{
			Transform,
			// collision detection
			Collider,
			// logic
			Script,
			// draw
			SpriteRenderer,
			Animator,
			// camera
			Camera,
			End
		};

		enum class eLayerType
		{
			None,
			Background,
			Tile,
			Map,
			Building,
			Equipment,
			Animal,
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