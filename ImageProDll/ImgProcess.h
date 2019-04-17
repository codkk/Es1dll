/*
purpose:			�㷨���װ
date:				2017-12-25
author:				�⺺Ȩ
last modification:	2017-12-25	�⺺Ȩ	�½�
					2017-12-26  �⺺Ȩ  �޸ĳɼ���ģ�壬��ʶ��
					2019-02-23  �⺺Ȩ  ���������roi����
*/
#pragma once
#include "stdafx.h"
# include "HalconCpp.h"
# include "HDevThread.h"
#include "myCameraClass.h"
# include "ConvertPixel.h"
#include <string>
#include <vector>
using namespace std;
using namespace HalconCpp;
#define CALIBRAT_PT_NUM 9

typedef struct xPara {
	double AngleStart;  //��ʼ�Ƕ�
	double AngleExtent; //�Ƕȷ�Χ
	double MinScore;	//��С���� ƥ��ȣ�0��1֮�䣩
	int    NumMatches;  //ƥ�������0�������ܶ��ƥ��)
	double MaxOverlap;  //����ص�
	string SubPixel;    //������
	int	   ModelLevels; //ģ���������
	int    NumLevels;   //��������
	double Greediness;  //̰���㷨
	xPara() {
		AngleStart = -90;
		AngleExtent =180;
		MinScore = 0.5;
		NumMatches = 0;
		MaxOverlap = 0.5;
		SubPixel = "least_squares";
		ModelLevels = 8;
		NumLevels = 1;
		Greediness = 0.75;
	}
}XPARA;

//�������
typedef struct DetectArea{
	bool bAvalid;  //�Ƿ���Ч
	int row1;	   //���Ͻ�����
	int col1;
	int row2;	   //���½�����
	int col2;
	DetectArea() {
		bAvalid = false;
		row1	= -1;
		col1	= -1;
		row2	= -1;
		col2	= -1;
	}
}DetectArea;

typedef struct MyPoint2f {
	double fx;
	double fy;
	MyPoint2f() {
		fx = 0.0;
		fy = 0.0;
	}
}MyPoint2f;

class ImgProcess {
public:
	ImgProcess();
	~ImgProcess();
	bool SaveParaFind(char* pPath);		//����ƥ�����
	bool SaveParaFind(CString strPath); //����ƥ�����
	bool LoadParaFind(char* pPath);		//����ƥ�����
	bool LoadParaFind(CString strPath); //����ƥ�����
	bool LoadDetectArea(char* pPath);	//���ؼ���������
	bool DrawModelDetectArea(char* pSavePath); //��ѡģ�����򲢱������
	bool DrawBarcodeDetectArea(char* pSavePath); //��ѡ��ά�������򲢱������
	bool SaveDetectArea(char* pPath);	//�������������
	void ShowDetectArea(bool bShow);    //�Ƿ���ʾ����������
	bool IsLoadModel();
	bool SetDispWnd(Hlong wnd, CRect showRect);
	bool LoadModel(char* pModelPath, char* pModelImagePath); //�������ط�����ģ���ļ��� pModelPath��ģ���·�����������磺"C:/Users/wuhq/Desktop/Matching 01.shm"
	bool LoadModel(CString pModelPath, CString pModelImagePath);
	bool LoadModel(char* pModelPath);
	void SetModelPathName(char* pModelPath);						//����ģ��·�� + ���� + �޺�׺
	bool CreateModel(BYTE *pImage, int imW, int imH);				//����ģ�壬����һ�Ŵ����ͼƬ��ģ��
	bool CreateModel(BYTE *pImage, int imW, int imH, char* ModImgPathname);    //ʹ��һ��Сͼ������ʱģ���ڴ�ͼ��ƥ��õ������ô������Լ���ͼ����ģ�塣   pImage: ���ڴ���ģ��Ĵ�ͼ�� imW��imH����ͼ���� ModImgPathname�����Ƚ�ȡ��ģ��ͼ��
	bool CreateModel(char* pModePath);								//����ģ�� ����·������ģ��
	bool CreateModel(char* pModePath, std::vector<CRect> &vctRoi);	//����ģ�� ������ROI
	bool CreateModelFromCam();										//������ɼ�ͼ������ģ��
	bool CreateModelFromModel();									//ʹ��Ԥ���ͼ�����ƥ�䲢��ѡģ�壬����ģ�塣
	bool SaveModel(char* pModelPath);								//����ģ��
	bool Find(BYTE *pImage,int imW,int imH, int &iNum,double &lfMinScore); //��pImage�ж�λģ�壬�õ�����iNum, ���꣨pX,pY,pAng), ƥ���(pScore)
	bool Find(char* pPathName, int &iNum, double &lfMinScore);		//��·���м���ͼ��pImage�ж�λģ�壬�õ�����iNum, ���꣨pX,pY,pAng), ƥ���(pScore)
	bool FindFromCam();				//������ɼ�ͼ��ʶ��
	bool FindBarCode(CString & codestr, bool bgetimage=true); //���Ҷ�ά��
	void disp_message(HTuple hv_WindowHandle, HTuple hv_String, HTuple hv_CoordSystem,HTuple hv_Row, HTuple hv_Column, HTuple hv_Color, HTuple hv_Box);
	void ShowException(HalconCpp::HException & except);
	bool LoadModelImage(char* pModelImagePath); //
	int	 ConvertoHalcon(unsigned char * pData, MV_FRAME_OUT_INFO_EX stImageInfo, HalconCpp::HObject& image);
	void GrabOneImage();
	bool SetContinueShow(bool bCont);
	bool SetExposureTime(double ExpTime);
	bool Calibrate9(double* Imx, double * Imy, double* Spx, double* Spy); //�ŵ�궨
	bool CalibrateRot(double* Imx, double* Imy, int ptNum);  //��ת�궨
	bool SaveCalibrate9(char* pPath);	//����9������
	bool LoadCalibrate9(char* pPath);   //����9�����겢�궨
	bool Calibration();  //�����궨���̣���9��궨��
	bool CalibrationStep(int ptIndex, double Spx, double Spy); //9��궨 ��ÿ����Բ����ȡ����, ������������spx, spy
	bool CheckCalibrate(double &Spx, double &Spy); //����궨����� ���տ�ѡĿ��õ�ͼ�����������Ӧ����������Spx Spy;
	bool CalibrateRotStep(int ptIndex);	//��ת�궨
	bool DrawMyRectangle(HalconCpp::HTuple HWindowID, HalconCpp::HTuple & RowTmp, HalconCpp::HTuple & ColumnTmp, HalconCpp::HTuple & PhiTmp, HalconCpp::HTuple & Length1Tmp, HalconCpp::HTuple & Length2Tmp);
	bool DrawMyRectangle1(HalconCpp::HTuple HWindowID, HalconCpp::HTuple & RowTmp1, HalconCpp::HTuple & ColumnTmp1, HalconCpp::HTuple & RowTmp2, HalconCpp::HTuple & ColumnTmp2);
	bool FindMyCircle(HObject srcImg, HObject regionROI, HTuple &RowY, HTuple &ColX, HTuple &Radius); //regionROI: Բ�������� RowY�� Բ��������
	void Image2World(double* Imx, double * Imy, double* Spx, double* Spy);  //ͼ������ת��Ϊ��������
	bool SavePicture(char* path); //���浱ǰͼ��
	void SetFullScreen(bool bFull); //������ʾȫ��
	void CloseCamera();           //�ر����
	void LoadImageFromFile();			  //�ļ��м���ͼ����ʾ
	void SetManuMode(bool bMan);		  //����Ϊ�ֶ�����ͼ��ģʽ	
public:
	
	static int g_num;
	int m_iIndex;		 //������
	HTuple	WindowHandle;//���ھ��������������ʾ
	bool  m_bManu;		//���ؼ���ͼ�񣬲�ͨ������ɼ�
	//ģ������
	double m_fModelX;
	double m_fModelY;
	double m_fModelAngle;
	double m_fModelScore;

	//ʶ����
	int  m_targetNum;    //�ҵ����ٸ�Ŀ��
	double *m_PosX;      //�������X����
	double *m_PosY;      //�������Y����
	double *m_RotDeg;    //���������ת�Ƕ�
	double *m_Score;     //�����ƥ���

private:
	//���
	myCameraClass *m_pCam;
	unsigned char *m_pImageBuffer;
	unsigned char *m_pDataSeparate;
	double       m_fExporTime;
	
	//������ʾ
	Hlong hl_wnd;//�ؼ����
	CRect m_rect;//�ؼ�����
	bool m_bShowDetectArea;
	int  m_TextRow;
	int  m_TextCol;
	int  m_TextRowBarcode;
	int  m_TextColBarcode;

	//ģ��
	bool m_bLoadModel;		//�ɹ�����ģ���ļ�.shm
	bool m_bLoadParaFind;	//�ɹ����ز���
	XPARA m_paraFind;      //���ҵĲ���
	char m_ModelPathAndName[128];
	HObject ho_ModelImage; //�����ģ��ͼ��
	HObject  ho_ModelContours, ho_TransContours, ho_Image;
	HTuple  hv_ModelID, hv_Row1, hv_Column1, hv_Row2;
	HTuple  hv_Column2, hv_RefRow, hv_RefColumn, hv_HomMat2D;
	HTuple  hv_TestImages, hv_T, hv_Row, hv_Column, hv_Angle;
	HTuple  hv_Score, hv_I;

	double m_MRow, m_MCol, m_MPhi, m_MLen1, m_MLen2;
	HObject m_ho_ModelRegion;		//ģ�����
	HObject m_ho_ModelDetectArea;   //ģ��������ROI��
	DetectArea m_ModelDetectArea;   //ģ������������
	vector<MyPoint2f> m_vectMark;	//ת�Ӱ�mark��

	//��ά��
	HObject m_ho_DetectBarcodeArea;//��ά��������ROI��
	DetectArea m_BarcodeDetectArea;
	HTuple  m_hv_DataCodeHandle; //��ά����
	HTuple  m_hv_ResultHandles, m_hv_DecodedDataStrings;

	//�궨
	HObject m_ho_Circles;   //��ѡʶ��õ���Բ��������ʾ
	//�ŵ�궨
	HTuple m_hv_HomMat2D;	//�������
	bool   m_bIsCalied;		//�Ƿ�ɹ��궨
	double m_fImx[CALIBRAT_PT_NUM];			//ͼ������x �� col
	double m_fImy[CALIBRAT_PT_NUM];			//ͼ������y �� row
	double m_fSpx[CALIBRAT_PT_NUM];			//��������x  ��ƽ̨����x
	double m_fSpy[CALIBRAT_PT_NUM];			//��������y  ��ƽ̨����Y

	double m_fImxTmp[CALIBRAT_PT_NUM];			//ͼ������x �� col
	double m_fImyTmp[CALIBRAT_PT_NUM];			//ͼ������y �� row
	double m_fSpxTmp[CALIBRAT_PT_NUM];			//��������x  ��ƽ̨����x
	double m_fSpyTmp[CALIBRAT_PT_NUM];			//��������y  ��ƽ̨����Y
	//��ת�궨
	double m_lfCentX; //���ĵ�ͼ������
	double m_lfCentY;
	double m_lfRadiu; //�뾶���س���
	double m_lfRotX[CALIBRAT_PT_NUM]; //���ڱ궨��ͼ������x
	double m_lfRotY[CALIBRAT_PT_NUM];
	bool m_bIsCaliedRot;   //�Ƿ�ɹ��궨��ת
};