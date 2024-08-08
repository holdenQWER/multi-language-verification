#ifndef _VC_HDRS_H
#define _VC_HDRS_H

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <stdio.h>
#include <dlfcn.h>
#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _VC_TYPES_
#define _VC_TYPES_
/* common definitions shared with DirectC.h */

typedef unsigned int U;
typedef unsigned char UB;
typedef unsigned char scalar;
typedef struct { U c; U d;} vec32;

#define scalar_0 0
#define scalar_1 1
#define scalar_z 2
#define scalar_x 3

extern long long int ConvUP2LLI(U* a);
extern void ConvLLI2UP(long long int a1, U* a2);
extern long long int GetLLIresult();
extern void StoreLLIresult(const unsigned int* data);
typedef struct VeriC_Descriptor *vc_handle;

#ifndef SV_3_COMPATIBILITY
#define SV_STRING const char*
#else
#define SV_STRING char*
#endif

#endif /* _VC_TYPES_ */


 extern int uvm_hdl_check_path(/* INPUT */const char* path);

 extern int uvm_hdl_deposit(/* INPUT */const char* path, const /* INPUT */svLogicVecVal *value);

 extern int uvm_hdl_force(/* INPUT */const char* path, const /* INPUT */svLogicVecVal *value);

 extern int uvm_hdl_release_and_read(/* INPUT */const char* path, /* INOUT */svLogicVecVal *value);

 extern int uvm_hdl_release(/* INPUT */const char* path);

 extern int uvm_hdl_read(/* INPUT */const char* path, /* OUTPUT */svLogicVecVal *value);

 extern SV_STRING uvm_hdl_read_string(/* INPUT */const char* path);

 extern int uvm_memory_load(/* INPUT */const char* nid, /* INPUT */const char* scope, /* INPUT */const char* fileName, /* INPUT */const char* radix, /* INPUT */const char* startaddr, /* INPUT */const char* endaddr, /* INPUT */const char* types);

 extern SV_STRING uvm_dpi_get_next_arg_c();

 extern SV_STRING uvm_dpi_get_tool_name_c();

 extern SV_STRING uvm_dpi_get_tool_version_c();

 extern void* uvm_dpi_regcomp(/* INPUT */const char* regex);

 extern int uvm_dpi_regexec(/* INPUT */void* preg, /* INPUT */const char* str);

 extern void uvm_dpi_regfree(/* INPUT */void* preg);

 extern int uvm_re_match(/* INPUT */const char* re, /* INPUT */const char* str);

 extern void uvm_dump_re_cache();

 extern SV_STRING uvm_glob_to_re(/* INPUT */const char* glob);

 extern void UVMC_XL_CONV_SV2C_copy_c2sv_array(/* INPUT */unsigned int num_bytes, /* INPUT */unsigned long long src_c_array_chandle, const /* INOUT */svOpenArrayHandle dst_sv_array);

 extern void UVMC_XL_CONV_SV2C_copy_c2sv_int_array(/* INPUT */unsigned int num_bytes, /* INPUT */unsigned long long src_c_array_chandle, const /* INOUT */svOpenArrayHandle dst_sv_array);

 extern void UVMC_XL_CONV_SV2C_convert_array_ref_to_chandle(const /* INPUT */svOpenArrayHandle src_sv_array, /* INOUT */svBitVecVal *dst_c_array_chandle);

 extern void UVMC_XL_CONV_SV2C_convert_int_array_ref_to_chandle(const /* INPUT */svOpenArrayHandle src_sv_array, /* INOUT */svBitVecVal *dst_c_array_chandle);

 extern void UVMC_XL_CONV_SV2C_duplicate_array_ref_to_chandle(const /* INPUT */svOpenArrayHandle src_sv_array, /* INOUT */svBitVecVal *dst_c_array_chandle);

 extern void UVMC_XL_CONV_SV2C_duplicate_int_array_ref_to_chandle(const /* INPUT */svOpenArrayHandle src_sv_array, /* INOUT */svBitVecVal *dst_c_array_chandle);

 extern void UVMC_XL_CONV_SV2C_free_duplicated_storage(/* INPUT */unsigned long long c_array_chandle);

 extern void UVMC_CONV_SV2C_copy_c2sv_array(/* INPUT */unsigned int num_bytes, /* INPUT */unsigned long long src_c_array_chandle, const /* INOUT */svOpenArrayHandle dst_sv_array);

 extern void UVMC_CONV_SV2C_convert_array_ref_to_chandle(const /* INPUT */svOpenArrayHandle src_sv_array, /* INOUT */svBitVecVal *dst_c_array_chandle);

 extern void UVMC_CONV_SV2C_duplicate_array_ref_to_chandle(const /* INPUT */svOpenArrayHandle src_sv_array, /* INOUT */svBitVecVal *dst_c_array_chandle);

 extern void UVMC_CONV_SV2C_free_duplicated_storage(/* INPUT */unsigned long long c_array_chandle);

 extern unsigned char SV2C_blocking_req_done(/* INPUT */int m_x_id);

 extern unsigned char SV2C_blocking_rsp_done(/* INPUT */int m_x_id, const /* INPUT */unsigned int *bits, /* INPUT */unsigned long long delay);

 extern int SV2C_resolve_binding(/* INPUT */const char* sv_port_name, /* INPUT */const char* sv_target, /* INPUT */const char* sv_trans_type, /* INPUT */int dummy, /* INPUT */int sv_proxy_type, /* INPUT */int sv_mask, /* INPUT */int sv_id, /* OUTPUT */int *sc_id);

 extern void C2SV_blocking_rsp_done(/* INPUT */int x_id, const /* INPUT */unsigned int *bits, /* INPUT */unsigned long long delay);

 extern void C2SV_blocking_req_done(/* INPUT */int x_id);

 extern unsigned char SV2C_put(/* INPUT */int x_id, const /* INPUT */unsigned int *bits);

 extern unsigned char SV2C_try_put(/* INPUT */int x_id, const /* INPUT */unsigned int *bits);

 extern unsigned char SV2C_can_put(/* INPUT */int x_id);

 extern unsigned char SV2C_get(/* INPUT */int x_id);

 extern unsigned char SV2C_try_get(/* INPUT */int x_id, /* OUTPUT */unsigned int *bits);

 extern unsigned char SV2C_can_get(/* INPUT */int x_id);

 extern unsigned char SV2C_peek(/* INPUT */int x_id);

 extern unsigned char SV2C_try_peek(/* INPUT */int x_id, /* OUTPUT */unsigned int *bits);

 extern unsigned char SV2C_can_peek(/* INPUT */int x_id);

 extern unsigned char SV2C_write(/* INPUT */int x_id, const /* INPUT */unsigned int *bits);

 extern unsigned char SV2C_transport(/* INPUT */int x_id, /* INOUT */unsigned int *bits);

 extern unsigned char SV2C_try_transport(/* INPUT */int x_id, /* INOUT */unsigned int *bits);

 extern void C2SV_put(/* INPUT */int x_id, const /* INPUT */unsigned int *bits);

 extern unsigned char C2SV_try_put(/* INPUT */int x_id, const /* INPUT */unsigned int *bits);

 extern unsigned char C2SV_can_put(/* INPUT */int x_id);

 extern void C2SV_get(/* INPUT */int x_id);

 extern unsigned char C2SV_try_get(/* INPUT */int x_id, /* OUTPUT */unsigned int *bits);

 extern unsigned char C2SV_can_get(/* INPUT */int x_id);

 extern void C2SV_peek(/* INPUT */int x_id);

 extern unsigned char C2SV_try_peek(/* INPUT */int x_id, /* OUTPUT */unsigned int *bits);

 extern unsigned char C2SV_can_peek(/* INPUT */int x_id);

 extern void C2SV_write(/* INPUT */int x_id, const /* INPUT */unsigned int *bits);

 extern void C2SV_transport(/* INPUT */int x_id, /* INOUT */unsigned int *bits);

 extern unsigned char C2SV_try_transport(/* INPUT */int x_id, /* INOUT */unsigned int *bits);

 extern int SV2C_nb_transport_fw(/* INPUT */int x_id, /* INOUT */unsigned int *bits, /* INOUT */unsigned int *phase, /* INOUT */unsigned long long *delay);

 extern int SV2C_nb_transport_bw(/* INPUT */int x_id, /* INOUT */unsigned int *bits, /* INOUT */unsigned int *phase, /* INOUT */unsigned long long *delay);

 extern unsigned char SV2C_b_transport(/* INPUT */int x_id, /* INOUT */unsigned int *bits, /* INPUT */unsigned long long delay);

 extern int C2SV_nb_transport_fw(/* INPUT */int x_id, /* INOUT */unsigned int *bits, /* INOUT */unsigned int *phase, /* INOUT */unsigned long long *delay);

 extern int C2SV_nb_transport_bw(/* INPUT */int x_id, /* INOUT */unsigned int *bits, /* INOUT */unsigned int *phase, /* INOUT */unsigned long long *delay);

 extern void C2SV_b_transport(/* INPUT */int x_id, /* INOUT */unsigned int *bits, /* INPUT */unsigned long long delay);

 extern unsigned char SV2C_phase_notification(/* INPUT */int id);

 extern unsigned char SV2C_sv_ready();

 extern int UVMC_wait_for_phase_request(/* INPUT */const char* ph_name, /* INPUT */int state, /* INPUT */int op);

 extern void UVMC_get_uvm_version(/* OUTPUT */unsigned int *major, /* OUTPUT */unsigned int *minor, /* OUTPUT */SV_STRING *fix);

 extern void UVMC_raise_objection(/* INPUT */const char* name, /* INPUT */const char* contxt, /* INPUT */const char* description, /* INPUT */unsigned int count);

 extern void UVMC_drop_objection(/* INPUT */const char* name, /* INPUT */const char* contxt, /* INPUT */const char* description, /* INPUT */unsigned int count);

 extern void UVMC_global_stop_request();

 extern void UVMC_print_topology(/* INPUT */const char* contxt, /* INPUT */int depth);

 extern unsigned char UVMC_report_enabled(/* INPUT */const char* contxt, /* INPUT */int verbosity, /* INPUT */int severity, /* INPUT */const char* id);

 extern void UVMC_report(/* INPUT */int severity, /* INPUT */const char* id, /* INPUT */const char* message, /* INPUT */int verbosity, /* INPUT */const char* contxt, /* INPUT */const char* filename, /* INPUT */int line);

 extern void UVMC_set_report_verbosity(/* INPUT */int level, /* INPUT */const char* contxt, /* INPUT */unsigned char recurse);

 extern void UVMC_set_config_int(/* INPUT */const char* contxt, /* INPUT */const char* inst_name, /* INPUT */const char* field_name, /* INPUT */unsigned long long value);

 extern void UVMC_set_config_string(/* INPUT */const char* contxt, /* INPUT */const char* inst_name, /* INPUT */const char* field_name, /* INPUT */const char* value);

 extern void UVMC_set_config_object(/* INPUT */const char* type_name, /* INPUT */const char* contxt, /* INPUT */const char* inst_name, /* INPUT */const char* field_name, const /* INPUT */unsigned int *value);

 extern unsigned char UVMC_get_config_int(/* INPUT */const char* contxt, /* INPUT */const char* inst_name, /* INPUT */const char* field_name, /* OUTPUT */unsigned long long *value);

 extern unsigned char UVMC_get_config_string(/* INPUT */const char* contxt, /* INPUT */const char* inst_name, /* INPUT */const char* field_name, /* OUTPUT */SV_STRING *value);

 extern unsigned char UVMC_get_config_object(/* INPUT */const char* type_name, /* INPUT */const char* contxt, /* INPUT */const char* inst_name, /* INPUT */const char* field_name, /* OUTPUT */unsigned int *value);

 extern void UVMC_print_factory(/* INPUT */int all_types);

 extern void UVMC_set_factory_inst_override(/* INPUT */const char* requested_type, /* INPUT */const char* override_type, /* INPUT */const char* contxt);

 extern void UVMC_set_factory_type_override(/* INPUT */const char* requested_type, /* INPUT */const char* override_type, /* INPUT */unsigned char replace);

 extern void UVMC_debug_factory_create(/* INPUT */const char* requested_type, /* INPUT */const char* contxt);

 extern void UVMC_find_factory_override(/* INPUT */const char* requested_type, /* INPUT */const char* contxt, /* OUTPUT */SV_STRING *override_type);
void SdisableFork();

#ifdef __cplusplus
}
#endif


#endif //#ifndef _VC_HDRS_H

