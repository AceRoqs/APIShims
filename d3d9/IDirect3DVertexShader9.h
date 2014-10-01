#ifndef IDIRECT3DVERTEXSHADER9_H
#define IDIRECT3DVERTEXSHADER9_H

#include "ForwardDeclarations.h"

struct IDirect3DVertexShader9 : public IUnknown
{
    IFACEMETHOD(GetDevice)(_Outptr_ IDirect3DDevice9** device) = 0;
    IFACEMETHOD(GetFunction)(_Out_writes_bytes_(*size) void* data, _Out_ UINT* size) = 0;
};

#endif

