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

		auto FNameToStringAdd = Util::FindPattern(Patterns::New::FNameToString, Masks::New::FNameToString);
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
		MH_CreateHook(reinterpret_cast<void*>(ProcessEventAdd), ProcessEventDetour, reinterpret_cast<void**>(&ProcessEvent));
		MH_EnableHook(reinterpret_cast<void*>(ProcessEventAdd));


		//Used to construct objects, mostly used for console stuff.
		//Tested from 12.41 to latest
		auto SCOIAdd = Util::FindPattern(Patterns::bGlobal::SCOI, Masks::bGlobal::SCOI);
		VALIDATE_ADDRESS(SCOIAdd, XOR("Failed to find SCOI Address. Check Number 1"));

		StaticConstructObject = decltype(StaticConstructObject)(SCOIAdd);


		//Used to load objects.
		/*auto SLOIAdd = Util::FindPattern(Patterns::bGlobal::SLOI, Masks::bGlobal::SLOI);
		VALIDATE_ADDRESS(SLOIAdd, XOR("Failed to find SLOI Address. Check Number 2 "));

		StaticLoadObject = decltype(StaticLoadObject)(SLOIAdd);*/


		//Used to spawn actors
		auto SpawnActorAdd = Util::FindPattern(Patterns::bGlobal::SpawnActorInternal, Masks::bGlobal::SpawnActorInternal);
		VALIDATE_ADDRESS(SpawnActorAdd, XOR("Failed to find SpawnActor Address."));

		SpawnActor = decltype(SpawnActor)(SpawnActorAdd);

		/*
		auto WeaponCheckAdd = Util::FindPattern("\x0F\x84\x00\x00\x00\x00\x44\x38\x00\x00\x00\x00\x00\x0F\x84\x00\x00\x00\x00\x80\x3D\x75\x44\x2F\x05", "xx????xx?????xx????xxxxxx");
		VALIDATE_ADDRESS(WeaponCheckAdd, XOR("Failed to find WeaponCheck Address."));*/

		//DWORD oldPrc;
		//VirtualProtect((void*)WeaponCheckAdd, 2, PAGE_EXECUTE_READWRITE, &oldPrc);

		//reinterpret_cast<uint8_t*>(WeaponCheckAdd)[1] = 0x85 /* JNE */;

		auto Map = APOLLO_TERRAIN;

		gPlaylist = UE4::FindObject<UObject*>(XOR(L"FortPlaylistAthena /Game/Athena/Playlists/BattleLab/Playlist_BattleLab.Playlist_BattleLab"));
		Start(Map);


		return true;
	}
}
