// editorDlg.h : header file
//

#if !defined(AFX_EDITORDLG_H__AE633967_03B3_4099_A5AD_6CC203E5584C__INCLUDED_)
#define AFX_EDITORDLG_H__AE633967_03B3_4099_A5AD_6CC203E5584C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEditorDlg dialog

class CEditorDlg : public CDialog
{
// Construction
public:
	CEditorDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEditorDlg)
	enum { IDD = IDD_EDITOR_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	int selected; // what block is selected
	int field[24][32];
	CBitmap bm[6];

	// Generated message map functions
	//{{AFX_MSG(CEditorDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBlock1();
	afx_msg void OnBlock2();
	afx_msg void OnBlock3();
	afx_msg void OnBlock4();
	afx_msg void OnBlock5();
	afx_msg void OnBlock6();
	afx_msg void OnSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITORDLG_H__AE633967_03B3_4099_A5AD_6CC203E5584C__INCLUDED_)
