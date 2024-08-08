#include "my_transaction.h"
#include <iostream>
#include <algorithm>

void my_transaction::do_print(std::ostream& os) const {
   os << "{ ";
   os << "cfg_s.height = ";
   os << cfg_s.height << " ";
   os << "cfg_s.width = ";
   os << cfg_s.width << " ";
   os << " }";
   os << endl;
}

void my_transaction::do_pack(uvm::uvm_packer& packer) const {
   packer << cfg_s.height;
   packer << cfg_s.width;
   packer << dat1;
   packer << dat2;
   packer << dat3;
}

void my_transaction::do_unpack(uvm::uvm_packer& packer) {
   packer >> cfg_s.height;
   packer >> cfg_s.width;
   packer >> dat1;
   packer >> dat2;
   packer >> dat3;
}

void my_transaction::do_copy(const uvm::uvm_object* rhs) {
   const my_transaction* drhs = dynamic_cast<const my_transaction*>(rhs);
   if (!drhs) { cerr << "ERROR in do_copy" ; return ; }
   this->cfg_s.height = drhs->cfg_s.height;
   this->cfg_s.width = drhs->cfg_s.width;
   this->dat1 = drhs->dat1;
   this->dat2 = drhs->dat2;
   this->dat3 = drhs->dat3;
}

bool my_transaction::do_compare(const uvm::uvm_object* rhs) const {
   const my_transaction* drhs = dynamic_cast<const my_transaction*>(rhs);
   if (!drhs) { cerr << "ERROR in do_compare" ; return false ; }
   if (this->cfg_s.height != drhs->cfg_s.height) return false;
   if (this->cfg_s.width != drhs->cfg_s.width) return false;
   if (this->dat1 != drhs->dat1) return false;
   if (this->dat2 != drhs->dat2) return false;
   if (this->dat3 != drhs->dat3) return false;
   return true;
}

