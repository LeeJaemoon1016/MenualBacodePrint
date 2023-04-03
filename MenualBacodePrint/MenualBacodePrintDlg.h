
// MenualBacodePrintDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"

#include "CommThread.h"	
#include "ini.h"

#define RXBUF_LENGTH	100000

// CMenualBacodePrintDlg 대화 상자
class CMenualBacodePrintDlg : public CDialogEx
{
// 생성입니다.
public:
	CMenualBacodePrintDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MENUALBACODEPRINT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg void OnSetfocusEditCellid(); //20210322 ljm
	afx_msg void OnSetfocusPalEdit(); //20210322 ljm
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	////////////serial////////////////////////////////////////////////////
	CCommThread *m_pCom;
	DWORD m_baudrate;
	BYTE m_port;
	int m_nBuffIndex;
	char m_rBuff[RXBUF_LENGTH];

	BOOL m_CommFlag;
	////////////serial////////////////////////////////////////////////////
	WORD	m_FocusCellPall; //20210323 ljm

	CString m_str_comport;
	CString m_str_baudlist;
	CString m_str_cellid;
	CString m_str_deviceid;
	CString m_str_week;
	CString m_str_countnum;
	CString m_str_barcode_x;
	CString m_str_barcode_y;
	CString m_str_deviceid_x;
	CString m_str_deviceid_y;
	CString m_str_week_x;
	CString m_str_week_y;
	CString m_str_bncode;
	CString m_str_labeltype;
	CString m_str_labellength;
	CString m_str_print_time;

	CEdit m_edit_CommNum;
	CEdit m_edit_CommRate;
	CEdit m_edit_cellid;
	CEdit m_edit_deviceid;
	CEdit m_edit_week;
	CEdit m_edit_countnum;

	CListBox m_list_log;

	int m_nWeekData[400];

	HANDLE m_hMutex;		// Mutex object

	CString m_array_send_massage[99];

	int m_labeltype;
	int m_labellength;

	int m_array_count;

	int m_excel_load;

	CString array_cellid[500];
	CString array_week[500];
	CString array_deviceid[500];
	CString array_bncode[500];

	CString GetPalletString(); //20210322 ljm

	int array_count;

	CString ApplicationPath(void);
	void Init_ReadINI(void);
	void GetWeekData(void);
	CString GetWeekCount(void);
	void Set_Week(void);
	afx_msg void OnBnClickedButtonComconnect();
	void SetLogWriteText(CString sS, BOOL err);
	void Init_System(void);
	void ClearBuffer(void);
	void WriteFile(const CString Filename, const CString FileContents);
	CEdit m_edit_barcode_x;
	CEdit m_edit_barcode_y;
	CEdit m_edit_device_x;
	CEdit m_edit_device_y;
	CEdit m_edit_week_x;
	CEdit m_edit_week_y;
	CButton m_Button_connect;
	afx_msg void OnBnClickedButtonSave();
	void CellIDSave(CString ss);

	afx_msg void OnBnClickedButtonMPrint();
	void Print();
	void SendMassageInit();
	CEdit m_edit_bncode;

	CButton m_check_15mm;
	CButton m_check_26mm;
	CButton m_check_40mm;

	afx_msg void OnBnClickedCheck15mm();
	afx_msg void OnBnClickedCheck26mm();
	afx_msg void OnBnClickedCheck40mm();
	afx_msg void OnBnClickedButtonRegPrint();
	afx_msg void OnBnClickedButtonMPrintcount();
	CEdit m_edit_print_time;

	// VD, VDSONY 신규 사항 추가. 20210513 ljm
	CButton m_check_qdvd;
	CButton m_check_qdvdc;
	CButton m_check_qdvdp;
	CButton m_check_qdvdm;
	CButton m_check_qdvdp90;
	CButton m_check_vdsony;
	CButton m_check_vdsonyc;
	CButton m_check_vdsonyp;
	CButton m_check_vdsonym;

	afx_msg void OnChangeEditCellid(); // 20210322 ljm
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	// VD, VDSONY 신규 사항 추가. 20210513 ljm
	afx_msg void OnBnClickedCheckQdvd();
	afx_msg void OnBnClickedCheckQdvdc();
	afx_msg void OnBnClickedCheckQdvdp();
	afx_msg void OnBnClickedCheckQdvdm();
	afx_msg void OnBnClickedCheckVdsony();
	afx_msg void OnBnClickedCheckVdsonyc();
	afx_msg void OnBnClickedCheckVdsonyp();
	afx_msg void OnBnClickedCheckVdsonym();
	afx_msg void OnBnClickedCheckQdvdp90();
};
