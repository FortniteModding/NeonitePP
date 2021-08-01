#pragma once
#include "pch.h"
#include "structs.h"
#include "enums.h"
#include "util.h"
#include "detours.h"
#include "ue4.h"
#include "veh.h"

namespace Hooks
{
#ifdef SSL_BYPASS

	inline bool Init()
	{
		//<REDACTED>

		
		return true;
	}

#endif

	inline bool Misc(float version)
	{
		if (MH_Initialize() != MH_OK)
		{
			MessageBoxA(nullptr, XOR("Failed to initialize min-hook, terminating the thread."), XOR("Cranium"), MB_OK);
			FreeLibraryAndExitThread(GetModuleHandle(nullptr), 0);
		}

		//GObject Array
		auto GObjectsAdd = Util::FindPattern(Patterns::bGlobal::GObjects, Masks::bGlobal::GObjects);
		VALIDATE_ADDRESS(GObjectsAdd, XOR("Failed to find GObjects Address."));

		GObjs = decltype(GObjs)(RELATIVE_ADDRESS(GObjectsAdd, 7));

		auto FNameToStringAdd = Util::FindPattern(Patterns::New::FNameToString,
		                                          Masks::New::FNameToString);
		VALIDATE_ADDRESS(FNameToStringAdd, XOR("Failed to find FNameToString Address."));

		/*const auto offset = *reinterpret_cast<int32_t*>(FNameToStringAdd + 1);
		FNameToStringAdd = FNameToStringAdd + 5 + offset;*/

		FNameToString = decltype(FNameToString)(FNameToStringAdd);

		//A work around instead of using a pattern.
		GEngine = UE4::FindObject<UEngine*>(XOR(L"FortEngine /Engine/Transient.FortEngine_"));


		uintptr_t ProcessEventAdd;
		if (version >= 16.00f)
		{
			const auto vtable = *reinterpret_cast<void***>(GEngine);
			ProcessEventAdd = (uintptr_t)vtable[0x44];
		}
		else
		{
			ProcessEventAdd = Util::FindPattern(Patterns::bGlobal::ProcessEvent, Masks::bGlobal::ProcessEvent);
			VALIDATE_ADDRESS(ProcessEventAdd, XOR("Failed to find ProcessEvent Address."));
		}


		ProcessEvent = decltype(ProcessEvent)(ProcessEventAdd);
		MH_CreateHook(reinterpret_cast<void*>(ProcessEventAdd), ProcessEventDetour,
		              reinterpret_cast<void**>(&ProcessEvent));
		MH_EnableHook(reinterpret_cast<void*>(ProcessEventAdd));


		//Used to construct objects, mostly used for console stuff.
		//Tested from 12.41 to latest
		auto SCOIAdd = Util::FindPattern(Patterns::bGlobal::SCOI, Masks::bGlobal::SCOI);
		VALIDATE_ADDRESS(SCOIAdd, XOR("Failed to find SCOI Address."));

		StaticConstructObject = decltype(StaticConstructObject)(SCOIAdd);


		//Used to load objects.
		auto SLOIAdd = Util::FindPattern(Patterns::bGlobal::SLOI, Masks::bGlobal::SLOI);
		VALIDATE_ADDRESS(SLOIAdd, XOR("Failed to find SLOI Address."));

		StaticLoadObject = decltype(StaticLoadObject)(SLOIAdd);


		//Used to spawn actors
		auto SpawnActorAdd = Util::FindPattern(Patterns::bGlobal::SpawnActorInternal,
		                                       Masks::bGlobal::SpawnActorInternal);
		VALIDATE_ADDRESS(SpawnActorAdd, XOR("Failed to find SpawnActor Address."));

		SpawnActor = decltype(SpawnActor)(SpawnActorAdd);


	

		auto Map = APOLLO_TERRAIN;

		gPlaylist = UE4::FindObject<UObject*>(XOR(L"FortPlaylistAthena /Game/Athena/Playlists/BattleLab/Playlist_BattleLab.Playlist_BattleLab"));
		Start(Map);



		return true;
	}
}
