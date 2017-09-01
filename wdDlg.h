// wdDlg.h : header file
//

#if !defined(AFX_WDDLG_H__294D125D_B738_46D3_8306_6B83AAC7190C__INCLUDED_)
#define AFX_WDDLG_H__294D125D_B738_46D3_8306_6B83AAC7190C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWdDlg dialog
#include "MainWnd.h"
class CWdDlg : public CDialog
{
// Construction
public:
	CStatic m_st1,m_st2,m_st3;
	CEdit m_numb,m_name;
	CComboBox m_dept;
	CListCtrl m_list;
	CButton m_add,m_del,m_mod;
	enum {
		IDC_NUMB=1234,
		IDC_NAME,
		IDC_COMBO,
		IDC_ADD,
		IDC_DEL,
		IDC_MOD,
		IDC_LIST
	};
public:
	void CreateCtrl();
	CWdDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWdDlg)
	enum { IDD = IDD_WD_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWdDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWdDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WDDLG_H__294D125D_B738_46D3_8306_6B83AAC7190C__INCLUDED_)
