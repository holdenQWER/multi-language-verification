`ifndef MY_ENV__SV
`define MY_ENV__SV

class my_env extends uvm_env;

   my_agent   agt;
   my_model   mdl;
   my_scoreboard scb;
   uvm_component sctop_proxy;

   uvm_tlm_analysis_fifo #(my_transaction) agt_scb_fifo;
   uvm_tlm_analysis_fifo #(my_transaction) agt_mdl_fifo;
   uvm_tlm_analysis_fifo #(my_transaction) mdl_scb_fifo;
   
   function new(string name = "my_env", uvm_component parent);
      super.new(name, parent);
   endfunction

   virtual function void build_phase(uvm_phase phase);
      super.build_phase(phase);
      agt = my_agent::type_id::create("agt", this);
      agt.is_active = UVM_ACTIVE;
      mdl = my_model::type_id::create("mdl", this);
      scb = my_scoreboard::type_id::create("scb", this);
      agt_scb_fifo = new("agt_scb_fifo", this);
      agt_mdl_fifo = new("agt_mdl_fifo", this);
      mdl_scb_fifo = new("mdl_scb_fifo", this);
      sctop_proxy = uvm_ml_create_component("SC","sctop","sctop",this);

   endfunction

   extern virtual function void connect_phase(uvm_phase phase);
   
   `uvm_component_utils(my_env)
endclass

function void my_env::connect_phase(uvm_phase phase);
   super.connect_phase(phase);
   agt.drv_ap.connect(agt_mdl_fifo.analysis_export);
   mdl.port.connect(agt_mdl_fifo.blocking_get_export);
   mdl.ap.connect(mdl_scb_fifo.analysis_export);
   scb.exp_port.connect(mdl_scb_fifo.blocking_get_export);
   agt.mon_ap.connect(agt_scb_fifo.analysis_export);
   scb.act_port.connect(agt_scb_fifo.blocking_get_export); 
   void'(uvm_ml::connect(mdl.sc_ap.get_full_name(),{get_full_name(),".sctop.model.sc_imp"}));
   void'(uvm_ml::connect({get_full_name(),".sctop.model.sc_ap"},mdl.sc_imp.get_full_name()));
endfunction

`endif
