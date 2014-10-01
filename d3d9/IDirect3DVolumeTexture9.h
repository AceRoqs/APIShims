#ifndef IDIRECT3DVOLUMETEXTURE9_H
#define IDIRECT3DVOLUMETEXTURE9_H

#include "IDirect3DBaseTexture9.h"

struct IDirect3DVolumeTexture9 : public IDirect3DBaseTexture9
{
    IFACEMETHOD(GetLevelDesc)(UINT level, _Out_ D3DVOLUME_DESC* descriptor) = 0;
    IFACEMETHOD(GetVolumeLevel)(UINT level, _Outptr_ IDirect3DVolume9** volume_level) = 0;
    IFACEMETHOD(LockBox)(UINT level, _Out_ D3DLOCKED_BOX* locked_volume, _In_opt_ const D3DBOX* box, DWORD flags) = 0;
    IFACEMETHOD(UnlockBox)(UINT level) = 0;
    IFACEMETHOD(AddDirtyBox)(_In_opt_ const D3DBOX* dirty_box) = 0;
};


#endif

