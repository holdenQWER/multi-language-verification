CUR_DIR_PATH := $(shell echo $(CURDIR))

all: matlab_gen gen_lib

matlab_gen:
	${MATLAB_HOME}/bin/mcc -W cpplib:libRGB888_to_YCbCr444 RGB888_to_YCbCr444.m  -g -d output/

gen_lib:
	g++ -g -fPIC -shared -D_GLIBCXX_USE_CXX11_ABI=1 \
	-Wall -Wno-write-strings \
	${CUR_DIR_PATH}/src_cpp/my_transaction.cpp \
	${CUR_DIR_PATH}/src_cpp/RGB888_to_YCbCr444_common.cpp \
	${CUR_DIR_PATH}/src_cpp/sctop.cpp \
	-I${SYSTEMC_HOME}/include \
	-I${UVM_ML_HOME}/ml/adapters/uvm_sc \
	-I${UVM_ML_HOME}/ml/adapters/uvm_sc/osci \
	-I${UVM_ML_HOME}/ml/frameworks/uvm/sc \
	-I${MATLAB_HOME}/extern/include \
	-I${VCS_HOME}/include \
	-I${CUR_DIR_PATH}/output -I${CUR_DIR_PATH}/src_cpp \
	-lmwmclmcrrt -L${MATLAB_HOME}/runtime/glnxa64 \
	-lRGB888_to_YCbCr444 -L./output \
	-luvm_sc_fw_osci -luvm_sc_ml_osci \
	-L${UVM_ML_HOME}/ml/libs/osci/2.3.3/9.2/64bit \
	-Wl,-rpath=${UVM_ML_HOME}/ml/libs/osci/2.3.3/9.2/64bit \
	-Wl,-rpath=${CUR_DIR_PATH} -Wl,-rpath=${CUR_DIR_PATH}/output \
	-o ./libsctop.so

clean:
	-rm -rf output *.so

