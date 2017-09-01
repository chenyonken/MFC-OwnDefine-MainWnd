// wd.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "wd.h"
#include "wdDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWdApp

BEGIN_MESSAGE_MAP(CWdApp, CWinApp)
	//{{AFX_MSG_MAP(CWdApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWdApp construction

CWdApp::CWdApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CWdApp object

CWdApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CWdApp initialization

BOOL CWdApp::InitInstance()
{

	CWnd* pWnd=new CMainWnd;
	m_pMainWnd=pWnd;
	LPCTSTR szclassname="MyWnd";
	WNDCLASS wc={0};
	wc.style=CS_HREDRAW|CS_VREDRAW;
	wc.lpfnWndProc=::DefWindowProc;
	wc.cbClsExtra=0;
	wc.cbWndExtra=0;
	wc.hInstance=AfxGetInstanceHandle();
	wc.hIcon=(HICON)LoadIcon(IDR_MAINFRAME);
	wc.hCursor=(HCURSOR)(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	wc.hbrBackground=(HBRUSH)::GetStockObject(GRAY_BRUSH);
	wc.lpszMenuName=NULL;
	wc.lpszClassName=szclassname;
	RegisterClass(&wc);
	pWnd->CreateEx(WS_EX_OVERLAPPEDWINDOW,szclassname,"≤‚ ‘CWnd::CreateEx",WS_OVERLAPPEDWINDOW|WS_VISIBLE,
		0,0,450,400,NULL,0);
	return TRUE;
}
