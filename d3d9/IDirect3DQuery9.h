#ifndef IDIRECT3DQUERY9_H
#define IDIRECT3DQUERY9_H

#include "ForwardDeclarations.h"

struct IDirect3DQuery9 : public IUnknown
{
    IFACEMETHOD(GetDevice)(_Outptr_ IDirect3DDevice9** device) = 0;
    IFACEMETHOD_(D3DQUERYTYPE, GetType)() = 0;
    IFACEMETHOD_(DWORD, GetDataSize)() = 0;
    IFACEMETHOD(Issue)(DWORD flags) = 0;
    IFACEMETHOD(GetData)(_Out_writes_bytes_opt_(size) void* data, DWORD size, DWORD flags) = 0;
};

#endif

