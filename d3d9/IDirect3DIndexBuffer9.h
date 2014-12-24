#pragma once

#include "IDirect3DResource9.h"

struct IDirect3DIndexBuffer9 : public IDirect3DResource9
{
    IFACEMETHOD(Lock)(UINT offset, UINT size, _Outptr_ void** data, DWORD flags) = 0;
    IFACEMETHOD(Unlock)() = 0;
    IFACEMETHOD(GetDesc)(_Out_ D3DINDEXBUFFER_DESC* descriptor) = 0;
};

