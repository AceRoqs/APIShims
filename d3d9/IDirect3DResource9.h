#ifndef IDIRECT3DRESOURCE_H
#define IDIRECT3DRESOURCE_H

#include "ForwardDeclarations.h"

struct IDirect3DResource9 : public IUnknown
{
    IFACEMETHOD(GetDevice)(_Outptr_ IDirect3DDevice9** device) = 0;
    IFACEMETHOD(SetPrivateData)(REFGUID guid, _In_reads_(size) const void* data, DWORD size, DWORD flags) = 0;
    IFACEMETHOD(GetPrivateData)(REFGUID guid, _Out_writes_(size) void* data, _Out_ DWORD* size) = 0;
    IFACEMETHOD(FreePrivateData)(REFGUID guid) = 0;
    IFACEMETHOD_(DWORD, SetPriority)(DWORD priority) = 0;
    IFACEMETHOD_(DWORD, GetPriority)() = 0;
    IFACEMETHOD_(void, PreLoad)() = 0;
    IFACEMETHOD_(D3DRESOURCETYPE, GetType)() = 0;
};

#endif

