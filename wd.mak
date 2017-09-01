# Microsoft Developer Studio Generated NMAKE File, Based on wd.dsp
!IF "$(CFG)" == ""
CFG=wd - Win32 Debug
!MESSAGE No configuration specified. Defaulting to wd - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "wd - Win32 Release" && "$(CFG)" != "wd - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "wd.mak" CFG="wd - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "wd - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "wd - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "wd - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\wd.exe"


CLEAN :
	-@erase "$(INTDIR)\ItemResize.obj"
	-@erase "$(INTDIR)\MainWnd.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\wd.obj"
	-@erase "$(INTDIR)\wd.pch"
	-@erase "$(INTDIR)\wd.res"
	-@erase "$(OUTDIR)\wd.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\wd.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\wd.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\wd.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\wd.pdb" /machine:I386 /out:"$(OUTDIR)\wd.exe" 
LINK32_OBJS= \
	"$(INTDIR)\MainWnd.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\wd.obj" \
	"$(INTDIR)\wd.res" \
	"$(INTDIR)\ItemResize.obj"

"$(OUTDIR)\wd.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "wd - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\wd.exe" "$(OUTDIR)\wd.bsc"


CLEAN :
	-@erase "$(INTDIR)\ItemResize.obj"
	-@erase "$(INTDIR)\ItemResize.sbr"
	-@erase "$(INTDIR)\MainWnd.obj"
	-@erase "$(INTDIR)\MainWnd.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\wd.obj"
	-@erase "$(INTDIR)\wd.pch"
	-@erase "$(INTDIR)\wd.res"
	-@erase "$(INTDIR)\wd.sbr"
	-@erase "$(OUTDIR)\wd.bsc"
	-@erase "$(OUTDIR)\wd.exe"
	-@erase "$(OUTDIR)\wd.ilk"
	-@erase "$(OUTDIR)\wd.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\wd.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\wd.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\wd.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\MainWnd.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\wd.sbr" \
	"$(INTDIR)\ItemResize.sbr"

"$(OUTDIR)\wd.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\wd.pdb" /debug /machine:I386 /out:"$(OUTDIR)\wd.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\MainWnd.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\wd.obj" \
	"$(INTDIR)\wd.res" \
	"$(INTDIR)\ItemResize.obj"

"$(OUTDIR)\wd.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("wd.dep")
!INCLUDE "wd.dep"
!ELSE 
!MESSAGE Warning: cannot find "wd.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "wd - Win32 Release" || "$(CFG)" == "wd - Win32 Debug"
SOURCE=.\ItemResize.cpp

!IF  "$(CFG)" == "wd - Win32 Release"


"$(INTDIR)\ItemResize.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wd.pch"


!ELSEIF  "$(CFG)" == "wd - Win32 Debug"


"$(INTDIR)\ItemResize.obj"	"$(INTDIR)\ItemResize.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wd.pch"


!ENDIF 

SOURCE=.\MainWnd.cpp

!IF  "$(CFG)" == "wd - Win32 Release"


"$(INTDIR)\MainWnd.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wd.pch"


!ELSEIF  "$(CFG)" == "wd - Win32 Debug"


"$(INTDIR)\MainWnd.obj"	"$(INTDIR)\MainWnd.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wd.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "wd - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\wd.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\wd.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "wd - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\wd.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\wd.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\wd.cpp

!IF  "$(CFG)" == "wd - Win32 Release"


"$(INTDIR)\wd.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wd.pch"


!ELSEIF  "$(CFG)" == "wd - Win32 Debug"


"$(INTDIR)\wd.obj"	"$(INTDIR)\wd.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\wd.pch"


!ENDIF 

SOURCE=.\wd.rc

"$(INTDIR)\wd.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)



!ENDIF 

