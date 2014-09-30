#ifndef IDIRECT3D9_H
#define IDIRECT3D9_H

#include "ForwardDeclarations.h"

struct IDirect3D9 : public IUnknown
{
    IFACEMETHOD(CheckDepthStencilMatch)(UINT adapter, D3DDEVTYPE device_type, D3DFORMAT adapter_format, D3DFORMAT render_target_format, D3DFORMAT depth_stencil_format) = 0;
    IFACEMETHOD(CheckDeviceFormat)(UINT adapter, D3DDEVTYPE device_type, D3DFORMAT adapter_format, DWORD usage, D3DRESOURCETYPE resource_type, D3DFORMAT check_format) = 0;
    IFACEMETHOD(CheckDeviceFormatConversion)(UINT adapter, D3DDEVTYPE device_type, D3DFORMAT source_format, D3DFORMAT target_format) = 0;
    IFACEMETHOD(CheckDeviceMultiSampleType)(UINT adapter, D3DDEVTYPE device_type, D3DFORMAT surface_format, BOOL windowed, D3DMULTISAMPLE_TYPE multisample_type, _Out_ DWORD* quality_levels) = 0;
    IFACEMETHOD(CheckDeviceType)(UINT adapter, D3DDEVTYPE device_type, D3DFORMAT display_format, D3DFORMAT back_buffer_format, BOOL windowed) = 0;
    IFACEMETHOD(CreateDevice)(UINT adapter, D3DDEVTYPE device_type, _In_opt_ HWND focus_window, DWORD behavior_flags, _Inout_ D3DPRESENT_PARAMETERS* presentation_parameters, _Outptr_ IDirect3DDevice9** device_interface) = 0;
    IFACEMETHOD(EnumAdapterModes)(UINT adapter, D3DFORMAT format, UINT index, _Out_ D3DDISPLAYMODE* mode) = 0;
    IFACEMETHOD_(UINT, GetAdapterCount)() = 0;
    IFACEMETHOD(GetAdapterDisplayMode)(UINT adapter, _Out_ D3DDISPLAYMODE* mode) = 0;
    IFACEMETHOD(GetAdapterIdentifier)(UINT adapter, DWORD flags, _Out_ D3DADAPTER_IDENTIFIER9* identifier) = 0;
    IFACEMETHOD_(UINT, GetAdapterModeCount)(UINT adapter, D3DFORMAT format) = 0;
    IFACEMETHOD_(HMONITOR, GetAdapterMonitor)(UINT adapter) = 0;
    IFACEMETHOD(GetDeviceCaps)(UINT adapter, D3DDEVTYPE device_type, _Out_ D3DCAPS9* caps) = 0;
    IFACEMETHOD(RegisterSoftwareDevice)(_In_ void* initialize_function) = 0;
};

struct IDirect3D9Ex : public IDirect3D9
{
    IFACEMETHOD(CreateDeviceEx)(UINT adapter, D3DDEVTYPE device_type, _In_opt_ HWND focus_window, DWORD behavior_flags, _Inout_ D3DPRESENT_PARAMETERS* presentation_parameters,
        _Out_ D3DDISPLAYMODEEX* full_screen_display_mode, _Outptr_ IDirect3DDevice9Ex** device_interface) = 0;
    IFACEMETHOD(EnumAdapterModesEx)(UINT adapter, _In_ const D3DDISPLAYMODEFILTER* filter, UINT index, _Out_ D3DDISPLAYMODEEX* mode) = 0;
    IFACEMETHOD(GetAdapterDisplayModeEx)(UINT adapter, _Out_opt_ D3DDISPLAYMODEEX* mode, _Out_opt_ D3DDISPLAYROTATION* rotation) = 0;
    IFACEMETHOD(GetAdapterLUID)(UINT adapter, _Out_ LUID* luid) = 0;
    IFACEMETHOD(GetAdapterModeCountEx)(UINT adapter, _In_ const D3DDISPLAYMODEFILTER* filter) = 0;
};

#endif

