#include "pch.h"
#include "core/application.h"

BOOL APIENTRY DllMain(HMODULE _Module, DWORD _ReasonForCall, LPVOID _Reserved)
{
    switch (_ReasonForCall)
    {
        case DLL_PROCESS_ATTACH:
        {
            application::initialize(_Module);
        }
        break;
        case DLL_PROCESS_DETACH:
        {
            application::cleanup(_Module);
        }
        break;
    }

    return TRUE;
}