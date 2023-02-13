// editorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "editor.h"
#include "editorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditorDlg dialog

CEditorDlg::CEditorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEditorDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEditorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditorDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEditorDlg, CDialog)
	//{{AFX_MSG_MAP(CEditorDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BLOCK1, OnBlock1)
	ON_BN_CLICKED(IDC_BLOCK2, OnBlock2)
	ON_BN_CLICKED(IDC_BLOCK3, OnBlock3)
	ON_BN_CLICKED(IDC_BLOCK4, OnBlock4)
	ON_BN_CLICKED(IDC_BLOCK5, OnBlock5)
	ON_BN_CLICKED(IDC_BLOCK6, OnBlock6)
	ON_BN_CLICKED(IDSAVE, OnSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditorDlg message handlers

BOOL CEditorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
		
	this->MoveWindow(0, 0, 1024, 768, true);
	selected = 1;
	for( int i = 0; i < 24; i++ )
		for( int j = 0; j < 32; j++ )
			field[i][j] = -1;

	bm[0].LoadBitmap(IDB_BLOCK1);
	bm[1].LoadBitmap(IDB_BLOCK2);
	bm[2].LoadBitmap(IDB_BLOCK3);
	bm[3].LoadBitmap(IDB_BLOCK4);
	bm[4].LoadBitmap(IDB_BLOCK5);
	bm[5].LoadBitmap(IDB_BLOCK6);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CEditorDlg::OnPaint()
{
	CPaintDC dc(this);

	CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
	dc.SelectObject(pen);
	for( int i = 0; i < 32; i++ )
	{
		dc.MoveTo(i * 32, 0);
		dc.LineTo(i * 32, 768);
	}
	for( i = 0; i < 24; i++ )
	{
		dc.MoveTo(0, i * 32);
		dc.LineTo(1024, i * 32);
	}

	CDialog::OnPaint();
}

HCURSOR CEditorDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CEditorDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	int col = point.x / 32;  // div tilewidth
	int row = point.y / 32;

	field[row][col] = selected;
	CClientDC dc(this);

	dc.DrawState(CPoint(32 * (point.x / 32), 32 * (point.y / 32)), CSize(32, 32), bm[selected-1], DST_BITMAP);

	CDialog::OnLButtonDown(nFlags, point);
}

void CEditorDlg::OnBlock1() 
{
	selected = 1;
}

void CEditorDlg::OnBlock2() 
{
	selected = 2;
}

void CEditorDlg::OnBlock3() 
{
	selected = 3;	
}

void CEditorDlg::OnBlock4() 
{
	selected = 4;	
}

void CEditorDlg::OnBlock5() 
{
	selected = 5;	
}

void CEditorDlg::OnBlock6() 
{
	selected = 6;	
}

void CEditorDlg::OnSave() 
{
	CFileDialog dialog(FALSE, "dat");	
	if( dialog.DoModal() == IDOK )
	{
		CString file = dialog.GetFileName();
		char *f = file.GetBuffer(MAX_PATH);
		FILE *fp = fopen(f, "wb");

		for( int r = 0; r < 24; r++ )
			for( int c = 0; c < 32; c++ )
				fwrite(&field[r][c], sizeof(int), 1, fp);

		fclose(fp);
	}
}
