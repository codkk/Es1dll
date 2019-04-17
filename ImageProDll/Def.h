//���ݽṹ�壬�������ͣ��ȶ���
#pragma once
#include <string>
#include "stdafx.h"
//////////////////////////////////////////////////////
//�궨��
/////////////////////////////////////////////////////
#define LOG_DEBUG


//����
#define TXT_INIFILENAME_TASKROOT "Task\\"  //�����ļ���
#define TXT_TASKFILE_TYPE ".Task"
#define TXT_NODE_TASK "Task"
#define SUBNODE_TASKPATH "TaskPath" //�����·��
#define TXT_NODE_LIGHT "Light"

//���
#define CAM1_IDX 0 //���1�����
#define CAM2_IDX 1 //���2�����
#define CAM3_IDX 2 //���3�����
#define CAM4_IDX 3 //���4�����
#define MIN_CAM_EXP 5000//�������عⷶΧ 5����
#define MAX_CAM_EXP 500000//�������عⷶΧ 500����
#define TXT_INIFILENAME_CAM1 "CamConfig1.ini"        //��һ������������ļ�����·��
#define TXT_INIFILENAME_CAM2 "CamConfig2.ini"

#define SUBNODE_LIGHTCTRL_CH1 "lightch1"
#define SUBNODE_LIGHTCTRL_CH2 "lightch2"
#define LIGHT_DEFAUL1		  100		
#define LIGHT_DEFAUL2		  100	


//�㷨
#define TXT_INIFILENAME_IMG "ImgProcessConfig.ini"	    //����·�����ļ��� 
#define TXT_INIFILENAME_IMG_FIX_A_1 "ImgProcessFix1Config.ini"  //�ξ߶�λ�㷨���ļ���
#define TXT_INIFILENAME_IMG_FIX_A_2 "ImgProcessFix2Config.ini"
#define TXT_INIFILENAME_IMG_FIX_A_3 "ImgProcessFix3Config.ini"
#define TXT_INIFILENAME_IMG_FIX_A_4 "ImgProcessFix4Config.ini"
#define TXT_MODELFILENAME		 "Model.shm"			//��Ʒ��λģ���ļ���
#define TXT_MODELFILENAME_FIX_A_1	 "ModelFix1.shm"		//�ξ�1��λģ���ļ���
#define TXT_MODELFILENAME_FIX_A_2	 "ModelFix2.shm"		//�ξ�2��λģ���ļ���
#define TXT_MODELFILENAME_FIX_A_3	 "ModelFix3.shm"		//�ξ�3��λģ���ļ���
#define TXT_MODELFILENAME_FIX_A_4	 "ModelFix4.shm"		//�ξ�4��λģ���ļ���


#define TXT_MODELFILENAME_IMG		 "Model.bmp"			//��Ʒ��λģ���ļ���
#define TXT_MODELFILENAME_FIX1_IMG_A	 "ModelFix1.jpg"		//�ξ�1��λģ���ļ���
#define TXT_MODELFILENAME_FIX2_IMG_A	 "ModelFix2.jpg"		//�ξ�2��λģ���ļ���
#define TXT_MODELFILENAME_FIX3_IMG_A	 "ModelFix3.jpg"		//�ξ�3��λģ���ļ���
#define TXT_MODELFILENAME_FIX4_IMG_A	 "ModelFix4.jpg"		//�ξ�4��λģ���ļ���



#define  PI 3.1415926535897932384626433832795
#define  RAD_0 0			//0�ȵĻ���ֵ
#define  RAD_90 1.570796	//90�ȵĻ���ֵ
#define	 RAD_90P (-1.570796)//-90��
#define  RAD_180 PI			//180
#define  RAD_180P (-PI)		//-180
#define  RAD_DELTA 0.174533	//����ķ�Χ10��

//�ξ�
//#define FIX_NUM 4  //�ξߵĸ���
//#define FIX1 0
//#define FIX2 1
//#define FIX3 2
//#define FIX4 3
enum FixEnum {
	FIX1=0,
	FIX2,
	FIX3,
	FIX4,
	FIX_NUM
};
#define TIME_WAIT_TESTPC 5000 //�ξ���ɵ�����PCҲ��ɵĳ�ʱʱ��
#define TIME_WAIT_STOP	10	  //��ѯֹͣ�źŵĳ�ʱʱ��
#define TIME_WAIT_PLCWRITE 5 //��ѯplcд�¼��ĵȴ���ʱʱ��
#define TIME_WAIT_PLCREAD 5  //��ѯplc���¼��ĵȴ���ʱʱ��
#define TIME_WAIT_ROBOTBACK 30000 //��е�ָ�λ��ʱʱ��

#define TXT_INIFILENAME_FIX1 "FixConfig1.ini"
#define TXT_INIFILENAME_FIX2 "FixConfig2.ini"
#define TXT_INIFILENAME_FIX3 "FixConfig3.ini"
#define TXT_INIFILENAME_FIX4 "FixConfig4.ini"
#define TXT_NODE_PARA_SERIAL "SerialPara"
#define SUBNODE_PORT		"portnr"
#define SUBNODE_BAUD		"baud"
#define SUBNODE_PARITY		"parity"
#define SUBNODE_DATABITS	"databits"
#define SUBNODE_STOPBITS	"stopbits"

#define TXT_FIX1 "FIX_1"
#define TXT_FIX2 "FIX_2"
#define TXT_FIX3 "FIX_3"
#define TXT_FIX4 "FIX_4"

//PLC ���ں� com1 = 0; com2 = 1
#define COMM_PLC 4
#define COMM_LIGHT 4
////��е��
#define TXT_INIFILENAME_ROBOT "RobotConfig.ini"
#define TXT_NODE_TCP "TCPconfig"
#define TXT_SUBNODE_TCP_NAME "Name"
#define TXT_SUBNODE_TCP_ADDR "IPAddr"
#define TXT_SUBNODE_TCP_PORT "Port"

enum RobotAxis {
	Axis_X = 0,
	Axis_Y,
	Axis_Z,
	Axis_R,
	ROBOT_AXIS_NUM
};
#define TXT_NODE_DUT_LOCATE_POS_ROBOT "RobotPos_DUT_LOCATE"  //�����λ��Ʒ��λ��
#define TXT_NODE_FIX1_LOCATE_POS_ROBOT "RobotPos_FIX1_LOCATE"  //�����λ�ξ�1��λ��
#define TXT_NODE_FIX2_LOCATE_POS_ROBOT "RobotPos_FIX2_LOCATE"  
#define TXT_NODE_FIX3_LOCATE_POS_ROBOT "RobotPos_FIX3_LOCATE"  
#define TXT_NODE_FIX4_LOCATE_POS_ROBOT "RobotPos_FIX4_LOCATE"  

#define TXT_NODE_DUT_CAP_POS_ROBOT "RobotPos_DUT_CAP"  //���ץȡ��Ʒ��λ��
#define TXT_NODE_FIX1_CAP_POS_ROBOT "RobotPos_FIX1_CAP"  //���ץȡ�ξ�1��λ��
#define TXT_NODE_FIX2_CAP_POS_ROBOT "RobotPos_FIX2_CAP"  //
#define TXT_NODE_FIX3_CAP_POS_ROBOT "RobotPos_FIX3_CAP"  
#define TXT_NODE_FIX4_CAP_POS_ROBOT "RobotPos_FIX4_CAP"  
//
#define TXT_NODE_OK_POS_ROBOT "RobotPos_OK"  //ok��Ʒ�ķ���λ��
#define TXT_NODE_NG_POS_ROBOT "RobotPos_NG"  //ng��Ʒ�ķ���λ��

#define TXT_SUBNODE_AXIS_X "X" 
#define TXT_SUBNODE_AXIS_Y "Y"
#define TXT_SUBNODE_AXIS_Z "Z"
#define TXT_SUBNODE_AXIS_U "U"

//�궨
#define TXT_INIFILENAME_CABLI1 "CabliConfig1.ini"
#define TXT_INIFILENAME_CABLI2 "CabliConfig1.ini"
#define TXT_INIFILENAME_CABLI3 "CabliConfig1.ini"
#define TXT_INIFILENAME_CABLI4 "CabliConfig1.ini"
#define TXT_NODE_CABLI_PT1	"Image Pt1"
#define TXT_NODE_CABLI_PT2	"Image Pt2"
#define TXT_NODE_CABLI_PT1_MA	"Mach Pt1"
#define TXT_NODE_CABLI_PT2_MA	"Mach Pt2"


/*
//���ݽṹ��
class CFloatPt
{
public:
	double x, y;

public:
	CFloatPt() { x = 0.0F; y = 0.0F; };
	CFloatPt(double x1, double y1) { x = x1; y = y1; };
	CFloatPt(const CFloatPt &pt) { x = pt.x; y = pt.y; };
	CFloatPt(const CPoint &pt) { x = (double)pt.x; y = (double)pt.y; };
	CFloatPt(const POINT & pt) { x = (double)pt.x; y = (double)pt.y; };

	CFloatPt* operator= (CFloatPt*      pPt)
	{
		x = pPt->x; y = pPt->y; return  this;
	};
	CFloatPt& operator= (const CFloatPt& pt)
	{
		x = pt.x; y = pt.y; return *this;
	};
	CFloatPt& operator= (const CPoint&   pt)
	{
		x = (double)pt.x; y = (double)pt.y; return *this;
	};
	CFloatPt& operator= (const POINT&    pt)
	{
		x = (double)pt.x; y = (double)pt.y; return *this;
	};
	CFloatPt& operator- (CFloatPt& pt)
	{
		x -= pt.x; y -= pt.y; return *this;
	};

	double Distance2Point(CFloatPt p = CFloatPt(0, 0))
	{
		return sqrt((x - p.x)* (x - p.x) + (y - p.y)* (y - p.y));
	}
	double Distance2Point(double fX, double fY)
	{
		return sqrt((x - fX)* (x - fX) + (y - fY)* (y - fY));
	}
};
*/
//����ͨ�Ų����ṹ��
typedef struct serialConfig{
	unsigned int	portnr;
	unsigned int	baud;
	unsigned int	parity;
	unsigned int	databits;
	unsigned int	stopbits;
	serialConfig(){
		portnr	= 2;
		baud = 9600;
		parity = 0; //0:None, 1:one, 2:two
		databits = 8;
		stopbits = 0;
	}
} serialConfig;

//TCPͨ�Ų���
typedef struct TCPConfig {
	std::string name;
	std::string/*char**/address;
	int			port;
	TCPConfig() {
		name = "CLIENT";
		address = "192.168.0.62";
		port = 10000;
	}
}TCPConfig;

//λ��
typedef struct MYPOS {
	//��������
	double PosX;
	double PosY;
	double PosZ;
	double RotU;
	//ͼ������
	double PosImX;
	double PosImY;
	double RotImU;
	//��ģ���ƫ����(mm)
	double deltaX;
	double deltaY;
	double deltaU;

	MYPOS() {
		PosX = 0.0;
		PosY = 0.0;
		PosZ = 0.0;
		RotU = 0.0;

		PosImX = 0.0;
		PosImY = 0.0;
		RotImU = 0.0;

		deltaX = 0.0;
		deltaY = 0.0;
		deltaU = 0.0;
	}
}MyPos;

//DUT(��Ʒ��
typedef struct DUT {
	int nFixIdx;		//��վ��
	bool bIsOK;			//�����
	MyPos pos;			//λ��

	DUT(){
		nFixIdx = -1;
		bIsOK = false;
	}
}DUT;

//�ξߵ�״̬
enum StateOfFix {
	ST_DOING = 0,//δ��ɣ����ڽ�����
	ST_DONE_OK,//��ɴ�ȡ
	ST_DONE_NG,//��ɴ�ȡ
	ST_READY//�ȴ�����
};

//��ת�������
/*
a,-b,c
b, a,d

a = cos(theta)
b = sin(theta)
c = x0
d = y0
*/
/*
typedef struct RotT 
{
	double a;
	double b;
	double c;
	double d;
	RotT()
	{
		a = 0.0;
		b = 0.0;
		c = 0.0;
		d = 0.0;
	}
}RotT;
*/

