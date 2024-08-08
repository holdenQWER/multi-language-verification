`ifndef MY_DRIVER__SV
`define MY_DRIVER__SV
class my_driver extends uvm_driver#(my_transaction);

   virtual my_if vif;

   uvm_analysis_port #(my_transaction)  ap;

   `uvm_component_utils(my_driver)
   function new(string name = "my_driver", uvm_component parent = null);
      super.new(name, parent);
   endfunction

   virtual function void build_phase(uvm_phase phase);
      super.build_phase(phase);
      if(!uvm_config_db#(virtual my_if)::get(this, "", "vif", vif))
         `uvm_fatal("my_driver", "virtual interface must be set for vif!!!")
      ap = new("ap", this);
   endfunction

   extern task main_phase(uvm_phase phase);
   extern task drive_one_frame(my_transaction tr);
endclass

task my_driver::main_phase(uvm_phase phase);
   my_transaction tr;

   vif.vsync_vld_i <= 1'b0;
   vif.href_vld_i <= 1'b0;
   while(!vif.rst_n)
      @(posedge vif.clk);
   while(1) begin
      seq_item_port.get_next_item(req);
      $cast(tr,req.clone());
      ap.write(tr);
      uvm_config_db#(my_ctrl_s)::set(null, "", "my_cfg", req.my_ctrl_struct);
      drive_one_frame(req);
      seq_item_port.item_done();
   end
endtask

task my_driver::drive_one_frame(my_transaction tr);
   repeat(5) @(posedge vif.clk);
   vif.vsync_vld_i <= 1'b1;
   `uvm_info("my_driver", "begin to drive one frame", UVM_LOW);
   for(int row_cnt = 0; row_cnt < tr.my_ctrl_struct.frame_height; row_cnt++) begin
      for(int col_cnt = 0; col_cnt < tr.my_ctrl_struct.frame_width; col_cnt++) begin
         @(posedge vif.clk);
         vif.href_vld_i  <= 1'b1;
         vif.R_dat_i <= tr.dat1[row_cnt*tr.my_ctrl_struct.frame_width+col_cnt];
         vif.G_dat_i <= tr.dat2[row_cnt*tr.my_ctrl_struct.frame_width+col_cnt];
         vif.B_dat_i <= tr.dat3[row_cnt*tr.my_ctrl_struct.frame_width+col_cnt];
      end
      @(posedge vif.clk);
      vif.href_vld_i  <= 1'b0;
   end
   @(posedge vif.clk);
   vif.vsync_vld_i <= 1'b0;
   `uvm_info("my_driver", "end drive one frame", UVM_LOW);
endtask


`endif
