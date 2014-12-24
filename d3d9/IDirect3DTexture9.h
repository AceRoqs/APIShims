#pragma once

#include "IDirect3DBaseTexture9.h"

struct IDirect3DTexture9 : public IDirect3DBaseTexture9
{
    IFACEMETHOD(GetLevelDesc)(UINT level, _Out_ D3DSURFACE_DESC* surface_descriptor) = 0;
    IFACEMETHOD(GetSurfaceLevel)(UINT level, _Out_ IDirect3DSurface9** surface_level) = 0;
    IFACEMETHOD(LockRect)(UINT level, _Out_ D3DLOCKED_RECT* locked_rect, _In_opt_ const RECT* rect, DWORD flags) = 0;
    IFACEMETHOD(UnlockRect)(UINT level) = 0;
    IFACEMETHOD(AddDirtyRect)(_In_ const RECT* dirty_rect) = 0;
};

