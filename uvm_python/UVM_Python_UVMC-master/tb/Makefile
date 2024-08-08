UVMC_HOME = /home/holden/systemc_work/lib/uvmc/uvmc-2.3.2
BOOST_HOME = /home/holden/systemc_work/lib/boost_1_72_0

comp_sc:
	syscan -full64 -kdb -cpp g++ -cc gcc -tlm2 \
	-cflags "-g -DVCS -I. -I${VCS_HOME}/include/systemc233/tlm_utils" \
	-cflags "-I${UVMC_HOME}/src/connect/sc" \
	-cflags "-I${VCS_HOME}/include" \
	-cflags "-I${BOOST_HOME}" \
	-cflags "-I/usr/local/python3/include/python3.7m" \
	${UVMC_HOME}/src/connect/sc/uvmc.cpp \
	${VCS_HOME}/etc/uvm-1.1/src/dpi/uvm_dpi.cc \
	-l comp_sc.log \
	./srs.cpp

comp_sv:
	vlogan -full64 -kdb -q  -sverilog \
	+incdir+${VCS_HOME}/etc/uvm-1.1/src \
	+incdir+${UVMC_HOME}/src/connect/sv \
	${VCS_HOME}/etc/uvm-1.1/src/uvm_pkg.sv \
	${UVMC_HOME}/src/connect/sv/uvmc_pkg.sv \
	-timescale=1ns/1ps  \
	+define+UVM_OBJECT_MUST_HAVE_CONSTRUCTOR \
	-l comp_sv.log \
	+incdir+../rtl/ ./input_if.sv ./output_if.sv \
	../rtl/adder.sv ./my_pkg.sv ./top.sv 

elab:
	vcs -full64 -cpp g++ -ld g++ -kdb -debug_access+all \
	-CFLAGS '-O0 -g ' \
	-LDFLAGS '-O0 -g -Wl,-rpath=/usr/local/python3/lib -Wl,-rpath=/home/holden/systemc_work/lib/boost_1_72_0/stage/lib' \
	-q -sysc=deltasync -lca  \
	${BOOST_HOME}/stage/lib/libboost_python37.so \
	${BOOST_HOME}/stage/lib/libboost_system.so \
	/usr/local/python3/lib/libpython3.7m.so \
	-l elab.log \
	-sysc -timescale=1ns/1ps top sc_main

run:
	./simv -q  +UVM_NO_RELNOTES -l run.log


all: clean comp_sc comp_sv elab run

clean:
	-rm -rf csrc simv* AN.DB work.lib++
     
