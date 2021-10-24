#pragma once

#define FRONTEND XOR(L"Frontend?game=/Script/FortniteGame.FortGameModeFrontEnd")
#define APOLLO_TERRAIN XOR(L"Apollo_Terrain?game=/Game/Athena/Athena_GameMode.Athena_GameMode_C")
#define APOLLO_TERRAIN_YOGURT XOR(L"Apollo_Terrain_Yogurt?game=/Game/Athena/Athena_GameMode.Athena_GameMode_C")
#define APOLLO_TERRAIN_VALKYIRE XOR(L"Apollo_Terrain?game=/Game/Athena/Valkyrie/Valkyrie_GameMode.Valkyrie_GameMode_C")
#define APOLLO_PAPAYA XOR(L"Apollo_Papaya?game=/Game/Athena/Athena_GameMode.Athena_GameMode_C")
#define APOLLO_TERRAIN_BASE XOR(L"Apollo_Terrain?game=/Script/FortniteGame.FortGameModeBase")
#define APOLLO_PAPAYA_BASE XOR(L"Apollo_Papaya?game=/Script/FortniteGame.FortGameModeBase")

#define GALACTUS_EVENT_MAP XOR(L"Junior_Map")
#define JERKY_EVENT_MAP XOR(L"JerkySequenceMap")
#define DEVICE_EVENT_MAP XOR(L"FritterSequenceLevel")
#define RIFT_TOUR_EVENT_MAP XOR(L"Buffet_P")
#define RIFT_TOUR_CUDDLE_MAP XOR(L"Buffet_Part5")
#define RIFT_TOUR_STORMKING_MAP XOR(L"Buffet_Part_6")
#define RIFT_TOUR_STAIRS_MAP XOR(L"Buffet_Escher")
#define RIFT_TOUR_POSITIONS_MAP XOR(L"Buffet_Shard")
#define RIFT_TOUR_CLOUDS_MAP XOR(L"Buffet_Cloud")
#define MOTHERSHIP_EVENT XOR(L"Kiwi_P")
#define KIWI_SPACE XOR(L"Kiwi_Space")
#define KIWI_TUBES XOR(L"Kiwi_Tubes")
#define KIWI_OBSERVATIONHALLWAY XOR(L"Kiwi_ObservationHallway")
#define KIWI_PRISONBLOCKS XOR(L"Kiwi_PrisonBlocks")
#define KIWI_PRISONJUNCTION XOR(L"Kiwi_PrisonJunction")
#define KIWI_HANGAR XOR(L"Kiwi_Hangar")
#define KIWI_KEVINROOM XOR(L"Kiwi_KevinRoom")

#define GALACTUS_EVENT_PLAYER XOR(L"LevelSequencePlayer /Junior/Levels/Junior_Map_LevelInstance_1.Junior_Map.PersistentLevel.Junior_Master_Rep_2.AnimationPlayer")
#define JERKY_EVENT_PLAYER XOR(L"LevelSequencePlayer /CycloneJerky/Levels/JerkySequenceMap_LevelInstance_1.JerkySequenceMap.PersistentLevel.Jerky.AnimationPlayer")
#define DEVICE_EVENT_PLAYER XOR(L"LevelSequencePlayer /Fritter/Level/FritterSequenceLevel_LevelInstance_1.FritterSequenceLevel.PersistentLevel.Fritter_2.AnimationPlayer")
#define YOUGURT_EVENT_PLAYER XOR(L"LevelSequencePlayer /Yogurt/Levels/YogurtLoaderLevel.YogurtLoaderLevel.PersistentLevel.Yogurt_Master_2.AnimationPlayer")
#define RIFT_TOUR_EVENT_PLAYER XOR(L"LevelSequencePlayer /Buffet/Levels/Buffet_P.Buffet_P.PersistentLevel.Buffet_Master_3.AnimationPlayer")
#define RIFT_TOUR_CUDDLE_PLAYER XOR(L"LevelSequencePlayer /Buffet/Levels/Buffet_Part5.Buffet_Part5.PersistentLevel.Buffet_Master_2.AnimationPlayer")
#define RIFT_TOUR_STORMKING_PLAYER XOR(L"LevelSequencePlayer /Buffet/Levels/Buffet_Part_6.Buffet_Part_6.PersistentLevel.BeatSync_Phase5Test_2.AnimationPlayer")
#define RIFT_TOUR_STAIRS_PLAYER XOR(L"LevelSequencePlayer /Buffet/Levels/Buffet_Escher.Buffet_Escher.PersistentLevel.Buffet_Animation_Escher_2.AnimationPlayer")
#define RIFT_TOUR_POSITIONS_PLAYER XOR(L"LevelSequencePlayer /Buffet/Levels/Buffet_Shard.Buffet_Shard.PersistentLevel.Buffet_Animation_Shards_2.AnimationPlayer")
#define RIFT_TOUR_CLOUDS_PLAYER XOR(L"LevelSequencePlayer /Buffet/Levels/Buffet_Cloud.Buffet_Cloud.PersistentLevel.Buffet_Master.AnimationPlayer")
#define MOTHERSHIP_EVENT_PLAYER XOR(L"LevelSequencePlayer /Kiwi/Levels/Kiwi_P.Kiwi_P.PersistentLevel.Kiwi_Master.AnimationPlayer")


enum ECommands
{
	ACTIVATE,
	EVENT,
	DEBUG_CAMERA,
	SKYDIVE,
	EQUIP,
	FLY,
	SET_GRAVITY,
	SET_SPEED,
	SET_PLAYLIST,
	RESPAWN,
	SET_HEALTH,
	SET_SHIELD,
	SET_MAX_HEALTH,
	SET_MAX_SHIELD,
	DUMP,
	DUMPBPS,
	TEST,
	LOADBPC,
	NONE
};

auto str2enum(const std::wstring& str)
{
	if (str.starts_with(L"event")) return EVENT;
	else if (str.starts_with(L"activate")) return DEBUG_CAMERA;
	else if (str.starts_with(L"debugcamera")) return DEBUG_CAMERA;
	else if (str.starts_with(L"fly")) return FLY;
	else if (str.starts_with(L"skydive")) return SKYDIVE;
	else if (str.starts_with(L"skydiving")) return SKYDIVE;
	else if (str.starts_with(L"equip")) return EQUIP;
	else if (str.starts_with(L"setgravity")) return SET_GRAVITY;
	else if (str.starts_with(L"setspeed") || str.starts_with(L"speed")) return SET_SPEED;
	else if (str.starts_with(L"setplaylist")) return SET_PLAYLIST;
	else if (str.starts_with(L"respawn")) return RESPAWN;
	else if (str.starts_with(L"sethealth")) return SET_HEALTH;
	else if (str.starts_with(L"setshield")) return SET_SHIELD;
	else if (str.starts_with(L"setmaxhealth")) return SET_MAX_HEALTH;
	else if (str.starts_with(L"setmaxshield")) return SET_MAX_SHIELD;
	else if (str.starts_with(L"dump")) return DUMP;
	else if (str.starts_with(L"test")) return TEST;
	else if (str.starts_with(L"dumpbps")) return DUMPBPS;
	else if (str.starts_with(L"loadbpc")) return LOADBPC;
	else return NONE;
}


//Memory
namespace Patterns
{

	//Works on 10.40^
	namespace Curl
	{
		namespace Oldies
		{
			constexpr const char* CurlEasySetOpt =
				"\x89\x54\x24\x10\x4C\x89\x44\x24\x18\x4C\x89\x4C\x24\x20\x48\x83\xEC\x28\x48\x85\xC9\x75\x08\x8D\x41\x2B\x48\x83\xC4\x28\xC3\x4C";
			constexpr const char* CurlSetOpt =
				"\x48\x89\x5C\x24\x08\x48\x89\x6C\x24\x10\x48\x89\x74\x24\x18\x57\x48\x83\xEC\x30\x33\xED\x49\x8B\xF0\x48\x8B\xD9";
		}

		constexpr const char* CurlSetOpt =
			"\x48\x89\x5C\x24\x08\x48\x89\x6C\x24\x10\x48\x89\x74\x24\x18\x48\x89\x7C\x24\x20\x41\x56\x48\x83\xEC\x40\x33\xED\x49\x8B\xF0\x44";
	}

	//16.60
	namespace New
	{
		constexpr const char* FNameToString =
			"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x55\x57\x41\x56\x48\x8D\xAC\x24\x00\x00\x00\x00\x48\x81\xEC\x00\x00\x00\x00\x48\x8B\x05\x00\x00\x00\x00\x48\x33\xC4\x48\x89\x85\x00\x00\x00\x00\x45\x33\xF6\x48\x8B\xF2\x44\x39\x71\x04\x0F\x85\x00\x00\x00\x00\x8B\x19\x0F\xB7\xFB\xE8\x00\x00\x00\x00\x8B\xCB\x48\x8D\x54\x24\x00\x48\xC1\xE9\x10\x8D\x1C\x3F\x48\x03\x5C\xC8\x00\x48\x8B\xCB\xF6\x03\x01\x0F\x85\x00\x00\x00\x00\xE8\x00\x00\x00\x00";
	}

	//Works on 10.40^
	namespace bGlobal
	{
		//Dead
		constexpr const char* GEngine = "\x48\x8B\x0D\x00\x00\x00\x00\x48\x8B\xD3\xE8\x00\x00\x00\x00\x84\xC0";

		constexpr const char* GObjects = "\x48\x8B\x05\x00\x00\x00\x00\x48\x8B\x0C\xC8\x48\x8D\x04\xD1\xEB\x06";

		constexpr const char* SCOI =
			"\x4C\x89\x44\x24\x18\x55\x53\x56\x57\x41\x54\x41\x55\x41\x56\x41\x57\x48\x8D\xAC\x24\x00\x00\x00\x00\x48\x81\xEC\x00\x00\x00\x00\x48\x8B\x05\x00\x00\x00\x00\x48\x33\xC4";

		constexpr const char* SLOI =
			"\x48\x8B\xC4\x4C\x89\x48\x20\x48\x89\x50\x10\x48\x89\x48\x08\x55\x53\x56\x57\x41\x54\x41\x55\x41\x56\x41\x57\x48\x8D\x68\xB9\x48\x81\xEC\x00\x00\x00\x00";

		constexpr const char* SpawnActorInternal =
			"\x48\x8b\xc4\x55\x53\x56\x57\x41\x54\x41\x55\x41\x56\x41\x57\x48\x8d\xa8\x00\x00\x00\x00\x48\x81\xec\x00\x00\x00\x00\x0f\x29\x70\x00\x0f\x29\x78\x00\x44\x0f\x29\x40\x00\x44\x0f\x29\x88\x00\x00\x00\x00\x44\x0f\x29\x90\x00\x00\x00\x00\x44\x0f\x29\x98\x00\x00\x00\x00\x44\x0f\x29\xa0\x00\x00\x00\x00\x44\x0f\x29\xa8\x00\x00\x00\x00\x44\x0f\x29\xb0\x00\x00\x00\x00\x44\x0f\x29\xb8\x00\x00\x00\x00\x48\x8b\x05\x00\x00\x00\x00\x48\x33\xc4\x48\x89\x45\x00\x45\x33\xed";

		//Dead
		constexpr const char* ProcessEvent =
			"\x40\x55\x56\x57\x41\x54\x41\x55\x41\x56\x41\x57\x48\x81\xEC\x00\x00\x00\x00\x48\x8D\x6C\x24\x00\x48\x89\x9D\x00\x00\x00\x00\x48\x8B\x05\x00\x00\x00\x00\x48\x33\xC5\x48\x89\x85\x00\x00\x00\x00\x8B\x41\x0C\x45\x33\xF6\x3B\x05\x00\x00\x00\x00\x4D\x8B\xF8\x48\x8B\xF2\x4C\x8B\xE1\x41\xB8\x00\x00\x00\x00\x7D\x2A";

		//Dead
		constexpr const char* GONI =
			"\x40\x53\x48\x83\xEC\x20\x48\x8B\xD9\x48\x85\xD2\x75\x45\x33\xC0\x48\x89\x01\x48\x89\x41\x08\x8D\x50\x05\xE8\x00\x00\x00\x00\x8B\x53\x08\x8D\x42\x05\x89\x43\x08\x3B\x43\x0C\x7E\x08\x48\x8B\xCB\xE8\x00\x00\x00\x00\x48\x8B\x0B\x48\x8D\x15\x00\x00\x00\x00\x41\xB8\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8B\xC3\x48\x83\xC4\x20\x5B\xC3\x48\x8B\x42\x18";

		//Dead
		constexpr const char* GetObjectFullName =
			"\x40\x53\x55\x56\x57\x41\x56\x48\x81\xec\x00\x00\x00\x00\x48\x8b\x05\x00\x00\x00\x00\x48\x33\xc4\x48\x89\x84\x24\x00\x00\x00\x00\x48\x8b\xda\x45\x33\xf6";

		constexpr const char* GetFullName =
			"\x48\x89\x5c\x24\x00\x57\x48\x83\xec\x00\x48\x8b\xd9\x48\x8b\xfa\x48\x8b\x49\x00\xe8\x00\x00\x00\x00\x41\xb8";

		//Dead
		constexpr const char* GetViewPoint =
			"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x48\x8B\xD9\x41\x8B\xF0\x48\x8B\x49\x30\x48\x8B\xFA\xE8\x00\x00\x00\x00\xBA\x00\x00\x00\x00\x48\x8B\xC8";

		//Dead
		constexpr const char* AbilityPatch = "\xC0\x0F\x84\x00\x02\x00\x00\x0F\x2F\xF7\x0F\x86\x00\x00\x00\x00";

		//Dead
		constexpr const char* FreeInternal =
			"\x48\x85\xC9\x74\x2E\x53\x48\x83\xEC\x20\x48\x8B\xD9\x48\x8B\x0D\x00\x00\x00\x00\x48\x85\xC9\x75\x0C";
	}


	namespace Oldies
	{
		//Tested on 12.41, 12.61
		namespace bGlobal
		{
			constexpr const char* GetObjectFullName =
				"\x48\x89\x5C\x24\x10\x48\x89\x6C\x24\x18\x56\x57\x41\x56\x48\x83\xEC\x30\x48\x8B\xDA\x45\x33\xF6\x4C\x89\x32\x48\x8B\xF1\x4C\x89\x72\x08\x48\x8B\xCB\xBA\x80\x00\x00\x00";
		}

		//Tested on 7.30
		namespace bMarshmallow
		{
			constexpr const char* GEngine =
				"\x48\x8B\xD3\x00\x00\x00\x00\x00\x48\x8B\x4C\x24\x40\x48\x89\x05\x00\x00\x00\x00\x48\x85\xC9";

			constexpr const char* GObjects = "\x48\x8B\x05\x00\x00\x00\x00\x48\x8B\x0C\xC8\x48\x8D\x04\xD1\xEB\x06";

			constexpr const char* GetObjectFullName =
				"\x40\x53\x48\x83\xEC\x20\x48\x8B\xD9\x48\x85\xD2\x75\x30\x33\xC0\x48\x89\x01\x48\xC7\x41\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8B\x0B\x48\x8D\x15\x00\x00\x00\x00\x41\xB8\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x8B\xC3\x48\x83\xC4\x20\x5B\xC3\x48\x8B\x42\x18";
		}
	}
}

namespace Masks
{
	namespace Curl
	{
		namespace Oldies
		{
			constexpr const char* CurlEasySetOpt = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
			constexpr const char* CurlSetOpt = "xxxxxxxxxxxxxxxxxxxxxxxxxxxx";
		}

		constexpr const char* CurlSetOpt = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
	}

	namespace New
	{
		constexpr const char* FNameToString =
			"xxxx?xxxx?xxxxxxxx????xxx????xxx????xxxxxx????xxxxxxxxxxxx????xxxxxx????xxxxxx?xxxxxxxxxxx?xxxxxxxx????x????";
	}

	namespace bGlobal
	{
		constexpr const char* GEngine = "xxx????xxxx????xx";
		constexpr const char* GObjects = "xxx????xxxx";
		constexpr const char* SCOI = "xxxxxxxxxxxxxxxxxxxxx????xxx????xxx????xxx";
		constexpr const char* SLOI = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx????";
		constexpr const char* SpawnActorInternal =
			"xxxxxxxxxxxxxxxxxx????xxx????xxx?xxx?xxxx?xxxx????xxxx????xxxx????xxxx????xxxx????xxxx????xxxx????xxx????xxxxxx?xxx";
		constexpr const char* ProcessEvent =
			"xxxxxxxxxxxxxxx????xxxx?xxx????xxx????xxxxxx????xxxxxxxx????xxxxxxxxxxx????xx";
		constexpr const char* GONI =
			"xxxxxxxxxxxxxxxxxxxxxxxxxxx????xxxxxxxxxxxxxxxxxx????xxxxxx????xx????x????xxxxxxxxxxxxx";
		constexpr const char* GetObjectFullName = "xxxxxxxxxx????xxx????xxxxxxx????xxxxxx";
		constexpr const char* GetFullName = "xxxx?xxxx?xxxxxxxxx?x????xx";
		constexpr const char* GetViewPoint = "xxxx?xxxx?xxxxxxxxxxxxxxxxxxx????x????xxx";
		constexpr const char* AbilityPatch = "xxx?xxxxxxxx??xx";
		constexpr const char* FreeInternal = "xxxxxxxxxxxxxxxx????xxxxx";
	}

	namespace Oldies
	{
		namespace bGlobal
		{
			constexpr const char* GetObjectFullName = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
		}

		namespace bMarshmallow
		{
			constexpr const char* GEngine = "xxx?????xxxxxxxx????xxx";

			constexpr const char* GObjects = "xxx????xxxxxxxxxx";

			constexpr const char* GetObjectFullName =
				"xxxxxxxxxxxxxxxxxxxxxx?????x????xxxxxx????xx????x????xxxxxxxxxxxxx";
		}
	}
}

//UE4
enum EObjectFlags
{
	RF_NoFlags = 0x00000000,
	RF_Public = 0x00000001,
	RF_Standalone = 0x00000002,
	RF_MarkAsNative = 0x00000004,
	RF_Transactional = 0x00000008,
	RF_ClassDefaultObject = 0x00000010,
	RF_ArchetypeObject = 0x00000020,
	RF_Transient = 0x00000040,
	RF_MarkAsRootSet = 0x00000080,
	RF_TagGarbageTemp = 0x00000100,
	RF_NeedInitialization = 0x00000200,
	RF_NeedLoad = 0x00000400,
	RF_KeepForCooker = 0x00000800,
	RF_NeedPostLoad = 0x00001000,
	RF_NeedPostLoadSubobjects = 0x00002000,
	RF_NewerVersionExists = 0x00004000,
	RF_BeginDestroyed = 0x00008000,
	RF_FinishDestroyed = 0x00010000,
	RF_BeingRegenerated = 0x00020000,
	RF_DefaultSubObject = 0x00040000,
	RF_WasLoaded = 0x00080000,
	RF_TextExportTransient = 0x00100000,
	RF_LoadCompleted = 0x00200000,
	RF_InheritableComponentTemplate = 0x00400000,
	RF_DuplicateTransient = 0x00800000,
	RF_StrongRefOnFrame = 0x01000000,
	RF_NonPIEDuplicateTransient = 0x02000000,
	RF_Dynamic = 0x04000000,
	RF_WillBeLoaded = 0x08000000,
};

enum EInternalObjectFlags
{
	None = 0,
	ReachableInCluster = 1 << 23,
	ClusterRoot = 1 << 24,
	Native = 1 << 25,
	Async = 1 << 26,
	AsyncLoading = 1 << 27,
	Unreachable = 1 << 28,
	PendingKill = 1 << 29,
	RootSet = 1 << 30,
	GarbageCollectionKeepFlags = Native | Async | AsyncLoading,
	AllFlags = ReachableInCluster | ClusterRoot | Native | Async | AsyncLoading | Unreachable | PendingKill | RootSet,
};

enum class ESpawnActorCollisionHandlingMethod : uint8_t
{
	Undefined,
	AlwaysSpawn,
	AdjustIfPossibleButAlwaysSpawn,
	AdjustIfPossibleButDontSpawnIfColliding,
	DontSpawnIfColliding,
	ESpawnActorCollisionHandlingMethod_MAX,
};

enum class EAthenaGamePhaseStep
{
	None,
	Setup,
	Warmup,
	GetReady,
	BusLocked,
	BusFlying,
	StormForming,
	StormHolding,
	StormShrinking,
	Countdown,
	FinalCountdown,
	EndGame,
	Count,
	EAthenaGamePhaseStep_MAX,
};

enum class ECameraProjectionMode : uint8_t
{
	Perspective = 0,
	Orthographic = 1,
	ECameraProjectionMode_MAX = 2
};

enum class EObjectFullNameFlags
{
	None = 0,
	IncludeClassPackage = 1,
};

enum class EAthenaGamePhase : uint8_t
{
	None = 0,
	Setup = 1,
	Warmup = 2,
	Aircraft = 3,
	SafeZones = 4,
	EndGame = 5,
	Count = 6,
	EAthenaGamePhase_MAX = 7
};

enum class ENetRole : uint8_t
{
	ROLE_None = 0,
	ROLE_SimulatedProxy = 1,
	ROLE_AutonomousProxy = 2,
	ROLE_Authority = 3,
	ROLE_MAX = 4
};

enum class EMontagePlayReturnType : uint8_t
{
	MontageLength = 0,
	Duration = 1,
	EMontagePlayReturnType_MAX = 2
};

enum class EFortCustomBodyType : uint8_t
{
	NONE = 0,
	Small = 1,
	Medium = 2,
	MediumAndSmall = 3,
	Large = 4,
	LargeAndSmall = 5,
	LargeAndMedium = 6,
	All = 7,
	Deprecated = 8,
	EFortCustomBodyType_MAX = 9
};

enum class EItemWrapMaterialType : uint8_t
{
	WeaponWrap = 0,
	VehicleWrap_Opaque = 1,
	VehicleWrap_Masked = 2,
	EItemWrapMaterialType_MAX = 3
};

enum class EFortMovementStyle : uint8_t
{
	Running = 0,
	Walking = 1,
	Charging = 2,
	Sprinting = 3,
	PersonalVehicle = 4,
	Flying = 5,
	Tethered = 6,
	EFortMovementStyle_MAX = 7
};

enum class EMouseCursor : uint8_t
{
	None = 0,
	Default = 1,
	TextEditBeam = 2,
	ResizeLeftRight = 3,
	ResizeUpDown = 4,
	ResizeSouthEast = 5,
	ResizeSouthWest = 6,
	CardinalCross = 7,
	Crosshairs = 8,
	Hand = 9,
	GrabHand = 10,
	GrabHandClosed = 11,
	SlashedCircle = 12,
	EyeDropper = 13,
	EMouseCursor_MAX = 14
};

enum class ECollisionChannel : uint8_t
{
	ECC_WorldStatic = 0,
	ECC_WorldDynamic = 1,
	ECC_Pawn = 2,
	ECC_Visibility = 3,
	ECC_Camera = 4,
	ECC_PhysicsBody = 5,
	ECC_Vehicle = 6,
	ECC_Destructible = 7,
	ECC_EngineTraceChannel1 = 8,
	ECC_EngineTraceChannel2 = 9,
	ECC_EngineTraceChannel3 = 10,
	ECC_EngineTraceChannel4 = 11,
	ECC_EngineTraceChannel5 = 12,
	ECC_EngineTraceChannel6 = 13,
	ECC_GameTraceChannel1 = 14,
	ECC_GameTraceChannel2 = 15,
	ECC_GameTraceChannel3 = 16,
	ECC_GameTraceChannel4 = 17,
	ECC_GameTraceChannel5 = 18,
	ECC_GameTraceChannel6 = 19,
	ECC_GameTraceChannel7 = 20,
	ECC_GameTraceChannel8 = 21,
	ECC_GameTraceChannel9 = 22,
	ECC_GameTraceChannel10 = 23,
	ECC_GameTraceChannel11 = 24,
	ECC_GameTraceChannel12 = 25,
	ECC_GameTraceChannel13 = 26,
	ECC_GameTraceChannel14 = 27,
	ECC_GameTraceChannel15 = 28,
	ECC_GameTraceChannel16 = 29,
	ECC_GameTraceChannel17 = 30,
	ECC_GameTraceChannel18 = 31,
	ECC_OverlapAll_Deprecated = 32,
	ECC_MAX = 33
};

enum class EWindowMode : uint8_t
{
	Fullscreen = 0,
	WindowedFullscreen = 1,
	Windowed = 2,
	EWindowMode_MAX = 3
};

enum EPropertyFlags : uint64_t
{
	CPF_None = 0,

	CPF_Edit = 0x0000000000000001,
	///< Property is user-settable in the editor.
	CPF_ConstParm = 0x0000000000000002,
	///< This is a constant function parameter
	CPF_BlueprintVisible = 0x0000000000000004,
	///< This property can be read by blueprint code
	CPF_ExportObject = 0x0000000000000008,
	///< Object can be exported with actor.
	CPF_BlueprintReadOnly = 0x0000000000000010,
	///< This property cannot be modified by blueprint code
	CPF_Net = 0x0000000000000020,
	///< Property is relevant to network replication.
	CPF_EditFixedSize = 0x0000000000000040,
	///< Indicates that elements of an array can be modified, but its size cannot be changed.
	CPF_Parm = 0x0000000000000080,
	///< Function/When call parameter.
	CPF_OutParm = 0x0000000000000100,
	///< Value is copied out after function call.
	CPF_ZeroConstructor = 0x0000000000000200,
	///< memset is fine for construction
	CPF_ReturnParm = 0x0000000000000400,
	///< Return value.
	CPF_DisableEditOnTemplate = 0x0000000000000800,
	///< Disable editing of this property on an archetype/sub-blueprint
	//CPF_      						= 0x0000000000001000,	///< 
	CPF_Transient = 0x0000000000002000,
	///< Property is transient: shouldn't be saved or loaded, except for Blueprint CDOs.
	CPF_Config = 0x0000000000004000,
	///< Property should be loaded/saved as permanent profile.
	//CPF_								= 0x0000000000008000,	///< 
	CPF_DisableEditOnInstance = 0x0000000000010000,
	///< Disable editing on an instance of this class
	CPF_EditConst = 0x0000000000020000,
	///< Property is uneditable in the editor.
	CPF_GlobalConfig = 0x0000000000040000,
	///< Load config from base class, not subclass.
	CPF_InstancedReference = 0x0000000000080000,
	///< Property is a component references.
	//CPF_								= 0x0000000000100000,	///<
	CPF_DuplicateTransient = 0x0000000000200000,
	///< Property should always be reset to the default value during any type of duplication (copy/paste, binary duplication, etc.)
	//CPF_								= 0x0000000000400000,	///< 
	//CPF_    							= 0x0000000000800000,	///< 
	CPF_SaveGame = 0x0000000001000000,
	///< Property should be serialized for save games, this is only checked for game-specific archives with ArIsSaveGame
	CPF_NoClear = 0x0000000002000000,
	///< Hide clear (and browse) button.
	//CPF_  							= 0x0000000004000000,	///<
	CPF_ReferenceParm = 0x0000000008000000,
	///< Value is passed by reference; CPF_OutParam and CPF_Param should also be set.
	CPF_BlueprintAssignable = 0x0000000010000000,
	///< MC Delegates only.  Property should be exposed for assigning in blueprint code
	CPF_Deprecated = 0x0000000020000000,
	///< Property is deprecated.  Read it from an archive, but don't save it.
	CPF_IsPlainOldData = 0x0000000040000000,
	///< If this is set, then the property can be memcopied instead of CopyCompleteValue / CopySingleValue
	CPF_RepSkip = 0x0000000080000000,
	///< Not replicated. For non replicated properties in replicated structs 
	CPF_RepNotify = 0x0000000100000000,
	///< Notify actors when a property is replicated
	CPF_Interp = 0x0000000200000000,
	///< interpolatable property for use with matinee
	CPF_NonTransactional = 0x0000000400000000,
	///< Property isn't transacted
	CPF_EditorOnly = 0x0000000800000000,
	///< Property should only be loaded in the editor
	CPF_NoDestructor = 0x0000001000000000,
	///< No destructor
	//CPF_								= 0x0000002000000000,	///<
	CPF_AutoWeak = 0x0000004000000000,
	///< Only used for weak pointers, means the export type is autoweak
	CPF_ContainsInstancedReference = 0x0000008000000000,
	///< Property contains component references.
	CPF_AssetRegistrySearchable = 0x0000010000000000,
	///< asset instances will add properties with this flag to the asset registry automatically
	CPF_SimpleDisplay = 0x0000020000000000,
	///< The property is visible by default in the editor details view
	CPF_AdvancedDisplay = 0x0000040000000000,
	///< The property is advanced and not visible by default in the editor details view
	CPF_Protected = 0x0000080000000000,
	///< property is protected from the perspective of script
	CPF_BlueprintCallable = 0x0000100000000000,
	///< MC Delegates only.  Property should be exposed for calling in blueprint code
	CPF_BlueprintAuthorityOnly = 0x0000200000000000,
	///< MC Delegates only.  This delegate accepts (only in blueprint) only events with BlueprintAuthorityOnly.
	CPF_TextExportTransient = 0x0000400000000000,
	///< Property shouldn't be exported to text format (e.g. copy/paste)
	CPF_NonPIEDuplicateTransient = 0x0000800000000000,
	///< Property should only be copied in PIE
	CPF_ExposeOnSpawn = 0x0001000000000000,
	///< Property is exposed on spawn
	CPF_PersistentInstance = 0x0002000000000000,
	///< A object referenced by the property is duplicated like a component. (Each actor should have an own instance.)
	CPF_UObjectWrapper = 0x0004000000000000,
	///< Property was parsed as a wrapper class like TSubclassOf<T>, FScriptInterface etc., rather than a USomething*
	CPF_HasGetValueTypeHash = 0x0008000000000000,
	///< This property can generate a meaningful hash value.
	CPF_NativeAccessSpecifierPublic = 0x0010000000000000,
	///< Public native access specifier
	CPF_NativeAccessSpecifierProtected = 0x0020000000000000,
	///< Protected native access specifier
	CPF_NativeAccessSpecifierPrivate = 0x0040000000000000,
	///< Private native access specifier
	CPF_SkipSerialization = 0x0080000000000000,
	///< Property shouldn't be serialized, can still be exported to text
};

enum ELifetimeCondition
{
	COND_None = 0,
	COND_InitialOnly = 1,
	COND_OwnerOnly = 2,
	COND_SkipOwner = 3,
	COND_SimulatedOnly = 4,
	COND_AutonomousOnly = 5,
	COND_SimulatedOrPhysics = 6,
	COND_InitialOrOwner = 7,
	COND_Custom = 8,
	COND_ReplayOrOwner = 9,
	COND_ReplayOnly = 10,
	COND_SimulatedOnlyNoReplay = 11,
	COND_SimulatedOrPhysicsNoReplay = 12,
	COND_SkipReplay = 13,
	COND_Never = 15,
	COND_Max = 16,
};

enum class EFortCustomPartType : uint8_t
{
	Head = 0,
	Body = 1,
	Hat = 2,
	Backpack = 3,
	Charm = 4,
	Face = 5,
	NumTypes = 6,
	EFortCustomPartType_MAX = 7
};

enum class EFortCustomGender : uint8_t
{
	Invalid = 0,
	Male = 1,
	Female = 2,
	Both = 3,
	EFortCustomGender_MAX = 4
};

enum class EMovementMode : uint8_t
{
	MOVE_None = 0,
	MOVE_Walking = 1,
	MOVE_NavWalking = 2,
	MOVE_Falling = 3,
	MOVE_Swimming = 4,
	MOVE_Flying = 5,
	MOVE_Custom = 6,
	MOVE_MAX = 7
};
