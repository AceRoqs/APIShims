#ifndef IDIRECT3DSWAPCHAIN9_H
#define IDIRECT3DSWAPCHAIN9_H

#include "ForwardDeclarations.h"

struct IDirect3DSwapChain9 : public IUnknown
{
    IFACEMETHOD(Present)(_In_opt_ const RECT* source_rect, _In_opt_ const RECT* destination_rect, _In_opt_ HWND destination_window, _In_opt_ const RGNDATA* dirty_region, DWORD flags) = 0;
    IFACEMETHOD(GetFrontBufferData)(_In_ IDirect3DSurface9* destination_surface) = 0;
    IFACEMETHOD(GetBackBuffer)(UINT index, D3DBACKBUFFER_TYPE type, _Outptr_ IDirect3DSurface9** back_buffer) = 0;
    IFACEMETHOD(GetRasterStatus)(_Out_ D3DRASTER_STATUS* raster_status) = 0;
    IFACEMETHOD(GetDisplayMode)(_Out_ D3DDISPLAYMODE* mode) = 0;
    IFACEMETHOD(GetDevice)(_Outptr_ IDirect3DDevice9** device) = 0;
    IFACEMETHOD(GetPresentParameters)(_Out_ D3DPRESENT_PARAMETERS* presentation_parameters) = 0;
};

struct IDirect3DSwapChain9Ex : public IDirect3DSwapChain9
{
    IFACEMETHOD(GetLastPresentCount)(_Out_ UINT* last_present_count) = 0;
    IFACEMETHOD(GetPresentStats)(_Out_ D3DPRESENTSTATS* presentation_statistics) = 0;
    IFACEMETHOD(GetDisplayModeEx)(_Out_ D3DDISPLAYMODEEX* mode, _Out_ D3DDISPLAYROTATION* rotation) = 0;
};

#endif

