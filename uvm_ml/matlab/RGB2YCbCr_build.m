i= getenv("PRJ_HOME")
p = fullfile(i)
addpath(p)
mcc -W cpplib:libRGB888_to_YCbCr444 -T link:lib RGB888_to_YCbCr444.m -C
