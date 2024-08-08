CUR_DIR_PATH := $(shell echo $(CURDIR))

all: matlab_gen gen_lib

matlab_gen:
	${MATLAB_HOME}/bin/mcc -W cpplib:libRGB888_to_YCbCr444 RGB888_to_YCbCr444.m  -g -d output/

gen_lib:
	g++ -shared -fPIC -g -Wno-write-strings \
	-Ioutput -I${VCS_HOME}/include -Isrc_cpp -I${MATLAB_HOME}/extern/include \
	-lmwmclmcrrt -L${MATLAB_HOME}/runtime/glnxa64 \
	-lRGB888_to_YCbCr444 -Loutput \
	-Wl,-rpath=${CUR_DIR_PATH} -Wl,-rpath=${CUR_DIR_PATH}/output \
	./src_cpp/RGB888_to_YCbCr444_common.cpp \
	./src_cpp/RGB888_to_YCbCr444_dpi.cpp \
	-o libRGB888_to_YCbCr444_sim.so

clean:
	-rm -rf output *.so
