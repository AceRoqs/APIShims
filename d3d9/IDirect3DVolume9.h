#ifndef IDIRECT3DVOLUME9_H
#define IDIRECT3DVOLUME9_H

#include "ForwardDeclarations.h"

struct IDirect3DVolume9 : public IUnknown
{
    IFACEMETHOD(GetDevice)(_Outptr_ IDirect3DDevice9** device) = 0;
    IFACEMETHOD(SetPrivateData)(REFGUID guid, _In_reads_bytes_(size) const void* data, DWORD size, DWORD dlags) = 0;
    IFACEMETHOD(GetPrivateData)(REFGUID guid, _Out_writes_bytes_(*size) void* data, _Out_ DWORD* size) = 0;
    IFACEMETHOD(FreePrivateData)(REFGUID guid) = 0;
    IFACEMETHOD(GetContainer)(REFIID iid, _Outptr_ void** container) = 0;
    IFACEMETHOD(GetDesc)(_Out_ D3DVOLUME_DESC* descriptor) = 0;
    IFACEMETHOD(LockBox)(_Out_ D3DLOCKED_BOX* locked_volume, _In_opt_ const D3DBOX* box, DWORD flags) = 0;
    IFACEMETHOD(UnlockBox)() = 0;
};

#endif

