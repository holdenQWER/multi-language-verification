all: clean comp run

pre_sim:
	mkdir -p dbg_log;
	rm -rf bootstrap.file ;
	touch bootstrap.file ;
	echo '#'!SV_LIBRARIES >> bootstrap.file;
	echo ${UVM_ML_HOME}/ml/libs/uvm_sv/9.2/64bit/libuvm_sv_ml >> bootstrap.file;
	echo ${UVM_ML_HOME}/ml/libs/backplane/9.2/64bit/libuvm_ml_bp >> bootstrap.file;
	echo ../matlab/libsctop >> bootstrap.file;

comp: pre_sim
	vcs -full64 \
	-kdb -lca \
	-debug_access+all \
	-sverilog \
	+incdir+${UVM_ML_HOME}/ml/frameworks/uvm/sv/1.1d-ml/src \
	+incdir+${UVM_ML_HOME}/ml/adapters/uvm_sv \
	+incdir+../tb \
	${UVM_ML_HOME}/ml/frameworks/uvm/sv/1.1d-ml/src/uvm_pkg.sv \
	${UVM_ML_HOME}/ml/adapters/uvm_sv/uvm_ml_adapter.sv \
	${UVM_ML_HOME}/ml/frameworks/uvm/sv/1.1d-ml/src/dpi/uvm_dpi.cc -CFLAGS '-DVCS -m64' \
	-timescale=1ns/1ns \
	+define+UVM_PACK_MAX_SIZE=12000000 \
	-l comp.log \
	-f ./filelist.f 
	
run:
	./simv \
	+UVM_TESTNAME=my_case0 \
	+ntb_solver_array_size_warn=100000 \
	+ntb_random_seed_automatic \
	-sv_liblist ./bootstrap.file \
	-l sim.log

verdi:
	verdi -ssf top_tb.fsdb &

clean:
	-rm -rf simv* csrc *.log *.fsdb dbg_log novas.* ucli.key vc_hdrs.h  verdi_config_file verdiLog

	#-LDFLAGS '-Wl,-rpath=../matlab/output -Wl,-rpath=../matlab' \
