#!/bin/tcsh -f
setenv MATLAB_HOME /usr/local/MATLAB/R2022b
setenv LD_LIBRARY_PATH ${MATLAB_HOME}/runtime/glnxa64:${MATLAB_HOME}/bin/glnxa64:${MATLAB_HOME}/extern/bin/glnxa64:${MATLAB_HOME}/sys/os/glnxa64:${MATLAB_HOME}/sys/opengl/lib/glnxa64:${LD_LIBRARY_PATH}
