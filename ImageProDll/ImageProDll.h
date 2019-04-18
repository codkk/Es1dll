#pragma once
#include <vector>
class ImgProcess;
//class myCameraClass;
class AFX_EXT_CLASS ImageProDll
{
public:
	ImageProDll();
	~ImageProDll();
	//bool SetContinueShow(bool bCont);					  //�������������ʾ
	
	bool HalconSaveParaFind(CString strPath); //����ƥ�����
	bool HalconLoadParaFind(CString strPath); //����ƥ�����
	bool IsHalconLoadModel();
	bool HalconLoadModel(CString pModelPath, CString pModelImagePath);
	void SetModelPathName(char* pathname);											//���ñ���ģ���·������ģ������ư�����׺
	bool HalconCreateModel(BYTE *pImage, int imW, int imH);							 //����ģ��,������ֻ���ܵ�ͨ��ͼ��
	bool HalconCreateModel(BYTE *pImage, int imW, int imH, char* ModImgPathname);    //ʹ��һ��Сͼ������ʱģ���ڴ�ͼ��ƥ��õ������ô������Լ���ͼ����ģ�塣   pImage: ���ڴ���ģ��Ĵ�ͼ�� imW��imH����ͼ���� ModImgPathname�����Ƚ�ȡ��ģ��ͼ��  
	bool HalconCreateModel(char* pathname);											 //����ģ�壬��·���м���ͼ��
	bool HalconCreateModel(char* pathname, std::vector<CRect> &vecRoi);				 //����ģ�� ����ԭʼͼ�񣬺Ͷ��ROI
	bool HalconFind_A(BYTE *pImage, int imH, int imW, int &iNum,double& lfMinScore); //��pImage�ж�λģ�壬�õ�����iNum, ���꣨pX,pY,pAng), ƥ���(pScore),������ֻ���ܵ�ͨ��ͼ��
	bool HalconFind_B(char* pPathName, int &iNum, double& lfMinScore); //��·���м���ͼ��pImage�ж�λģ�壬�õ�����iNum, ���꣨pX,pY,pAng), ƥ���(pScore),������ֻ���ܵ�ͨ��ͼ��
	bool SetHalconDispWnd(HWND wnd, CRect showRect);
	int GetTargetNum();  //��ȡ���ҵ���Ŀ����
	bool GetMaxScoreTarget(double &x, double&y, double&r, double&maxScoreOut);
	void GetModelPt(double&x, double&y);  //��ȡģ�����������
	int GetIndex();						  //��ȡ��ǰ�㷨��������Ҳ����������
	
	
	//V1.0 �ӿ�
	bool DrawDetectRoi();						//��ѡ�����ü��ģ������
	bool DrawDetectCodebarRoi();				//��ѡ�����ü���ά������
	void ShowDetectArea(bool bshow);
	bool FindBarCode(CString &strCode, bool bGetImage);			//����ά�� bGetImage:�Ƿ�������ȡ��ͼ��
	bool CreateModel();							//����ģ��
	bool CreateModelFromModel();				//ͨ��ʶ��ͼ���Զ���ѡģ������ ����ģ��
	bool FindModel();							//����ģ��
	bool GetTarget(int ptIdx, double&x, double&y, double&r); //��ȡ��n��Ŀ��� x, y, theta
	bool GetTargetRel(int ptIdx, double& x, double &y, double &r); //��ȡ��n��Ŀ�������ģ���ƫ����pix
	bool GetTargetRelSp(int ptIdx, double& x, double &y, double &r); //��ȡ��n��Ŀ�������ģ���ƫ����������mm
	void GrabOneImage();				  //�ɼ�һ��ͼ����ʾ
	void LoadImageFromFile();			  //�ļ��м���ͼ����ʾ
	void SetManuMode(bool bMan);		  //����Ϊ�ֶ�����ͼ��ģʽ		
	void LoadCalibIni();
	bool Calibrate();//3��궨����
	bool Calibrate(int ptIndex, double Spx, double Spy);//9��궨��ƽ̨ÿ��һ����λ����һ�Σ���9��ʱ�Զ��궨��ɡ�����TRUE;
	bool CheckCalibrate(double& Spx_out, double& Spy_out); //�궨���飬������Spx_out������õ���y���������ꡣ   �������������տ�ѡ�õ�ͼ������ת��Ϊ�������꣨����궨��λ�ò������������겻�䡣 ���궨��λ���ƶ���Ҳû��ϵ��������������Ĳ�ֵ���䣩��
	bool CalibrateRot(int ptIndex);	//��ת�궨
	bool SetExposureTime(double fExpTime); //�����ع�
	bool SaveImage(char* path); //���浱ǰͼ��
	void SetFullScreen(bool bFull); //������ʾȫ��
	void CloseCamera(); //�ر����

	//V2.0�ӿڣ���Ӧ��ʹ�ò��裩
	//��ѡת�Ӱ�������ģ�弰��������(ֻ�е��ƶ��������ƽ̨�����λ�ã�����Ҫ����)
	bool DrawBaseMark();
	//��ѡ��Ʒ������ģ�弰��������ֻ�е��ƶ��������ƽ̨�����λ�ã�����Ҫ���ã�
	bool DrawDutMark();

	//����ʶ���Ʒ��ģ�壨���ƫ������
	bool FindDutMark(double& spx, double &spy, double &ang);
	//����ʶ��ת�Ӱ���ģ�� �����ƫ������
	bool FindBaseMark(double& spx, double &spy, double &ang);

	//�����Ʒƫ������ת�Ӱ���ƫ�����ܺͼ�������Ĳ��������õ��ƶ�ƽ̨���ƶ�������һ�������������������


private:
	ImgProcess *m_pImgProcess;
};