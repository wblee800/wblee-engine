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
			// drawing
			SpriteRenderer,
			Animator,
			// camera
			Camera,
			// sound
			AudioListener,
			AudioSource,
			End
		};

		enum class eLayerType
		{
			None,
			Background,
			Title,
			Tile,
			Map,
			Building,
			Equipment,
			Animal,
			NPC,
			Monster,
			Player,
			ObjectOnPlayer,
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