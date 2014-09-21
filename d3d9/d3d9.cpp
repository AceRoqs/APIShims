#include <Windows.h>
#include <new>
#include "IDirect3D9.h"

#include <InitGuid.h>
// Interface IDs.
DEFINE_GUID(IID_IDirect3D9, 0x81bdcbca, 0x64d4, 0x426d, 0xae, 0x8d, 0xad, 0x1, 0x47, 0xf4, 0x27, 0x5c);
DEFINE_GUID(IID_IDirect3D9Ex, 0x02177241, 0x69FC, 0x400C, 0x8F, 0xF1, 0x93, 0xA4, 0x4D, 0xF6, 0x86, 0x1D);

#if 0
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
#endif

class Direct3D9 : public IDirect3D9Ex
{
public:
    Direct3D9();

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

private:
    ULONG m_references;
};

struct IDirect3D9* WINAPI Direct3DCreate9(_In_ UINT SDKVersion)
{
    return new(std::nothrow) Direct3D9();
}

HRESULT WINAPI Direct3DCreate9Ex(UINT SDKVersion, _Outptr_ struct IDirect3D9Ex** ppD3D)
{
    return E_NOTIMPL;
}

Direct3D9::Direct3D9() : m_references(1)
{
}

IFACEMETHODIMP_(ULONG) Direct3D9::AddRef()
{
    return InterlockedIncrement(&m_references);
}

IFACEMETHODIMP_(ULONG) Direct3D9::Release()
{
    ULONG references = InterlockedDecrement(&m_references);
    if(references == 0)
    {
        delete this;
    }
    return references;
}

IFACEMETHODIMP Direct3D9::QueryInterface(REFIID riid, _Outptr_ void** ppvObject)
{
    HRESULT hr;

    if(ppvObject == nullptr)
    {
        hr = E_POINTER;
    }
    else if((riid == IID_IUnknown) || (riid == IID_IDirect3D9) || (riid == IID_IDirect3D9Ex))
    {
        AddRef();
        IDirect3D9Ex* out_pointer = this;
        *ppvObject = out_pointer;
        hr = S_OK;
    }
    else
    {
        hr = E_NOINTERFACE;
    }

    return hr;
}

IFACEMETHODIMP Direct3D9::CheckDepthStencilMatch(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP Direct3D9::CheckDeviceFormat(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP Direct3D9::CheckDeviceFormatConversion(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SourceFormat, D3DFORMAT TargetFormat)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP Direct3D9::CheckDeviceMultiSampleType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType, _Out_ DWORD* pQualityLevels)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP Direct3D9::CheckDeviceType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT DisplayFormat, D3DFORMAT BackBufferFormat, BOOL Windowed)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP Direct3D9::CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, _Inout_ D3DPRESENT_PARAMETERS* pPresentationParameters, _Outptr_ struct IDirect3DDevice9** ppReturnedDeviceInterface)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP Direct3D9::EnumAdapterModes(UINT Adapter, D3DFORMAT Format, UINT Mode, _Out_ D3DDISPLAYMODE* pMode)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP_(UINT) Direct3D9::GetAdapterCount()
{
    return 0;
}

IFACEMETHODIMP Direct3D9::GetAdapterDisplayMode(UINT Adapter, _Out_ D3DDISPLAYMODE* pMode)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP Direct3D9::GetAdapterIdentifier(UINT Adapter, DWORD Flags, _Out_ D3DADAPTER_IDENTIFIER9* pIdentifier)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP_(UINT) Direct3D9::GetAdapterModeCount(UINT Adapter, D3DFORMAT Format)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP_(HMONITOR) Direct3D9::GetAdapterMonitor(UINT Adapter)
{
    return nullptr;
}

IFACEMETHODIMP Direct3D9::GetDeviceCaps(UINT Adapter, D3DDEVTYPE DeviceType, _Out_ D3DCAPS9* pCaps)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP Direct3D9::RegisterSoftwareDevice(void* pInitializeFunction)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP Direct3D9::CreateDeviceEx(UINT Adapter, D3DDEVTYPE DeviceType, _In_opt_ HWND hFocusWindow, DWORD BehaviorFlags, _Inout_ D3DPRESENT_PARAMETERS* pPresentationParameters,
    _Out_ struct D3DDISPLAYMODEEX* pFullscreenDisplayMode, _Outptr_ struct IDirect3DDevice9Ex** ppReturnedDeviceInterface)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP Direct3D9::EnumAdapterModesEx(UINT Adapter, _In_ const struct D3DDISPLAYMODEFILTER* pFilter, UINT Mode, _Out_ D3DDISPLAYMODEEX* pMode)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP Direct3D9::GetAdapterDisplayModeEx(UINT Adapter, _Out_opt_ D3DDISPLAYMODEEX* pMode, _Out_opt_ enum D3DDISPLAYROTATION* pRotation)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP Direct3D9::GetAdapterLUID(UINT Adapter, _Out_ LUID* pLUID)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP Direct3D9::GetAdapterModeCountEx(UINT Adapter, _In_ const D3DDISPLAYMODEFILTER* pFilter)
{
    return E_NOTIMPL;
}

