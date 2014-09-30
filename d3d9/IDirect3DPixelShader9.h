#ifndef IDIRECT3DPIXELSHADER9_H
#define IDIRECT3DPIXELSHADER9_H

#include "ForwardDeclarations.h"

struct IDirect3DPixelShader9 : public IUnknown
{
    IFACEMETHOD(GetDevice)(_Outptr_ IDirect3DDevice9** ppDevice) = 0;
    IFACEMETHOD(GetFunction)(_Out_writes_(*size) void* data, _Out_ UINT* size) = 0;
};

#endif

