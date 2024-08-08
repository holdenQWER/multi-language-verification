#ifndef RTW_HEADER_RGB888_to_YCbCr444_dpi_h_
#define RTW_HEADER_RGB888_to_YCbCr444_dpi_h_

#ifdef __cplusplus
#define DPI_LINK_DECL extern "C"
#else
#define DPI_LINK_DECL
#endif

#ifndef DPI_DLL_EXPORT
#ifdef _MSC_VER
#define DPI_DLL_EXPORT __declspec(dllexport)
#else
#define DPI_DLL_EXPORT 
#endif
#endif

#include <svdpi.h>

typedef struct{
   uint32_t height;
   uint32_t width;
} cfg_struct;

DPI_LINK_DECL
DPI_DLL_EXPORT void * DPI_RGB888_to_YCbCr444_initialize(void* existhandle);
DPI_LINK_DECL
DPI_DLL_EXPORT void DPI_RGB888_to_YCbCr444(void* objhandle,
                                           const svOpenArrayHandle array_Y_o,
                                           const svOpenArrayHandle array_Cb_o,
                                           const svOpenArrayHandle array_Cr_o,
                                           const svOpenArrayHandle array_R_i,
                                           const svOpenArrayHandle array_G_i,
                                           const svOpenArrayHandle array_B_i,
                                           const cfg_struct *cfg_s
                                          );
DPI_LINK_DECL
DPI_DLL_EXPORT void DPI_RGB888_to_YCbCr444_terminate(void* existhandle);
#endif
