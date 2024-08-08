#ifndef RGB888_to_YCbCr444_common_h_
#define RGB888_to_YCbCr444_common_h_
#include "libRGB888_to_YCbCr444.h"

typedef struct{
   uint32_t height;
   uint32_t width;
} cfg_struct;

void init_RGB888_to_YCbCr444();

void term_RGB888_to_YCbCr444();

void RGB888_to_YCbCr444_main_process(
       uint32_t* u_array_Y_o,
       uint32_t* u_array_Cb_o,
       uint32_t* u_array_Cr_o,
       const uint32_t* u_array_R_i,
       const uint32_t* u_array_G_i,
       const uint32_t* u_array_B_i,
       const cfg_struct *cfg_s
      );

#endif
