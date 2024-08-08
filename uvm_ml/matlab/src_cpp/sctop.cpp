#include "uvm_ml.h"
#include "vcsuser.h"
using namespace tlm;
using namespace uvm_ml;

#include "my_transaction.h"

class ref_model : public uvm_component,
                  tlm_analysis_port<my_transaction>
{
public:
   sc_port<tlm_analysis_if<my_transaction>, 2, SC_ONE_OR_MORE_BOUND> sc_ap;
   sc_export<tlm_analysis_if<my_transaction> > sc_imp;

   ref_model(sc_module_name nm) : uvm_component(nm)
                                  , sc_ap("sc_ap")
                                  , sc_imp("sc_imp")
   {
      sc_imp(*this);
   }

   UVM_COMPONENT_UTILS(ref_model)

   void build() {
      io_printf("[SC] %s: ref_model::build\n",TIME_STRING);
   }

   void write(const my_transaction& tr) {
      my_transaction out_tr;
      unsigned int frm_size;
      unsigned int *dat1_h;
      unsigned int *dat2_h;
      unsigned int *dat3_h;
      
      frm_size = tr.cfg_s.height*tr.cfg_s.width;
      dat1_h = (unsigned int*)malloc(sizeof(unsigned int)*frm_size);
      dat2_h = (unsigned int*)malloc(sizeof(unsigned int)*frm_size);
      dat3_h = (unsigned int*)malloc(sizeof(unsigned int)*frm_size);

      // call matlab API
      io_printf("[SC] %s: ref_model::before call matlab\n",TIME_STRING);
      init_RGB888_to_YCbCr444();
      RGB888_to_YCbCr444_main_process(
            dat1_h,
            dat2_h,
            dat3_h,
            &(tr.dat1[0]),
            &(tr.dat2[0]),
            &(tr.dat3[0]),
            &tr.cfg_s
            );
      io_printf("[SC] %s: ref_model::after call matlab\n",TIME_STRING);

      // construct out transaction
      out_tr.cfg_s.height = 0; // no use
      out_tr.cfg_s.width = 0; // no use
      out_tr.dat1 = std::vector<unsigned int>(dat1_h,(dat1_h+frm_size));
      out_tr.dat2 = std::vector<unsigned int>(dat2_h,(dat2_h+frm_size));
      out_tr.dat3 = std::vector<unsigned int>(dat3_h,(dat3_h+frm_size));

      sc_ap->write(out_tr);
      io_printf("[SC] %s: ref_model::after send out transaction\n",TIME_STRING);

      free(dat1_h);
      free(dat2_h);
      free(dat3_h);
      out_tr.dat1.clear();
      out_tr.dat2.clear();
      out_tr.dat3.clear();

   }

};
UVM_COMPONENT_REGISTER(ref_model)

// Top level component 
class sctop : public uvm_component
{
public:
   ref_model model;

   sctop(sc_module_name nm) : uvm_component(nm)
                              , model("model")
   {
      io_printf("[SC] %s: sctop::sctop name=%s\n",TIME_STRING,this->name());
   }

   void build() {
      io_printf("[SC] %s: sctop::build\n",TIME_STRING);
   }

   void before_end_of_elaboration() {
      io_printf("[SC] %s: sctop::before_end_of_elaboration\n",TIME_STRING);
      uvm_ml_register(&model.sc_ap);
      uvm_ml_register(&model.sc_imp);
   }
   void connect() {
      io_printf("[SC] %s: sctop::connect\n",TIME_STRING);
   }
   void start_of_simulation() {
      io_printf("[SC] %s: sctop::start_of_simulation\n",TIME_STRING);
   }
   void end_of_elaboration() {
      io_printf("[SC] %s: sctop::end_of_elaboration\n",TIME_STRING);
   }

   UVM_COMPONENT_UTILS(sctop)
};

UVM_COMPONENT_REGISTER(sctop)

#if(!defined(NC_SYSTEMC) && !defined(XM_SYSTEMC))
int sc_main(int argc, char** argv) {
   return 0;
}
#endif

UVM_ML_MODULE_EXPORT(sctop)

