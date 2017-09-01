// wd.h : main header file for the WD application
//

#if !defined(AFX_WD_H__3451A93E_4D1A_46E3_9FAF_8803E145F0DD__INCLUDED_)
#define AFX_WD_H__3451A93E_4D1A_46E3_9FAF_8803E145F0DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWdApp:
// See wd.cpp for the implementation of this class
//

class CWdApp : public CWinApp
{
public:
	CWdApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWdApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWdApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WD_H__3451A93E_4D1A_46E3_9FAF_8803E145F0DD__INCLUDED_)
