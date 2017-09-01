// ItemResize.h: interface for the CItemResize class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ITEMRESIZE_H__E6E60119_66A3_4DDC_A417_ED26328F81FB__INCLUDED_)
#define AFX_ITEMRESIZE_H__E6E60119_66A3_4DDC_A417_ED26328F81FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include<vector>
#include<stdio.h>
using namespace std;
typedef struct _RESIZEINFO
{
	UINT nID;
	CWnd* pParent;
	float fLeft;
	float fRight;
	float fTop;
	float fBottom;
}RESIZEINFO;

class CItemResize  
{
public:
	CRect m_rectDlg;
	//在窗口创建时，添加需要自动按比例调整大小的空间ID
	vector<RESIZEINFO> m_vResizeID;
public:
	void ResizeItem();
	void AddItemRect(UINT nID,CWnd* pParent);
	CItemResize();
	virtual ~CItemResize();

};

#endif // !defined(AFX_ITEMRESIZE_H__E6E60119_66A3_4DDC_A417_ED26328F81FB__INCLUDED_)
