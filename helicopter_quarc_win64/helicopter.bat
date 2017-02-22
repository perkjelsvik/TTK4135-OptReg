@echo on
call "C:\Program Files\Microsoft SDKs\Windows\v7.1\Bin\SetEnv.cmd" /x64 /Release 2>1 > nul:
set MATLAB=C:\PROGRA~1\MATLAB\R2014a
nmake -f helicopter.mk  MAT_FILE=0 SHOW_TIMES=0 DEBUG=0 DEBUG_HEAP=0 OPTS="-DON_TARGET_WAIT_FOR_START=0"
