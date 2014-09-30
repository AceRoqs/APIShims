#ifndef IDIRECT3DDEVICE9_H
#define IDIRECT3DDEVICE9_H

#include "ForwardDeclarations.h"

struct IDirect3DDevice9 : public IUnknown
{
    // IUnknown.
    IFACEMETHOD(QueryInterface)(REFIID riid, _Outptr_ void** object) = 0;
    IFACEMETHOD_(ULONG, AddRef)() = 0;
    IFACEMETHOD_(ULONG, Release)() = 0;

    // IDirect3DDevice9.
    IFACEMETHOD(TestCooperativeLevel)() = 0;
    IFACEMETHOD_(UINT, GetAvailableTextureMem)() = 0;
    IFACEMETHOD(EvictManagedResources)() = 0;
    IFACEMETHOD(GetDirect3D)(_Outptr_ IDirect3D9** direct3D) = 0;
    IFACEMETHOD(GetDeviceCaps)(_Out_ D3DCAPS9* caps) = 0;
    IFACEMETHOD(GetDisplayMode)(UINT swap_chain, _Out_ D3DDISPLAYMODE* mode) = 0;
    IFACEMETHOD(GetCreationParameters)(_Out_ D3DDEVICE_CREATION_PARAMETERS* parameters) = 0;
    IFACEMETHOD(SetCursorProperties)(UINT x_hot_spot, UINT y_hot_spot, _In_ IDirect3DSurface9* cursor_bitmap) = 0;
    IFACEMETHOD_(void, SetCursorPosition)(int x, int y, DWORD flags) = 0;
    IFACEMETHOD_(BOOL, ShowCursor)(BOOL show) = 0;
    IFACEMETHOD(CreateAdditionalSwapChain)(_Inout_ D3DPRESENT_PARAMETERS* presentation_parameters, _Outptr_ IDirect3DSwapChain9** swap_chain) = 0;
    IFACEMETHOD(GetSwapChain)(UINT ordinal, _Outptr_ IDirect3DSwapChain9** swap_chain) = 0;
    IFACEMETHOD_(UINT, GetNumberOfSwapChains)() = 0;
    IFACEMETHOD(Reset)(_Inout_ D3DPRESENT_PARAMETERS* presentation_parameters) = 0;
    IFACEMETHOD(Present)(_In_opt_ const RECT* source_rect, _In_opt_ const RECT* destination_rect, _In_opt_ HWND destination_window_override, _In_opt_ const RGNDATA* dirty_region) = 0;
    IFACEMETHOD(GetBackBuffer)(UINT swap_chain, UINT index, D3DBACKBUFFER_TYPE type, _Outptr_ IDirect3DSurface9** surface) = 0;
    IFACEMETHOD(GetRasterStatus)(UINT swap_chain, _Out_ D3DRASTER_STATUS* raster_status) = 0;
    IFACEMETHOD(SetDialogBoxMode)(BOOL enable_dialogs) = 0;
    IFACEMETHOD_(void, SetGammaRamp)(UINT swap_chain, DWORD flags, _In_ const D3DGAMMARAMP* ramp) = 0;
    IFACEMETHOD_(void, GetGammaRamp)(UINT swap_chain, _Out_ D3DGAMMARAMP* ramp) = 0;
    IFACEMETHOD(CreateTexture)(UINT width, UINT height, UINT levels, DWORD usage, D3DFORMAT format, D3DPOOL pool, _Outptr_ IDirect3DTexture9** texture, _In_opt_ HANDLE* shared_handle) = 0;
    IFACEMETHOD(CreateVolumeTexture)(UINT width, UINT height, UINT depth, UINT levels, DWORD usage, D3DFORMAT format, D3DPOOL pool, _Outptr_ IDirect3DVolumeTexture9** volume_texture, _In_opt_ HANDLE* shared_handle) = 0;
    IFACEMETHOD(CreateCubeTexture)(UINT edge_length, UINT levels, DWORD usage, D3DFORMAT format, D3DPOOL pool, _Outptr_ IDirect3DCubeTexture9** cube_texture, _In_opt_ HANDLE* shared_handle) = 0;
    IFACEMETHOD(CreateVertexBuffer)(UINT length, DWORD usage, DWORD flexible_vertex_format, D3DPOOL pool, _Outptr_ IDirect3DVertexBuffer9** vertex_buffer, _In_opt_ HANDLE* shared_handle) = 0;
    IFACEMETHOD(CreateIndexBuffer)(UINT length, DWORD usage, D3DFORMAT format, D3DPOOL pool, _Outptr_ IDirect3DIndexBuffer9** index_buffer, _In_opt_ HANDLE* shared_handle) = 0;
    IFACEMETHOD(CreateRenderTarget)(UINT width, UINT height, D3DFORMAT format, D3DMULTISAMPLE_TYPE multisample, DWORD multisample_quality, BOOL lockable, _Outptr_ IDirect3DSurface9** surface, _In_opt_ HANDLE* shared_handle) = 0;
    IFACEMETHOD(CreateDepthStencilSurface)(UINT width, UINT height, D3DFORMAT format, D3DMULTISAMPLE_TYPE multisample, DWORD multisample_quality, BOOL discard, _Outptr_ IDirect3DSurface9** surface, _In_opt_ HANDLE* shared_handle) = 0;
    IFACEMETHOD(UpdateSurface)(_In_ IDirect3DSurface9* source_surface, _In_opt_ const RECT* source_rect, _In_ IDirect3DSurface9* destination_surface, _In_opt_ const POINT* destination_point) = 0;
    IFACEMETHOD(UpdateTexture)(_In_ IDirect3DBaseTexture9* source_texture, _In_ IDirect3DBaseTexture9* destination_texture) = 0;
    IFACEMETHOD(GetRenderTargetData)(_In_ IDirect3DSurface9* render_target, _In_ IDirect3DSurface9* destination_surface) = 0;
    IFACEMETHOD(GetFrontBufferData)(UINT swap_chain, _In_ IDirect3DSurface9* destination_surface) = 0;
    IFACEMETHOD(StretchRect)(_In_ IDirect3DSurface9* source_surface, _In_opt_ const RECT* source_rect, _In_ IDirect3DSurface9* destination_surface, _In_opt_ const RECT* destination_rect, D3DTEXTUREFILTERTYPE filter) = 0;
    IFACEMETHOD(ColorFill)(_In_ IDirect3DSurface9* surface, _In_opt_ const RECT* rect, D3DCOLOR color) = 0;
    IFACEMETHOD(CreateOffscreenPlainSurface)(UINT width, UINT height, D3DFORMAT format, D3DPOOL pool, _Outptr_ IDirect3DSurface9** surface, _In_opt_ HANDLE* shared_handle) = 0;
    IFACEMETHOD(SetRenderTarget)(DWORD render_target_index, _In_ IDirect3DSurface9* render_target) = 0;
    IFACEMETHOD(GetRenderTarget)(DWORD render_target_index, _Outptr_ IDirect3DSurface9** render_target) = 0;
    IFACEMETHOD(SetDepthStencilSurface)(_In_ IDirect3DSurface9* zstencil_surface) = 0;
    IFACEMETHOD(GetDepthStencilSurface)(_Outptr_ IDirect3DSurface9** zstencil_surface) = 0;
    IFACEMETHOD(BeginScene)() = 0;
    IFACEMETHOD(EndScene)() = 0;
    IFACEMETHOD(Clear)(DWORD count, _In_opt_ const D3DRECT* rects, DWORD flags, D3DCOLOR color, float z, DWORD stencil) = 0;
    IFACEMETHOD(SetTransform)(D3DTRANSFORMSTATETYPE state, _In_ const D3DMATRIX* matrix) = 0;
    IFACEMETHOD(GetTransform)(D3DTRANSFORMSTATETYPE state, _Out_ D3DMATRIX* matrix) = 0;
    IFACEMETHOD(MultiplyTransform)(D3DTRANSFORMSTATETYPE state, _In_ const D3DMATRIX* matrix) = 0;
    IFACEMETHOD(SetViewport)(_In_ const D3DVIEWPORT9* viewport) = 0;
    IFACEMETHOD(GetViewport)(_Out_ D3DVIEWPORT9* viewport) = 0;
    IFACEMETHOD(SetMaterial)(_In_ const D3DMATERIAL9* material) = 0;
    IFACEMETHOD(GetMaterial)(_Out_ D3DMATERIAL9* material) = 0;
    IFACEMETHOD(SetLight)(DWORD index, _In_ const D3DLIGHT9* light) = 0;
    IFACEMETHOD(GetLight)(DWORD index, _Out_ D3DLIGHT9* light) = 0;
    IFACEMETHOD(LightEnable)(DWORD index, BOOL enable) = 0;
    IFACEMETHOD(GetLightEnable)(DWORD index, _Out_ BOOL* enable) = 0;
    IFACEMETHOD(SetClipPlane)(DWORD index, _In_reads_(4) const float* plane) = 0;
    IFACEMETHOD(GetClipPlane)(DWORD index, _Out_writes_(4) float* plane) = 0;
    IFACEMETHOD(SetRenderState)(D3DRENDERSTATETYPE state, DWORD value) = 0;
    IFACEMETHOD(GetRenderState)(D3DRENDERSTATETYPE state, _Out_ DWORD* value) = 0;
    IFACEMETHOD(CreateStateBlock)(D3DSTATEBLOCKTYPE type, _Outptr_ IDirect3DStateBlock9** state_block) = 0;
    IFACEMETHOD(BeginStateBlock)() = 0;
    IFACEMETHOD(EndStateBlock)(_Outptr_ IDirect3DStateBlock9** state_block) = 0;
    IFACEMETHOD(SetClipStatus)(_In_ const D3DCLIPSTATUS9* clip_status) = 0;
    IFACEMETHOD(GetClipStatus)(_Out_ D3DCLIPSTATUS9* clip_status) = 0;
    IFACEMETHOD(GetTexture)(DWORD stage, _Outptr_ IDirect3DBaseTexture9** texture) = 0;
    IFACEMETHOD(SetTexture)(DWORD stage, _In_ IDirect3DBaseTexture9* texture) = 0;
    IFACEMETHOD(GetTextureStageState)(DWORD stage, D3DTEXTURESTAGESTATETYPE type, _Out_ DWORD* value) = 0;
    IFACEMETHOD(SetTextureStageState)(DWORD stage, D3DTEXTURESTAGESTATETYPE type, DWORD value) = 0;
    IFACEMETHOD(GetSamplerState)(DWORD sampler, D3DSAMPLERSTATETYPE type, _Out_ DWORD* value) = 0;
    IFACEMETHOD(SetSamplerState)(DWORD sampler, D3DSAMPLERSTATETYPE type, DWORD value) = 0;
    IFACEMETHOD(ValidateDevice)(_Out_ DWORD* passes_required) = 0;
    IFACEMETHOD(SetPaletteEntries)(UINT palette_number, _In_ const PALETTEENTRY* entries) = 0;
    IFACEMETHOD(GetPaletteEntries)(UINT palette_number, _Out_ PALETTEENTRY* entries) = 0;
    IFACEMETHOD(SetCurrentTexturePalette)(UINT palette_number) = 0;
    IFACEMETHOD(GetCurrentTexturePalette)(_Out_ UINT* palette_number) = 0;
    IFACEMETHOD(SetScissorRect)(_In_ const RECT* rect) = 0;
    IFACEMETHOD(GetScissorRect)(_Out_ RECT* rect) = 0;
    IFACEMETHOD(SetSoftwareVertexProcessing)(BOOL software) = 0;
    IFACEMETHOD_(BOOL, GetSoftwareVertexProcessing)() = 0;
    IFACEMETHOD(SetNPatchMode)(float segments) = 0;
    IFACEMETHOD_(float, GetNPatchMode)() = 0;
    IFACEMETHOD(DrawPrimitive)(D3DPRIMITIVETYPE primitive_type, UINT start_vertex, UINT primitive_count) = 0;
    IFACEMETHOD(DrawIndexedPrimitive)(D3DPRIMITIVETYPE primitive_type, INT base_vertex_index, UINT min_index, UINT num_vertices, UINT start_index, UINT primitive_count) = 0;
    IFACEMETHOD(DrawPrimitiveUP)(D3DPRIMITIVETYPE primitive_type, UINT primitive_count, _In_ const void* vertex_stream_zero_data, UINT vertex_stream_zero_stride) = 0;
    IFACEMETHOD(DrawIndexedPrimitiveUP)(D3DPRIMITIVETYPE primitive_type, UINT min_index, UINT num_vertices, UINT primitive_count, _In_ const void* index_data, D3DFORMAT index_data_format, _In_ const void* vertex_stream_zero_data, UINT vertex_stream_zero_stride) = 0;
    IFACEMETHOD(ProcessVertices)(UINT source_start_index, UINT destination_index, UINT vertex_count, _In_ IDirect3DVertexBuffer9* destination_buffer, _In_ IDirect3DVertexDeclaration9* vertex_declaration, DWORD flags) = 0;
    IFACEMETHOD(CreateVertexDeclaration)(_In_ const D3DVERTEXELEMENT9* vertex_elements, _Outptr_ IDirect3DVertexDeclaration9** vertex_declaration) = 0;
    IFACEMETHOD(SetVertexDeclaration)(_In_ IDirect3DVertexDeclaration9* vertex_declaration) = 0;
    IFACEMETHOD(GetVertexDeclaration)(_Outptr_ IDirect3DVertexDeclaration9** vertex_declaration) = 0;
    IFACEMETHOD(SetFVF)(DWORD flexible_vertex_format) = 0;
    IFACEMETHOD(GetFVF)(_Out_ DWORD* flexible_vertex_format) = 0;
    IFACEMETHOD(CreateVertexShader)(_In_ const DWORD* function, _Outptr_ IDirect3DVertexShader9** shader) = 0;
    IFACEMETHOD(SetVertexShader)(_In_ IDirect3DVertexShader9* shader) = 0;
    IFACEMETHOD(GetVertexShader)(_Outptr_ IDirect3DVertexShader9** shader) = 0;
    IFACEMETHOD(SetVertexShaderConstantF)(UINT start_register, _In_reads_(vector4_count * 4) const float* constant_data, UINT vector4_count) = 0;
    IFACEMETHOD(GetVertexShaderConstantF)(UINT start_register, _Out_writes_(vector4_count * 4) float* constant_data, UINT vector4_count) = 0;
    IFACEMETHOD(SetVertexShaderConstantI)(UINT start_register, _In_reads_(vector4_count * 4) const int* constant_data, UINT vector4_count) = 0;
    IFACEMETHOD(GetVertexShaderConstantI)(UINT start_register, _Out_writes_(vector4_count * 4) int* constant_data, UINT vector4_count) = 0;
    IFACEMETHOD(SetVertexShaderConstantB)(UINT start_register, _In_reads_(bool_count) const BOOL* constant_data, UINT bool_count) = 0;
    IFACEMETHOD(GetVertexShaderConstantB)(UINT start_register, _Out_writes_(bool_count) BOOL* constant_data, UINT bool_count) = 0;
    IFACEMETHOD(SetStreamSource)(UINT stream_number, _In_ IDirect3DVertexBuffer9* stream_data, UINT offset_in_bytes, UINT stride) = 0;
    IFACEMETHOD(GetStreamSource)(UINT stream_number, _Outptr_ IDirect3DVertexBuffer9** stream_data, _Out_ UINT* offset_in_bytes, _Out_ UINT* stride) = 0;
    IFACEMETHOD(SetStreamSourceFreq)(UINT stream_number, UINT setting) = 0;
    IFACEMETHOD(GetStreamSourceFreq)(UINT stream_number, _Out_ UINT* setting) = 0;
    IFACEMETHOD(SetIndices)(_In_ IDirect3DIndexBuffer9* index_data) = 0;
    IFACEMETHOD(GetIndices)(_Outptr_ IDirect3DIndexBuffer9** index_data) = 0;
    IFACEMETHOD(CreatePixelShader)(_In_ const DWORD* function, _Outptr_ IDirect3DPixelShader9** shader) = 0;
    IFACEMETHOD(SetPixelShader)(_In_ IDirect3DPixelShader9* shader) = 0;
    IFACEMETHOD(GetPixelShader)(_Outptr_ IDirect3DPixelShader9** shader) = 0;
    IFACEMETHOD(SetPixelShaderConstantF)(UINT start_register, _In_reads_(vector4_count * 4) const float* constant_data, UINT vector4_count) = 0;
    IFACEMETHOD(GetPixelShaderConstantF)(UINT start_register, _Out_writes_(vector4_count * 4) float* constant_data, UINT vector4_count) = 0;
    IFACEMETHOD(SetPixelShaderConstantI)(UINT start_register, _In_reads_(vector4_count * 4) const int* constant_data, UINT vector4_count) = 0;
    IFACEMETHOD(GetPixelShaderConstantI)(UINT start_register, _Out_writes_(vector4_count * 4) int* constant_data, UINT vector4_count) = 0;
    IFACEMETHOD(SetPixelShaderConstantB)(UINT start_register, _In_reads_(bool_count) const BOOL* constant_data, UINT bool_count) = 0;
    IFACEMETHOD(GetPixelShaderConstantB)(UINT start_register, _Out_writes_(bool_count) BOOL* constant_data, UINT bool_count) = 0;
    IFACEMETHOD(DrawRectPatch)(UINT handle, _In_reads_(4) const float* segment_count_per_edge, _In_ const D3DRECTPATCH_INFO* rect_patch_info) = 0;
    IFACEMETHOD(DrawTriPatch)(UINT handle, _In_reads_(4) const float* segment_count_per_edge, _In_ const D3DTRIPATCH_INFO* triangle_patch_info) = 0;
    IFACEMETHOD(DeletePatch)(UINT handle) = 0;
    IFACEMETHOD(CreateQuery)(D3DQUERYTYPE type, _Outptr_ IDirect3DQuery9** query) = 0;
};

#endif

