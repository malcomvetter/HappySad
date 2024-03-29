// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <string>

HANDLE hThread;
DWORD threadID;


// Function executed when the thread starts
DWORD WINAPI __dllInit(LPVOID lpParam)
{
    char buff[100];
    std::string s = "HAPPY DLL";
    sprintf_s(buff, "I AM %s", s.c_str());
    MessageBoxA(NULL, buff, s.c_str(), MB_OK | MB_ICONQUESTION);

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
        DisableThreadLibraryCalls(hModule);
        hThread = CreateThread(NULL, 0, __dllInit, NULL, 0, &threadID);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }

    return TRUE;
}

// This is so the the DLL can be started with rundll and still function properly
extern "C" __declspec(dllexport) BOOL Load(LPVOID lpUserdata, DWORD nUserdataLen)
{
    if (hThread)
    {
        WaitForSingleObject(hThread, INFINITE);
    }
    return TRUE;
};


extern "C" __declspec(dllexport) STDAPI DllRegisterServer()
{
    if (hThread)
    {
        WaitForSingleObject(hThread, INFINITE);
    }
    return S_OK;
};


extern "C" __declspec(dllexport) STDAPI DllUnregisterServer()
{
    if (hThread)
    {
        WaitForSingleObject(hThread, INFINITE);
    }
    return S_OK;
};


extern "C" __declspec(dllexport) STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID * ppvObj)
{
    if (hThread)
    {
        WaitForSingleObject(hThread, INFINITE);
    }
    return S_OK;
};


