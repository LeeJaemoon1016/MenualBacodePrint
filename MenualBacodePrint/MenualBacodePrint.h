
// MenualBacodePrint.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMenualBacodePrintApp:
// �� Ŭ������ ������ ���ؼ��� MenualBacodePrint.cpp�� �����Ͻʽÿ�.
//

class CMenualBacodePrintApp : public CWinApp
{
public:
	CMenualBacodePrintApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMenualBacodePrintApp theApp;