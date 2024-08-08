#ifndef MY_TRANSACTION_H
#define MY_TRANSACTION_H
#include <systemc.h>
#include <uvm.h>
using namespace uvm;
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using std::string;
using std::vector;
#include "RGB888_to_YCbCr444_common.h"

#define TIME_STRING sc_time_stamp().to_string().c_str()

class my_transaction : public uvm_object {
public:
   UVM_OBJECT_UTILS(my_transaction)
   cfg_struct cfg_s;
   std::vector<unsigned int> dat1;
   std::vector<unsigned int> dat2;
   std::vector<unsigned int> dat3;

// public methods defined for UVM
public:
   my_transaction() {}
   virtual ~my_transaction() {}
   virtual void do_print(std::ostream&) const;
   virtual void do_pack(uvm::uvm_packer&) const;
   virtual void do_unpack(uvm::uvm_packer&);
   virtual void do_copy(const uvm::uvm_object*);
   virtual bool do_compare(const uvm::uvm_object*) const;
}; // end of class my_transaction

inline bool operator == (const my_transaction & arg1, const my_transaction & arg2) {
   return arg1.do_compare(&arg2);
}

inline bool operator != (const my_transaction & arg1, const my_transaction & arg2) {
   return !(arg1 == arg2);
}

UVM_OBJECT_REGISTER(my_transaction)

#endif
