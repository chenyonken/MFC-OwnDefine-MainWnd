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
	m_st1.CWnd::CreateEx(0,_T("STATIC"),_T("����"),WS_VISIBLE|WS_CHILD,
		CRect(11,11,48,23),this,IDC_STATIC1);
	m_st1.SetFont(pFont);
	
	
	m_numb.CWnd::CreateEx(WS_EX_CLIENTEDGE|WS_EX_STATICEDGE,_T("EDIT"),_T(""),ES_AUTOHSCROLL|WS_VISIBLE|WS_CHILD|WS_TABSTOP,
		CRect(57,11,137,30),this,IDC_NUMB);
	m_numb.SetFont(pFont);

	m_st2.CWnd::CreateEx(0,_T("STATIC"),_T("����"),WS_VISIBLE|WS_CHILD,
		CRect(146,11,183,23),this,IDC_STATIC2);
	m_st2.SetFont(pFont);

	m_name.CWnd::CreateEx(WS_EX_CLIENTEDGE|WS_EX_STATICEDGE,_T("EDIT"),_T(""),WS_VISIBLE|WS_CHILD|WS_TABSTOP,
		CRect(192,11,272,30),this,IDC_NAME);
	m_name.SetFont(pFont);

	m_st3.CWnd::CreateEx(0,_T("STATIC"),_T("����"),WS_VISIBLE|WS_CHILD,
		CRect(285,11,321,23),this,IDC_STATIC3);
	m_st3.SetFont(pFont);

	m_dept.CWnd::CreateEx(WS_EX_CLIENTEDGE|WS_EX_STATICEDGE,_T("COMBOBOX"),_T(""),CBS_DROPDOWNLIST|WS_VISIBLE|WS_CHILD|WS_TABSTOP,
		CRect(321,11,414,188),this,IDC_COMBO);
	m_dept.SetFont(pFont);

	m_add.CWnd::CreateEx(WS_EX_CLIENTEDGE|WS_EX_DLGMODALFRAME,_T("BUTTON"),_T("���"),WS_VISIBLE|WS_CHILD|WS_TABSTOP,
		CRect(11,36,86,65),this,IDC_ADD);
	m_add.SetFont(pFont);


	m_del.CWnd::CreateEx(WS_EX_CLIENTEDGE,_T("BUTTON"),_T("ɾ��"),WS_VISIBLE|WS_CHILD|WS_TABSTOP,
	CRect(98,36,173,65),this,IDC_DEL);
	m_del.SetFont(pFont);

	m_mod.CWnd::CreateEx(WS_EX_CLIENTEDGE|WS_EX_DLGMODALFRAME,_T("BUTTON"),_T("�޸�"),WS_VISIBLE|WS_CHILD|WS_TABSTOP,
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
	//�����ڴ�����ϣ������Ӵ���
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	CreateCtrl();


	m_list.InsertColumn(0,_T("����"),0,100);
	m_list.InsertColumn(1,_T("����"),0,100);
	m_list.InsertColumn(2,_T("����"),0,100);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT |LVS_EX_GRIDLINES);

	m_dept.AddString(_T("��ѡ����"));
	m_dept.AddString(_T("������"));
	m_dept.AddString(_T("Ӫ����"));
	m_dept.AddString(_T("������"));
	m_dept.SetCurSel(0);


	m_tip.Create(this);
	EnableToolTips(TRUE);
	m_tip.SetMaxTipWidth(500);
	m_tip.SetTipBkColor(RGB(210,210,255));
	m_tip.SetTipTextColor(RGB(0,106,53));
	m_tip.SetDelayTime(TTDT_INITIAL,100);
	m_tip.AddTool(&m_numb,_T("�����빤��"));
	m_tip.AddTool(&m_name,_T("����������"));
	m_tip.AddTool(&m_dept,_T("�����벿��"));
	m_tip.AddTool(&m_list);


	m_itemSize.AddItemRect(IDC_NUMB,this);
	m_itemSize.AddItemRect(IDC_NAME,this);
//	m_itemSize.AddItemRect(IDC_COMBO,this);//��֪��ʲôԭ��������һ��֮��ComboBOx����ʾ��������
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
		AfxMessageBox("��ѡ���������");
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
		AfxMessageBox(_T("��ѡ��һ���û���Ϣ��ɾ��"));
		return;
	}
	CString str=m_list.GetItemText(nSel,0);
	str=_T("ȷ��Ҫɾ�����Ϊ: "+str+"��Ϣ��?");
	if(AfxMessageBox(str,MB_YESNO)==IDYES)
		m_list.DeleteItem(nSel);
}

void CMainWnd::OnMod()
{
	int nSel=m_list.GetSelectionMark();
	if(nSel<0)
	{
		AfxMessageBox(_T("��ѡ��һ���û���Ϣ���޸�"));
		return;
	}

	CString str=m_list.GetItemText(nSel,0);
	str=_T("ȷ��Ҫ�޸ı��Ϊ: "+str+"��Ϣ��?");
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
		if(pTTT ->uFlags==3)//���û����һ�䣬
			return TRUE;
        // idFrom is actually the HWND of the tool
        nID = ::GetDlgCtrlID((HWND)nID);
        switch(nID)
        {
		case IDC_LIST:
			if(!m_list.GetSelectedCount())
			{
				strcpy(pTTT->lpszText,_T("δѡ����Ϣ"));
				return TRUE;
			}
			int nSel=m_list.GetSelectionMark();
			CString  str;
			str.Format("ѡ���Ա����Ϣ:\r\n����:%s \r\n����:%s \r\n����:%s",
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
//DEL 		CRect rect;  //��ȡ�ؼ��仯ǰ��С
//DEL //		LONG cWidth,cHeight; //��¼�ؼ����Ҳ��������Ҳ��ľ��룬��¼�ؼ��ĵײ�������ײ��ľ���
//DEL 		pWnd->GetWindowRect(&rect);
//DEL 		ScreenToClient(&rect);//���ؼ���Сת��Ϊ�ڶԻ����е���������
//DEL 		rect.left=rect.left*cx/m_rect.Width();
//DEL 		rect.right=rect.right*cx/m_rect.Width();
//DEL 		rect.top=rect.top*cy/m_rect.Height();
//DEL 		rect.bottom=rect.bottom*cy/m_rect.Height();
//DEL 		pWnd->MoveWindow(rect);
//DEL 	}
//DEL //	GetClientRect(&m_rect);//���仯��ĶԻ����С��Ϊ�ɴ�С
//DEL }
