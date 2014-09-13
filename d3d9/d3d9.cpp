#include <Windows.h>

void* Direct3DCreate9(_In_ UINT SDKVersion)
{
    return nullptr;
}

HRESULT Direct3DCreate9Ex(_In_ UINT SDKVersion, _Out_ struct IDirect3D9Ex** ppD3D)
{
    return E_NOTIMPL;
}

HRESULT Direct3DShaderValidatorCreate9()
{
    return E_NOTIMPL;
}

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
    D3DRTYPE_CubeTexture = 5,
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

struct IDirect3D9
{
    virtual HRESULT CheckDepthStencilMatch(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat) = 0;
    virtual HRESULT CheckDeviceFormat(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat) = 0;
    virtual HRESULT CheckDeviceFormatConversion(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SourceFormat, D3DFORMAT TargetFormat) = 0;
    virtual HRESULT CheckDeviceMultiSampleType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType, _Out_ DWORD* pQualityLevels) = 0;
    virtual HRESULT CheckDeviceType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT DisplayFormat, D3DFORMAT BackBufferFormat, BOOL Windowed) = 0;
    virtual HRESULT CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, _Inout_ D3DPRESENT_PARAMETERS* pPresentationParameters, _Outptr_ struct IDirect3DDevice9** ppReturnedDeviceInterface) = 0;
    virtual HRESULT EnumAdapterModes(UINT Adapter, D3DFORMAT Format, UINT Mode, _Out_ D3DDISPLAYMODE* pMode) = 0;
    virtual UINT GetAdapterCount() = 0;
    virtual HRESULT GetAdapterDisplayMode(UINT Adapter, _Out_ D3DDISPLAYMODE* pMode) = 0;
    virtual HRESULT GetAdapterIdentifier(UINT Adapter, DWORD Flags, _Out_ D3DADAPTER_IDENTIFIER9* pIdentifier) = 0;
    virtual UINT GetAdapterModeCount(UINT Adapter, D3DFORMAT Format) = 0;
    virtual HMONITOR GetAdapterMonitor(UINT Adapter) = 0;
    virtual HRESULT GetDeviceCaps(UINT Adapter, D3DDEVTYPE DeviceType, _Out_ D3DCAPS9* pCaps) = 0;
    virtual HRESULT RegisterSoftwareDevice(void* pInitializeFunction) = 0;
};

class CDirect3D9 : public IDirect3D9
{
public:
    HRESULT CheckDepthStencilMatch(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat) override;
    HRESULT CheckDeviceFormat(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat) override;
    HRESULT CheckDeviceFormatConversion(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SourceFormat, D3DFORMAT TargetFormat) override;
    HRESULT CheckDeviceMultiSampleType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType, _Out_ DWORD* pQualityLevels) override;
    HRESULT CheckDeviceType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT DisplayFormat, D3DFORMAT BackBufferFormat, BOOL Windowed) override;
    HRESULT CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, _Inout_ D3DPRESENT_PARAMETERS* pPresentationParameters, _Outptr_ struct IDirect3DDevice9** ppReturnedDeviceInterface) override;
    HRESULT EnumAdapterModes(UINT Adapter, D3DFORMAT Format, UINT Mode, _Out_ D3DDISPLAYMODE* pMode) override;
    UINT GetAdapterCount() override;
    HRESULT GetAdapterDisplayMode(UINT Adapter, _Out_ D3DDISPLAYMODE* pMode) override;
    HRESULT GetAdapterIdentifier(UINT Adapter, DWORD Flags, _Out_ D3DADAPTER_IDENTIFIER9* pIdentifier) override;
    UINT GetAdapterModeCount(UINT Adapter, D3DFORMAT Format) override;
    HMONITOR GetAdapterMonitor(UINT Adapter) override;
    HRESULT GetDeviceCaps(UINT Adapter, D3DDEVTYPE DeviceType, _Out_ D3DCAPS9* pCaps) override;
    HRESULT RegisterSoftwareDevice(void* pInitializeFunction) override;
};

HRESULT CDirect3D9::CheckDepthStencilMatch(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat)
{
    return E_NOTIMPL;
}

HRESULT CDirect3D9::CheckDeviceFormat(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat)
{
    return E_NOTIMPL;
}

HRESULT CDirect3D9::CheckDeviceFormatConversion(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SourceFormat, D3DFORMAT TargetFormat)
{
    return E_NOTIMPL;
}

HRESULT CDirect3D9::CheckDeviceMultiSampleType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType, _Out_ DWORD* pQualityLevels)
{
    return E_NOTIMPL;
}

HRESULT CDirect3D9::CheckDeviceType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT DisplayFormat, D3DFORMAT BackBufferFormat, BOOL Windowed)
{
    return E_NOTIMPL;
}

HRESULT CDirect3D9::CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, _Inout_ D3DPRESENT_PARAMETERS* pPresentationParameters, _Outptr_ struct IDirect3DDevice9** ppReturnedDeviceInterface)
{
    return E_NOTIMPL;
}

HRESULT CDirect3D9::EnumAdapterModes(UINT Adapter, D3DFORMAT Format, UINT Mode, _Out_ D3DDISPLAYMODE* pMode)
{
    return E_NOTIMPL;
}

UINT CDirect3D9::GetAdapterCount()
{
    return 0;
}

HRESULT CDirect3D9::GetAdapterDisplayMode(UINT Adapter, _Out_ D3DDISPLAYMODE* pMode)
{
    return E_NOTIMPL;
}

HRESULT CDirect3D9::GetAdapterIdentifier(UINT Adapter, DWORD Flags, _Out_ D3DADAPTER_IDENTIFIER9* pIdentifier)
{
    return E_NOTIMPL;
}

UINT CDirect3D9::GetAdapterModeCount(UINT Adapter, D3DFORMAT Format)
{
    return E_NOTIMPL;
}

HMONITOR CDirect3D9::GetAdapterMonitor(UINT Adapter)
{
    return nullptr;
}

HRESULT CDirect3D9::GetDeviceCaps(UINT Adapter, D3DDEVTYPE DeviceType, _Out_ D3DCAPS9* pCaps)
{
    return E_NOTIMPL;
}

HRESULT CDirect3D9::RegisterSoftwareDevice(void* pInitializeFunction)
{
    return E_NOTIMPL;
}

