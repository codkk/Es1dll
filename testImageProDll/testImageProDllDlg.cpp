
// testImageProDllDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "testImageProDll.h"
#include "testImageProDllDlg.h"
#include "afxdialogex.h"
#include "opencv2\opencv.hpp"
using namespace cv;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtestImageProDllDlg �Ի���



CtestImageProDllDlg::CtestImageProDllDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TESTIMAGEPRODLL_DIALOG, pParent)
	, m_bShowArea(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtestImageProDllDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_SHOW, m_show);
	DDX_Check(pDX, IDC_CHECK1, m_bShowArea);
}

BEGIN_MESSAGE_MAP(CtestImageProDllDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CtestImageProDllDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CtestImageProDllDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CtestImageProDllDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CtestImageProDllDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CtestImageProDllDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CtestImageProDllDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CtestImageProDllDlg::OnBnClickedButton7)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON8, &CtestImageProDllDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CtestImageProDllDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CtestImageProDllDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_CHECK1, &CtestImageProDllDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_BUTTON11, &CtestImageProDllDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CtestImageProDllDlg::OnBnClickedButton12)
END_MESSAGE_MAP()


// CtestImageProDllDlg ��Ϣ�������

BOOL CtestImageProDllDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CRect rect;
	m_show.GetClientRect(&rect);
	m_mydll.SetHalconDispWnd(m_show.GetSafeHwnd(), rect);

	SetTimer(1, 500, NULL);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CtestImageProDllDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CtestImageProDllDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CtestImageProDllDlg::OnBnClickedButton1()
{
	double spx1, spy1;
	double spx2, spy2;

	//ƽ̨�ƶ���ԭ�����ĳһ��

	//��һ����
	m_mydll.CheckCalibrate(spx1, spy1);

	//ƽ̨�ƶ� delX,delY;

	//�ڶ�����
	m_mydll.CheckCalibrate(spx2, spy2);

	//��������Ĳ�ֵ����2����ֵ��ƽ̨�������ƶ���delX, delY���бȽϡ�
	double delta_x, delta_y;
	delta_x = spx2 - spx1;
	delta_y = spy2 - spy1;

	CString str;
	str.Format(_T("x,y�Ĳ�ֵ��%lf, %lf"), delta_x, delta_y);
	AfxMessageBox(str);
}


void CtestImageProDllDlg::OnBnClickedButton2()
{
	m_mydll.Calibrate();
	//for (int i = 0; i < 9; i++)
	//{
	//	if (!m_mydll.Calibrate(i, 0.0, 0.0))
	//		break;
	//}
}

//����ģ��
void CtestImageProDllDlg::OnBnClickedButton3()
{
	m_mydll.CreateModel();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//Mat img;
	//img = imread("test.bmp",CV_LOAD_IMAGE_GRAYSCALE);
	//imshow("test", img);
	////m_mydll.HalconCreateModel(img.data, img.cols, img.rows);
	//m_mydll.HalconCreateModel("test.bmp");
	//cvReleaseMat(&img);
}


void CtestImageProDllDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//m_mydll.SetModelPathName("d:\\model2.shm");
	m_mydll.SetFullScreen(true);
}


void CtestImageProDllDlg::OnBnClickedButton5()
{
	//���Ի�ȡ��ʾһ��ͼ��
	//m_mydll.GrabOneImage();
	long t1 = GetTickCount();
	m_mydll.FindModel();
	long t2 = GetTickCount();
	CString str;
	str.Format(_T("time: %d ms"), t2 - t1);
	AfxMessageBox(str);
}


void CtestImageProDllDlg::OnBnClickedButton6()
{
	//
	//m_mydll.LoadCalibIni();
	if (m_mydll.SaveImage("saveimg.bmp"))
	{
		AfxMessageBox(_T("ok"));
	}
	else
	{
		AfxMessageBox(_T("ng"));
	}
}


void CtestImageProDllDlg::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//m_mydll.SetContinueShow(false);
}


void CtestImageProDllDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//if (1 == nIDEvent)
	//{
	//	m_mydll.GrabOneImage();
	//}
	CDialogEx::OnTimer(nIDEvent);
}


void CtestImageProDllDlg::OnBnClickedButton8()
{
	long t1 = GetTickCount();
	m_mydll.GrabOneImage();
	long t2 = GetTickCount();
	CString str;
	str.Format(_T("time: %d ms"), t2 - t1);
	AfxMessageBox(str);
}


void CtestImageProDllDlg::OnBnClickedButton9()
{
	m_mydll.DrawDetectRoi();
}


void CtestImageProDllDlg::OnBnClickedButton10()
{
	m_mydll.DrawDetectCodebarRoi();
}


void CtestImageProDllDlg::OnBnClickedCheck1()
{
	UpdateData();
	m_mydll.ShowDetectArea(m_bShowArea);
}


void CtestImageProDllDlg::OnBnClickedButton11()
{
	CString str;
	m_mydll.FindBarCode(str, false);
	//AfxMessageBox(str);
}


void CtestImageProDllDlg::OnBnClickedButton12()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_mydll.LoadImageFromFile();
	m_mydll.SetManuMode(true);
}
