
// testImageProDll.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CtestImageProDllApp: 
// �йش����ʵ�֣������ testImageProDll.cpp
//

class CtestImageProDllApp : public CWinApp
{
public:
	CtestImageProDllApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CtestImageProDllApp theApp;