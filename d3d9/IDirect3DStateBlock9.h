#pragma once

#include "ForwardDeclarations.h"

struct IDirect3DStateBlock9 : public IUnknown
{
    IFACEMETHOD(GetDevice)(_Outptr_ IDirect3DDevice9** device) = 0;
    IFACEMETHOD(Capture)() = 0;
    IFACEMETHOD(Apply)() = 0;
};

