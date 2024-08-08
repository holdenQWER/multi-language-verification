`ifndef MY_TRANSACTION__SV
`define MY_TRANSACTION__SV

typedef struct {
   rand int unsigned frame_height;
   rand int unsigned frame_width;
} my_ctrl_s;

class my_transaction extends uvm_sequence_item;

   rand int unsigned dat1[];
   rand int unsigned dat2[];
   rand int unsigned dat3[];
   rand my_ctrl_s my_ctrl_struct;

   constraint my_transaction_c {
      my_ctrl_struct.frame_width inside {[200:300]};
      my_ctrl_struct.frame_height inside {[100:200]};
      dat1.size == my_ctrl_struct.frame_width*my_ctrl_struct.frame_height;
      dat2.size == my_ctrl_struct.frame_width*my_ctrl_struct.frame_height;
      dat3.size == my_ctrl_struct.frame_width*my_ctrl_struct.frame_height;
      foreach(dat1[i]){
         dat1[i] inside {[0:8'hFF]};
         dat2[i] inside {[0:8'hFF]};
         dat3[i] inside {[0:8'hFF]};
      }
   }

   `uvm_object_utils_begin(my_transaction)
      `uvm_field_int (my_ctrl_struct.frame_height,UVM_ALL_ON | UVM_NOCOMPARE)
      `uvm_field_int (my_ctrl_struct.frame_width,UVM_ALL_ON | UVM_NOCOMPARE)
      `uvm_field_array_int (dat1,UVM_ALL_ON)
      `uvm_field_array_int (dat2,UVM_ALL_ON)
      `uvm_field_array_int (dat3,UVM_ALL_ON)
   `uvm_object_utils_end

   function new(string name = "my_transaction");
      super.new();
   endfunction

endclass
`endif
