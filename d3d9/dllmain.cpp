#include "PreCompile.h"

BOOL WINAPI DllMain(_In_ HINSTANCE instance, DWORD reason, _In_opt_ PVOID reserved)
{
    (void)instance;     // Unreferenced parameter.
    (void)reason;
    (void)reserved;
    return TRUE;
}

void WINAPI DebugSetMute()
{
}

void WINAPI Direct3DShaderValidatorCreate9()
{
}

