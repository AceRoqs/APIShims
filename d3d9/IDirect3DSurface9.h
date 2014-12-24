#pragma once

#include "IDirect3DResource9.h"

struct IDirect3DSurface9 : public IDirect3DResource9
{
    IFACEMETHOD(GetContainer)(REFIID iid, _Outptr_ void** container) = 0;
    IFACEMETHOD(GetDesc)(_Out_ D3DSURFACE_DESC* descriptor) = 0;
    IFACEMETHOD(LockRect)(_Out_ D3DLOCKED_RECT* locked_rect, _In_opt_ const RECT* rect, DWORD flags) = 0;
    IFACEMETHOD(UnlockRect)() = 0;
    IFACEMETHOD(GetDC)(_Out_ HDC* device_context) = 0;
    IFACEMETHOD(ReleaseDC)(_In_ HDC device_context) = 0;
};

