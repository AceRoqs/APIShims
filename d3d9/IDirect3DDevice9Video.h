#ifndef IDIRECT3DDEVICE9VIDEO_H
#define IDIRECT3DDEVICE9VIDEO_H

#include "ForwardDeclarations.h"

struct IDirect3DDevice9Video : public IUnknown
{
    IFACEMETHOD(GetContentProtectionCaps)(_In_ const GUID* crypto_type, _In_opt_ const GUID* decode_profile, _Out_ D3DCONTENTPROTECTIONCAPS* caps) = 0;
    IFACEMETHOD(CreateAuthenticatedChannel)(D3DAUTHENTICATEDCHANNELTYPE channel_type, _Outptr_ IDirect3DAuthenticatedChannel9** channel, _Out_ HANDLE* channel_handle) = 0;
    IFACEMETHOD(CreateCryptoSession)(_In_ const GUID* crypto_type, _In_opt_ const GUID* decode_profile, _Outptr_ IDirect3DCryptoSession9** crypto_session, _Out_ HANDLE* crypto_handle) = 0;
};

struct IDirect3DAuthenticatedChannel9 : public IUnknown
{
    IFACEMETHOD(GetCertificateSize)(_Out_ UINT* certificate_size) = 0;
    IFACEMETHOD(GetCertificate)(UINT certificate_size, _Out_writes_(certificate_size) BYTE* certificate) = 0;
    IFACEMETHOD(NegotiateKeyExchange)(UINT size, _In_reads_bytes_(size) void* data) = 0;
    IFACEMETHOD(Query)(UINT input_size, _In_reads_bytes_(input_size) const void* input, UINT output_size, _Out_writes_bytes_(output_size) void* output) = 0;
    IFACEMETHOD(Configure)(UINT input_size, _In_reads_bytes_(input_size) const void* input, _Out_ D3DAUTHENTICATEDCHANNEL_CONFIGURE_OUTPUT* output) = 0;
};

struct IDirect3DCryptoSession9 : public IUnknown
{
    IFACEMETHOD(GetCertificateSize)(_Out_ UINT* certificate_size) = 0;
    IFACEMETHOD(GetCertificate)(UINT certificate_size, _Out_writes_(certificate_size) BYTE* certificate) = 0;
    IFACEMETHOD(NegotiateKeyExchange)(UINT size, _In_reads_bytes_(size) void* data) = 0;
    IFACEMETHOD(EncryptionBlt)(_In_ IDirect3DSurface9* source_surface, _In_ IDirect3DSurface9* destination_surface, UINT destination_surface_size, _Out_ void* initialization_vector) = 0;
    IFACEMETHOD(DecryptionBlt)(_In_ IDirect3DSurface9* source_surface, _In_ IDirect3DSurface9* destination_surface, UINT source_surface_size, _In_opt_ D3DENCRYPTED_BLOCK_INFO* encrypted_block_info, _In_ void* content_key, _In_ void* initialization_vector) = 0;
    IFACEMETHOD(GetSurfacePitch)(_In_ IDirect3DSurface9* surface, _Out_ UINT* pitch) = 0;
    IFACEMETHOD(StartSessionKeyRefresh)(_Out_writes_bytes_(random_number_size) void* random_number, UINT random_number_size) = 0;
    IFACEMETHOD(FinishSessionKeyRefresh)() = 0;
    IFACEMETHOD(GetEncryptionBltKey)(_Out_writes_bytes_(key_size) void* key, UINT key_size) = 0;
};

#endif

