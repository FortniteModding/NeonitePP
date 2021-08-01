/**
 * Copyright (c) 2020-2021 Kareem Olim (Kemo)
 * All Rights Reserved. Licensed under the Neo License
 * https://neonite.dev/LICENSE.html
 */

#include "pch.h"
#include "hooks.h"


void WINAPI dllMain()
{
	#ifdef CONSOLE
	//#ifndef PROD
	FILE* fDummy;
	AllocConsole();
	freopen_s(&fDummy, "CONIN$", "r", stdin);
	freopen_s(&fDummy, "CONOUT$", "w", stderr);
	freopen_s(&fDummy, "CONOUT$", "w", stdout);
	//freopen_s(&fDummy, "ProcessEvent.log", "w", stdout);
	//#endif
	printf(XOR("[=]Scuffed build for latest, Made by kemo (@xkem0x on twitter)"));
	#endif


	#ifdef HOOKS
	Hooks::Misc(99.99f);
	#endif
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH: dllMain();
		break;
	case DLL_PROCESS_DETACH: case DLL_THREAD_ATTACH: case DLL_THREAD_DETACH: default: break;
	}
	return TRUE;
}
