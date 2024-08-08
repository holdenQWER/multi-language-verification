`ifndef MY_MODEL__SV
`define MY_MODEL__SV

class my_model extends uvm_component;
   
   uvm_blocking_get_port #(my_transaction)  port;
   uvm_analysis_port #(my_transaction)  ap;

   uvm_analysis_port #(my_transaction)  sc_ap;
   uvm_analysis_imp #(my_transaction,my_model) sc_imp;
   my_transaction sc_tr_q[$];

   extern function new(string name, uvm_component parent);
   extern function void build_phase(uvm_phase phase);
   extern virtual  task main_phase(uvm_phase phase);
   extern function void phase_ended(uvm_phase phase);
   extern function void write(input my_transaction tr_from_sc);

   `uvm_component_utils(my_model)
endclass 

function my_model::new(string name, uvm_component parent);
   super.new(name, parent);
endfunction 

function void my_model::phase_ended(uvm_phase phase);
   if (phase.get_name() == "build") begin
      uvm_ml::ml_tlm1 #(my_transaction)::register(sc_ap);
      uvm_ml::ml_tlm1 #(my_transaction)::register(sc_imp);
   end
endfunction

function void my_model::write(input my_transaction tr_from_sc);
   my_transaction tr;
   $cast(tr,tr_from_sc.clone());
   sc_tr_q.push_back(tr);
endfunction

function void my_model::build_phase(uvm_phase phase);
   super.build_phase(phase);
   port = new("port", this);
   ap = new("ap", this);
   sc_imp = new("sc_imp",this);
   sc_ap = new("sc_ap",this);
endfunction

task my_model::main_phase(uvm_phase phase);
   my_transaction tr;
   my_transaction sc_tr;
   super.main_phase(phase);
   while(1) begin
      port.get(tr);
      sc_ap.write(tr);
      wait(sc_tr_q.size()>0);
      sc_tr = sc_tr_q.pop_front();
      `uvm_info("my_model", "get sc_tr from sc model:", UVM_LOW)
      sc_tr.print();
      ap.write(sc_tr);
   end
endtask
`endif
