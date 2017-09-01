; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainWnd
LastTemplate=generic CWnd
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "wd.h"

ClassCount=3
Class1=CWdApp
Class2=CWdDlg

ResourceCount=1
Resource1=IDR_MAINFRAME
Class3=CMainWnd

[CLS:CWdApp]
Type=0
HeaderFile=wd.h
ImplementationFile=wd.cpp
Filter=N

[CLS:CWdDlg]
Type=0
HeaderFile=wdDlg.h
ImplementationFile=wdDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC



[CLS:CMainWnd]
Type=0
HeaderFile=MainWnd.h
ImplementationFile=MainWnd.cpp
BaseClass=CWnd
Filter=W
VirtualFilter=WC
LastObject=CMainWnd

