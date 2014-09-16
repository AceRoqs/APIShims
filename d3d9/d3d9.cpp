#include <Windows.h>
#include <new>

enum D3DDEVTYPE
{
    D3DDEVTYPE_HAL = 1,
    D3DDEVTYPE_NULLREF = 4,
    D3DDEVTYPE_REF = 2,
    D3DDEVTYPE_SW = 3,
    D3DDEVTYPE_FORCE_DWORD = 0xffffffff
};
typedef D3DDEVTYPE* *LPD3DDEVTYPE;

enum D3DFORMAT; // TODO
enum D3DMULTISAMPLE_TYPE; // TODO

enum D3DRESOURCETYPE
{
    D3DRTYPE_SURFACE = 1,
    D3DRTYPE_VOLUME = 2,
    D3DRTYPE_TEXTURE = 3,
    D3DRTYPE_VOLUMETEXTURE = 4,
    D3DRTYPE_CUBETEXTURE = 5,
    D3DRTYPE_VERTEXBUFFER = 6,
    D3DRTYPE_INDEXBUFFER = 7,
    D3DRTYPE_FORCE_DWORD = 0x7fffffff
};
typedef D3DRESOURCETYPE* LPD3DRESOURCETYPE;

struct D3DDISPLAYMODE
{
    UINT      Width;
    UINT      Height;
    UINT      RefreshRate;
    D3DFORMAT Format;
};
typedef D3DDISPLAYMODE *LPD3DDISPLAYMODE;

struct D3DPRESENT_PARAMETERS; // TODO
struct D3DADAPTER_IDENTIFIER9; // TODO
struct D3DCAPS9; // TODO

struct IDirect3D9 : public IUnknown
{
    IFACEMETHOD(CheckDepthStencilMatch)(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat) = 0;
    IFACEMETHOD(CheckDeviceFormat)(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat) = 0;
    IFACEMETHOD(CheckDeviceFormatConversion)(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SourceFormat, D3DFORMAT TargetFormat) = 0;
    IFACEMETHOD(CheckDeviceMultiSampleType)(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType, _Out_ DWORD* pQualityLevels) = 0;
    IFACEMETHOD(CheckDeviceType)(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT DisplayFormat, D3DFORMAT BackBufferFormat, BOOL Windowed) = 0;
    IFACEMETHOD(CreateDevice)(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, _Inout_ D3DPRESENT_PARAMETERS* pPresentationParameters, _Outptr_ struct IDirect3DDevice9** ppReturnedDeviceInterface) = 0;
    IFACEMETHOD(EnumAdapterModes)(UINT Adapter, D3DFORMAT Format, UINT Mode, _Out_ D3DDISPLAYMODE* pMode) = 0;
    IFACEMETHOD_(UINT, GetAdapterCount)() = 0;
    IFACEMETHOD(GetAdapterDisplayMode)(UINT Adapter, _Out_ D3DDISPLAYMODE* pMode) = 0;
    IFACEMETHOD(GetAdapterIdentifier)(UINT Adapter, DWORD Flags, _Out_ D3DADAPTER_IDENTIFIER9* pIdentifier) = 0;
    IFACEMETHOD_(UINT, GetAdapterModeCount)(UINT Adapter, D3DFORMAT Format) = 0;
    IFACEMETHOD_(HMONITOR, GetAdapterMonitor)(UINT Adapter) = 0;
    IFACEMETHOD(GetDeviceCaps)(UINT Adapter, D3DDEVTYPE DeviceType, _Out_ D3DCAPS9* pCaps) = 0;
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

class CDirect3D9 : public IDirect3D9Ex
{
public:
    // IUnknown.
    IFACEMETHOD_(ULONG, AddRef)() override;
    IFACEMETHOD_(ULONG, Release)() override;
    IFACEMETHOD(QueryInterface)(REFIID riid, _Outptr_ void** ppvObject) override;

    // IDirect3D9.
    IFACEMETHOD(CheckDepthStencilMatch)(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat) override;
    IFACEMETHOD(CheckDeviceFormat)(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat) override;
    IFACEMETHOD(CheckDeviceFormatConversion)(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SourceFormat, D3DFORMAT TargetFormat) override;
    IFACEMETHOD(CheckDeviceMultiSampleType)(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType, _Out_ DWORD* pQualityLevels) override;
    IFACEMETHOD(CheckDeviceType)(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT DisplayFormat, D3DFORMAT BackBufferFormat, BOOL Windowed) override;
    IFACEMETHOD(CreateDevice)(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, _Inout_ D3DPRESENT_PARAMETERS* pPresentationParameters, _Outptr_ struct IDirect3DDevice9** ppReturnedDeviceInterface) override;
    IFACEMETHOD(EnumAdapterModes)(UINT Adapter, D3DFORMAT Format, UINT Mode, _Out_ D3DDISPLAYMODE* pMode) override;
    IFACEMETHOD_(UINT, GetAdapterCount)() override;
    IFACEMETHOD(GetAdapterDisplayMode)(UINT Adapter, _Out_ D3DDISPLAYMODE* pMode) override;
    IFACEMETHOD(GetAdapterIdentifier)(UINT Adapter, DWORD Flags, _Out_ D3DADAPTER_IDENTIFIER9* pIdentifier) override;
    IFACEMETHOD_(UINT, GetAdapterModeCount)(UINT Adapter, D3DFORMAT Format) override;
    IFACEMETHOD_(HMONITOR, GetAdapterMonitor)(UINT Adapter) override;
    IFACEMETHOD(GetDeviceCaps)(UINT Adapter, D3DDEVTYPE DeviceType, _Out_ D3DCAPS9* pCaps) override;
    IFACEMETHOD(RegisterSoftwareDevice)(void* pInitializeFunction) override;

    // IDirect3D9Ex.
    IFACEMETHOD(CreateDeviceEx)(UINT Adapter, D3DDEVTYPE DeviceType, _In_opt_ HWND hFocusWindow, DWORD BehaviorFlags, _Inout_ D3DPRESENT_PARAMETERS* pPresentationParameters,
        _Out_ struct D3DDISPLAYMODEEX* pFullscreenDisplayMode, _Outptr_ struct IDirect3DDevice9Ex** ppReturnedDeviceInterface) override;
    IFACEMETHOD(EnumAdapterModesEx)(UINT Adapter, _In_ const struct D3DDISPLAYMODEFILTER* pFilter, UINT Mode, _Out_ D3DDISPLAYMODEEX* pMode) override;
    IFACEMETHOD(GetAdapterDisplayModeEx)(UINT Adapter, _Out_opt_ D3DDISPLAYMODEEX* pMode, _Out_opt_ enum D3DDISPLAYROTATION* pRotation) override;
    IFACEMETHOD(GetAdapterLUID)(UINT Adapter, _Out_ LUID* pLUID) override;
    IFACEMETHOD(GetAdapterModeCountEx)(UINT Adapter, _In_ const D3DDISPLAYMODEFILTER* pFilter) override;
};

BOOL WINAPI DllMain(_In_ HINSTANCE instance, DWORD reason, _In_opt_ PVOID reserved)
{
    return TRUE;
}

struct IDirect3D9* WINAPI Direct3DCreate9(_In_ UINT SDKVersion)
{
    return new(std::nothrow) CDirect3D9();
}

HRESULT WINAPI Direct3DCreate9Ex(UINT SDKVersion, _Outptr_ struct IDirect3D9Ex** ppD3D)
{
    return E_NOTIMPL;
}

void WINAPI DebugSetMute()
{
}

void WINAPI Direct3DShaderValidatorCreate9()
{
}

IFACEMETHODIMP_(ULONG) CDirect3D9::AddRef()
{
    return 0;
}

IFACEMETHODIMP_(ULONG) CDirect3D9::Release()
{
    return 0;
}

IFACEMETHODIMP CDirect3D9::QueryInterface(REFIID riid, _Outptr_ void** ppvObject)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP CDirect3D9::CheckDepthStencilMatch(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP CDirect3D9::CheckDeviceFormat(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP CDirect3D9::CheckDeviceFormatConversion(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SourceFormat, D3DFORMAT TargetFormat)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP CDirect3D9::CheckDeviceMultiSampleType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType, _Out_ DWORD* pQualityLevels)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP CDirect3D9::CheckDeviceType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT DisplayFormat, D3DFORMAT BackBufferFormat, BOOL Windowed)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP CDirect3D9::CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, _Inout_ D3DPRESENT_PARAMETERS* pPresentationParameters, _Outptr_ struct IDirect3DDevice9** ppReturnedDeviceInterface)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP CDirect3D9::EnumAdapterModes(UINT Adapter, D3DFORMAT Format, UINT Mode, _Out_ D3DDISPLAYMODE* pMode)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP_(UINT) CDirect3D9::GetAdapterCount()
{
    return 0;
}

IFACEMETHODIMP CDirect3D9::GetAdapterDisplayMode(UINT Adapter, _Out_ D3DDISPLAYMODE* pMode)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP CDirect3D9::GetAdapterIdentifier(UINT Adapter, DWORD Flags, _Out_ D3DADAPTER_IDENTIFIER9* pIdentifier)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP_(UINT) CDirect3D9::GetAdapterModeCount(UINT Adapter, D3DFORMAT Format)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP_(HMONITOR) CDirect3D9::GetAdapterMonitor(UINT Adapter)
{
    return nullptr;
}

IFACEMETHODIMP CDirect3D9::GetDeviceCaps(UINT Adapter, D3DDEVTYPE DeviceType, _Out_ D3DCAPS9* pCaps)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP CDirect3D9::RegisterSoftwareDevice(void* pInitializeFunction)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP CDirect3D9::CreateDeviceEx(UINT Adapter, D3DDEVTYPE DeviceType, _In_opt_ HWND hFocusWindow, DWORD BehaviorFlags, _Inout_ D3DPRESENT_PARAMETERS* pPresentationParameters,
    _Out_ struct D3DDISPLAYMODEEX* pFullscreenDisplayMode, _Outptr_ struct IDirect3DDevice9Ex** ppReturnedDeviceInterface)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP CDirect3D9::EnumAdapterModesEx(UINT Adapter, _In_ const struct D3DDISPLAYMODEFILTER* pFilter, UINT Mode, _Out_ D3DDISPLAYMODEEX* pMode)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP CDirect3D9::GetAdapterDisplayModeEx(UINT Adapter, _Out_opt_ D3DDISPLAYMODEEX* pMode, _Out_opt_ enum D3DDISPLAYROTATION* pRotation)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP CDirect3D9::GetAdapterLUID(UINT Adapter, _Out_ LUID* pLUID)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP CDirect3D9::GetAdapterModeCountEx(UINT Adapter, _In_ const D3DDISPLAYMODEFILTER* pFilter)
{
    return E_NOTIMPL;
}

