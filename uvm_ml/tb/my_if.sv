`ifndef MY_IF__SV
`define MY_IF__SV

interface my_if(input clk, input rst_n);

   logic vsync_vld_i;
   logic href_vld_i;
   logic [7:0] R_dat_i;
   logic [7:0] G_dat_i;
   logic [7:0] B_dat_i;
   
   logic vsync_vld_o;
   logic href_vld_o;
   logic [7:0] Y_dat_o;
   logic [7:0] Cb_dat_o;
   logic [7:0] Cr_dat_o;

endinterface

`endif
