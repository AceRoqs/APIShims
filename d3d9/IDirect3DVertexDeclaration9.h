#ifndef IDIRECT3DVERTEXDECLARATION9_H
#define IDIRECT3DVERTEXDECLARATION9_H

#include "ForwardDeclarations.h"

struct IDirect3DVertexDeclaration9 : public IUnknown
{
    IFACEMETHOD(GetDevice)(_Outptr_ IDirect3DDevice9** device) = 0;
    IFACEMETHOD(GetDeclaration)(_Out_writes_(*element_count) D3DVERTEXELEMENT9* element, _Out_ UINT* element_count) = 0;
};

#endif

