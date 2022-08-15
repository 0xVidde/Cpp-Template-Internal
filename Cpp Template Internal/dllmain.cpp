#include "pch.h"
#include <Windows.h>
#include <cstdio>

// Temp
#include <iostream>
#include "Utilities.h"
// --------

DWORD HackThread(HMODULE hModule) {
    Utilities::AllocateConsole();
    
    std::cout << "Successfully Injected Into Process!";

    FreeConsole();
    FreeLibraryAndExitThread(hModule, 0);
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)HackThread, hModule, 0, nullptr));
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

