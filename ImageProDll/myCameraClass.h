#pragma once
#include "afxwin.h"
#include <stdio.h>
#include "MultipleCameraDefine.h"
#include "MyCamera.h"

class myCameraClass
{
public:
	myCameraClass(int idex);
	~myCameraClass();
private:
	// ch:״̬ | en:
	BOOL  m_bCreateDevice;                          // ch:�Ƿ񴴽��豸 | en:Create
	BOOL  m_bOpenDevice;                            // ch:�Ƿ�� | en:Open
	BOOL  m_bStartGrabbing;                         // ch:�Ƿ�ʼץͼ | en:Start grabbing
	int   m_nTriggerMode;                           // ch:����ģʽ | en:Trigger mode
	int   m_nTriggerSource;                         // ch:����Դ | en:Trigger source
	
public:
	int				m_idex; //������
	CMyCamera*		m_pcMyCamera;
	void*           m_hGetOneFrameHandle;
	unsigned int    m_nPayloadSize;


	// ch:��־�豸 | en:
	HWND  m_hwndDisplay;            // ch:��ʾ��� | en:Display window
	CWnd* m_cwndDisplay;

	MV_CC_DEVICE_INFO_LIST m_stDevList;             // ch:�豸��Ϣ�б�ṹ������������洢�豸�б�
													// en:Device information list structure variable, to save device list
	// ch:�ʼʱ�Ĵ��ڳ�ʼ�� | en:Window initialization
	int CameraInit(CWnd* pWnd);               // ch:��ȡ���ھ�� | en:Get window handle 
	int RegisterImageCallBack(void(__stdcall* cbOutput)(unsigned char * pData, MV_FRAME_OUT_INFO_EX* pFrameInfo,
		void* pUser), void* pUser);
											  
											  // ch:��ť������ʹ�� | en:Button enable
	//int EnableControls(BOOL bIsCameraReady);
	//int EnableWindowWhenInitCamera(void);    // ch:���³�ʼ����ťʱ�İ�ť��ɫ | en:Button color after press initialization
	void   ShowErrorMsg(CString csMessage, int nErrorNum);
	int OpenDevice(int idx);                     // ch:���豸 | en:Open Device

	// ch:���ò������� | en:Set parameter
	int SetTriggerMode(int nTriggerMode);       // ch:���ô���ģʽ | en:
	int SetExposureTime(int dExpouse);			// ch:�����ع�ʱ�� | en:
	int SetGain(int dGain);                     // ch:�������� | en:
	int SetTriggerSource(int nTriggerSource);   // ch:���ô���Դ | en:
	int DoSoftwareOnce(void);                    // ch:����һ�� | en:
	int SetAcquisitionMode(int dMode);
	// ch:����������ܲ��� | en:Basic function
	int StartGrabbing(void);                     // ch:��ʼ�� | en:
	int StopGrabbing(void);                      // ch:������ | en:
	int GrabOneImage(unsigned char**pData, MV_FRAME_OUT_INFO_EX &info);                      // ch:��ȡһ��ͼ
	// ch:�ر����ٲ��� | en:Close and destroy
	int CloseDevice(void);                       // ch:�ر��豸 | en:
	int DestroyDevice(void);                     // ch:�����豸 | en:
public:
	int ThreadFun();
};

