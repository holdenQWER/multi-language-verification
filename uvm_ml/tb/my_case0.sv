`ifndef MY_CASE0__SV
`define MY_CASE0__SV
class case0_sequence extends uvm_sequence #(my_transaction);

   function  new(string name= "case0_sequence");
      super.new(name);
   endfunction 
   
   virtual task body();
      my_transaction tr;
      if(starting_phase != null) 
         starting_phase.raise_objection(this);
      repeat (2) begin
         tr = my_transaction::type_id::create("tr");
         assert(tr.randomize());
         start_item(tr);
         finish_item(tr);
      end
      #1000ns;
      if(starting_phase != null) 
         starting_phase.drop_objection(this);
   endtask

   `uvm_object_utils(case0_sequence)
endclass


class my_case0 extends base_test;

   function new(string name = "my_case0", uvm_component parent = null);
      super.new(name,parent);
   endfunction 
   extern virtual function void build_phase(uvm_phase phase); 
   `uvm_component_utils(my_case0)
endclass


function void my_case0::build_phase(uvm_phase phase);
   super.build_phase(phase);

   uvm_config_db#(uvm_object_wrapper)::set(this, 
                                           "env.agt.sqr.main_phase", 
                                           "default_sequence", 
                                           case0_sequence::type_id::get());
endfunction

`endif
