
// testImageProDllDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CtestImageProDllDlg �Ի���
class CtestImageProDllDlg : public CDialogEx
{
// ����
public:
	CtestImageProDllDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTIMAGEPRODLL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	ImageProDll m_mydll;
	//ImageProDll m_mydll2;
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CStatic m_show;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	// �Ƿ���ʾ�������
	BOOL m_bShowArea;
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
};
