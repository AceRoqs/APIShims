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
    IFACEMETHOD(QueryInterface)(REFIID riid, _Outptr_ void** object) override;

    // IDirect3D9.
    IFACEMETHOD(CheckDepthStencilMatch)(UINT adapter, D3DDEVTYPE device_type, D3DFORMAT adapter_format, D3DFORMAT render_target_format, D3DFORMAT depth_stencil_format) override;
    IFACEMETHOD(CheckDeviceFormat)(UINT adapter, D3DDEVTYPE device_type, D3DFORMAT adapter_format, DWORD usage, D3DRESOURCETYPE resource_type, D3DFORMAT check_format) override;
    IFACEMETHOD(CheckDeviceFormatConversion)(UINT adapter, D3DDEVTYPE device_type, D3DFORMAT source_format, D3DFORMAT target_format) override;
    IFACEMETHOD(CheckDeviceMultiSampleType)(UINT adapter, D3DDEVTYPE device_type, D3DFORMAT surface_format, BOOL windowed, D3DMULTISAMPLE_TYPE multisample_type, _Out_ DWORD* quality_levels) override;
    IFACEMETHOD(CheckDeviceType)(UINT adapter, D3DDEVTYPE device_type, D3DFORMAT display_format, D3DFORMAT back_buffer_format, BOOL windowed) override;
    IFACEMETHOD(CreateDevice)(UINT adapter, D3DDEVTYPE device_type, HWND focus_window, DWORD behavior_flags, _Inout_ D3DPRESENT_PARAMETERS* presentation_parameters, _Outptr_ struct IDirect3DDevice9** device_interface) override;
    IFACEMETHOD(EnumAdapterModes)(UINT adapter, D3DFORMAT format, UINT index, _Out_ D3DDISPLAYMODE* mode) override;
    IFACEMETHOD_(UINT, GetAdapterCount)() override;
    IFACEMETHOD(GetAdapterDisplayMode)(UINT adapter, _Out_ D3DDISPLAYMODE* mode) override;
    IFACEMETHOD(GetAdapterIdentifier)(UINT adapter, DWORD flags, _Out_ D3DADAPTER_IDENTIFIER9* identifier) override;
    IFACEMETHOD_(UINT, GetAdapterModeCount)(UINT adapter, D3DFORMAT format) override;
    IFACEMETHOD_(HMONITOR, GetAdapterMonitor)(UINT adapter) override;
    IFACEMETHOD(GetDeviceCaps)(UINT adapter, D3DDEVTYPE device_type, _Out_ D3DCAPS9* caps) override;
    IFACEMETHOD(RegisterSoftwareDevice)(void* initialize_function) override;

    // IDirect3D9Ex.
    IFACEMETHOD(CreateDeviceEx)(UINT adapter, D3DDEVTYPE device_type, _In_opt_ HWND focus_window, DWORD behavior_flags, _Inout_ D3DPRESENT_PARAMETERS* presentation_parameters,
        _Out_ struct D3DDISPLAYMODEEX* full_screen_display_mode, _Outptr_ struct IDirect3DDevice9Ex** device_interface) override;
    IFACEMETHOD(EnumAdapterModesEx)(UINT adapter, _In_ const struct D3DDISPLAYMODEFILTER* filter, UINT index, _Out_ D3DDISPLAYMODEEX* mode) override;
    IFACEMETHOD(GetAdapterDisplayModeEx)(UINT adapter, _Out_opt_ D3DDISPLAYMODEEX* mode, _Out_opt_ enum D3DDISPLAYROTATION* rotation) override;
    IFACEMETHOD(GetAdapterLUID)(UINT adapter, _Out_ LUID* luid) override;
    IFACEMETHOD(GetAdapterModeCountEx)(UINT adapter, _In_ const D3DDISPLAYMODEFILTER* filter) override;

private:
    ULONG m_references;
};

struct IDirect3D9* WINAPI Direct3DCreate9(_In_ UINT SDK_version)
{
    return new(std::nothrow) Direct3D9();
}

HRESULT WINAPI Direct3DCreate9Ex(UINT SDK_version, _Outptr_ struct IDirect3D9Ex** direct3D)
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

IFACEMETHODIMP Direct3D9::QueryInterface(REFIID riid, _Outptr_ void** object)
{
    HRESULT hr;

    if(object == nullptr)
    {
        hr = E_POINTER;
    }
    else if((riid == IID_IUnknown) || (riid == IID_IDirect3D9) || (riid == IID_IDirect3D9Ex))
    {
        AddRef();
        IDirect3D9Ex* out_pointer = this;
        *object = out_pointer;
        hr = S_OK;
    }
    else
    {
        hr = E_NOINTERFACE;
    }

    return hr;
}

IFACEMETHODIMP Direct3D9::CheckDepthStencilMatch(UINT adapter, D3DDEVTYPE device_type, D3DFORMAT adapter_format, D3DFORMAT render_target_format, D3DFORMAT depth_stencil_format)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP Direct3D9::CheckDeviceFormat(UINT adapter, D3DDEVTYPE device_type, D3DFORMAT adapter_format, DWORD usage, D3DRESOURCETYPE resource_type, D3DFORMAT check_format)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP Direct3D9::CheckDeviceFormatConversion(UINT adapter, D3DDEVTYPE device_type, D3DFORMAT source_format, D3DFORMAT target_format)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP Direct3D9::CheckDeviceMultiSampleType(UINT adapter, D3DDEVTYPE device_type, D3DFORMAT surface_format, BOOL windowed, D3DMULTISAMPLE_TYPE multisample_type, _Out_ DWORD* quality_levels)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP Direct3D9::CheckDeviceType(UINT adapter, D3DDEVTYPE device_type, D3DFORMAT display_format, D3DFORMAT back_buffer_format, BOOL windowed)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP Direct3D9::CreateDevice(UINT adapter, D3DDEVTYPE device_type, HWND focus_window, DWORD behavior_flags, _Inout_ D3DPRESENT_PARAMETERS* presentation_parameters, _Outptr_ struct IDirect3DDevice9** device_interface)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP Direct3D9::EnumAdapterModes(UINT adapter, D3DFORMAT format, UINT index, _Out_ D3DDISPLAYMODE* mode)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP_(UINT) Direct3D9::GetAdapterCount()
{
    return 0;
}

IFACEMETHODIMP Direct3D9::GetAdapterDisplayMode(UINT adapter, _Out_ D3DDISPLAYMODE* mode)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP Direct3D9::GetAdapterIdentifier(UINT adapter, DWORD flags, _Out_ D3DADAPTER_IDENTIFIER9* identifier)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP_(UINT) Direct3D9::GetAdapterModeCount(UINT adapter, D3DFORMAT format)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP_(HMONITOR) Direct3D9::GetAdapterMonitor(UINT adapter)
{
    return nullptr;
}

IFACEMETHODIMP Direct3D9::GetDeviceCaps(UINT adapter, D3DDEVTYPE device_type, _Out_ D3DCAPS9* caps)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP Direct3D9::RegisterSoftwareDevice(void* initialize_function)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP Direct3D9::CreateDeviceEx(UINT adapter, D3DDEVTYPE device_type, _In_opt_ HWND focus_window, DWORD behavior_flags, _Inout_ D3DPRESENT_PARAMETERS* presentation_parameters,
    _Out_ struct D3DDISPLAYMODEEX* full_screen_display_mode, _Outptr_ struct IDirect3DDevice9Ex** device_interface)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP Direct3D9::EnumAdapterModesEx(UINT adapter, _In_ const struct D3DDISPLAYMODEFILTER* filter, UINT index, _Out_ D3DDISPLAYMODEEX* mode)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP Direct3D9::GetAdapterDisplayModeEx(UINT adapter, _Out_opt_ D3DDISPLAYMODEEX* mode, _Out_opt_ enum D3DDISPLAYROTATION* rotation)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP Direct3D9::GetAdapterLUID(UINT adapter, _Out_ LUID* luid)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP Direct3D9::GetAdapterModeCountEx(UINT adapter, _In_ const D3DDISPLAYMODEFILTER* filter)
{
    return E_NOTIMPL;
}

