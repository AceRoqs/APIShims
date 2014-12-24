#pragma once

#include "IDirect3DBaseTexture9.h"

struct IDirect3DCubeTexture9 : public IDirect3DBaseTexture9
{
    IFACEMETHOD(GetLevelDesc)(UINT level, _Out_ D3DSURFACE_DESC* surface_descriptor) = 0;
    IFACEMETHOD(GetCubeMapSurface)(D3DCUBEMAP_FACES face_type, UINT level, _Outptr_ IDirect3DSurface9** cube_map_surface) = 0;
    IFACEMETHOD(LockRect)(D3DCUBEMAP_FACES face_type, UINT level, _Out_ D3DLOCKED_RECT* locked_rect, _In_opt_ const RECT* rect, DWORD flags) = 0;
    IFACEMETHOD(UnlockRect)(D3DCUBEMAP_FACES face_type, UINT level) = 0;
    IFACEMETHOD(AddDirtyRect)(D3DCUBEMAP_FACES face_type, _In_ const RECT* dirty_rect) = 0;
};

