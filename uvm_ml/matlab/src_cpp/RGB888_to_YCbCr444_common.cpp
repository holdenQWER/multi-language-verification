#include "RGB888_to_YCbCr444_common.h"
#include "mclmcr.h"
#include "mclcppclass.h"
#include "vcsuser.h"
using namespace std;

//============================================================================================
// init_RGB888_to_YCbCr444
//============================================================================================
void init_RGB888_to_YCbCr444() {
   bool isok = 0;
   isok = libRGB888_to_YCbCr444Initialize();
   if(isok) {
      io_printf("[matlab_model] matlab lib initialize successful\n");
   }
   else {
      io_printf("[matlab_model] matlab lib initialize failed\n");
   }
}

//============================================================================================
// term_RGB888_to_YCbCr444
//============================================================================================
void term_RGB888_to_YCbCr444() {
   libRGB888_to_YCbCr444Terminate();
}

//============================================================================================
// RGB888_to_YCbCr444_main_process
//============================================================================================
void RGB888_to_YCbCr444_main_process(
                                     uint32_t* u_array_Y_o,
                                     uint32_t* u_array_Cb_o,
                                     uint32_t* u_array_Cr_o,
                                     const uint32_t* u_array_R_i,
                                     const uint32_t* u_array_G_i,
                                     const uint32_t* u_array_B_i,
                                     const cfg_struct *cfg_s
                                    ) {



   io_printf("[matlab_model] height:%d,width:%d\n",cfg_s->height,cfg_s->width);
   uint32_t u_cfg_s_height[1] = {cfg_s->height};
   uint32_t u_cfg_s_width[1] = {cfg_s->width};

   //********************************************************************************
   //**************************declare mwArray***************************************
   //********************************************************************************
   mwArray m_array_Y_o (cfg_s->height,cfg_s->width,mxUINT32_CLASS);
   mwArray m_array_Cb_o (cfg_s->height,cfg_s->width,mxUINT32_CLASS);
   mwArray m_array_Cr_o (cfg_s->height,cfg_s->width,mxUINT32_CLASS);
   mwArray m_array_R_i (cfg_s->height,cfg_s->width,mxUINT32_CLASS);
   mwArray m_array_G_i (cfg_s->height,cfg_s->width,mxUINT32_CLASS);
   mwArray m_array_B_i (cfg_s->height,cfg_s->width,mxUINT32_CLASS);
   mwArray m_cfg_s_height (1,1,mxUINT32_CLASS);
   mwArray m_cfg_s_width (1,1,mxUINT32_CLASS);

   //********************************************************************************
   //**************************set data**********************************************
   //********************************************************************************
   m_array_R_i.SetData (u_array_R_i,cfg_s->height*cfg_s->width);
   m_array_G_i.SetData (u_array_G_i,cfg_s->height*cfg_s->width);
   m_array_B_i.SetData (u_array_B_i,cfg_s->height*cfg_s->width);

   m_cfg_s_height.SetData (u_cfg_s_height,1);
   m_cfg_s_width.SetData  (u_cfg_s_width,1);

   //********************************************************************************
   //**************************struct type*******************************************
   //********************************************************************************
   const int nfield_cfg_s=2;
   const char *fieldnames_cfg_s[nfield_cfg_s]= {"height","width"};
   mwArray m_cfg_s(1,1,nfield_cfg_s,fieldnames_cfg_s);
   m_cfg_s(fieldnames_cfg_s[0],1,1) = m_cfg_s_height;
   m_cfg_s(fieldnames_cfg_s[1],1,1) = m_cfg_s_width;

   //********************************************************************************
   //**************************matlab_call*******************************************
   //********************************************************************************
   io_printf("[matlab_model] before call RGB888_to_YCbCr444\n");
   RGB888_to_YCbCr444(
          3,//number of matlab output
          m_array_Y_o,
          m_array_Cb_o,
          m_array_Cr_o,
          m_array_R_i,
          m_array_G_i,
          m_array_B_i,
          m_cfg_s
         );
   io_printf("[matlab_model] after call RGB888_to_YCbCr444\n");
   //add_common_get_data
   m_array_Y_o.GetData  (u_array_Y_o,cfg_s->height*cfg_s->width);
   m_array_Cb_o.GetData (u_array_Cb_o,cfg_s->height*cfg_s->width);
   m_array_Cr_o.GetData (u_array_Cr_o,cfg_s->height*cfg_s->width);
}











