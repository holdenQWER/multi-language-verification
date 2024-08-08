#include "RGB888_to_YCbCr444_dpi.h"
#include "RGB888_to_YCbCr444_common.h"
using namespace std;

//=============================================================================================
// DPI_RGB888_to_YCbCr444_initialize
//=============================================================================================
DPI_DLL_EXPORT void * DPI_RGB888_to_YCbCr444_initialize(void* existhandle) {

   init_RGB888_to_YCbCr444();
   existhandle = NULL;
   return NULL;

}

//=============================================================================================
// DPI_RGB888_to_YCbCr444_terminate
//=============================================================================================
DPI_DLL_EXPORT void DPI_RGB888_to_YCbCr444_terminate(void* existhandle) {

   existhandle = NULL;
   term_RGB888_to_YCbCr444();

}

//=============================================================================================
// DPI_RGB888_to_YCbCr444
//=============================================================================================
DPI_DLL_EXPORT void DPI_RGB888_to_YCbCr444(void* objhandle,
                                           const svOpenArrayHandle array_Y_o,
                                           const svOpenArrayHandle array_Cb_o,
                                           const svOpenArrayHandle array_Cr_o,
                                           const svOpenArrayHandle array_R_i,
                                           const svOpenArrayHandle array_G_i,
                                           const svOpenArrayHandle array_B_i,
                                           const cfg_struct *cfg_s
                                          ) {
   uint32_t *u_array_Y_o;
   uint32_t *u_array_Cb_o;
   uint32_t *u_array_Cr_o;
   uint32_t *u_array_R_i;
   uint32_t *u_array_G_i;
   uint32_t *u_array_B_i;
   u_array_Y_o  = (uint32_t *) svGetArrayPtr(array_Y_o);
   u_array_Cb_o = (uint32_t *) svGetArrayPtr(array_Cb_o);
   u_array_Cr_o = (uint32_t *) svGetArrayPtr(array_Cr_o);
   u_array_R_i  = (uint32_t *) svGetArrayPtr(array_R_i);
   u_array_G_i  = (uint32_t *) svGetArrayPtr(array_G_i);
   u_array_B_i  = (uint32_t *) svGetArrayPtr(array_B_i);

   RGB888_to_YCbCr444_main_process(
             u_array_Y_o,
             u_array_Cb_o,
             u_array_Cr_o,
             u_array_R_i,
             u_array_G_i,
             u_array_B_i,
             cfg_s
         );

   objhandle = NULL;

}

















