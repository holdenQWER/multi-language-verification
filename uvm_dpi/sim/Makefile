all: clean comp run

pre_sim:
	mkdir -p dbg_log;
	rm -rf bootstrap.file ;
	touch bootstrap.file ;
	echo '#'!SV_LIBRARIES >> bootstrap.file;
	echo ../matlab/output/libRGB888_to_YCbCr444 >> bootstrap.file;
	echo ../matlab/libRGB888_to_YCbCr444_sim >> bootstrap.file;

comp: pre_sim
	vcs -full64 \
	-kdb -lca \
	-debug_access+all \
	-sverilog \
	-ntb_opts uvm \
	-timescale=1ns/1ns \
	+incdir+../tb \
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
