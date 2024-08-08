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

typedef struct _vcs_dpi_uvm_ml_srv_provider_struct	uvm_ml_srv_provider_struct;

struct	_vcs_dpi_uvm_ml_srv_provider_struct	{
	SV_STRING	phase_srv_provider;
	SV_STRING	wakeup_srv_provider;
	SV_STRING	stopper_srv_provider;
	SV_STRING	print_srv_provider;
	SV_STRING	error_handling_srv_provider;
	int	bp_srv_provider_strength;
};



 extern int uvm_hdl_check_path(/* INPUT */const char* path);

 extern int uvm_hdl_deposit(/* INPUT */const char* path, const /* INPUT */svLogicVecVal *value);

 extern int uvm_hdl_force(/* INPUT */const char* path, const /* INPUT */svLogicVecVal *value);

 extern int uvm_hdl_release_and_read(/* INPUT */const char* path, /* INOUT */svLogicVecVal *value);

 extern int uvm_hdl_release(/* INPUT */const char* path);

 extern int uvm_hdl_read(/* INPUT */const char* path, /* OUTPUT */svLogicVecVal *value);

 extern SV_STRING uvm_dpi_get_next_arg_c(/* INPUT */int init);

 extern SV_STRING uvm_dpi_get_tool_name_c();

 extern SV_STRING uvm_dpi_get_tool_version_c();

 extern void* uvm_dpi_regcomp(/* INPUT */const char* regex);

 extern int uvm_dpi_regexec(/* INPUT */void* preg, /* INPUT */const char* str);

 extern void uvm_dpi_regfree(/* INPUT */void* preg);

 extern int uvm_re_match(/* INPUT */const char* re, /* INPUT */const char* str);

 extern void uvm_dump_re_cache();

 extern SV_STRING uvm_glob_to_re(/* INPUT */const char* glob);

 extern void uvm_ml_uvmsv_set_trace_mode(/* INPUT */int mode);

 extern int uvm_ml_uvmsv_register_framework();

 extern int uvm_ml_uvmsv_add_root_node(/* INPUT */unsigned int top_level_id, /* INPUT */const char* component_name, /* INPUT */const char* instance_name);

 extern int uvm_ml_uvmsv_notify_phase(/* INPUT */const char* phase_group, /* INPUT */const char* phase_name, /* INPUT */int phase_action);

 extern int uvm_ml_uvmsv_transmit_phase(/* INPUT */const char* target_frmw_ind, /* INPUT */int target_id, /* INPUT */const char* phase_group, /* INPUT */const char* phase_name, /* INPUT */int phase_action);

 extern unsigned char uvm_ml_uvmsv_notify_runtime_phase(/* INPUT */const char* phase_group, /* INPUT */const char* phase_name, /* INPUT */int phase_action, /* INPUT */unsigned int next_runtime_phases_num, const /* INPUT */svOpenArrayHandle next_runtime_phases_names, /* OUTPUT */unsigned int *participate);

 extern int uvm_ml_uvmsv_get_current_numeric_version();

 extern int uvm_ml_uvmsv_get_numeric_version(/* INPUT */unsigned int major, /* INPUT */unsigned int middle, /* INPUT */unsigned int minor);

 extern unsigned char uvm_ml_uvmsv_connect_ports(/* INPUT */const char* path1, /* INPUT */const char* path2);

 extern unsigned char uvm_ml_uvmsv_synchronize_runtime_phases(/* INPUT */const char* this_phase_domain, /* INPUT */const char* this_phase_schedule, /* INPUT */const char* this_phase_name, /* INPUT */const char* other_framework_name, /* INPUT */const char* other_phase_group, /* INPUT */const char* other_phase_name);

 extern unsigned char uvm_ml_uvmsv_get_connector_size(/* INPUT */unsigned int local_port_id);

 extern unsigned char uvm_ml_uvmsv_nb_put(/* INPUT */unsigned int local_port_id, /* INPUT */int packed_size, const /* INPUT */svBitVecVal *stream);

 extern unsigned char uvm_ml_uvmsv_can_put(/* INPUT */unsigned int local_port_id);

 extern unsigned char uvm_ml_uvmsv_nb_get(/* INPUT */unsigned int local_port_id, /* OUTPUT */unsigned int *stream_size, /* OUTPUT */svBitVecVal *stream);

 extern unsigned char uvm_ml_uvmsv_nb_peek(/* INPUT */unsigned int local_port_id, /* OUTPUT */unsigned int *stream_size, /* OUTPUT */svBitVecVal *stream);

 extern unsigned char uvm_ml_uvmsv_can_get(/* INPUT */unsigned int local_port_id);

 extern unsigned char uvm_ml_uvmsv_can_peek(/* INPUT */unsigned int local_port_id);

 extern unsigned char uvm_ml_uvmsv_nb_transport(/* INPUT */unsigned int local_port_id, /* INPUT */int req_stream_size, const /* INPUT */svBitVecVal *req_stream, /* OUTPUT */int *rsp_stream_size, /* OUTPUT */svBitVecVal *rsp_stream);

 extern void uvm_ml_uvmsv_write(/* INPUT */unsigned int local_port_id, /* INPUT */int packed_size, const /* INPUT */svBitVecVal *stream);

 extern void uvm_ml_uvmsv_set_pack_max_size(/* INPUT */int size);

 extern int uvm_ml_uvmsv_get_pack_max_size();

 extern void uvm_ml_uvmsv_notify_end_blocking(/* INPUT */unsigned int callback_adapter_id, /* INPUT */unsigned int call_id);

 extern void uvm_ml_uvmsv_put_request(/* INPUT */unsigned int local_port_id, /* INPUT */unsigned int call_id, /* INPUT */unsigned int stream_size, const /* INPUT */svBitVecVal *stream, /* OUTPUT */unsigned int *done);

 extern void uvm_ml_uvmsv_get_request(/* INPUT */unsigned int local_port_id, /* INPUT */unsigned int call_id, /* OUTPUT */unsigned int *stream_size, /* OUTPUT */svBitVecVal *stream, /* OUTPUT */unsigned int *done);

 extern unsigned int uvm_ml_uvmsv_get_requested(/* INPUT */unsigned int local_port_id, /* INPUT */unsigned int call_id, /* OUTPUT */svBitVecVal *stream);

 extern void uvm_ml_uvmsv_peek_request(/* INPUT */unsigned int local_port_id, /* INPUT */unsigned int call_id, /* OUTPUT */unsigned int *stream_size, /* OUTPUT */svBitVecVal *stream, /* OUTPUT */unsigned int *done);

 extern void uvm_ml_uvmsv_transport_request(/* INPUT */unsigned int local_port_id, /* INPUT */unsigned int call_id, /* INPUT */unsigned int req_stream_size, const /* INPUT */svBitVecVal *req_stream, /* OUTPUT */unsigned int *rsp_stream_size, /* OUTPUT */svBitVecVal *rsp_stream, /* OUTPUT */unsigned int *done);

 extern unsigned int uvm_ml_uvmsv_transport_response(/* INPUT */unsigned int local_port_id, /* INPUT */unsigned int call_id, /* OUTPUT */svBitVecVal *rsp_stream);

 extern int uvm_ml_uvmsv_set_match_types(/* INPUT */const char* type1, /* INPUT */const char* type2);

 extern void uvm_ml_uvmsv_run_test(/* INPUT */unsigned int adapter_id, const /* INPUT */svOpenArrayHandle tops, /* INPUT */const char* test, /* INPUT */unsigned int is_blocking_runtime_phases, /* OUTPUT */int *result);

 extern int uvm_ml_uvmsv_tlm2_nb_transport_fw(/* INPUT */unsigned int socket_id, /* INOUT */unsigned int *stream_size, /* INOUT */svBitVecVal *stream, /* INOUT */int *p, /* INPUT */unsigned int transaction_id, /* INOUT */int *delay_unit, /* INOUT */double *delay_val, /* INPUT */unsigned int index_in_socket);

 extern int uvm_ml_uvmsv_tlm2_nb_transport_bw(/* INPUT */unsigned int socket_id, /* INOUT */unsigned int *stream_size, /* INOUT */svBitVecVal *stream, /* INOUT */int *p, /* INPUT */unsigned int transaction_id, /* INOUT */int *delay_unit, /* INOUT */double *delay_val, /* INPUT */unsigned int index_in_socket);

 extern int uvm_ml_uvmsv_tlm2_b_transport_request(/* INPUT */unsigned int socket_id, /* INPUT */unsigned int call_id, /* INOUT */unsigned int *stream_size, /* INOUT */svBitVecVal *stream, /* INPUT */int delay_unit, /* INPUT */double delay_val, /* OUTPUT */unsigned int *done, /* INPUT */unsigned int index_in_socket);

 extern int uvm_ml_uvmsv_tlm2_b_transport_response(/* INPUT */unsigned int socket_id, /* INPUT */unsigned int call_id, /* OUTPUT */unsigned int *stream_size, /* OUTPUT */svBitVecVal *stream, /* INPUT */unsigned int index_in_socket);

 extern void uvm_ml_uvmsv_turn_off_transaction_mapping(/* INPUT */const char* socket_name);

 extern unsigned int uvm_ml_uvmsv_assign_transaction_id();

 extern int uvm_ml_uvmsv_get_type_id_from_name(/* INPUT */const char* typename);

 extern SV_STRING uvm_ml_uvmsv_get_type_name_from_id(/* INPUT */int uni_type_id);

 extern void uvm_ml_uvmsv_synchronize();

 extern int uvm_ml_uvmsv_create_child_junction_node(/* INPUT */const char* target_framework_indicator, /* INPUT */const char* component_type_name, /* INPUT */const char* instance_name, /* INPUT */const char* parent_full_name, /* INPUT */int parent_junction_node_id);

 extern void uvm_ml_uvmsv_notify_phase_done(/* INPUT */const char* phase_group, /* INPUT */const char* phase_name);

 extern void uvm_ml_uvmsv_register_srv_providers(const /* INPUT */uvm_ml_srv_provider_struct *srv_provider);

 extern void uvm_ml_uvmsv_notify_resource(/* INPUT */int action, /* INPUT */const char* item_scope, /* INPUT */const char* item_name, /* INPUT */const char* accessor_name, /* INPUT */unsigned int stream_size, const /* INPUT */svBitVecVal *stream);

 extern void uvm_ml_uvmsv_notify_config(/* INPUT */const char* cntxt, /* INPUT */const char* instance_name, /* INPUT */const char* field_name, /* INPUT */unsigned int stream_size, const /* INPUT */svBitVecVal *stream);

 extern void uvm_ml_uvmsv_dpi_context_notify_time_cb();

 extern void uvm_ml_uvmsv_notify_event(/* INPUT */const char* scope_name, /* INPUT */const char* event_name, /* INPUT */int action_name, /* INPUT */int stream_size, const /* INPUT */svBitVecVal *stream, /* INPUT */const char* event_data_type_name);

 extern void uvm_ml_uvmsv_notify_barrier(/* INPUT */const char* scope_name, /* INPUT */const char* barrier_name, /* INPUT */int action_name, /* INPUT */int data);

 extern void uvm_ml_uvmsv_register_reset_callback();

 extern void uvm_ml_uvmsv_export_get_request(/* INPUT */unsigned int connector_id, /* INPUT */unsigned int call_id, /* INPUT */unsigned int callback_adapter_id);

 extern void uvm_ml_uvmsv_export_peek_request(/* INPUT */unsigned int connector_id, /* INPUT */unsigned int call_id, /* INPUT */unsigned int callback_adapter_id);

 extern unsigned int uvm_ml_uvmsv_export_get_requested(/* INPUT */unsigned int connector_id, /* INPUT */unsigned int call_id, /* OUTPUT */svBitVecVal *stream);

 extern unsigned int uvm_ml_uvmsv_export_peek_requested(/* INPUT */unsigned int connector_id, /* INPUT */unsigned int call_id, /* OUTPUT */svBitVecVal *stream);

 extern void uvm_ml_uvmsv_export_transport_request(/* INPUT */unsigned int connector_id, /* INPUT */unsigned int call_id, /* INPUT */unsigned int callback_adapter_id, /* INPUT */unsigned int req_stream_size, const /* INPUT */svBitVecVal *req_stream);

 extern unsigned int uvm_ml_uvmsv_export_transport_response(/* INPUT */unsigned int connector_id, /* INPUT */unsigned int call_id, /* OUTPUT */svBitVecVal *stream);

 extern void uvm_ml_uvmsv_export_put_request(/* INPUT */unsigned int connector_id, /* INPUT */unsigned int call_id, /* INPUT */unsigned int callback_adapter_id, /* INPUT */unsigned int stream_size, const /* INPUT */svBitVecVal *stream);

 extern int uvm_ml_uvmsv_export_tlm2_nb_transport_incoming(/* INPUT */unsigned int to_socket_id, /* INOUT */unsigned int *stream_size, /* INOUT */svBitVecVal *stream, /* INOUT */int *phase, /* INPUT */unsigned int transaction_id, /* INOUT */int *delay_unit, /* INOUT */double *delay_value, /* INPUT */unsigned int from_frmw_id, /* INPUT */unsigned int from_socket_id);

 extern int uvm_ml_uvmsv_export_tlm2_b_transport_request(/* INPUT */unsigned int to_socket_id, /* INPUT */unsigned int call_id, /* INPUT */unsigned int callback_adapter_id, /* INPUT */unsigned int stream_size, const /* INPUT */svBitVecVal *stream, /* INPUT */int delay_unit, /* INPUT */double delay_value, /* INPUT */unsigned int from_socket_id);

 extern int uvm_ml_uvmsv_export_tlm2_b_transport_response(/* INPUT */unsigned int to_socket_id, /* INPUT */unsigned int call_id, /* INOUT */unsigned int *stream_size, /* OUTPUT */svBitVecVal *stream, /* INPUT */unsigned int from_frmw_id, /* INPUT */unsigned int from_socket_id);

 extern void uvm_ml_uvmsv_export_tlm2_turn_off_transaction_mapping(/* INPUT */const char* socket_name);

 extern void uvm_ml_uvmsv_export_notify_end_blocking(/* INPUT */unsigned int call_id);

 extern void uvm_ml_uvmsv_export_unrecoverable_error_handler(/* INPUT */int mode);

 extern int uvm_ml_uvmsv_export_startup();

 extern int uvm_ml_uvmsv_export_construct_top(/* INPUT */const char* top_name, /* INPUT */const char* instance_name);

 extern unsigned char uvm_ml_uvmsv_export_notify_resource(/* INPUT */int action, /* INPUT */const char* scope, /* INPUT */const char* name, /* INPUT */const char* accessor_name, /* INPUT */unsigned int stream_size, const /* INPUT */svBitVecVal *stream);

 extern void uvm_ml_uvmsv_export_notify_config(/* INPUT */const char* cntxt, /* INPUT */const char* instance_name, /* INPUT */const char* field_name, /* INPUT */unsigned int stream_size, const /* INPUT */svBitVecVal *stream);

 extern void uvm_ml_uvmsv_export_stopper_srv_stop_request();

 extern void uvm_ml_uvmsv_export_print_srv_print_request(/* INPUT */const char* message);

 extern int uvm_ml_uvmsv_export_get_num_children(/* INPUT */const char* instance_name);

 extern SV_STRING uvm_ml_uvmsv_export_get_child_name(/* INPUT */const char* parent_name, /* INPUT */unsigned int num);

 extern SV_STRING uvm_ml_uvmsv_export_get_component_type_name(/* INPUT */const char* component_name);

 extern int uvm_ml_uvmsv_export_is_port(/* INPUT */const char* component_name);

 extern int uvm_ml_uvmsv_export_phase_srv_check_phase(/* INPUT */const char* phase_name);

 extern int uvm_ml_uvmsv_export_phase_srv_check_future_phase(/* INPUT */const char* phase_name, /* INPUT */int phaseAction);

 extern void uvm_ml_uvmsv_export_notify_event(/* INPUT */const char* scope_name, /* INPUT */const char* event_name, /* INPUT */int action, /* INPUT */unsigned int stream_size, const /* INPUT */svBitVecVal *stream);

 extern void uvm_ml_uvmsv_export_notify_barrier(/* INPUT */const char* scope_name, /* INPUT */const char* barrier_name, /* INPUT */int action, /* INPUT */int data);

 extern int uvm_ml_uvmsv_export_transmit_phase(/* INPUT */unsigned int target_id, /* INPUT */const char* phase_group, /* INPUT */const char* phase_name, /* INPUT */int phase_action);

 extern int uvm_ml_uvmsv_export_notify_phase(/* INPUT */const char* phase_group, /* INPUT */const char* phase_name, /* INPUT */int phase_action);

 extern int uvm_ml_uvmsv_export_notify_runtime_phase(/* INPUT */const char* phase_group, /* INPUT */const char* phase_name, /* INPUT */int phase_action, /* INPUT */unsigned int is_other_frmw_phase_sync, /* INPUT */const char* this_frmw_phase_group, /* INPUT */const char* this_frmw_phase_name, /* OUTPUT */unsigned int *participate);

 extern void uvm_ml_uvmsv_export_synchronize_runtime_phases(/* INPUT */const char* this_phase_group, /* INPUT */const char* this_phase_name, /* INPUT */int other_framework_id, /* INPUT */const char* other_phase_group, /* INPUT */const char* other_phase_name);

 extern void uvm_ml_uvmsv_export_set_trace_mode(/* INPUT */int mode);

 extern void uvm_ml_uvmsv_export_set_trace_serialization_params(/* INPUT */unsigned int obj_kinds, /* INPUT */int list_items);

 extern int uvm_ml_uvmsv_export_find_connector_id_by_name(/* INPUT */const char* name);

 extern SV_STRING uvm_ml_uvmsv_export_get_connector_intf_name(/* INPUT */unsigned int connector_id);

 extern SV_STRING uvm_ml_uvmsv_export_get_connector_T1_name(/* INPUT */unsigned int connector_id);

 extern SV_STRING uvm_ml_uvmsv_export_get_connector_T2_name(/* INPUT */unsigned int connector_id);

 extern int uvm_ml_uvmsv_export_get_connector_type(/* INPUT */unsigned int connector_id);

 extern unsigned char uvm_ml_uvmsv_export_try_put(/* INPUT */unsigned int connector_id, /* INPUT */unsigned int stream_size, const /* INPUT */svBitVecVal *stream);

 extern unsigned char uvm_ml_uvmsv_export_can_put(/* INPUT */unsigned int connector_id);

 extern unsigned char uvm_ml_uvmsv_export_try_get(/* INPUT */unsigned int connector_id, /* OUTPUT */unsigned int *stream_size, /* OUTPUT */svBitVecVal *stream);

 extern unsigned char uvm_ml_uvmsv_export_can_get(/* INPUT */unsigned int connector_id);

 extern unsigned char uvm_ml_uvmsv_export_try_peek(/* INPUT */unsigned int connector_id, /* OUTPUT */unsigned int *stream_size, /* OUTPUT */svBitVecVal *stream);

 extern unsigned char uvm_ml_uvmsv_export_can_peek(/* INPUT */unsigned int connector_id);

 extern unsigned char uvm_ml_uvmsv_export_nb_transport(/* INPUT */unsigned int connector_id, /* INPUT */unsigned int req_stream_size, const /* INPUT */svBitVecVal *req_stream, /* OUTPUT */unsigned int *rsp_stream_size, /* OUTPUT */svBitVecVal *rsp_stream);

 extern void uvm_ml_uvmsv_export_tlm_write(/* INPUT */unsigned int connector_id, /* INPUT */unsigned int stream_size, const /* INPUT */svBitVecVal *stream);

 extern void uvm_ml_uvmsv_export_external_connect(/* INPUT */unsigned int other_frmw_id, /* INPUT */unsigned int other_socket_id, /* INPUT */unsigned int this_frmw_socket_id);

 extern unsigned int uvm_ml_uvmsv_export_tlm2_is_adapter_support_multi_connections_socket();

 extern unsigned int uvm_ml_uvmsv_export_is_uvm_object_type_name_registered(/* INPUT */const char* type_name);

 extern void uvm_ml_uvmsv_export_phase_srv_notify_phase_done(/* INPUT */unsigned int framework_id, /* INPUT */const char* phase_group, /* INPUT */const char* phase_name, /* INPUT */int time_unit, /* INPUT */double time_value);

 extern int uvm_ml_uvmsv_export_create_child_junction_node(/* INPUT */const char* component_type_name, /* INPUT */const char* instance_name, /* INPUT */const char* parent_full_name, /* INPUT */int parent_framework_id, /* INPUT */int parent_junction_node_id);

 extern void uvm_ml_uvmsv_export_notify_time_cb_helper();

 extern void uvm_ml_uvmsv_export_notify_trace_register_command(/* INPUT */int turn_on);

 extern int uvm_ml_uvmsv_export_phase_srv_enforce_end_of_test();

 extern int uvm_ml_uvmsv_export_phase_srv_stop_all_runtime_phases();

 extern void uvm_ml_uvmsv_export_phase_srv_start(/* INPUT */unsigned int is_blocking_runtime_phases);
void SdisableFork();

#ifdef __cplusplus
}
#endif


#endif //#ifndef _VC_HDRS_H

