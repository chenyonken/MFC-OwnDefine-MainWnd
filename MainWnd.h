#if !defined(AFX_MAINWND_H__E4CCBDA4_E274_4731_A199_87A1256A4B00__INCLUDED_)
#define AFX_MAINWND_H__E4CCBDA4_E274_4731_A199_87A1256A4B00__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MainWnd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMainWnd window
#include "ItemResize.h"

class CMainWnd : public CWnd
{
// Construction
public:
	CStatic m_st1,m_st2,m_st3;
	CEdit m_numb,m_name;
	CComboBox m_dept;
	CListCtrl m_list;
	CButton m_add,m_del,m_mod;
	CToolTipCtrl m_tip;
	CRect m_rect;//保存对话框初始大小
	CItemResize m_itemSize;
	enum {
		IDC_STATIC1=1234,
		IDC_STATIC2,
		IDC_STATIC3,
		IDC_NUMB,
		IDC_NAME,
		IDC_COMBO,
		IDC_ADD,
		IDC_DEL,
		IDC_MOD,
		IDC_LIST
	};

public:
	CMainWnd();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainWnd)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL SetTipText( UINT id,NMHDR* pTTTStruct,LRESULT * pResult );
	void OnMod();
	void OnDel();
	void OnAdd();
	void CreateCtrl();
	virtual ~CMainWnd();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMainWnd)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINWND_H__E4CCBDA4_E274_4731_A199_87A1256A4B00__INCLUDED_)
