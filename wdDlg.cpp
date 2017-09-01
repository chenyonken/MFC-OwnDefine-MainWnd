// wdDlg.cpp : implementation file
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
// CWdDlg dialog

CWdDlg::CWdDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWdDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWdDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWdDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWdDlg, CDialog)
	//{{AFX_MSG_MAP(CWdDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWdDlg message handlers

BOOL CWdDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CWdDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CWdDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
/*
 DWORD dwExStyle,
   LPCTSTR lpszClassName,
   LPCTSTR lpszWindowName,
   DWORD dwStyle,
   int x,
   int y,
   int nWidth,
   int nHeight,
   HWND hWndParent,
   HMENU nIDorHMenu,
   LPVOID lpParam = NULL 


virtual BOOL CreateEx(
   DWORD dwExStyle,
   LPCTSTR lpszClassName,
   LPCTSTR lpszWindowName,
   DWORD dwStyle,
   const RECT& rect,
   CWnd* pParentWnd,
   UINT nID,
   LPVOID lpParam = NULL
);
*/
void CWdDlg::CreateCtrl()
{
	CFont* pFont=CFont::FromHandle((HFONT)GetStockObject(DEFAULT_GUI_FONT));
	m_st1.CWnd::CreateEx(0,_T("STATIC"),_T("工号"),WS_VISIBLE|WS_CHILD,
		CRect(11,11,48,23),this,IDC_STATIC);
	m_st1.SetFont(pFont);
	
	m_numb.CWnd::CreateEx(0,_T("EDIT"),_T(""),WS_VISIBLE|WS_CHILD|WS_TABSTOP,
		CRect(57,11,137,30),this,IDC_NUMB);
	m_numb.SetFont(pFont);

	m_st2.CWnd::CreateEx(0,_T("STATIC"),_T("姓名"),WS_VISIBLE|WS_CHILD,
		CRect(146,11,183,23),this,IDC_STATIC);
	m_st2.SetFont(pFont);

	m_name.CWnd::CreateEx(0,_T("EDIT"),_T(""),WS_VISIBLE|WS_CHILD|WS_TABSTOP,
		CRect(146,11,183,23),this,IDC_NAME);
	m_name.SetFont(pFont);

	m_st3.CWnd::CreateEx(0,_T("STATIC"),_T("部门"),WS_VISIBLE|WS_CHILD,
		CRect(285,11,321,23),this,IDC_STATIC);
	m_st3.SetFont(pFont);

	m_dept.CWnd::CreateEx(0,_T("COMBOBOX"),_T(""),WS_VISIBLE|WS_CHILD|WS_TABSTOP,
		CRect(321,11,414,188),this,IDC_COMBO);
	m_dept.SetFont(pFont);

	m_add.CWnd::CreateEx(0,_T("BUTTON"),_T("添加"),WS_VISIBLE|WS_CHILD|WS_TABSTOP,
		CRect(11,36,86,58),this,IDC_ADD);
	m_add.SetFont(pFont);

	m_add.CWnd::CreateEx(0,_T("BUTTON"),_T("删除"),WS_VISIBLE|WS_CHILD|WS_TABSTOP,
	CRect(98,36,173,58),this,IDC_DEL);
	m_del.SetFont(pFont);

	m_add.CWnd::CreateEx(0,_T("BUTTON"),_T("修改"),WS_VISIBLE|WS_CHILD|WS_TABSTOP,
		CRect(185,36,260,58),this,IDC_MOD);
	m_mod.SetFont(pFont);

	m_list.CWnd::CreateEx(0,_T("LISTCTRL"),NULL,WS_VISIBLE|WS_CHILD|WS_TABSTOP,
		CRect(11,65,429,342),this,IDC_MOD);
	m_list.SetFont(pFont);





}

int CWdDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	CreateCtrl();
	return 0;
}
