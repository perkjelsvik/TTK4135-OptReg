# Copyright 2008 Quanser, Inc.
#
# File    : quarc_win64.tmf   $Revision: 1.0 $
#
# Abstract:
#       Real-Time Workshop template makefile for building a standalone
#       QUARC real-time version of a Simulink model using generated
#       C code and the Microsoft Visual C/C++ compiler versions: 6.0, 7.1
#
#       Note that this template is automatically customized by the Real-Time
#       Workshop build procedure to create "<model>.mk"
#
#       The following defines can be used to modify the behavior of the
#       build:
#
#         OPT_OPTS       - Optimization option. Default is -O2. To enable
#                          debugging specify as OPT_OPTS=-Zd.
#         OPTS           - User specific options.
#         CPP_OPTS       - C++ compiler options.
#         USER_SRCS      - Additional user sources, such as files needed by
#                          S-functions.
#         USER_INCLUDES  - Additional include paths
#                          (i.e. USER_INCLUDES="-Iwhere-ever -Iwhere-ever2")
#
#       This template makefile is designed to be used with a system target
#       file that contains 'rtwgensettings.BuildDirSuffix' see grt.tlc


#------------------------ Macros read by make_rtw -----------------------------
#
# The following macros are read by the Real-Time Workshop build procedure:
#
#  MAKECMD             - This is the command used to invoke the make utility
#  HOST                - What platform this template makefile is targeted for
#                        (i.e. PC or UNIX)
#  BUILD               - Invoke make from the Real-Time Workshop build procedure
#                        (yes/no)?
#  SYS_TARGET_FILE     - Name of system target file.
#  BUILD_SUCCESS       - String that is used to indicate that the build succeeded
#  COMPILER_TOOL_CHAIN - Compiler suite that is used to compile the code

MAKECMD             = nmake
HOST                = PC
BUILD               = yes
SYS_TARGET_FILE     = quarc_win64.tlc
BUILD_SUCCESS	    = ^#^#^# Created
COMPILER_TOOL_CHAIN = vcx64

#---------------------- Tokens expanded by make_rtw ---------------------------
#
# The following tokens, when wrapped with "|>" and "<|" are expanded by the
# Real-Time Workshop build procedure.
#
#  MODEL_NAME          - Name of the Simulink block diagram
#  MODEL_MODULES       - Any additional generated source modules
#  MAKEFILE_NAME       - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT         - Path to were MATLAB is installed.
#  MATLAB_BIN          - Path to MATLAB executable.
#  ALT_MATLAB_ROOT     - Alternate path to were MATLAB is installed. Used when MATLAB_ROOT contains spaces.
#  ALT_MATLAB_BIN      - Alternate path to MATLAB executable. Used when MATLAB_BIN contains spaces.
#  S_FUNCTIONS         - List of S-functions.
#  S_FUNCTIONS_LIB     - List of S-functions libraries to link.
#  SOLVER              - Solver source file name
#  NUMST               - Number of sample times
#  TID01EQ             - yes (1) or no (0): Are sampling rates of continuous task
#                        (tid=0) and 1st discrete task equal.
#  NCSTATES            - Number of continuous states
#  BUILDARGS           - Options passed in at the command line.
#  MULTITASKING        - yes (1) or no (0): Is solver mode multitasking
#  MAT_FILE            - yes (1) or no (0): generate a model.mat file?
#  EXT_MODE            - yes (1) or no (0): Build for external mode
#  TMW_EXTMODE_TESTING - yes (1) or no (0): Build ext_test.c for external mode
#                        testing.
#  EXTMODE_TRANSPORT   - Index of transport mechanism (e.g. tcpip, serial) for extmode
#  EXTMODE_STATIC      - yes (1) or no (0): Use static instead of dynamic mem alloc.
#  EXTMODE_STATIC_SIZE - Size of static memory allocation buffer.
#  RELEASE_VERSION     - The release version of MATLAB.
#
#  MODELREFS           - A list of the referenced model names.
#
#  MODELLIB                - The name of the library generated for the model.
#  MODELREF_LINK_LIBS      - A list of referenced model libraries that the top-level model links against.
#  MODELREF_INC_PATH       - The include path to the referenced models.
#  RELATIVE_PATH_TO_ANCHOR - The relative path from the location of the generated makefile to the MATLAB working directory.
#  MODELREF_TARGET_TYPE    - The type of target being built. Possible values are:
#                              NONE - standalone model or top-level model referencing other models.
#                              RTW  - model reference Real-Time Workshop target build.
#                              SIM  - model reference simulation target build.
#


MODEL                = Task_10_3
MODULES              = Task_10_3_data.c Task_10_3_main.c rtGetInf.c rtGetNaN.c rt_nonfinite.c 
MAKEFILE             = Task_10_3.mk
MATLAB_ROOT          = C:\Program Files\MATLAB\R2014a
ALT_MATLAB_ROOT      = C:\PROGRA~1\MATLAB\R2014a
MATLAB_BIN           = C:\Program Files\MATLAB\R2014a\bin
ALT_MATLAB_BIN       = C:\PROGRA~1\MATLAB\R2014a\bin
S_FUNCTIONS          = rtiostream_utils.c
S_FUNCTIONS_LIB      = C:\PROGRA~1\Quanser\QUARC\lib\win64\hil.lib C:\PROGRA~1\Quanser\QUARC\lib\win64\QUDCFC~1.LIB C:\PROGRA~1\Quanser\QUARC\lib\win64\QUANSE~4.LIB
SOLVER               = 
NUMST                = 2
TID01EQ              = 1
NCSTATES             = 4
COMPUTER             = PCWIN64
BUILDARGS            =  MAT_FILE=0 SHOW_TIMES=0 DEBUG=0 DEBUG_HEAP=0 OPTS="-DON_TARGET_WAIT_FOR_START=0"
MULTITASKING         = 0
EXT_MODE             = 1
TMW_EXTMODE_TESTING  = 0
EXTMODE_TRANSPORT    = 0
EXTMODE_STATIC       = 0
EXTMODE_STATIC_SIZE  = 1000000
RELEASE_VERSION      = R2014a

MODELREFS            = 
SHARED_SRC           = 
SHARED_SRC_DIR       = 
SHARED_BIN_DIR       = 
SHARED_LIB           = 
TARGET_LANG_EXT      = c

#--------------------------- Model and reference models -----------------------
MODELLIB                  = Task_10_3lib.lib
MODELREF_LINK_LIBS        = 
MODELREF_LINK_RSPFILE     = Task_10_3_ref.rsp
MODELREF_INC_PATH         = 
RELATIVE_PATH_TO_ANCHOR   = ..
# NONE: standalone, SIM: modelref sim, RTW: modelref rtw
MODELREF_TARGET_TYPE      = NONE

#-- Support for parallel builds
START_DIR         = C:\Users\kjetisg\Desktop\InitFiles
MASTER_ANCHOR_DIR = 

#-- Support multi-instance code
MULTI_INSTANCE_CODE  = 0

#-- In the case when directory name contains space ---
!if "$(MATLAB_ROOT)" != "$(ALT_MATLAB_ROOT)"
MATLAB_ROOT = $(ALT_MATLAB_ROOT)
!endif
!if "$(MATLAB_BIN)" != "$(ALT_MATLAB_BIN)"
MATLAB_BIN = $(ALT_MATLAB_BIN)
!endif

#--------------------------- Additional options -------------------------------

ASSERTACTION = "Stop model with an error"
HAVESTDIO = 1

#--------------------------- Tool Specifications ------------------------------

APPVER=5.02
CPU=AMD64
!include $(QUARC)\include\vctools.mak

PERL = $(MATLAB_ROOT)\sys\perl\win32\bin\perl

#------------------------------ Include/Lib Path ------------------------------

MATLAB_INCLUDES =                    $(MATLAB_ROOT)\simulink\include
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\extern\include
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\src
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\rtw\c\src\ext_mode\common

# Additional file include paths (from rtwmakecfg.m functions)

MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(START_DIR)\Task_10_3_quarc_win64
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(START_DIR)
MATLAB_INCLUDES = $(MATLAB_INCLUDES);$(MATLAB_ROOT)\toolbox\coder\rtiostream\src\utils
MATLAB_INCLUDES = $(MATLAB_INCLUDES);C:\PROGRA~1\Quanser\QUARC\include

QUARC_INCLUDES = $(QUARC)\include

INCLUDE = .;$(RELATIVE_PATH_TO_ANCHOR);$(QUARC_INCLUDES);$(MATLAB_INCLUDES);$(ADD_INCLUDES);$(INCLUDE);$(MODELREF_INC_PATH)

!if "$(SHARED_SRC_DIR)" != ""
INCLUDE = $(INCLUDE);$(SHARED_SRC_DIR)
!endif

#------------------------ External mode ---------------------------------------
# Uncomment -DVERBOSE to have information printed to stdout
# To add a new transport layer, see the comments in
#   <matlabroot>/toolbox/simulink/simulink/extmode_transports.m
!if $(EXT_MODE) == 1
EXT_CC_OPTS = -DEXT_MODE -DMODEL_URI="$(MODEL_URI)" -DVERBOSE
!if $(EXTMODE_TRANSPORT) == 0 #quarc_comm
EXT_SRC =
EXT_LIB = extmode_quarc_r2013b.lib quanser_communications.lib          
!endif
!if $(TMW_EXTMODE_TESTING) == 1
EXT_SRC     = $(EXT_SRC) ext_test.c
EXT_CC_OPTS = $(EXT_CC_OPTS) -DTMW_EXTMODE_TESTING
!endif
!if $(EXTMODE_STATIC) == 1
EXT_SRC     = $(EXT_SRC) mem_mgr.c
EXT_CC_OPTS = $(EXT_CC_OPTS) -DEXTMODE_STATIC -DEXTMODE_STATIC_SIZE=$(EXTMODE_STATIC_SIZE)
!endif
!else
EXT_SRC     =
EXT_CC_OPTS =
EXT_LIB     =
!endif

#
# .mat File Logging
#
!if "$(MAT_FILE)" == "1"
LOG_OPTS  = -DMAT_FILE
!endif

#------------------------ rtModel ----------------------------------------------

RTM_CC_OPTS = -DUSE_RTMODEL

#----------------- Compiler and Linker Options --------------------------------

# Optimization Options. The DEFAULT_OPT_OPTS macro depends on the build configuration.
OPT_OPTS = $(DEFAULT_OPT_OPTS)

# General User Options
OPTS =

CC_OPTS = $(OPT_OPTS) $(OPTS) $(EXT_CC_OPTS) $(LOG_OPTS) $(RTM_CC_OPTS) /wd4100

# msvcprt.lib is the multi--threaded, dynamic lib version of the C++ standard lib
# msvcprtd.lib is the multi--threaded, dynamic debug lib version of the C++ standard lib
# /EHsc enables exception handling (needed to use C++ standard lib)

!if "$(DEBUG)" == "1"
OPT_DEFINES =
CPP_LIB = msvcprtd.lib
!else
OPT_DEFINES = -DNDEBUG
CPP_LIB = msvcprt.lib
!endif

ACTION = $(ASSERTACTION:"Ignore"=0)
ACTION = $(ACTION:"Stop model with an error"=1)
ACTION = $(ACTION:"Print assertion"=2)

ASSERT_DEFINES = -DASSERTIONS=$(ACTION)
!if $(ACTION) > 0
ASSERT_DEFINES = $(ASSERT_DEFINES) -DDOASSERTS
!endif

!if $(HAVESTDIO)
STDIO_DEFINES = -DHAVESTDIO
!else
STDIO_DEFINES =
!endif

CPP_REQ_DEFINES = -DMODEL=$(MODEL) -DRT -DNUMST=$(NUMST) \
		  -DTID01EQ=$(TID01EQ) -DNCSTATES=$(NCSTATES) \
		  -DMULTITASKING=$(MULTITASKING) $(STDIO_DEFINES) \
		  -DVXWORKS -DQUARC -DTARGET_TYPE=win64 \
		  -D_CRT_SECURE_NO_DEPRECATE $(ASSERT_DEFINES) \
		  -DMULTI_INSTANCE_CODE=$(MULTI_INSTANCE_CODE) \
		  $(OPT_DEFINES)

!if "$(DEBUG)" == "1"
NODEFAULTFLAGS = /NODEFAULTLIB:libc.lib /NODEFAULTLIB:libcmt.lib /NODEFAULTLIB:msvcrt.lib \
                 /NODEFAULTLIB:libcd.lib /NODEFAULTLIB:libcmtd.lib /NODEFAULTLIB:msvcprt.lib
!else
NODEFAULTFLAGS = /NODEFAULTLIB:libc.lib /NODEFAULTLIB:libcmt.lib /NODEFAULTLIB:msvcrtd.lib \
                 /NODEFAULTLIB:libcd.lib /NODEFAULTLIB:libcmtd.lib /NODEFAULTLIB:msvcprtd.lib
!endif

# Uncomment this line to leave warning level at W4
cflags = $(cflags:W4=W3)

# Remove the -Wp64 flag since it is deprecated and the 64-bit compiler checks by default
cflags = $(cflags:-Wp64=)

CFLAGS   = $(CC_OPTS) $(CPP_REQ_DEFINES) $(USER_INCLUDES) \
	   $(cflags) $(cvarsdll) $(CFLAGS_VERSPECIFIC)
CPPFLAGS = $(CPP_OPTS) $(CC_OPTS) $(CPP_REQ_DEFINES) $(USER_INCLUDES) \
	   $(cflags) $(cvarsdll) $(CPPFLAGS_VERSPECIFIC)
LDFLAGS  = $(ldebug) $(conlflags) $(NODEFAULTFLAGS) $(EXT_LIB) $(conlibs) $(CPP_LIB) winmm.lib

#----------------------------- Source Files -----------------------------------


# Standalone executable
!if "$(MODELREF_TARGET_TYPE)" == "NONE"
PRODUCT   = $(RELATIVE_PATH_TO_ANCHOR)\$(MODEL)$(TARGET_EXT)

REQ_SRCS  = $(MODEL).$(TARGET_LANG_EXT) $(MODULES) \
            rt_sim.c $(EXT_SRC) $(SOLVER)

# Model Reference Target
!else
PRODUCT   = $(MODELLIB)
REQ_SRCS  = $(MODULES) $(EXT_SRC)
!endif

USER_SRCS =

SRCS = $(REQ_SRCS) $(USER_SRCS) $(S_FUNCTIONS)
OBJS_CPP_UPPER = $(SRCS:.CPP=.obj)
OBJS_CPP_LOWER = $(OBJS_CPP_UPPER:.cpp=.obj)
OBJS_C_UPPER = $(OBJS_CPP_LOWER:.C=.obj)
OBJS = $(OBJS_C_UPPER:.c=.obj)
SHARED_OBJS = $(SHARED_SRC:.c=.obj)

# ------------------------- Additional Object Files ---------------------------

#QUARC_OBJS = "$(QUARC)\lib\quarc_entry.obj"

# ------------------------- Additional Libraries ------------------------------

# Set library search path
LIB = $(QUARC)\lib\win64;$(LIB)

# Set QUARC libraries
QUARC_LIBS = quanser_runtime.lib quanser_common.lib shell32.lib

!if "$(OPT_OPTS)" == "$(DEFAULT_OPT_OPTS)"
LIBS = 
!else
LIBS = 
!endif

# See rtwmakecfg.m documentation

LIBS = $(LIBS)

# ---------------------------- Linker Script ----------------------------------

CMD_FILE = $(MODEL).lk
GEN_LNK_SCRIPT = $(MATLAB_ROOT)\rtw\c\tools\mkvc_lnk.pl

!if "$(DEBUG)" == "1"
MANIFEST_BASENAME=$(MODEL).Debug
!else
MANIFEST_BASENAME=$(MODEL)
!endif

#--------------------------------- Rules --------------------------------------
all: set_environment_variables $(PRODUCT)

!if "$(MODELREF_TARGET_TYPE)" == "NONE"
#--- Stand-alone model ---
$(PRODUCT) : $(OBJS) $(SHARED_LIB) $(LIBS) $(MODELREF_LINK_LIBS) $(MANIFEST_BASENAME).auto.res
	@echo ### Linking ...
	"$(PERL)" "$(GEN_LNK_SCRIPT)" $(CMD_FILE) $(OBJS) $(MODELREF_LINK_LIBS)
	$(LD) $(LDFLAGS) /MANIFESTFILE:$(MODEL).manifest $(QUARC_OBJS) $(S_FUNCTIONS_LIB) $(SHARED_LIB) $(LIBS) $(MAT_LIBS) @$(CMD_FILE) @$(MODELREF_LINK_RSPFILE) $(QUARC_LIBS) $(CRT_LIB) -out:$@
	@if exist $(MODEL).manifest \
		$(MT) -nologo -manifest $(MODEL).manifest -out:$(MANIFEST_BASENAME).auto.manifest \
		& if "%ERRORLEVEL%" == "0" \
			$(RC) /r $(MANIFEST_BASENAME).auto.rc \
			& $(LD) $(LDFLAGS) /MANIFESTFILE:$(MODEL).manifest $(QUARC_OBJS) $(S_FUNCTIONS_LIB) $(SHARED_LIB) $(LIBS) $(MAT_LIBS) @$(CMD_FILE) @$(MODELREF_LINK_RSPFILE) $(QUARC_LIBS) $(CRT_LIB) $(MANIFEST_BASENAME).auto.res -out:$@
	@del $(CMD_FILE)
	@echo $(BUILD_SUCCESS) executable $(MODEL)$(TARGET_EXT)
!else
#--- Model reference RTW Target ---
$(PRODUCT) : $(OBJS) $(SHARED_LIB) $(LIBS)
	@echo ### Linking ...
	"$(PERL)" "$(GEN_LNK_SCRIPT)" $(CMD_FILE) $(OBJS)
	$(LD) -lib /OUT:$(MODELLIB) @$(CMD_FILE) $(S_FUNCTIONS_LIB)
	@echo $(BUILD_SUCCESS) static library $(MODELLIB)
!endif

{$(MATLAB_ROOT)\rtw\c\src}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src\ext_mode\common}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src\ext_mode\tcpip}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src\ext_mode\serial}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src\ext_mode\custom}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

# Additional sources. See rtwmakecfg.m documentation.

{$(MATLAB_ROOT)\rtw\c\src}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\simulink\src}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src\ext_mode\common}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\toolbox\coder\rtiostream\src\utils}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<



{$(MATLAB_ROOT)\rtw\c\src}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\simulink\src}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\rtw\c\src\ext_mode\common}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

{$(MATLAB_ROOT)\toolbox\coder\rtiostream\src\utils}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<



# Look in simulink/src helper files

{$(MATLAB_ROOT)\simulink\src}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

{$(MATLAB_ROOT)\simulink\src}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

# Look in QUARC helper files

{$(QUARC)\quarc}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

{$(QUARC)\src}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

# Put these rule last, otherwise nmake will check toolboxes first

{$(RELATIVE_PATH_TO_ANCHOR)}.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

{$(RELATIVE_PATH_TO_ANCHOR)}.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

.c.obj :
	@echo ### Compiling $<
	$(CC) $(CFLAGS) $<

.cpp.obj :
	@echo ### Compiling $<
	$(CC) $(CPPFLAGS) $<

!if "$(SHARED_LIB)" != ""
$(SHARED_LIB) : $(SHARED_SRC)
	@echo ### Creating $@
	@$(CC) $(CFLAGS) -Fo$(SHARED_BIN_DIR)\ @<<
$?
<<
	@$(LIBCMD) /nologo /out:$@ $(SHARED_OBJS)
	@echo ### $@ Created
!endif


set_environment_variables:
	@set INCLUDE=$(INCLUDE)
	@set LIB=$(LIB)

# Libraries. See rtwmakecfg.m documentation.





#----------------------------- Dependencies -----------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw

$(MANIFEST_BASENAME).auto.res:	$(MANIFEST_BASENAME).auto.rc

$(MANIFEST_BASENAME).auto.rc:	$(MANIFEST_BASENAME).auto.manifest
	@type > nul: <<$@
#include <winuser.rh>
1 RT_MANIFEST "$(MANIFEST_BASENAME).auto.manifest"
<< KEEP

$(MANIFEST_BASENAME).auto.manifest:
	@type > nul: <<$@
<?xml version='1.0' encoding='UTF-8' standalone='yes'?>
<assembly xmlns='urn:schemas-microsoft-com:asm.v1' manifestVersion='1.0'>
  <ms_asmv2:trustInfo xmlns:ms_asmv2="urn:schemas-microsoft-com:asm.v2">
      <ms_asmv2:security>
         <ms_asmv2:requestedPrivileges>
            <ms_asmv2:requestedExecutionLevel level="asInvoker" uiAccess="false">
            </ms_asmv2:requestedExecutionLevel>
         </ms_asmv2:requestedPrivileges>
      </ms_asmv2:security>
   </ms_asmv2:trustInfo>
</assembly>
<< KEEP
	