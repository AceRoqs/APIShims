#ifndef IDIRECT3D9_H
#define IDIRECT3D9_H

struct IDirect3D9 : public IUnknown
{
    IFACEMETHOD(CheckDepthStencilMatch)(UINT Adapter, enum D3DDEVTYPE DeviceType, enum D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat) = 0;
    IFACEMETHOD(CheckDeviceFormat)(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, enum D3DRESOURCETYPE RType, D3DFORMAT CheckFormat) = 0;
    IFACEMETHOD(CheckDeviceFormatConversion)(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SourceFormat, D3DFORMAT TargetFormat) = 0;
    IFACEMETHOD(CheckDeviceMultiSampleType)(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, enum D3DMULTISAMPLE_TYPE MultiSampleType, _Out_ DWORD* pQualityLevels) = 0;
    IFACEMETHOD(CheckDeviceType)(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT DisplayFormat, D3DFORMAT BackBufferFormat, BOOL Windowed) = 0;
    IFACEMETHOD(CreateDevice)(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, _Inout_ struct D3DPRESENT_PARAMETERS* pPresentationParameters, _Outptr_ struct IDirect3DDevice9** ppReturnedDeviceInterface) = 0;
    IFACEMETHOD(EnumAdapterModes)(UINT Adapter, D3DFORMAT Format, UINT Mode, _Out_ struct D3DDISPLAYMODE* pMode) = 0;
    IFACEMETHOD_(UINT, GetAdapterCount)() = 0;
    IFACEMETHOD(GetAdapterDisplayMode)(UINT Adapter, _Out_ D3DDISPLAYMODE* pMode) = 0;
    IFACEMETHOD(GetAdapterIdentifier)(UINT Adapter, DWORD Flags, _Out_ struct D3DADAPTER_IDENTIFIER9* pIdentifier) = 0;
    IFACEMETHOD_(UINT, GetAdapterModeCount)(UINT Adapter, D3DFORMAT Format) = 0;
    IFACEMETHOD_(HMONITOR, GetAdapterMonitor)(UINT Adapter) = 0;
    IFACEMETHOD(GetDeviceCaps)(UINT Adapter, D3DDEVTYPE DeviceType, _Out_ struct D3DCAPS9* pCaps) = 0;
    IFACEMETHOD(RegisterSoftwareDevice)(void* pInitializeFunction) = 0;
};

struct IDirect3D9Ex : public IDirect3D9
{
    IFACEMETHOD(CreateDeviceEx)(UINT Adapter, D3DDEVTYPE DeviceType, _In_opt_ HWND hFocusWindow, DWORD BehaviorFlags, _Inout_ D3DPRESENT_PARAMETERS* pPresentationParameters,
        _Out_ struct D3DDISPLAYMODEEX* pFullscreenDisplayMode, _Outptr_ struct IDirect3DDevice9Ex** ppReturnedDeviceInterface) = 0;
    IFACEMETHOD(EnumAdapterModesEx)(UINT Adapter, _In_ const struct D3DDISPLAYMODEFILTER* pFilter, UINT Mode, _Out_ D3DDISPLAYMODEEX* pMode) = 0;
    IFACEMETHOD(GetAdapterDisplayModeEx)(UINT Adapter, _Out_opt_ D3DDISPLAYMODEEX* pMode, _Out_opt_ enum D3DDISPLAYROTATION* pRotation) = 0;
    IFACEMETHOD(GetAdapterLUID)(UINT Adapter, _Out_ LUID* pLUID) = 0;
    IFACEMETHOD(GetAdapterModeCountEx)(UINT Adapter, _In_ const D3DDISPLAYMODEFILTER* pFilter) = 0;
};

#endif

