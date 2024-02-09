// Project.h : main header file for the Project application
//

#if !defined(AFX_Project_H__C82E4675_62DC_11D2_82FD_0020AFF2F56F__INCLUDED_)
#define AFX_Project_H__C82E4675_62DC_11D2_82FD_0020AFF2F56F__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
//
// CProjectApp:
// See Project.cpp for the implementation of this class
//
/////////////////////////////////////////////////////////////////////////////

class CProjectApp : public CWinApp {
  public:
	CProjectApp();

	virtual BOOL InitInstance();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

#endif // !defined(AFX_Project_H__C82E4675_62DC_11D2_82FD_0020AFF2F56F__INCLUDED_)
