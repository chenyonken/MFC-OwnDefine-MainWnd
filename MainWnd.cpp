// MainWnd.cpp : implementation file
//

#include "stdafx.h"
#include "wd.h"
#include "MainWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainWnd

CMainWnd::CMainWnd()
{
}

CMainWnd::~CMainWnd()
{
}


BEGIN_MESSAGE_MAP(CMainWnd, CWnd)
	ON_BN_CLICKED(IDC_ADD,OnAdd)
	ON_BN_CLICKED(IDC_DEL,OnDel)
	ON_BN_CLICKED(IDC_MOD,OnMod)
	ON_NOTIFY_EX(TTN_NEEDTEXT,0,SetTipText)
	//{{AFX_MSG_MAP(CMainWnd)
	ON_WM_CREATE()
	ON_WM_CTLCOLOR()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CMainWnd message handlers

void CMainWnd::PostNcDestroy() 
{
	// TODO: Add your specialized code here and/or call the base class
	delete this;	
	CWnd::PostNcDestroy();
}

void CMainWnd::CreateCtrl()
{
	CFont* pFont=CFont::FromHandle((HFONT)GetStockObject(DEFAULT_GUI_FONT));
	m_st1.CWnd::CreateEx(0,_T("STATIC"),_T("工号"),WS_VISIBLE|WS_CHILD,
		CRect(11,11,48,23),this,IDC_STATIC1);
	m_st1.SetFont(pFont);
	
	
	m_numb.CWnd::CreateEx(WS_EX_CLIENTEDGE|WS_EX_STATICEDGE,_T("EDIT"),_T(""),ES_AUTOHSCROLL|WS_VISIBLE|WS_CHILD|WS_TABSTOP,
		CRect(57,11,137,30),this,IDC_NUMB);
	m_numb.SetFont(pFont);

	m_st2.CWnd::CreateEx(0,_T("STATIC"),_T("姓名"),WS_VISIBLE|WS_CHILD,
		CRect(146,11,183,23),this,IDC_STATIC2);
	m_st2.SetFont(pFont);

	m_name.CWnd::CreateEx(WS_EX_CLIENTEDGE|WS_EX_STATICEDGE,_T("EDIT"),_T(""),WS_VISIBLE|WS_CHILD|WS_TABSTOP,
		CRect(192,11,272,30),this,IDC_NAME);
	m_name.SetFont(pFont);

	m_st3.CWnd::CreateEx(0,_T("STATIC"),_T("部门"),WS_VISIBLE|WS_CHILD,
		CRect(285,11,321,23),this,IDC_STATIC3);
	m_st3.SetFont(pFont);

	m_dept.CWnd::CreateEx(WS_EX_CLIENTEDGE|WS_EX_STATICEDGE,_T("COMBOBOX"),_T(""),CBS_DROPDOWNLIST|WS_VISIBLE|WS_CHILD|WS_TABSTOP,
		CRect(321,11,414,188),this,IDC_COMBO);
	m_dept.SetFont(pFont);

	m_add.CWnd::CreateEx(WS_EX_CLIENTEDGE|WS_EX_DLGMODALFRAME,_T("BUTTON"),_T("添加"),WS_VISIBLE|WS_CHILD|WS_TABSTOP,
		CRect(11,36,86,65),this,IDC_ADD);
	m_add.SetFont(pFont);


	m_del.CWnd::CreateEx(WS_EX_CLIENTEDGE,_T("BUTTON"),_T("删除"),WS_VISIBLE|WS_CHILD|WS_TABSTOP,
	CRect(98,36,173,65),this,IDC_DEL);
	m_del.SetFont(pFont);

	m_mod.CWnd::CreateEx(WS_EX_CLIENTEDGE|WS_EX_DLGMODALFRAME,_T("BUTTON"),_T("修改"),WS_VISIBLE|WS_CHILD|WS_TABSTOP,
		CRect(185,36,260,65),this,IDC_MOD);
	m_mod.SetFont(pFont);

//	m_list.CreateEx(WS_EX_CLIENTEDGE,WC_LISTVIEW,NULL,LVS_REPORT|LVS_SHOWSELALWAYS|
//		WS_VISIBLE|WS_CHILD|WS_TABSTOP,CRect(11,65,429,342),this,IDC_LIST);

	m_list.CWnd::CreateEx(WS_EX_CLIENTEDGE|WS_EX_DLGMODALFRAME,_T("SysListView32"),NULL,LVS_REPORT|WS_VISIBLE|WS_CHILD|WS_TABSTOP,
		CRect(11,67,417,342),this,IDC_LIST);
	m_list.SetFont(pFont);



}

int CMainWnd::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	//父窗口创建完毕，创建子窗口
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	CreateCtrl();


	m_list.InsertColumn(0,_T("工号"),0,100);
	m_list.InsertColumn(1,_T("姓名"),0,100);
	m_list.InsertColumn(2,_T("部门"),0,100);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT |LVS_EX_GRIDLINES);

	m_dept.AddString(_T("请选择部门"));
	m_dept.AddString(_T("技术部"));
	m_dept.AddString(_T("营销部"));
	m_dept.AddString(_T("公共部"));
	m_dept.SetCurSel(0);


	m_tip.Create(this);
	EnableToolTips(TRUE);
	m_tip.SetMaxTipWidth(500);
	m_tip.SetTipBkColor(RGB(210,210,255));
	m_tip.SetTipTextColor(RGB(0,106,53));
	m_tip.SetDelayTime(TTDT_INITIAL,100);
	m_tip.AddTool(&m_numb,_T("请填入工号"));
	m_tip.AddTool(&m_name,_T("请填入姓名"));
	m_tip.AddTool(&m_dept,_T("请填入部门"));
	m_tip.AddTool(&m_list);


	m_itemSize.AddItemRect(IDC_NUMB,this);
	m_itemSize.AddItemRect(IDC_NAME,this);
//	m_itemSize.AddItemRect(IDC_COMBO,this);//不知道什么原因有了这一句之后，ComboBOx就显示不出东西
	m_itemSize.AddItemRect(IDC_ADD,this);
	m_itemSize.AddItemRect(IDC_DEL,this);
	m_itemSize.AddItemRect(IDC_MOD,this);
	m_itemSize.AddItemRect(IDC_LIST,this);
	m_itemSize.AddItemRect(IDC_STATIC1,this);
	m_itemSize.AddItemRect(IDC_STATIC2,this);
	m_itemSize.AddItemRect(IDC_STATIC3,this);

	GetClientRect(&m_rect);

	return TRUE;
}

HBRUSH CMainWnd::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CWnd::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	pDC->SetBkMode(TRANSPARENT);
	switch(pWnd->GetDlgCtrlID())
	{
	case IDC_STATIC1:
	case IDC_STATIC2:
	case IDC_STATIC3:
		{
			pDC->SetTextColor(RGB(0,255,0));
			return (HBRUSH)GetStockObject(NULL_BRUSH);
		}
	case IDC_NUMB:
		{
			pDC->SetTextColor(RGB(0,0,255));
			return (HBRUSH)GetStockObject(NULL_BRUSH);
		}
		
	}
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CMainWnd::OnAdd()
{
	int nSel=m_dept.GetCurSel();
	if(nSel<1)
	{
		AfxMessageBox("请选择部门再添加");
		return;
	}
	int nCount=m_list.GetItemCount();
	CString str;
	GetDlgItemText(IDC_NUMB,str);
	m_list.InsertItem(nCount,str);
	GetDlgItemText(IDC_NAME,str);
	m_list.SetItemText(nCount,1,str);
	m_dept.GetLBText(nSel,str);
	m_list.SetItemText(nCount,2,str);
	m_list.SetSelectionMark(-1);
	Invalidate(FALSE);
}

void CMainWnd::OnDel()
{
	int nSel=m_list.GetSelectionMark();
	if(nSel<0)
	{
		AfxMessageBox(_T("请选择一个用户信息再删除"));
		return;
	}
	CString str=m_list.GetItemText(nSel,0);
	str=_T("确定要删除编号为: "+str+"信息吗?");
	if(AfxMessageBox(str,MB_YESNO)==IDYES)
		m_list.DeleteItem(nSel);
}

void CMainWnd::OnMod()
{
	int nSel=m_list.GetSelectionMark();
	if(nSel<0)
	{
		AfxMessageBox(_T("请选择一个用户信息再修改"));
		return;
	}

	CString str=m_list.GetItemText(nSel,0);
	str=_T("确定要修改编号为: "+str+"信息吗?");
	if(AfxMessageBox(str,MB_YESNO)==IDNO)
		return;
	GetDlgItemText(IDC_NAME,str);
	m_list.SetItemText(nSel,1,str);
	m_dept.GetWindowText(str);
	m_list.SetItemText(nSel,2,str);
	m_list.SetSelectionMark(-1);
}

BOOL CMainWnd::SetTipText(UINT id, NMHDR *pTTTStruct, LRESULT *pResult)
{
   TOOLTIPTEXT *pTTT = (TOOLTIPTEXT *)pTTTStruct;
    UINT nID =pTTTStruct->idFrom;
    if (pTTT->uFlags & TTF_IDISHWND)
    {
		if(pTTT ->uFlags==3)//如果没有这一句，
			return TRUE;
        // idFrom is actually the HWND of the tool
        nID = ::GetDlgCtrlID((HWND)nID);
        switch(nID)
        {
		case IDC_LIST:
			if(!m_list.GetSelectedCount())
			{
				strcpy(pTTT->lpszText,_T("未选择信息"));
				return TRUE;
			}
			int nSel=m_list.GetSelectionMark();
			CString  str;
			str.Format("选择的员工信息:\r\n工号:%s \r\n姓名:%s \r\n部门:%s",
				m_list.GetItemText(nSel,0),
				m_list.GetItemText(nSel,1),
				m_list.GetItemText(nSel,2));
			strcpy(pTTT->lpszText,str);
			return TRUE;

        }
    }
    return(FALSE);
}

BOOL CMainWnd::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	m_tip.RelayEvent(pMsg);
	return CWnd::PreTranslateMessage(pMsg);
}

void CMainWnd::OnSize(UINT nType, int cx, int cy) 
{
	CWnd::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	m_itemSize.ResizeItem();
	Invalidate(FALSE);


}

//DEL void CMainWnd::ChangeSize(UINT nID, int cx, int cy)
//DEL {
//DEL 	CWnd *pWnd;
//DEL 	pWnd=GetDlgItem(nID);
//DEL 	if(pWnd!=NULL)
//DEL 	{
//DEL 		CRect rect;  //获取控件变化前大小
//DEL //		LONG cWidth,cHeight; //记录控件的右部到窗体右部的距离，记录控件的底部到窗体底部的距离
//DEL 		pWnd->GetWindowRect(&rect);
//DEL 		ScreenToClient(&rect);//将控件大小转换为在对话框中的区域坐标
//DEL 		rect.left=rect.left*cx/m_rect.Width();
//DEL 		rect.right=rect.right*cx/m_rect.Width();
//DEL 		rect.top=rect.top*cy/m_rect.Height();
//DEL 		rect.bottom=rect.bottom*cy/m_rect.Height();
//DEL 		pWnd->MoveWindow(rect);
//DEL 	}
//DEL //	GetClientRect(&m_rect);//将变化后的对话框大小设为旧大小
//DEL }
