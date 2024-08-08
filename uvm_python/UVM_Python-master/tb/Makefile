all:
	g++ -g -fPIC -Wall -I/usr/local/python3/include/python3.7m  -L/usr/local/python3/lib  \
	-lpython3.7m -std=c++0x ../model/adder.cpp -shared -o test.so 	-Wl,-rpath=/usr/local/python3/lib
	vcs -kdb -lca  -full64 -sverilog -debug_access+all -ntb_opts uvm +incdir+../rtl/ input_if.sv output_if.sv ../rtl/adder.sv  ./my_pkg.sv  top.sv ./test.so \
	+UVM_TESTNAME=simple_test -l vcs.log -R

clean:
	-rm -rf csrc simv* *.so

