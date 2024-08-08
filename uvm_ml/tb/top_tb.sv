`timescale 1ns/1ps
`include "uvm_macros.svh"

import uvm_pkg::*;
import uvm_ml::*;
`include "my_if.sv"
`include "my_transaction.sv"
`include "my_sequencer.sv"
`include "my_driver.sv"
`include "my_monitor.sv"
`include "my_agent.sv"
`include "my_model.sv"
`include "my_scoreboard.sv"
`include "my_env.sv"
`include "base_test.sv"
`include "my_case0.sv"

module top_tb;

reg clk;
reg rst_n;

   my_if if_inst(clk, rst_n);

   VIP_RGB888_YCbCr444 dut(
      .clk            (clk            ),
      .rst_n          (rst_n          ),
      .per_img_vsync  (if_inst.vsync_vld_i),
      .per_img_href   (if_inst.href_vld_i ),
      .per_img_red    (if_inst.R_dat_i    ),
      .per_img_green  (if_inst.G_dat_i    ),
      .per_img_blue   (if_inst.B_dat_i    ),
      .post_img_vsync (if_inst.vsync_vld_o),
      .post_img_href  (if_inst.href_vld_o ),
      .post_img_Y     (if_inst.Y_dat_o    ),
      .post_img_Cb    (if_inst.Cb_dat_o   ),
      .post_img_Cr    (if_inst.Cr_dat_o   )
   );


initial begin
   clk = 0;
   forever begin
      #100 clk = ~clk;
   end
end

initial begin
   rst_n = 1'b0;
   #1000;
   rst_n = 1'b1;
end

initial begin
   string tops[1];
   string uvm_testname = "";
   if(!$value$plusargs("UVM_TESTNAME=%0s",uvm_testname)) 
      `uvm_fatal("top_tb",$psprintf("+uvm_testname is not provided"))
   tops[0] = "";
   #0;
   uvm_ml_run_test(tops,{"SV:",uvm_testname});
end

initial begin
   uvm_config_db#(virtual my_if)::set(null, "uvm_test_top.env.agt.drv", "vif", if_inst);
   uvm_config_db#(virtual my_if)::set(null, "uvm_test_top.env.agt.mon", "vif", if_inst);
end

initial begin
   $timeformat(-9,2,"ns",14);
   $fsdbDumpfile("top_tb.fsdb");
   $fsdbDumpvars;
end

endmodule
