#pragma once

#include "IDirect3DResource9.h"

struct IDirect3DBaseTexture9 : public IDirect3DResource9
{
    IFACEMETHOD_(DWORD, SetLOD)(DWORD lod) = 0;
    IFACEMETHOD_(DWORD, GetLOD)() = 0;
    IFACEMETHOD_(DWORD, GetLevelCount)() = 0;
    IFACEMETHOD(SetAutoGenFilterType)(D3DTEXTUREFILTERTYPE filter_type) = 0;
    IFACEMETHOD_(D3DTEXTUREFILTERTYPE, GetAutoGenFilterType)() = 0;
    IFACEMETHOD_(void, GenerateMipSubLevels)() = 0;
};

