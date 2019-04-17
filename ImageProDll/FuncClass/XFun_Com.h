// --------------------------------------------------------
//�������������������������ó����˵������������������������
//��													  ��
//���� �ÿ����ռ����ֳ��õĳ��������д����ļ����������� ��
//��                                                      ��
//��������ʱ�䡢�жϲ���ϵͳ...�ȵ�һЩ�Ƚ����õĺ�����   ��
//��                                                      ��
//��ϣ���õ���ҵ�֧�֣������ʲô�õĽ������ֱ��������  ��
//��                                                      ��
//���ᡣ����Ϊ�˸ÿ�Ľ�һ�����ƣ����Ҿ�����Ҫ�Ըÿ��  ��
//��                                                      ��
//����ֱ���޸ġ�										  ��
//��                                                      ��
//����������������������������������������������������������
//---------------------------------------------------------
#ifndef _FUN_COM
#define _FUN_COM

#ifndef PI
#define PI			3.1415926535897932384626433832795028841971693993751
#endif

#define R2D				57.295779513082323
#define Deg2Rad( Deg )	(Deg)/ R2D		// �Ƕȵ�����
#define Rad2Deg( Rad )	(Rad)* R2D		// ���ȵ��Ƕ�

#include "math.h"

// ��ά����������Ͷ���
struct LFloatPt2D
{
	double	x;		// x����
	double	y;		// y����
	
	LFloatPt2D( ) { x= y= 0; };
	LFloatPt2D( double Ix, double Iy ) { x= Ix; y= Iy; };
	
	LFloatPt2D operator - ()
	{
		return LFloatPt2D( -x, -y );
	};
	friend LFloatPt2D operator + (const LFloatPt2D &p1, const LFloatPt2D &p2)
	{
		return LFloatPt2D( p1.x+ p2.x, p1.y+ p2.y );
	};
	friend LFloatPt2D operator - (const LFloatPt2D &p1, const LFloatPt2D &p2)
	{
		return LFloatPt2D( p1.x- p2.x, p1.y- p2.y );
	};
	double Distance2P( LFloatPt2D p = LFloatPt2D(0,0)) // Added by QZQ 
	{
		return sqrt( (x-p.x)* (x-p.x) + (y-p.y)* (y-p.y) );
	}
};

// ��ʾ��ȡ��ͼ�������ı����ͺ���
#include <afxtempl.h>
typedef	CList< LFloatPt2D, LFloatPt2D >	LFPtList;

//------------------------------------------�ļ�����������ĺ���
//--�����һ��ͼ����ļ���
CString	GetNextSerialFilename(CString Filename);

//--�����һ��ͼ����ļ���
CString	GetPrevSerialFilename(CString Filename);

//--�����һ��ͼ����ļ���,��һ��������ͼ��
BOOL    FindNextFile(CString &Filename);

//--�����һ��ͼ����ļ���,��һ��������ͼ��
BOOL    FindPrevFile(CString &Filename);

//--��õ�ǰ���ڵ�Ŀ¼
CString GetCurrentDirectory();

//--��ͼ���ļ�ȫ���л�����ڵ�Ŀ¼��
CString GetDir_Form_FullFileName(CString Filename);

//--��ͼ���ļ�ȫ���л�����ڵ��ļ���
CString GetFileName_Form_FullFileName(CString FullFileName);

//--�ж��Ƿ����ĳ��Ŀ¼���ļ�
BOOL    IsExistFile(CString Filename);

//--����ǰĿ¼�еķ�������Ҫ����ļ��������һ��CStringList�������
void	GetCurrrentDirFilename(CString Dir, CString Ext, CStringList &FileList);

//--��������ļ������ֵĸ����ĺ���
int		Get_Numbers_InFileName		  ( CString FileName );

//--��������ļ������ֵĺ���
long	Get_IDNo_InFileName			  ( CString FileName );

//--���������ļ������ֵĺ���
//void	ResetCurrentFileNameFromNumber( CString & FileName , int FileNum );
//--���ָ��Ŀ¼�µ�һ��ָ����չ���ļ�
CString Get_FirstFilename_From_Dir( CString Dir, CString FileExt);
//------------------------------------------�ļ���������ĺ�����������

//---���windows �汾�ĺ���
int		CheckOSVersion( CString &m_stInfo, CString &m_stServVersion);

long	getHardDriveComputerID ();

//--��õ�ǰӦ�ó����ȫ��
CString GetAppExeFileFullName();



// ���湤��������
class CIni  
{
public:
	CString csLineEnd;

	void RemoveMultiLineItem(const int idx);
	int	 FindItem		(const int iSection, const char * cItem, CString &csVal);
	int	 FindMultiItem	(const int iSection, const char * cItem, CString &csVal);
	bool RemoveSection	(const char *cSection);
	bool IsSection		(const int	 iSection);
	int	 InsertSection	(const char *cSection);
	int	 FindSection	(const char *cSection);

	bool SetMultiValue(const char * cSection, const char * cItem, const char * cVal);
	bool GetMultiValue(const char * cSection, const char * cItem, CString &cVal);

	bool SetValue(const char *cSection, const char *cItem, const COLORREF	crVal);
	bool SetValue(const char *cSection, const char *cItem, const bool		bVal);
	bool SetValue(const char *cSection, const char *cItem, const char		*cVal);
	bool SetValue(const char *cSection, const char *cItem, const double		dbVal);
	bool SetValue(const char *cSection, const char *cItem, const float		fVal);
	bool SetValue(const char *cSection, const char *cItem, const long		lVal);
	bool SetValue(const char *cSection, const char *cItem, const int		iVal);
	bool SetValue(const char *cSection, const char *cItem, const CRect		rcVal);
	bool SetValue(const char *cSection, const char *cItem, const CPoint		ptVal);

	bool GetValue(const char *cSection, const char *cItem, COLORREF &crVal);
	bool GetValue(const char *cSection, const char *cItem, bool		&bVal);
	bool GetValue(const char *cSection, const char *cItem, CString	&cVal);
	bool GetValue(const char *cSection, const char *cItem, double	&dbVal);
	bool GetValue(const char *cSection, const char *cItem, float	&fVal);
	bool GetValue(const char *cSection, const char *cItem, long		&lVal);
	bool GetValue(const char *cSection, const char *cItem, int		&iVal);
	bool GetValue(const char *cSection, const char *cItem, CRect	&rcVal);
	bool GetValue(const char *cSection, const char *cItem, CPoint	&ptVal);

	void Clear();
	bool Write(const char * cFileName);
	bool Read (const char * cFileName);
	CIni();
	virtual ~CIni();
	CStringArray	csList;
};

// ��ȷ����㷨����ʱ�����(��������)
class LTimeCount
{
private:	
	double			UseTime;				// �㷨����ʱ��(��λ:��)
	LARGE_INTEGER	Time, Frequency, old;	// ����ֵ
	
public:	
	void Start() // ��ʱ��ʼ
	{
		QueryPerformanceFrequency( &Frequency );
		QueryPerformanceCounter  ( &old );
		UseTime = 0.0;
	}
	void End() // ��ʱ����
	{
		QueryPerformanceCounter( &Time );
		UseTime = (double) ( Time.QuadPart - old.QuadPart) / (double)Frequency.QuadPart;
		//		TRACE("Use time = %20.10f(ms)\n", UseTime );
	}
	double GetUseTime() // ����㷨����ʱ��(��λ:��)
	{		
		return UseTime;
	}
};
//------------------------------------------��ȷ����㷨����ʱ����ඨ�����

#endif