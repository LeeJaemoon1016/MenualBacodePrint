
// MenualBacodePrintDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "MenualBacodePrint.h"
#include "MenualBacodePrintDlg.h"
#include "afxdialogex.h"

#include "XLEzAutomation.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMenualBacodePrintDlg ��ȭ ����



CMenualBacodePrintDlg::CMenualBacodePrintDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMenualBacodePrintDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMenualBacodePrintDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_COMM, m_edit_CommNum);
	DDX_Control(pDX, IDC_EDIT_COMMRATE, m_edit_CommRate);
	DDX_Control(pDX, IDC_EDIT_CELLID, m_edit_cellid);
	DDX_Control(pDX, IDC_EDIT_DEVICEID, m_edit_deviceid);
	DDX_Control(pDX, IDC_EDIT_WEEK, m_edit_week);
	DDX_Control(pDX, IDC_EDIT_COUNT, m_edit_countnum);
	DDX_Control(pDX, IDC_LIST_LOG, m_list_log);
	DDX_Control(pDX, IDC_EDIT_BAR_X, m_edit_barcode_x);
	DDX_Control(pDX, IDC_EDIT_BAR_Y, m_edit_barcode_y);
	DDX_Control(pDX, IDC_EDIT_DEVICE_X, m_edit_device_x);
	DDX_Control(pDX, IDC_EDIT_DEVICE_Y, m_edit_device_y);
	DDX_Control(pDX, IDC_EDIT_WEEK_X, m_edit_week_x);
	DDX_Control(pDX, IDC_EDIT_WEEK_Y, m_edit_week_y);
	DDX_Control(pDX, IDC_BUTTON_COMCONNECT, m_Button_connect);
	DDX_Control(pDX, IDC_EDIT_BNCODE, m_edit_bncode);

	DDX_Control(pDX, IDC_CHECK_15MM, m_check_15mm);
	DDX_Control(pDX, IDC_CHECK_26MM, m_check_26mm);
	DDX_Control(pDX, IDC_CHECK_40MM, m_check_40mm);

	DDX_Control(pDX, IDC_EDIT_PRINT_TIME, m_edit_print_time);

	// VD, VDSONY �ű� ���� �߰�. 20210513 ljm
	DDX_Control(pDX, IDC_CHECK_QDVD, m_check_qdvd);
	DDX_Control(pDX, IDC_CHECK_QDVDC, m_check_qdvdc);
	DDX_Control(pDX, IDC_CHECK_QDVDP, m_check_qdvdp);
	DDX_Control(pDX, IDC_CHECK_QDVDM, m_check_qdvdm);
	DDX_Control(pDX, IDC_CHECK_QDVDP90, m_check_qdvdp90);
	DDX_Control(pDX, IDC_CHECK_VDSONY, m_check_vdsony);
	DDX_Control(pDX, IDC_CHECK_VDSONYC, m_check_vdsonyc);
	DDX_Control(pDX, IDC_CHECK_VDSONYP, m_check_vdsonyp);
	DDX_Control(pDX, IDC_CHECK_VDSONYM, m_check_vdsonym);
}

BEGIN_MESSAGE_MAP(CMenualBacodePrintDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_COMCONNECT, &CMenualBacodePrintDlg::OnBnClickedButtonComconnect)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CMenualBacodePrintDlg::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_M_PRINT, &CMenualBacodePrintDlg::OnBnClickedButtonMPrint)
	ON_BN_CLICKED(IDC_CHECK_15MM, &CMenualBacodePrintDlg::OnBnClickedCheck15mm)
	ON_BN_CLICKED(IDC_CHECK_26MM, &CMenualBacodePrintDlg::OnBnClickedCheck26mm)
	ON_BN_CLICKED(IDC_CHECK_40MM, &CMenualBacodePrintDlg::OnBnClickedCheck40mm)
	ON_BN_CLICKED(IDC_BUTTON_REG_PRINT, &CMenualBacodePrintDlg::OnBnClickedButtonRegPrint)
	ON_BN_CLICKED(IDC_BUTTON_M_PRINTCOUNT, &CMenualBacodePrintDlg::OnBnClickedButtonMPrintcount)
	ON_EN_CHANGE(IDC_EDIT_CELLID, &CMenualBacodePrintDlg::OnChangeEditCellid)
	ON_EN_SETFOCUS(IDC_EDIT_CELLID, &CMenualBacodePrintDlg::OnSetfocusEditCellid)
	ON_EN_SETFOCUS(IDC_EDIT_DEVICE_X, &CMenualBacodePrintDlg::OnSetfocusPalEdit)

	// VD, VDSONY �ű� ���� �߰�. 20210513 ljm
	ON_BN_CLICKED(IDC_CHECK_QDVD, &CMenualBacodePrintDlg::OnBnClickedCheckQdvd)
	ON_BN_CLICKED(IDC_CHECK_QDVDC, &CMenualBacodePrintDlg::OnBnClickedCheckQdvdc)
	ON_BN_CLICKED(IDC_CHECK_QDVDP, &CMenualBacodePrintDlg::OnBnClickedCheckQdvdp)
	ON_BN_CLICKED(IDC_CHECK_QDVDM, &CMenualBacodePrintDlg::OnBnClickedCheckQdvdm)
	ON_BN_CLICKED(IDC_CHECK_QDVDP90, &CMenualBacodePrintDlg::OnBnClickedCheckQdvdp90)
	ON_BN_CLICKED(IDC_CHECK_VDSONY, &CMenualBacodePrintDlg::OnBnClickedCheckVdsony)
	ON_BN_CLICKED(IDC_CHECK_VDSONYC, &CMenualBacodePrintDlg::OnBnClickedCheckVdsonyc)
	ON_BN_CLICKED(IDC_CHECK_VDSONYP, &CMenualBacodePrintDlg::OnBnClickedCheckVdsonyp)
	ON_BN_CLICKED(IDC_CHECK_VDSONYM, &CMenualBacodePrintDlg::OnBnClickedCheckVdsonym)
END_MESSAGE_MAP()


// CMenualBacodePrintDlg �޽��� ó����

BOOL CMenualBacodePrintDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	Set_Week();

	Init_System();
	Init_ReadINI();

	m_excel_load = 0;

#ifdef SDV_FOR_USE
#else
	m_check_codeqrh.ShowWindow(false);
	m_check_uniquecodeqr.ShowWindow(false);
	m_check_chinesecodeqr.ShowWindow(false);
	m_check_codeqrh23.ShowWindow(false);
#endif

	CString sTemp;
	//	sTemp = "ManualBarcodPrint v1.0.0 2019-11-09"; //
	//	sTemp = "ManualBarcodPrint v1.0.5 2021-02-26"; // ��� ���� x, y ��ǥ ���� �� ���ڵ� ũ�� ����, 12*40 ���� Ÿ�� �߰� ��... �������� ���α׷� ����...
	//	sTemp = "ManualBarcodPrint v1.0.5 2021-03-10"; // Panel, C-PBA �� �ű� ����
	//	sTemp = "ManualBarcodPrint v1.0.5 2021-03-18"; // QD VD, QD Sony ���� ����� ���� �� Ÿ�� �߰�, QD Sony �� ����.
	//	sTemp = "Manual Barcod / QR OC Label Printer v1.0.5 2021-03-19"; // QD VD, QD Sony ���� ��� ��� �и� �� ���ʿ� üũ�ڽ� ���� ó��.
	//	sTemp = "Manual Barcod / QR OC Label Printer v1.0.6 2021-03-24"; // ���ڵ� ��ĵ�� �ڵ� CellID �Է�, ����Ʈ ��� �߰�.
	//	sTemp = "Manual QR OC Label Printer v1.0.7 2021-05-13"; // VD QD, VD Sony �ű� ���� �߰�
	//	sTemp = "Manual QR OC Label Printer v1.0.8 2021-05-20"; // VD QD P 90 Degrees Rotate ���� �߰�
	sTemp = "Manual QR OC Label Printer v1.0.9 2021-05-21"; // VD QD P 90 Degrees Rotate ���� ����, C-PBA Label�� ����� P-PBA ��� ��� �߰�.


	SetWindowText(sTemp);
	m_edit_cellid.SetWindowText(""); //�ʱ� CellID�� �������� �����ؾߵȴ�.
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CMenualBacodePrintDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMenualBacodePrintDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CMenualBacodePrintDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

///////////////////////////////////////////////////////////////////////////////////////////////

CString CMenualBacodePrintDlg::ApplicationPath()
{
	CString strFolderPath;

	// ���� ���α׷��� ���� ������ �ִ� �������� ������
	::GetModuleFileName(NULL, strFolderPath.GetBuffer(MAX_PATH), MAX_PATH);
	strFolderPath.ReleaseBuffer();

	if (strFolderPath.Find('\\') != -1)
	{
		for (int i = strFolderPath.GetLength() - 1; i >= 0; i--)
		{
			TCHAR ch = strFolderPath[i];
			strFolderPath.Delete(i);
			if (ch == '\\')	break;
		}
	}

	return strFolderPath;
}

void CMenualBacodePrintDlg::Init_ReadINI(void)
{
	CString strINIPath;

	strINIPath = ApplicationPath();
	strINIPath += "\\MenualBacodeInfo.ini";

	CString strSection, strKey, strValue;
	TCHAR tmp[255];

	strSection = "COMM";   // ����
	strKey = "ComPort";
	GetPrivateProfileString(strSection, strKey, "1", tmp, sizeof(tmp), strINIPath);
	strValue = CString(tmp);
	m_str_comport = strValue;   // ��
	m_edit_CommNum.SetWindowText(strValue);
	strKey = "Baud";
	GetPrivateProfileString(strSection, strKey, "9600", tmp, sizeof(tmp), strINIPath);
	strValue = CString(tmp);
	m_str_baudlist = strValue;  // ��
	m_edit_CommRate.SetWindowText(strValue);

	strSection = "Print";   // ����
	strKey = "CELLID";
	GetPrivateProfileString(strSection, strKey, "1234567890", tmp, sizeof(tmp), strINIPath);
	strValue = CString(tmp);
	m_str_cellid = strValue;   // ��
	//m_edit_cellid.SetWindowText(strValue); //Ŭ���̾�Ʈ ���� �� CellID�� �ڲ� 10�ڸ� �־ EN_CHANGE�� �����Ű�� ����. 20210324 ljm
	strKey = "DEVICEID";
	GetPrivateProfileString(strSection, strKey, "1234567890-123", tmp, sizeof(tmp), strINIPath);
	strValue = CString(tmp);
	m_str_deviceid = strValue;   // ��
	m_edit_deviceid.SetWindowText(strValue);
	strKey = "WEEK";
	GetPrivateProfileString(strSection, strKey, "0000", tmp, sizeof(tmp), strINIPath);
	strValue = CString(tmp);
	m_str_week = strValue;   // ��
	m_edit_week.SetWindowText(strValue);
	strKey = "BNCODE";
	GetPrivateProfileString(strSection, strKey, "BN12-345678", tmp, sizeof(tmp), strINIPath);
	strValue = CString(tmp);
	m_str_bncode = strValue;   // ��
	m_edit_bncode.SetWindowText(strValue);
	strKey = "LABELTYPE";
	GetPrivateProfileString(strSection, strKey, "1", tmp, sizeof(tmp), strINIPath);
	strValue = CString(tmp);
	m_str_labeltype = strValue;   // ��
#ifdef SDV_FOR_USE
#else
	if (m_str_labeltype == "4" || m_str_labeltype == "5" || m_str_labeltype == "6" || m_str_labeltype == "7" || m_str_labeltype == "9")
		m_str_labeltype = "1";
#endif

	m_labeltype = 1;

	if (m_str_labeltype == "1")
	{
		m_labeltype = 1;
		m_check_qdvd.SetCheck(1);
		m_check_qdvdc.SetCheck(0);
		m_check_qdvdp.SetCheck(0);
		m_check_qdvdm.SetCheck(0);
		m_check_vdsony.SetCheck(0);
		m_check_vdsonyc.SetCheck(0);
		m_check_vdsonyp.SetCheck(0);
		m_check_vdsonym.SetCheck(0);
		m_check_qdvdp90.SetCheck(0);
	}
	else if (m_str_labeltype == "2")
	{
		m_labeltype = 2;
		m_check_qdvd.SetCheck(0);
		m_check_qdvdc.SetCheck(1);
		m_check_qdvdp.SetCheck(0);
		m_check_qdvdm.SetCheck(0);
		m_check_vdsony.SetCheck(0);
		m_check_vdsonyc.SetCheck(0);
		m_check_vdsonyp.SetCheck(0);
		m_check_vdsonym.SetCheck(0);
		m_check_qdvdp90.SetCheck(0);
	}
	else if (m_str_labeltype == "3")
	{
		m_labeltype = 3;
		m_check_qdvd.SetCheck(0);
		m_check_qdvdc.SetCheck(0);
		m_check_qdvdp.SetCheck(1);
		m_check_qdvdm.SetCheck(0);
		m_check_vdsony.SetCheck(0);
		m_check_vdsonyc.SetCheck(0);
		m_check_vdsonyp.SetCheck(0);
		m_check_vdsonym.SetCheck(0);
		m_check_qdvdp90.SetCheck(0);
	}
	else if (m_str_labeltype == "4")
	{
		m_labeltype = 4;
		m_check_qdvd.SetCheck(0);
		m_check_qdvdc.SetCheck(0);
		m_check_qdvdp.SetCheck(0);
		m_check_qdvdm.SetCheck(1);
		m_check_vdsony.SetCheck(0);
		m_check_vdsonyc.SetCheck(0);
		m_check_vdsonyp.SetCheck(0);
		m_check_vdsonym.SetCheck(0);
		m_check_qdvdp90.SetCheck(0);
	}
	else if (m_str_labeltype == "5")
	{
		m_labeltype = 5;
		m_check_qdvd.SetCheck(0);
		m_check_qdvdc.SetCheck(0);
		m_check_qdvdp.SetCheck(0);
		m_check_qdvdm.SetCheck(0);
		m_check_vdsony.SetCheck(1);
		m_check_vdsonyc.SetCheck(0);
		m_check_vdsonyp.SetCheck(0);
		m_check_vdsonym.SetCheck(0);
		m_check_qdvdp90.SetCheck(0);
	}
	else if (m_str_labeltype == "6")
	{
		m_labeltype = 6;
		m_check_qdvd.SetCheck(0);
		m_check_qdvdc.SetCheck(0);
		m_check_qdvdp.SetCheck(0);
		m_check_qdvdm.SetCheck(0);
		m_check_vdsony.SetCheck(0);
		m_check_vdsonyc.SetCheck(1);
		m_check_vdsonyp.SetCheck(0);
		m_check_vdsonym.SetCheck(0);
		m_check_qdvdp90.SetCheck(0);
	}
	else if (m_str_labeltype == "7")
	{
		m_labeltype = 7;
		m_check_qdvd.SetCheck(0);
		m_check_qdvdc.SetCheck(0);
		m_check_qdvdp.SetCheck(0);
		m_check_qdvdm.SetCheck(0);
		m_check_vdsony.SetCheck(0);
		m_check_vdsonyc.SetCheck(0);
		m_check_vdsonyp.SetCheck(1);
		m_check_vdsonym.SetCheck(0);
		m_check_qdvdp90.SetCheck(0);
	}
	else if (m_str_labeltype == "8")
	{
		m_labeltype = 8;
		m_check_qdvd.SetCheck(0);
		m_check_qdvdc.SetCheck(0);
		m_check_qdvdp.SetCheck(0);
		m_check_qdvdm.SetCheck(0);
		m_check_vdsony.SetCheck(0);
		m_check_vdsonyc.SetCheck(0);
		m_check_vdsonyp.SetCheck(0);
		m_check_vdsonym.SetCheck(1);
		m_check_qdvdp90.SetCheck(0);
	}
	else if (m_str_labeltype == "9")
	{
		m_labeltype = 9;
		m_check_qdvd.SetCheck(0);
		m_check_qdvdc.SetCheck(0);
		m_check_qdvdp.SetCheck(0);
		m_check_qdvdm.SetCheck(0);
		m_check_vdsony.SetCheck(0);
		m_check_vdsonyc.SetCheck(0);
		m_check_vdsonyp.SetCheck(0);
		m_check_vdsonym.SetCheck(0);
		m_check_qdvdp90.SetCheck(1);
	}

	strKey = "LABELLENGTH";
	GetPrivateProfileString(strSection, strKey, "1", tmp, sizeof(tmp), strINIPath);
	strValue = CString(tmp);
	m_str_labellength = strValue;   // ��
	m_str_labellength = "1"; // ������ 8/26mm ����
	m_labellength = 1; // 1 -> 2 ������ 8/26mm ����

	if (m_str_labellength == "1")
	{
		m_labellength = 1;
		m_check_15mm.SetCheck(1);
		m_check_26mm.SetCheck(0);
		m_check_40mm.SetCheck(0);
	}
	else if (m_str_labellength == "2")
	{
		m_labellength = 2;
		m_check_15mm.SetCheck(0);
		m_check_26mm.SetCheck(1);
		m_check_40mm.SetCheck(0);
	}
	else if (m_str_labellength == "3")
	{
		m_labellength = 3;
		m_check_15mm.SetCheck(0);
		m_check_26mm.SetCheck(0);
		m_check_40mm.SetCheck(1);
	}
	/*strKey = "NUM";
	GetPrivateProfileString(strSection, strKey, "Not Info", tmp, sizeof(tmp), strINIPath);
	strValue = CString(tmp);
	m_str_countnum = strValue;   // ��
	m_edit_countnum.SetWindowText(strValue);*/

	strSection = "PrintCoordinate";   // ����
	strKey = "BarcodeX";
	GetPrivateProfileString(strSection, strKey, "160", tmp, sizeof(tmp), strINIPath);
	strValue = CString(tmp);
	m_str_barcode_x = strValue;   // ��
	m_edit_barcode_x.SetWindowText(strValue);
	strKey = "BarcodeY";
	GetPrivateProfileString(strSection, strKey, "10", tmp, sizeof(tmp), strINIPath);
	strValue = CString(tmp);
	m_str_barcode_y = strValue;   // ��
	m_edit_barcode_y.SetWindowText(strValue);
	strKey = "PrintTime";
	GetPrivateProfileString(strSection, strKey, "100", tmp, sizeof(tmp), strINIPath);
	strValue = CString(tmp);
	strValue = "100";
	m_str_print_time = strValue;   // ��
	m_edit_print_time.SetWindowText(strValue);
	/*strKey = "DeviceIDX";
	GetPrivateProfileString(strSection, strKey, "Not Info", tmp, sizeof(tmp), strINIPath);
	strValue = CString(tmp);
	m_str_deviceid_x = strValue;   // ��
	m_edit_device_x.SetWindowText(strValue);
	strKey = "DeviceIDY";
	GetPrivateProfileString(strSection, strKey, "Not Info", tmp, sizeof(tmp), strINIPath);
	strValue = CString(tmp);
	m_str_deviceid_y = strValue;   // ��
	m_edit_device_y.SetWindowText(strValue);
	strKey = "WeekX";
	GetPrivateProfileString(strSection, strKey, "Not Info", tmp, sizeof(tmp), strINIPath);
	strValue = CString(tmp);
	m_str_week_x = strValue;   // ��
	m_edit_week_x.SetWindowText(strValue);
	strKey = "WeekY";
	GetPrivateProfileString(strSection, strKey, "Not Info", tmp, sizeof(tmp), strINIPath);
	strValue = CString(tmp);
	m_str_week_y = strValue;   // ��
	m_edit_week_y.SetWindowText(strValue);*/
}

void CMenualBacodePrintDlg::GetWeekData(void)
{
	CString strWeekDataPath;

	CIni		iniWeek;			//by kwonhk 20111219
	CString strYearWeek;

	char *token;
	char seps[5];

	CFile file;
	CString str;
	int nFindFile;

	nFindFile = 0;

	strWeekDataPath = ApplicationPath();
	strWeekDataPath += "\\WeekData.ini";
	//strWeekDataPath.Format("%s\\WeekData.ini", ApplicationPath());

	if (!file.Open(strWeekDataPath, CFile::modeRead))
	{
		str.Format("%s Not Find File. WeekData Calculator Fail", "WeekData.ini");

		//SetLogWriteText(str);

		AfxMessageBox(str, MB_ICONEXCLAMATION);

		nFindFile = 0;
	}
	else
	{
		str.Format("%s File Fien Success", "WeekData.ini");

		//SetLogWriteText(str);

		nFindFile = 1;
		file.Close();
	}

	COleDateTime date = COleDateTime::GetCurrentTime();
	CString strFileChangeTime = date.Format("%H");

	CTime	Time = CTime::GetCurrentTime();
	CString	strTime;

	CString strDays;
	CString strWeeks;
	CString strBeforeWeekVal;
	CString strBeforeWeek;
	CString strFirstWeek;
	CString strLastWeek;
	CString strLastWeekTitle;
	CString strNextFirstWeek;
	CString sTmp;

	int nBeforWeekVal;
	int nBeforeStart;
	int nBeforeEnd;
	int nFirstStart;
	int nFirstEnd;
	int nLastStart;
	int nLastEnd;

	int nNextFirstStart;
	int nNextFirstEnd;

	int nWeeks;
	int nDays;

	int i;
	int nWeekCount;
	int k;

	int nDiffCount;

	memset(m_nWeekData, 0, sizeof(int) * 400);

	seps[0] = ':';//������ ����.
	seps[1] = '\r';
	seps[2] = '\n';
	seps[3] = 0x0;

	if (nFindFile == 1)
	{
		iniWeek.SetPathName(ApplicationPath() + _T("\\WeekData.ini"));		//by kwonhk 20111219

		strYearWeek.Format("%d_WEEK_DATA", Time.GetYear());				//by kwonhk 20111219

		strDays = iniWeek.GetString(strYearWeek, "DAYS", _T(""));
		strWeeks = iniWeek.GetString(strYearWeek, "WEEKS", _T(""));

		nDays = atoi(strDays);

		nWeeks = atoi(strWeeks);

		strBeforeWeekVal = iniWeek.GetString(strYearWeek, "BEFORE_WEEK_VAL", _T(""));

		nBeforWeekVal = atoi(strBeforeWeekVal);

		strBeforeWeek = iniWeek.GetString(strYearWeek, "BEFORE_WEEK", _T(""));

		token = strtok((LPSTR)(LPCTSTR)strBeforeWeek, seps);
		sTmp.Format("%s", token);
		nBeforeStart = atoi(sTmp);

		token = strtok(NULL, seps); //IDD MSB
		sTmp.Format("%s", token);
		nBeforeEnd = atoi(sTmp);

		for (i = nBeforeStart; i <= nBeforeEnd; i++)
		{
			m_nWeekData[i] = nBeforWeekVal;
		}

		strFirstWeek = iniWeek.GetString(strYearWeek, "01_WEEK", _T(""));

		token = strtok((LPSTR)(LPCTSTR)strFirstWeek, seps);
		sTmp.Format("%s", token);
		nFirstStart = atoi(sTmp);

		token = strtok(NULL, seps); //IDD MSB
		sTmp.Format("%s", token);
		nFirstEnd = atoi(sTmp);

		nWeekCount = 1;
		for (i = nFirstStart; i <= nFirstEnd; i++)	//3:9
		{
			m_nWeekData[i] = nWeekCount;
		}

		nDiffCount = nFirstEnd - nFirstStart;	// v32.5 kwonhk 20130107

		if (nDiffCount == 6)			// v32.5 kwonhk 20130107
		{
			for (k = nFirstEnd + 1; k <= nDays; k++) // 4
			{
				m_nWeekData[k] = (k) / 7 + 1;
			}
		}
		else if (nDiffCount == 5)	// v32.5 kwonhk 20130107
		{
			for (k = nFirstEnd + 1; k <= nDays; k++) // 4
			{
				m_nWeekData[k] = (k + 1) / 7 + 1;
			}
		}
		else if (nDiffCount == 4)	// v32.5 kwonhk 20130107
		{
			for (k = nFirstEnd + 1; k <= nDays; k++) // 4
			{
				m_nWeekData[k] = (k + 2) / 7 + 1;
			}
		}
		else if (nDiffCount == 3)	// v32.5 kwonhk 20130107
		{
			for (k = nFirstEnd + 1; k <= nDays; k++) // 4
			{
				m_nWeekData[k] = (k + 3) / 7 + 1;
			}
		}
		else if (nDiffCount == 2)	// v32.5 kwonhk 20130107
		{
			for (k = nFirstEnd + 1; k <= nDays; k++) // 4
			{
				m_nWeekData[k] = (k + 4) / 7 + 1;
			}
		}
		else if (nDiffCount == 1)	// v32.5 kwonhk 20130107
		{
			for (k = nFirstEnd + 1; k <= nDays; k++) // 4
			{
				m_nWeekData[k] = (k + 5) / 7 + 1;
			}
		}
		else
		{
			for (k = nFirstEnd + 1; k <= nDays; k++) // 4
			{
				m_nWeekData[k] = (k - nFirstStart) / 7 + 1;
			}
		}

		strLastWeekTitle.Format("%s_WEEK", strWeeks);

		strLastWeek = iniWeek.GetString(strYearWeek, strLastWeekTitle, _T(""));

		token = strtok((LPSTR)(LPCTSTR)strLastWeek, seps);
		sTmp.Format("%s", token);
		nLastStart = atoi(sTmp);

		token = strtok(NULL, seps); //IDD MSB
		sTmp.Format("%s", token);
		nLastEnd = atoi(sTmp);

		for (i = nLastStart; i <= nLastEnd; i++)
		{
			m_nWeekData[i] = nWeeks;
		}

		strNextFirstWeek = iniWeek.GetString(strYearWeek, "NEXT_01_WEEK", _T(""));

		token = strtok((LPSTR)(LPCTSTR)strNextFirstWeek, seps);
		sTmp.Format("%s", token);
		nNextFirstStart = atoi(sTmp);

		token = strtok(NULL, seps); //IDD MSB
		sTmp.Format("%s", token);
		nNextFirstEnd = atoi(sTmp);

		for (i = nNextFirstStart; i <= nNextFirstEnd; i++)
		{
			m_nWeekData[i] = 1;
		}
	}
	else
	{
		for (k = 1; k <= 365; k++) //
		{
			m_nWeekData[k] = (k - 1) / 7 + 1;
		}

	}
}

CString CMenualBacodePrintDlg::GetWeekCount(void)		//by kwonhk 20111219   v32.2  nate ������ �ҽ� �༭ ������ �� 
{

	COleDateTime date = COleDateTime::GetCurrentTime();
	CString strFileChangeTime = date.Format("%H");

	CTime	Time = CTime::GetCurrentTime();
	CString	strTime;

	int nMonth;
	int nDay;
	int nRetDay;
	int nYearDay;
	int nYear;
	int nDiffYear;

	CString strWeekData;
	int nWeeks;

	nYear = Time.GetYear();

	nMonth = Time.GetMonth();

	nDay = Time.GetDay();

	if (nMonth == 1)
	{
		nRetDay = nDay;
	}
	else if (nMonth == 2)
	{
		nRetDay = 31 + nDay;
	}
	else if (nMonth == 3)
	{
		nDiffYear = nYear - 2008;
		nYearDay = nDiffYear % 4;

		if (nYearDay == 0)	//�����̸� 29�� �ƴϸ� 28��
		{
			nRetDay = 31 + 29 + nDay;
		}
		else
		{
			nRetDay = 31 + 28 + nDay;
		}
	}
	else if (nMonth == 4)
	{
		nDiffYear = nYear - 2008;
		nYearDay = nDiffYear % 4;

		if (nYearDay == 0)	//�����̸� 29�� �ƴϸ� 28��
		{
			nRetDay = 31 + 29 + 31 + nDay;
		}
		else
		{
			nRetDay = 31 + 28 + 31 + nDay;
		}
	}
	else if (nMonth == 5)
	{
		nDiffYear = nYear - 2008;
		nYearDay = nDiffYear % 4;

		if (nYearDay == 0)	//�����̸� 29�� �ƴϸ� 28��
		{
			nRetDay = 31 + 29 + 31 + 30 + nDay;
		}
		else
		{
			nRetDay = 31 + 28 + 31 + 30 + nDay;
		}
	}
	else if (nMonth == 6)
	{
		nDiffYear = nYear - 2008;
		nYearDay = nDiffYear % 4;

		if (nYearDay == 0)	//�����̸� 29�� �ƴϸ� 28��
		{
			nRetDay = 31 + 29 + 31 + 30 + 31 + nDay;
		}
		else
		{
			nRetDay = 31 + 28 + 31 + 30 + 31 + nDay;
		}
	}
	else if (nMonth == 7)
	{
		nDiffYear = nYear - 2008;
		nYearDay = nDiffYear % 4;

		if (nYearDay == 0)	//�����̸� 29�� �ƴϸ� 28��
		{
			nRetDay = 31 + 29 + 31 + 30 + 31 + 30 + nDay;
		}
		else
		{
			nRetDay = 31 + 28 + 31 + 30 + 31 + 30 + nDay;
		}
	}
	else if (nMonth == 8)
	{
		nDiffYear = nYear - 2008;
		nYearDay = nDiffYear % 4;

		if (nYearDay == 0)	//�����̸� 29�� �ƴϸ� 28��
		{
			nRetDay = 31 + 29 + 31 + 30 + 31 + 30 + 31 + nDay;
		}
		else
		{
			nRetDay = 31 + 28 + 31 + 30 + 31 + 30 + 31 + nDay;
		}
	}
	else if (nMonth == 9)
	{
		nDiffYear = nYear - 2008;
		nYearDay = nDiffYear % 4;

		if (nYearDay == 0)	//�����̸� 29�� �ƴϸ� 28��
		{
			nRetDay = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + nDay;
		}
		else
		{
			nRetDay = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + nDay;
		}
	}
	else if (nMonth == 10)
	{
		nDiffYear = nYear - 2008;
		nYearDay = nDiffYear % 4;

		if (nYearDay == 0)	//�����̸� 29�� �ƴϸ� 28��
		{
			nRetDay = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + nDay;
		}
		else
		{
			nRetDay = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + nDay;
		}
	}
	else if (nMonth == 11)
	{
		nDiffYear = nYear - 2008;
		nYearDay = nDiffYear % 4;

		if (nYearDay == 0)	//�����̸� 29�� �ƴϸ� 28��
		{
			nRetDay = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + nDay;
		}
		else
		{
			nRetDay = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + nDay;
		}
	}
	else if (nMonth == 12)
	{
		nDiffYear = nYear - 2008;
		nYearDay = nDiffYear % 4;

		if (nYearDay == 0)	//�����̸� 29�� �ƴϸ� 28��
		{
			nRetDay = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + nDay;
		}
		else
		{
			nRetDay = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + nDay;
		}
	}

	nWeeks = m_nWeekData[nRetDay];

	if (nRetDay == 366)				//v32.2 kwonhk 20121231
	{
		strWeekData.Format("%d%0.2d", (nYear - 2000) + 1, nWeeks);
	}
	else
	{
		strWeekData.Format("%d%0.2d", (nYear - 2000), nWeeks);
	}

	return strWeekData;
}

void CMenualBacodePrintDlg::Set_Week(void)
{
	GetWeekData();
	CString strWeeks;
	strWeeks = GetWeekCount();

	m_edit_week.SetWindowText(strWeeks);

	m_str_week = strWeeks;
}

void CMenualBacodePrintDlg::OnBnClickedButtonComconnect()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	BYTE tempComport;
	DWORD tempRate;
	m_edit_CommNum.GetWindowTextA(m_str_comport);
	m_edit_CommRate.GetWindowTextA(m_str_baudlist);
	tempComport = (BYTE)_ttoi(m_str_comport);
	tempRate = (DWORD)_ttoi(m_str_baudlist);

	m_pCom->hCommWnd = 0;// this->m_hWnd;

	CString strMsg;

	if (m_CommFlag == 0)
	{
		if (!m_pCom->OpenPort(tempComport, tempRate))
		{
			m_Button_connect.SetWindowText("Connecting");
			m_edit_CommNum.EnableWindow(TRUE);
			m_edit_CommRate.EnableWindow(TRUE);

			strMsg.Format("COM%d Connect Fail", tempComport);
			SetLogWriteText(strMsg, TRUE);
		}
		else
		{
			m_CommFlag = 1;

			ClearBuffer();
			m_nBuffIndex = 0;

			m_Button_connect.SetWindowText("Disconnect");
			m_edit_CommNum.EnableWindow(FALSE);
			m_edit_CommRate.EnableWindow(FALSE);

			strMsg.Format("COM%d Connect Success", tempComport);
			SetLogWriteText(strMsg, TRUE);
		}
	}
	else
	{
		m_pCom->ClosePort();
		m_CommFlag = 0;

		m_Button_connect.SetWindowText("Connencting");
		m_edit_CommNum.EnableWindow(TRUE);
		m_edit_CommRate.EnableWindow(TRUE);

		strMsg.Format("COM%d Disconnect", tempComport);
		SetLogWriteText(strMsg, TRUE);
	}
}

void CMenualBacodePrintDlg::SetLogWriteText(CString sS, BOOL err)
{
	CTime LogTime2;
	LogTime2 = CTime::GetCurrentTime();
	CString strTime2 = LogTime2.Format("%Y-%m-%d %H-%M-%S");
	CString strTime3 = LogTime2.Format("%Y-%m-%d %H");


	CString sLog;
	sLog.Format("[%s] %s", strTime2, sS);

	m_list_log.AddString(sLog);
	m_list_log.SetTopIndex(m_list_log.GetCount() - 1);

	CString FilePath = ApplicationPath() + "\\LOG";
	CString strMakeFolder, strTemp;

	int exist = GetFileAttributes(FilePath);
	if (exist < 0) ::CreateDirectory(FilePath, NULL); // �ΰ� ���� ����

	strMakeFolder = FilePath;

	//���� folder �� ���� ���� �ʴ´ٸ� Return �� ��Ų��.
	CFileFind find;
	if (find.FindFile(strMakeFolder) == 0)
		return;

	strTemp.Format("\\MBP_%s.txt", strTime3);
	strMakeFolder = strMakeFolder + strTemp;

	//CString sTmp;
	//sTmp.Format("%s%s", strTime2, strMsg);
	WriteFile(strMakeFolder, sLog);
}

void CMenualBacodePrintDlg::Init_System(void)
{
	m_pCom = new CCommThread;

	m_CommFlag = 0;

	m_hMutex = ::CreateMutex(NULL, FALSE, NULL);	//added by kwonhk 20080625
}

void CMenualBacodePrintDlg::ClearBuffer(void)
{
	memset(m_rBuff, 0, sizeof(m_rBuff));
}

void CMenualBacodePrintDlg::WriteFile(const CString Filename, const CString FileContents)
{
	::WaitForSingleObject(m_hMutex, 100);		//was 500 by kwonhk 20070308
	//	CFile file;
	CStdioFile f;

	CFileException fe;
	CString s;

	if (Filename.IsEmpty())
	{
		return;
	}
	else
	{
		if (f.Open(_T(Filename), CFile::modeWrite | CFile::modeCreate |
			CFile::shareDenyNone |					//�ٸ������� �а� ���Ⱑ �����ϵ��� �Ѵ�.
			CFile::modeNoTruncate, &fe) == FALSE)	//�乮���� �������� �ȴ´�.
		{
			return;
		}

		try
		{
			f.SeekToEnd();

			s.Format("%s\r\n", FileContents);

			f.WriteString(s);
		}
		catch (CException* e)
		{
			e->Delete();
		}
		f.Close();

	}
	// ���۸� ��� ����.

	::ReleaseMutex(m_hMutex);
}

void CMenualBacodePrintDlg::OnBnClickedButtonSave()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strINIPath;

	strINIPath = ApplicationPath();
	strINIPath += "\\MenualBacodeInfo.ini";

	CString strSection, strKey, strValue;

	strSection = "COMM";   // ����
	strKey = "ComPort";
	m_edit_CommNum.GetWindowText(strValue);
	WritePrivateProfileString(strSection, strKey, strValue, strINIPath);
	strKey = "Baud";
	m_edit_CommRate.GetWindowText(strValue);
	WritePrivateProfileString(strSection, strKey, strValue, strINIPath);

	strSection = "Print";   // ����
	strKey = "CELLID";
	m_edit_cellid.GetWindowText(strValue);
	WritePrivateProfileString(strSection, strKey, strValue, strINIPath);
	strKey = "DEVICEID";
	m_edit_deviceid.GetWindowText(strValue);
	WritePrivateProfileString(strSection, strKey, strValue, strINIPath);
	strKey = "WEEK";
	m_edit_week.GetWindowText(strValue);
	WritePrivateProfileString(strSection, strKey, strValue, strINIPath);
	strKey = "BNCODE";
	m_edit_bncode.GetWindowText(strValue);
	WritePrivateProfileString(strSection, strKey, strValue, strINIPath);
	strKey = "LABELTYPE";
	//m_edit_deviceid.GetWindowText(strValue);
	strValue = m_str_labeltype;
	WritePrivateProfileString(strSection, strKey, strValue, strINIPath);
	strKey = "LABELLENGTH";
	//m_edit_deviceid.GetWindowText(strValue);
	strValue = m_str_labellength;
	WritePrivateProfileString(strSection, strKey, strValue, strINIPath);

	/*strSection = "Print";   // ����
	strKey = "CELLID";
	m_edit_cellid.GetWindowText(strValue);
	WritePrivateProfileString(strSection, strKey, strValue, strINIPath);
	strKey = "DEVICEID";
	m_edit_deviceid.GetWindowText(strValue);
	WritePrivateProfileString(strSection, strKey, strValue, strINIPath);
	strKey = "NUM";
	m_edit_countnum.GetWindowText(strValue);
	WritePrivateProfileString(strSection, strKey, strValue, strINIPath);*/

	strSection = "PrintCoordinate";   // ����
	strKey = "BarcodeX";
	m_edit_barcode_x.GetWindowText(strValue);
	WritePrivateProfileString(strSection, strKey, strValue, strINIPath);
	strKey = "BarcodeY";
	m_edit_barcode_y.GetWindowText(strValue);
	WritePrivateProfileString(strSection, strKey, strValue, strINIPath);
	strKey = "PrintTime";
	m_edit_print_time.GetWindowText(strValue);
	strValue = "100";
	WritePrivateProfileString(strSection, strKey, strValue, strINIPath);
	/*strKey = "DeviceIDX";
	m_edit_device_x.GetWindowText(strValue);
	WritePrivateProfileString(strSection, strKey, strValue, strINIPath);
	strKey = "DeviceIDY";
	m_edit_device_y.GetWindowText(strValue);
	WritePrivateProfileString(strSection, strKey, strValue, strINIPath);
	strKey = "WeekX";
	m_edit_week_x.GetWindowText(strValue);
	WritePrivateProfileString(strSection, strKey, strValue, strINIPath);
	strKey = "WeekY";
	m_edit_week_y.GetWindowText(strValue);
	WritePrivateProfileString(strSection, strKey, strValue, strINIPath);*/

	CString strMsg;
	strMsg.Format("ini Setting Save");
	SetLogWriteText(strMsg, TRUE);
}

void CMenualBacodePrintDlg::CellIDSave(CString ss)
{
	CString strINIPath;

	strINIPath = ApplicationPath();
	strINIPath += "\\MenualBacodeInfo.ini";

	CString strSection, strKey, strValue;

	strSection = "Print";   // ����
	strKey = "CELLID";
	m_edit_cellid.GetWindowText(strValue);
	WritePrivateProfileString(strSection, strKey, strValue, strINIPath);


	CString strMsg;
	strMsg.Format("CELLID Save");
	SetLogWriteText(strMsg, TRUE);
}

void CMenualBacodePrintDlg::OnBnClickedButtonMPrint()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_CommFlag == TRUE)
	{
		Init_ReadINI();

		SendMassageInit();

		CString str;
		for (int i = 0; i < m_array_count; i++)
		{
			str = m_array_send_massage[i];
			str += "\r\n";
			m_pCom->WriteComm((BYTE *)(LPSTR)(LPCTSTR)str, str.GetLength());
			Sleep(atoi(m_str_print_time));
		}
	}
	else
	{
		AfxMessageBox("COM Port Not Open!!! COM Port Open And Connect Please.", NULL, NULL);
	}
}

void CMenualBacodePrintDlg::Print() // CellID Edit Control�� �������� ������ֱ� ���� Print �Լ� ���� 20210324 ljm
{
	if (m_CommFlag == TRUE)
	{
		Init_ReadINI();

		SendMassageInit();

		CString str;
		for (int i = 0; i < m_array_count; i++)
		{
			str = m_array_send_massage[i];
			str += "\r\n";
			m_pCom->WriteComm((BYTE *)(LPSTR)(LPCTSTR)str, str.GetLength());
			Sleep(atoi(m_str_print_time));
		}
		m_edit_cellid.SetWindowText("");
	}
	else
	{
		AfxMessageBox("COM Port Not Open!!! COM Port Open And Connect Please.", NULL, NULL);
	}
}
void CMenualBacodePrintDlg::SendMassageInit()
{
	CString strTemp;
	CString strTemp2;
	CString Bncode6;
	CString Cell6;
	CString Cell4;
	CString Deviceid13;

	if (m_str_bncode != "")
		Bncode6 = m_str_bncode.Right(6);
	if (m_str_cellid != "")
		Cell6 = m_str_cellid.Left(6);
	Cell4 = m_str_cellid.Right(4);
	if (m_str_deviceid != "")
		Deviceid13 = m_str_deviceid.Left(10) + m_str_deviceid.Right(3);

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 1. QD VD ���� ���. 20210513 ljm
	if (m_labeltype == 1)
	{
		if (m_labellength == 1)
		{

			m_array_count = 30; // REV A00 �߰��Ǿ��� ������ Array�� ���ν��� �� ��ŭ �߰� ljm

			m_array_send_massage[0] = "^XA";
			m_array_send_massage[1] = "^MCY";	// maping �ʱ�ȭ
			m_array_send_massage[2] = "^PON";
			m_array_send_massage[3] = "^LH0,0";
			m_array_send_massage[4] = "^XZ";

			m_array_send_massage[5] = "^XA";
			m_array_send_massage[6] = "^FO" + m_str_barcode_x + "," + m_str_barcode_y; //�⺻�� 160, 35 �Է¹���
			m_array_send_massage[7] = "^BY1,1.0";
			m_array_send_massage[8] = "^BQN,2,5";
			m_array_send_massage[9] = "^FDMM,A" + m_str_cellid + Deviceid13 + m_str_week + "G" + Bncode6; //Panel ID 10�ڸ� + Device ID 13�ڸ� + Week 4�ڸ� + G + BN code 6�ڸ�
			m_array_send_massage[10] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) + 140); //300
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 47); //82
			m_array_send_massage[11] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[12] = "^CI0";
			m_array_send_massage[13] = "^A2N,35,20";
			m_array_send_massage[14] = "^FD" + m_str_week + " " + Cell6; //Week + Cell ID �� 6�ڸ�
			m_array_send_massage[15] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) + 415); //570
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 85); //120
			m_array_send_massage[16] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[17] = "^A1N,90,30";
			m_array_send_massage[18] = "^FD" + Cell4; //Panel ID �� 4�ڸ�
			m_array_send_massage[19] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) + 140); //310
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 95); //130
			m_array_send_massage[20] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[21] = "^A1N,35,20";
			m_array_send_massage[22] = "^FD" + m_str_bncode; //BN code 11�ڸ�
			m_array_send_massage[23] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) + 140); //310
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 135); //170
			m_array_send_massage[24] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[25] = "^A1N,35,20";
			m_array_send_massage[26] = "^FD" + m_str_deviceid; //Device ID 13�ڸ�
			m_array_send_massage[27] = "^FS";

			m_array_send_massage[28] = "^PQ1,0,1,Y";
			m_array_send_massage[29] = "^XZ";

			m_array_count = 7;

			CString sArraySumTemp;

			sArraySumTemp = m_array_send_massage[0] + m_array_send_massage[1] + m_array_send_massage[2] + m_array_send_massage[3]
				+ m_array_send_massage[4];
			m_array_send_massage[0] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[5] + m_array_send_massage[6] + m_array_send_massage[7] + m_array_send_massage[8]
				+ m_array_send_massage[9] + m_array_send_massage[10];
			m_array_send_massage[1] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[11] + m_array_send_massage[12] + m_array_send_massage[13] + m_array_send_massage[14]
				+ m_array_send_massage[15];
			m_array_send_massage[2] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[16] + m_array_send_massage[17] + m_array_send_massage[18] + m_array_send_massage[19];
			m_array_send_massage[3] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[20] + m_array_send_massage[21] + m_array_send_massage[22] + m_array_send_massage[23];
			m_array_send_massage[4] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[24] + m_array_send_massage[25] + m_array_send_massage[26] + m_array_send_massage[27];
			m_array_send_massage[5] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[28] + m_array_send_massage[29];
			m_array_send_massage[6] = sArraySumTemp;
		}
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 2. QD VD C ���� ��� 20210513 ljm
	else if (m_labeltype == 2)	// QR 16Len	// XY 2,7 - F ,35,20, 20210226 �������� ��� ���� ��ǥ�� ���� LJM96
	{
		if (m_labellength == 1)
		{

			m_array_count = 30; // REV A00 �߰��Ǿ��� ������ Array�� ���ν��� �� ��ŭ �߰� ljm

			m_array_send_massage[0] = "^XA";
			m_array_send_massage[1] = "^MCY";	// maping �ʱ�ȭ
			m_array_send_massage[2] = "^PON";
			m_array_send_massage[3] = "^LH0,0";
			m_array_send_massage[4] = "^XZ";

			m_array_send_massage[5] = "^XA";
			m_array_send_massage[6] = "^FO" + m_str_barcode_x + "," + m_str_barcode_y; //�⺻�� 160, 35 �Է¹���
			m_array_send_massage[7] = "^BY1,1.0";
			m_array_send_massage[8] = "^BQN,2,5";
			m_array_send_massage[9] = "^FDMM,A" + m_str_cellid + Deviceid13 + m_str_week + "C" + Bncode6; //Panel ID 10�ڸ� + Device ID 13�ڸ� + Week 4�ڸ� + C + BN code 6�ڸ�
			m_array_send_massage[10] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) + 140); //300
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 47); //82
			m_array_send_massage[11] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[12] = "^CI0";
			m_array_send_massage[13] = "^A2N,35,20";
			m_array_send_massage[14] = "^FD" + m_str_week + " " + Cell6; //Week + Cell ID �� 6�ڸ�
			m_array_send_massage[15] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) + 415); //570
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 85); //120
			m_array_send_massage[16] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[17] = "^A1N,90,30";
			m_array_send_massage[18] = "^FD" + Cell4; //Panel ID �� 4�ڸ�
			m_array_send_massage[19] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) + 140); //310
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 95); //130
			m_array_send_massage[20] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[21] = "^A1N,35,20";
			m_array_send_massage[22] = "^FD" + m_str_bncode; //BN code 11�ڸ�
			m_array_send_massage[23] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) + 140); //310
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 135); //170
			m_array_send_massage[24] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[25] = "^A1N,35,20";
			m_array_send_massage[26] = "^FD" + m_str_deviceid + " C"; //Device ID 13�ڸ� + C
			m_array_send_massage[27] = "^FS";

			m_array_send_massage[28] = "^PQ1,0,1,Y";
			m_array_send_massage[29] = "^XZ";

			m_array_count = 7;

			CString sArraySumTemp;

			sArraySumTemp = m_array_send_massage[0] + m_array_send_massage[1] + m_array_send_massage[2] + m_array_send_massage[3]
				+ m_array_send_massage[4];
			m_array_send_massage[0] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[5] + m_array_send_massage[6] + m_array_send_massage[7] + m_array_send_massage[8]
				+ m_array_send_massage[9] + m_array_send_massage[10];
			m_array_send_massage[1] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[11] + m_array_send_massage[12] + m_array_send_massage[13] + m_array_send_massage[14]
				+ m_array_send_massage[15];
			m_array_send_massage[2] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[16] + m_array_send_massage[17] + m_array_send_massage[18] + m_array_send_massage[19];
			m_array_send_massage[3] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[20] + m_array_send_massage[21] + m_array_send_massage[22] + m_array_send_massage[23];
			m_array_send_massage[4] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[24] + m_array_send_massage[25] + m_array_send_massage[26] + m_array_send_massage[27];
			m_array_send_massage[5] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[28] + m_array_send_massage[29];
			m_array_send_massage[6] = sArraySumTemp;
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 3. QD VD P ���� ��� 20210513 ljm
	else if (m_labeltype == 3)
	{
		if (m_labellength == 1)
		{

			m_array_count = 30; // REV A00 �߰��Ǿ��� ������ Array�� ���ν��� �� ��ŭ �߰� ljm

			m_array_send_massage[0] = "^XA";
			m_array_send_massage[1] = "^MCY";	// maping �ʱ�ȭ
			m_array_send_massage[2] = "^PON";
			m_array_send_massage[3] = "^LH0,0";
			m_array_send_massage[4] = "^XZ";

			m_array_send_massage[5] = "^XA";
			m_array_send_massage[6] = "^FO" + m_str_barcode_x + "," + m_str_barcode_y; //�⺻�� 160, 35 �Է¹���
			m_array_send_massage[7] = "^BY1,1.0";
			m_array_send_massage[8] = "^BQN,2,5";
			m_array_send_massage[9] = "^FDMM,A" + m_str_cellid + Deviceid13 + m_str_week + "P" + Bncode6; //Panel ID 10�ڸ� + Device ID 13�ڸ� + Week 4�ڸ� + P + BN code 6�ڸ�
			m_array_send_massage[10] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) + 140); //300
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 47); //82
			m_array_send_massage[11] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[12] = "^CI0";
			m_array_send_massage[13] = "^A2N,35,20";
			m_array_send_massage[14] = "^FD" + m_str_week + " " + Cell6; //Week + Cell ID �� 6�ڸ�
			m_array_send_massage[15] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) + 415); //570
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 85); //120
			m_array_send_massage[16] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[17] = "^A1N,90,30";
			m_array_send_massage[18] = "^FD" + Cell4; //Panel ID �� 4�ڸ�
			m_array_send_massage[19] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) + 140); //310
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 95); //130
			m_array_send_massage[20] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[21] = "^A1N,35,20";
			m_array_send_massage[22] = "^FD" + m_str_bncode; //BN code 11�ڸ�
			m_array_send_massage[23] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) + 140); //310
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 135); //170
			m_array_send_massage[24] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[25] = "^A1N,35,20";
			m_array_send_massage[26] = "^FD" + m_str_deviceid + " P"; //Device ID 13�ڸ� + P
			m_array_send_massage[27] = "^FS";

			m_array_send_massage[28] = "^PQ1,0,1,Y";
			m_array_send_massage[29] = "^XZ";

			m_array_count = 7;

			CString sArraySumTemp;

			sArraySumTemp = m_array_send_massage[0] + m_array_send_massage[1] + m_array_send_massage[2] + m_array_send_massage[3]
				+ m_array_send_massage[4];
			m_array_send_massage[0] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[5] + m_array_send_massage[6] + m_array_send_massage[7] + m_array_send_massage[8]
				+ m_array_send_massage[9] + m_array_send_massage[10];
			m_array_send_massage[1] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[11] + m_array_send_massage[12] + m_array_send_massage[13] + m_array_send_massage[14]
				+ m_array_send_massage[15];
			m_array_send_massage[2] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[16] + m_array_send_massage[17] + m_array_send_massage[18] + m_array_send_massage[19];
			m_array_send_massage[3] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[20] + m_array_send_massage[21] + m_array_send_massage[22] + m_array_send_massage[23];
			m_array_send_massage[4] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[24] + m_array_send_massage[25] + m_array_send_massage[26] + m_array_send_massage[27];
			m_array_send_massage[5] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[28] + m_array_send_massage[29];
			m_array_send_massage[6] = sArraySumTemp;
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 4. 20210513 QD VD M ���� ��� ljmm
	else if (m_labeltype == 4)
	{
		if (m_labellength == 1) //20210318 Code Double QR
		{

			m_array_count = 65; // REV A00 �߰��Ǿ��� ������ Array�� ���ν��� �� ��ŭ �߰� LJM96

			m_array_send_massage[0] = "^XA";
			m_array_send_massage[1] = "^MCY";	// maping �ʱ�ȭ
			m_array_send_massage[2] = "^PON";
			m_array_send_massage[3] = "^LH0,0";
			m_array_send_massage[4] = "^XZ";

			m_array_send_massage[5] = "^XA";
			m_array_send_massage[6] = "^FO" + m_str_barcode_x + "," + m_str_barcode_y; //�⺻�� 160, 35 �Է¹���
			m_array_send_massage[7] = "^BY1,1.0";
			m_array_send_massage[8] = "^BQN,2,5";
			m_array_send_massage[9] = "^FDMM,A" + m_str_cellid + Deviceid13 + m_str_week + "G" + Bncode6; //Panel ID 10�ڸ� + Device ID 13�ڸ� + Week 4�ڸ� + G + BN code 6�ڸ�
			m_array_send_massage[10] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) + 140); //300
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 47); //82
			m_array_send_massage[11] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[12] = "^CI0";
			m_array_send_massage[13] = "^A2N,35,20";
			m_array_send_massage[14] = "^FD" + m_str_week + " " + Cell6; //Week + Cell ID �� 6�ڸ�
			m_array_send_massage[15] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) + 415); //570
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 85); //120
			m_array_send_massage[16] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[17] = "^A1N,90,30";
			m_array_send_massage[18] = "^FD" + Cell4; //Panel ID �� 4�ڸ�
			m_array_send_massage[19] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) + 140); //310
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 95); //130
			m_array_send_massage[20] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[21] = "^A1N,35,20";
			m_array_send_massage[22] = "^FD" + m_str_bncode; //BN code 11�ڸ�
			m_array_send_massage[23] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) + 140); //310
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 135); //170
			m_array_send_massage[24] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[25] = "^A1N,35,20";
			m_array_send_massage[26] = "^FD" + m_str_deviceid; //Device ID 13�ڸ�
			m_array_send_massage[27] = "^FS";

			m_array_send_massage[28] = "^PQ1,0,1,Y";
			m_array_send_massage[29] = "^XZ";

			m_array_send_massage[30] = "^XA";
			m_array_send_massage[31] = "^MCY";	// maping �ʱ�ȭ
			m_array_send_massage[32] = "^PON";
			m_array_send_massage[33] = "^LH0,0";
			m_array_send_massage[34] = "^XZ";

			m_array_send_massage[35] = "^XA";
			m_array_send_massage[36] = "^FO" + m_str_barcode_x + "," + m_str_barcode_y; //�⺻�� 160, 35 �Է¹���
			m_array_send_massage[37] = "^BY1,1.0";
			m_array_send_massage[38] = "^BQN,2,5";
			m_array_send_massage[39] = "^FDMM,A" + m_str_cellid + Deviceid13 + m_str_week + "C" + Bncode6; //Panel ID 10�ڸ� + Device ID 13�ڸ� + Week 4�ڸ� + C + BN code 6�ڸ�
			m_array_send_massage[40] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) + 140); //300
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 47); //82
			m_array_send_massage[41] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[42] = "^CI0";
			m_array_send_massage[43] = "^A2N,35,20";
			m_array_send_massage[44] = "^FD" + m_str_week + " " + Cell6; //Week + Cell ID �� 6�ڸ�
			m_array_send_massage[45] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) + 410); //570
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 85); //120
			m_array_send_massage[46] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[47] = "^A1N,90,30";
			m_array_send_massage[48] = "^FD" + Cell4; //Panel ID �� 4�ڸ�
			m_array_send_massage[49] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) + 150); //310
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 95); //130
			m_array_send_massage[50] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[51] = "^A1N,35,20";
			m_array_send_massage[52] = "^FD" + m_str_bncode; //BN code 11�ڸ�
			m_array_send_massage[53] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) + 150); //310
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 135); //170
			m_array_send_massage[54] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[55] = "^A1N,35,20";
			m_array_send_massage[56] = "^FD" + m_str_deviceid + " C"; //Device ID 13�ڸ�
			m_array_send_massage[57] = "^FS";

			m_array_send_massage[58] = "^PQ1,0,1,Y";
			m_array_send_massage[59] = "^XZ";

			m_array_send_massage[60] = "^XA";
			m_array_send_massage[61] = "^MCY";	// maping �ʱ�ȭ
			m_array_send_massage[62] = "^PON";
			m_array_send_massage[63] = "^LH0,0";
			m_array_send_massage[64] = "^XZ";

			m_array_count = 15;

			CString sArraySumTemp;

			sArraySumTemp = m_array_send_massage[0] + m_array_send_massage[1] + m_array_send_massage[2] + m_array_send_massage[3]
				+ m_array_send_massage[4];
			m_array_send_massage[0] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[5] + m_array_send_massage[6] + m_array_send_massage[7] + m_array_send_massage[8]
				+ m_array_send_massage[9] + m_array_send_massage[10];
			m_array_send_massage[1] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[11] + m_array_send_massage[12] + m_array_send_massage[13] + m_array_send_massage[14]
				+ m_array_send_massage[15];
			m_array_send_massage[2] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[16] + m_array_send_massage[17] + m_array_send_massage[18] + m_array_send_massage[19];
			m_array_send_massage[3] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[20] + m_array_send_massage[21] + m_array_send_massage[22] + m_array_send_massage[23];
			m_array_send_massage[4] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[24] + m_array_send_massage[25] + m_array_send_massage[26] + m_array_send_massage[27];
			m_array_send_massage[5] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[28] + m_array_send_massage[29];
			m_array_send_massage[6] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[30] + m_array_send_massage[31] + m_array_send_massage[32] + m_array_send_massage[33]
				+ m_array_send_massage[34];
			m_array_send_massage[7] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[35] + m_array_send_massage[36] + m_array_send_massage[37] + m_array_send_massage[38]
				+ m_array_send_massage[39] + m_array_send_massage[40];
			m_array_send_massage[8] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[41] + m_array_send_massage[42] + m_array_send_massage[43] + m_array_send_massage[44]
				+ m_array_send_massage[45];
			m_array_send_massage[9] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[46] + m_array_send_massage[47] + m_array_send_massage[48] + m_array_send_massage[49];
			m_array_send_massage[10] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[50] + m_array_send_massage[51] + m_array_send_massage[52] + m_array_send_massage[53];
			m_array_send_massage[11] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[54] + m_array_send_massage[55] + m_array_send_massage[56] + m_array_send_massage[57];
			m_array_send_massage[12] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[58] + m_array_send_massage[59];
			m_array_send_massage[13] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[60] + m_array_send_massage[61] + m_array_send_massage[62] + m_array_send_massage[63]
				+ m_array_send_massage[64];
			m_array_send_massage[14] = sArraySumTemp;
		}
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 5. 20210513 VD SONY ���� ��� ljm
	else if (m_labeltype == 5)
	{
		if (m_labellength == 1)
		{
			m_array_count = 31; // REV A00 �߰��Ǿ��� ������ Array�� ���ν��� �� ��ŭ �߰� LJM96

			m_array_send_massage[0] = "^XA";
			m_array_send_massage[1] = "^MCY";	// maping �ʱ�ȭ
			m_array_send_massage[2] = "^PON";
			m_array_send_massage[3] = "^LH0,0";
			m_array_send_massage[4] = "^XZ";

			m_array_send_massage[5] = "^XA";
			m_array_send_massage[6] = "^FO" + m_str_barcode_x + "," + m_str_barcode_y; //�⺻�� 160, 35 �Է¹���
			m_array_send_massage[7] = "^BY1,1.0";
			m_array_send_massage[8] = "^BQN,2,5";
			m_array_send_massage[9] = "^FDMM,A" + m_str_cellid + m_str_deviceid + m_str_week; //Panel ID 10�ڸ�, Device ID 13�ڸ�, ���� 4�ڸ�
			m_array_send_massage[10] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) + 160); //320
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 47); //82
			m_array_send_massage[11] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[12] = "^CI0";
			m_array_send_massage[13] = "^A2N,35,20";
			m_array_send_massage[14] = "^FD" + Cell6; //Panel ID 6�ڸ�
			m_array_send_massage[15] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) + 320); //480
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 85); //120
			m_array_send_massage[16] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[17] = "^A1N,97,50";
			m_array_send_massage[18] = "^FD" + Cell4; //Panel ID 4�ڸ�
			m_array_send_massage[19] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) + 140); //300
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 135); //170
			m_array_send_massage[20] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[21] = "^A1N,35,20";
			m_array_send_massage[22] = "^FD" + m_str_deviceid + m_str_week; //BN code 11�ڸ�, ���� 4�ڸ�
			m_array_send_massage[23] = "^FS";

			m_array_send_massage[24] = "^PQ1,0,1,Y";
			m_array_send_massage[25] = "^XZ";

			m_array_send_massage[26] = "^XA";
			m_array_send_massage[27] = "^MCY";	// maping �ʱ�ȭ
			m_array_send_massage[28] = "^PON";
			m_array_send_massage[29] = "^LH0,0";
			m_array_send_massage[30] = "^XZ";


			m_array_count = 7;

			CString sArraySumTemp;

			sArraySumTemp = m_array_send_massage[0] + m_array_send_massage[1] + m_array_send_massage[2] + m_array_send_massage[3]
				+ m_array_send_massage[4];
			m_array_send_massage[0] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[5] + m_array_send_massage[6] + m_array_send_massage[7] + m_array_send_massage[8]
				+ m_array_send_massage[9] + m_array_send_massage[10];
			m_array_send_massage[1] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[11] + m_array_send_massage[12] + m_array_send_massage[13] + m_array_send_massage[14]
				+ m_array_send_massage[15];
			m_array_send_massage[2] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[16] + m_array_send_massage[17] + m_array_send_massage[18] + m_array_send_massage[19];
			m_array_send_massage[3] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[20] + m_array_send_massage[21] + m_array_send_massage[22] + m_array_send_massage[23];
			m_array_send_massage[4] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[24] + m_array_send_massage[25];
			m_array_send_massage[5] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[26] + m_array_send_massage[27] + m_array_send_massage[28] + m_array_send_massage[29]
				+ m_array_send_massage[30];
			m_array_send_massage[6] = sArraySumTemp;
		}
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 6. 20210513 VD SONY C ���� ��� ljm
	else if (m_labeltype == 6)
	{
		if (m_labellength == 1)
		{
			m_array_count = 31;

			m_array_send_massage[1] = "^XA";
			m_array_send_massage[2] = "^MCY";	// maping �ʱ�ȭ
			m_array_send_massage[3] = "^PON";
			m_array_send_massage[4] = "^LH0,0";
			m_array_send_massage[5] = "^XZ";

			m_array_send_massage[6] = "^XA";
			m_array_send_massage[7] = "^FO" + m_str_barcode_x + "," + m_str_barcode_y; // �⺻�� x=165, y=35
			m_array_send_massage[8] = "^BY1,1.0";
			m_array_send_massage[9] = "^BQN,2,5";
			m_array_send_massage[10] = "^FDMM,A" + m_str_cellid + m_str_deviceid + m_str_week + "C";
			m_array_send_massage[11] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) + 160); // x= 380
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 47); // y = 95
			m_array_send_massage[12] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[13] = "^CI0";
			m_array_send_massage[14] = "^A2N,35,20";
			m_array_send_massage[15] = "^FD" + Cell6; // cell id �� 6�ڸ�
			m_array_send_massage[16] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) + 220); // x=380
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 95); // y=130
			m_array_send_massage[17] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[18] = "^A1N,35,30";
			m_array_send_massage[19] = "^FDC"; // C �μ� �߰�
			m_array_send_massage[20] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) + 320); // x=480
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 85); // y=120
			m_array_send_massage[21] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[22] = "^A1N,97,50";
			m_array_send_massage[23] = "^FD" + Cell4; // Cell ID �� 4�ڸ�
			m_array_send_massage[24] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) + 140); // x=300
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 135); // y=170
			m_array_send_massage[25] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[26] = "^A1N,35,20";
			m_array_send_massage[27] = "^FD" + m_str_deviceid + m_str_week;
			m_array_send_massage[28] = "^FS";

			m_array_send_massage[29] = "^PQ1,0,1,Y";
			m_array_send_massage[30] = "^XZ";

			m_array_count = 7;

			CString sArraySumTemp;

			sArraySumTemp = m_array_send_massage[0] + m_array_send_massage[1] + m_array_send_massage[2] + m_array_send_massage[3]
				+ m_array_send_massage[4] + m_array_send_massage[5];
			m_array_send_massage[0] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[6] + m_array_send_massage[7] + m_array_send_massage[8] + m_array_send_massage[9]
				+ m_array_send_massage[10] + m_array_send_massage[11];
			m_array_send_massage[1] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[12] + m_array_send_massage[13] + m_array_send_massage[14] + m_array_send_massage[15]
				+ m_array_send_massage[16];
			m_array_send_massage[2] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[17] + m_array_send_massage[18] + m_array_send_massage[19] + m_array_send_massage[20];
			m_array_send_massage[3] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[21] + m_array_send_massage[22] + m_array_send_massage[23] + m_array_send_massage[24];
			m_array_send_massage[4] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[25] + m_array_send_massage[26] + m_array_send_massage[27] + m_array_send_massage[28];
			m_array_send_massage[5] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[29] + m_array_send_massage[30];
			m_array_send_massage[6] = sArraySumTemp;
		}
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 7. 20210513 VD SONY P ���� ��� ljm
	else if (m_labeltype == 7)
	{
		if (m_labellength == 1)
		{
			m_array_count = 31;

			m_array_send_massage[1] = "^XA";
			m_array_send_massage[2] = "^MCY";	// maping �ʱ�ȭ
			m_array_send_massage[3] = "^PON";
			m_array_send_massage[4] = "^LH0,0";
			m_array_send_massage[5] = "^XZ";

			m_array_send_massage[6] = "^XA";
			m_array_send_massage[7] = "^FO" + m_str_barcode_x + "," + m_str_barcode_y; // �⺻�� x=165, y=35
			m_array_send_massage[8] = "^BY1,1.0";
			m_array_send_massage[9] = "^BQN,2,5";
			m_array_send_massage[10] = "^FDMM,A" + m_str_cellid + m_str_deviceid + m_str_week + "P";
			m_array_send_massage[11] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) + 160); // x= 380
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 47); // y = 95
			m_array_send_massage[12] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[13] = "^CI0";
			m_array_send_massage[14] = "^A2N,35,20";
			m_array_send_massage[15] = "^FD" + Cell6; // cell id �� 6�ڸ�
			m_array_send_massage[16] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) + 220); // x=380
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 95); // y=130
			m_array_send_massage[17] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[18] = "^A1N,35,30";
			m_array_send_massage[19] = "^FDC"; // C �μ� �߰�
			m_array_send_massage[20] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) + 320); // x=480
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 85); // y=120
			m_array_send_massage[21] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[22] = "^A1N,97,50";
			m_array_send_massage[23] = "^FD" + Cell4; // Cell ID �� 4�ڸ�
			m_array_send_massage[24] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) + 140); // x=300
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 135); // y=170
			m_array_send_massage[25] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[26] = "^A1N,35,20";
			m_array_send_massage[27] = "^FD" + m_str_deviceid + m_str_week;
			m_array_send_massage[28] = "^FS";

			m_array_send_massage[29] = "^PQ1,0,1,Y";
			m_array_send_massage[30] = "^XZ";

			m_array_count = 7;

			CString sArraySumTemp;

			sArraySumTemp = m_array_send_massage[0] + m_array_send_massage[1] + m_array_send_massage[2] + m_array_send_massage[3]
				+ m_array_send_massage[4] + m_array_send_massage[5];
			m_array_send_massage[0] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[6] + m_array_send_massage[7] + m_array_send_massage[8] + m_array_send_massage[9]
				+ m_array_send_massage[10] + m_array_send_massage[11];
			m_array_send_massage[1] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[12] + m_array_send_massage[13] + m_array_send_massage[14] + m_array_send_massage[15]
				+ m_array_send_massage[16];
			m_array_send_massage[2] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[17] + m_array_send_massage[18] + m_array_send_massage[19] + m_array_send_massage[20];
			m_array_send_massage[3] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[21] + m_array_send_massage[22] + m_array_send_massage[23] + m_array_send_massage[24];
			m_array_send_massage[4] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[25] + m_array_send_massage[26] + m_array_send_massage[27] + m_array_send_massage[28];
			m_array_send_massage[5] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[29] + m_array_send_massage[30];
			m_array_send_massage[6] = sArraySumTemp;
		}
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 8. 20210513 VD SONY M ���� ��� ljm
	else if (m_labeltype == 8)
	{
		if (m_labellength == 1)
			if (m_labellength == 1)
			{
				m_array_count = 56; // REV A00 �߰��Ǿ��� ������ Array�� ���ν��� �� ��ŭ �߰� LJM96

				m_array_send_massage[0] = "^XA";
				m_array_send_massage[1] = "^MCY";	// maping �ʱ�ȭ
				m_array_send_massage[2] = "^PON";
				m_array_send_massage[3] = "^LH0,0";
				m_array_send_massage[4] = "^XZ";

				m_array_send_massage[5] = "^XA";
				m_array_send_massage[6] = "^FO" + m_str_barcode_x + "," + m_str_barcode_y; //�⺻�� 160, 35 �Է¹���
				m_array_send_massage[7] = "^BY1,1.0";
				m_array_send_massage[8] = "^BQN,2,5";
				m_array_send_massage[9] = "^FDMM,A" + m_str_cellid + m_str_deviceid + m_str_week; //Panel ID 10�ڸ�, Device ID 13�ڸ�, ���� 4�ڸ�
				m_array_send_massage[10] = "^FS";

				strTemp.Format("%d", (atoi(m_str_barcode_x)) + 160); //320
				strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 47); //82
				m_array_send_massage[11] = "^FT" + strTemp + "," + strTemp2;
				m_array_send_massage[12] = "^CI0";
				m_array_send_massage[13] = "^A2N,35,20";
				m_array_send_massage[14] = "^FD" + Cell6; //Panel ID 6�ڸ�
				m_array_send_massage[15] = "^FS";

				strTemp.Format("%d", (atoi(m_str_barcode_x)) + 320); //480
				strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 85); //120
				m_array_send_massage[16] = "^FT" + strTemp + "," + strTemp2;
				m_array_send_massage[17] = "^A1N,97,50";
				m_array_send_massage[18] = "^FD" + Cell4; //Panel ID 4�ڸ�
				m_array_send_massage[19] = "^FS";

				strTemp.Format("%d", (atoi(m_str_barcode_x)) + 140); //300
				strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 135); //170
				m_array_send_massage[20] = "^FT" + strTemp + "," + strTemp2;
				m_array_send_massage[21] = "^A1N,35,20";
				m_array_send_massage[22] = "^FD" + m_str_deviceid + m_str_week; //BN code 11�ڸ�, ���� 4�ڸ�
				m_array_send_massage[23] = "^FS";

				m_array_send_massage[24] = "^PQ1,0,1,Y";
				m_array_send_massage[25] = "^XZ";

				m_array_send_massage[26] = "^XA";
				m_array_send_massage[27] = "^MCY";	// maping �ʱ�ȭ
				m_array_send_massage[28] = "^PON";
				m_array_send_massage[29] = "^LH0,0";
				m_array_send_massage[30] = "^XZ";

				m_array_send_massage[31] = "^XA";
				m_array_send_massage[32] = "^FO" + m_str_barcode_x + "," + m_str_barcode_y; // �⺻�� x=160, y=35
				m_array_send_massage[33] = "^BY1,1.0";
				m_array_send_massage[34] = "^BQN,2,5";
				m_array_send_massage[35] = "^FDMM,A" + m_str_cellid + m_str_deviceid + m_str_week + "C";
				m_array_send_massage[36] = "^FS";

				strTemp.Format("%d", (atoi(m_str_barcode_x)) + 160); // x= 320
				strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 47); // y = 82
				m_array_send_massage[37] = "^FT" + strTemp + "," + strTemp2;
				m_array_send_massage[38] = "^CI0";
				m_array_send_massage[39] = "^A2N,35,20";
				m_array_send_massage[40] = "^FD" + Cell6; // cell id �� 6�ڸ�
				m_array_send_massage[41] = "^FS";

				strTemp.Format("%d", (atoi(m_str_barcode_x)) + 220); // x=380
				strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 95); // y=130
				m_array_send_massage[42] = "^FT" + strTemp + "," + strTemp2;
				m_array_send_massage[43] = "^A1N,35,30";
				m_array_send_massage[44] = "^FDC"; // C �μ� �߰�
				m_array_send_massage[45] = "^FS";

				strTemp.Format("%d", (atoi(m_str_barcode_x)) + 320); // x=480
				strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 85); // y=120
				m_array_send_massage[46] = "^FT" + strTemp + "," + strTemp2;
				m_array_send_massage[47] = "^A1N,97,50";
				m_array_send_massage[48] = "^FD" + Cell4; // Cell ID �� 4�ڸ�
				m_array_send_massage[49] = "^FS";

				strTemp.Format("%d", (atoi(m_str_barcode_x)) + 140); // x=300
				strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 135); // y=170
				m_array_send_massage[50] = "^FT" + strTemp + "," + strTemp2;
				m_array_send_massage[51] = "^A1N,35,20";
				m_array_send_massage[52] = "^FD" + m_str_deviceid + m_str_week;
				m_array_send_massage[53] = "^FS";

				m_array_send_massage[54] = "^PQ1,0,1,Y";
				m_array_send_massage[55] = "^XZ";

				m_array_count = 13;

				CString sArraySumTemp;

				sArraySumTemp = m_array_send_massage[0] + m_array_send_massage[1] + m_array_send_massage[2] + m_array_send_massage[3]
					+ m_array_send_massage[4];
				m_array_send_massage[0] = sArraySumTemp;

				sArraySumTemp = m_array_send_massage[5] + m_array_send_massage[6] + m_array_send_massage[7] + m_array_send_massage[8]
					+ m_array_send_massage[9] + m_array_send_massage[10];
				m_array_send_massage[1] = sArraySumTemp;

				sArraySumTemp = m_array_send_massage[11] + m_array_send_massage[12] + m_array_send_massage[13] + m_array_send_massage[14]
					+ m_array_send_massage[15];
				m_array_send_massage[2] = sArraySumTemp;

				sArraySumTemp = m_array_send_massage[16] + m_array_send_massage[17] + m_array_send_massage[18] + m_array_send_massage[19];
				m_array_send_massage[3] = sArraySumTemp;

				sArraySumTemp = m_array_send_massage[20] + m_array_send_massage[21] + m_array_send_massage[22] + m_array_send_massage[23];
				m_array_send_massage[4] = sArraySumTemp;

				sArraySumTemp = m_array_send_massage[24] + m_array_send_massage[25];
				m_array_send_massage[5] = sArraySumTemp;

				sArraySumTemp = m_array_send_massage[26] + m_array_send_massage[27] + m_array_send_massage[28] + m_array_send_massage[29]
					+ m_array_send_massage[30];
				m_array_send_massage[6] = sArraySumTemp;

				sArraySumTemp = m_array_send_massage[31] + m_array_send_massage[32] + m_array_send_massage[33] + m_array_send_massage[34]
					+ m_array_send_massage[35] + m_array_send_massage[36];
				m_array_send_massage[7] = sArraySumTemp;

				sArraySumTemp = m_array_send_massage[37] + m_array_send_massage[38] + m_array_send_massage[39] + m_array_send_massage[40]
					+ m_array_send_massage[41];
				m_array_send_massage[8] = sArraySumTemp;

				sArraySumTemp = m_array_send_massage[42] + m_array_send_massage[43] + m_array_send_massage[44] + m_array_send_massage[45];
				m_array_send_massage[9] = sArraySumTemp;

				sArraySumTemp = m_array_send_massage[46] + m_array_send_massage[47] + m_array_send_massage[48] + m_array_send_massage[49];
				m_array_send_massage[10] = sArraySumTemp;

				sArraySumTemp = m_array_send_massage[50] + m_array_send_massage[51] + m_array_send_massage[52] + m_array_send_massage[53];
				m_array_send_massage[11] = sArraySumTemp;

				sArraySumTemp = m_array_send_massage[54] + m_array_send_massage[55];
				m_array_send_massage[12] = sArraySumTemp;
			}
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 9. QD VD P 90 Degree Rotate ���� ��� 20210520 ljm
	else if (m_labeltype == 9)
	{
		if (m_labellength == 1)
		{

			m_array_count = 30; // REV A00 �߰��Ǿ��� ������ Array�� ���ν��� �� ��ŭ �߰� ljm

			m_array_send_massage[0] = "^XA";
			m_array_send_massage[1] = "^MCY";	// maping �ʱ�ȭ
			m_array_send_massage[2] = "^PON";
			m_array_send_massage[3] = "^LH0,0";
			m_array_send_massage[4] = "^XZ";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) - 95); //65
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 800); // 835
			m_array_send_massage[5] = "^XA";
			m_array_send_massage[6] = "^FWB^FO" + strTemp + "," + strTemp2; //�⺻�� 160, 35 �Է¹���
			m_array_send_massage[7] = "^BY1,1.0";
			m_array_send_massage[8] = "^BQN,2,5";
			m_array_send_massage[9] = "^FDMM,A" + m_str_cellid + Deviceid13 + m_str_week + "P" + Bncode6; //Panel ID 10�ڸ� + Device ID 13�ڸ� + Week 4�ڸ� + P + BN code 6�ڸ�
			m_array_send_massage[10] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) - 65); // 95
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 775); // 810
			m_array_send_massage[11] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[12] = "^CI0";
			m_array_send_massage[13] = "^A2,35,20";
			m_array_send_massage[14] = "^FD" + m_str_week + " " + Cell6; //Week + Cell ID �� 6�ڸ�
			m_array_send_massage[15] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) - 15); // 145
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 515); // 545
			m_array_send_massage[16] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[17] = "^A1,90,30";
			m_array_send_massage[18] = "^FD" + Cell4; //Panel ID �� 4�ڸ�
			m_array_send_massage[19] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) - 15); // 145
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 775); // 810
			m_array_send_massage[20] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[21] = "^A1,35,20";
			m_array_send_massage[22] = "^FD" + m_str_bncode; //BN code 11�ڸ�
			m_array_send_massage[23] = "^FS";

			strTemp.Format("%d", (atoi(m_str_barcode_x)) + 35); // 195
			strTemp2.Format("%d", (atoi(m_str_barcode_y)) + 775); // 810
			m_array_send_massage[24] = "^FT" + strTemp + "," + strTemp2;
			m_array_send_massage[25] = "^A1,35,20";
			m_array_send_massage[26] = "^FD" + m_str_deviceid + " P"; //Device ID 13�ڸ� + P
			m_array_send_massage[27] = "^FS";

			m_array_send_massage[28] = "^PQ1,0,1,Y";
			m_array_send_massage[29] = "^XZ";

			m_array_count = 7;

			CString sArraySumTemp;

			sArraySumTemp = m_array_send_massage[0] + m_array_send_massage[1] + m_array_send_massage[2] + m_array_send_massage[3]
				+ m_array_send_massage[4];
			m_array_send_massage[0] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[5] + m_array_send_massage[6] + m_array_send_massage[7] + m_array_send_massage[8]
				+ m_array_send_massage[9] + m_array_send_massage[10];
			m_array_send_massage[1] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[11] + m_array_send_massage[12] + m_array_send_massage[13] + m_array_send_massage[14]
				+ m_array_send_massage[15];
			m_array_send_massage[2] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[16] + m_array_send_massage[17] + m_array_send_massage[18] + m_array_send_massage[19];
			m_array_send_massage[3] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[20] + m_array_send_massage[21] + m_array_send_massage[22] + m_array_send_massage[23];
			m_array_send_massage[4] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[24] + m_array_send_massage[25] + m_array_send_massage[26] + m_array_send_massage[27];
			m_array_send_massage[5] = sArraySumTemp;

			sArraySumTemp = m_array_send_massage[28] + m_array_send_massage[29];
			m_array_send_massage[6] = sArraySumTemp;
		}
	}
}

void CMenualBacodePrintDlg::OnBnClickedButtonRegPrint()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	char chThisPath[_MAX_PATH];
	GetCurrentDirectory(_MAX_PATH, chThisPath);
	CString strThisPath;
	strThisPath.Format("%s\\MenualPrint.xlsx", chThisPath);

	CString strMsg;
	CString strTemp;

	strMsg.Format("Excel File Load -> %s", strThisPath);
	SetLogWriteText(strMsg, TRUE);

	CXLEzAutomation XL(FALSE); // FALSE: ó�� ������ ȭ�鿡 ������ �ʴ´�

	XL.OpenExcelFile(strThisPath); // �׼� ���� ����

	for (int i = 0; i < 500; i++)
	{
		array_cellid[i] = XL.GetCellValue(1, i + 2);
		array_week[i] = XL.GetCellValue(2, i + 2);
		array_deviceid[i] = XL.GetCellValue(3, i + 2);
		array_bncode[i] = XL.GetCellValue(4, i + 2);

		strMsg.Format("%d: %s %s %s %s", i + 1, array_cellid[i], array_week[i], array_deviceid[i], array_bncode[i]);
		SetLogWriteText(strMsg, TRUE);

		if (array_cellid[i] == "")
		{
			array_count = i;
			break;
		}
	}

	strMsg.Format("Load Panel Quantity : %d", array_count);
	SetLogWriteText(strMsg, TRUE);

	if (array_count > 0)
	{
		m_excel_load = 1;
	}

	XL.ReleaseExcel(); // ���� ���� ����
}

void CMenualBacodePrintDlg::OnBnClickedButtonMPrintcount()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_excel_load == 0)
	{
		AfxMessageBox("Not Load Excel File!", MB_ICONEXCLAMATION);
	}

	if (m_CommFlag == TRUE)
	{
		Init_ReadINI();

		for (int v = 0; v < array_count; v++)
		{
			m_str_cellid = array_cellid[v];
			m_str_deviceid = array_deviceid[v];
			m_str_week = array_week[v];
			m_str_bncode = array_bncode[v];

			SendMassageInit();

			CString str;
			for (int i = 0; i < m_array_count; i++)
			{
				str = m_array_send_massage[i];
				str += "\r\n";
				m_pCom->WriteComm((BYTE *)(LPSTR)(LPCTSTR)str, str.GetLength());
				Sleep(atoi(m_str_print_time));
			}

			Sleep(atoi(m_str_print_time));
		}
	}
	else
	{
		AfxMessageBox("COM Port Not Open!!! COM Port Open And Connect Please.", NULL, NULL);
	}
}

void CMenualBacodePrintDlg::OnBnClickedCheck15mm()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_labellength = 1;
	m_str_labellength = "1";

	m_check_15mm.SetCheck(1);
	m_check_26mm.SetCheck(0);
	m_check_40mm.SetCheck(0);
}


void CMenualBacodePrintDlg::OnBnClickedCheck26mm()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_labellength = 2;
	m_str_labellength = "2";

	m_check_15mm.SetCheck(0);
	m_check_26mm.SetCheck(1);
	m_check_40mm.SetCheck(0);
}


void CMenualBacodePrintDlg::OnBnClickedCheck40mm()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_labellength = 3;
	m_str_labellength = "3";

	m_check_15mm.SetCheck(0);
	m_check_26mm.SetCheck(0);
	m_check_40mm.SetCheck(1);
}


//////////////////////////////////////////////////////////////////////Cell ID ��ĵ ��� �߰� 20210322 ljm
char g_tBuff[20];
void CMenualBacodePrintDlg::OnChangeEditCellid()
{
	char *m_CellID;
	m_CellID = new char[256];
	::ZeroMemory(m_CellID, 256);

	CString sS;
	CString left;
	CString sT;
	CString strMsg;

	static int flag;
	int nLen;
	
	memset(g_tBuff, 0, sizeof(char) * 20);

	m_edit_cellid.GetWindowText(sS);
	left = sS.Left(10);
	nLen = left.GetLength();

	memcpy(g_tBuff, (LPCTSTR)left, 20);
	sT.Format("%s", g_tBuff);

	if (nLen == 10)
	{

			left = sT;
			strcpy(m_CellID, (LPSTR)(LPCTSTR)left);

			strMsg.Format("Input CELL ID = %s", m_CellID);
			SetLogWriteText(strMsg, TRUE);

			OnBnClickedButtonSave(); // ���ڵ�� Read�� CELL ID�� INI�� ����.

			Print(); //Print �Լ� ���� (����Ʈ �Ϸ� �� CellID 0���� �ʱ�ȭ) //20210324 ljm

			OnBnClickedButtonSave(); // 0���� �ʱ�ȭ �� CellID�� INI�� �����ϰ� �Լ� ����.

			MessageBox("��� ���Դϴ�.", "�˸�", MB_OK | MB_ICONQUESTION);
	}
}

void CMenualBacodePrintDlg::OnSetfocusEditCellid()
{
	m_FocusCellPall = 0;
}

void CMenualBacodePrintDlg::OnSetfocusPalEdit()
{
	m_FocusCellPall = 1;
}

CString CMenualBacodePrintDlg::GetPalletString()
{

	CString sS;
	m_edit_device_x.GetWindowText(sS);

	return  sS;
}

BOOL CMenualBacodePrintDlg::PreTranslateMessage(MSG* pMsg) //���ڵ� ������ ����Ű �����ϱ� ���� �߰��� 20210323 ljm
{
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
		{
			return FALSE;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


void CMenualBacodePrintDlg::OnBnClickedCheckQdvd()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_labeltype = 1;
	m_str_labeltype = "1";

	m_check_qdvd.SetCheck(1);
	m_check_qdvdc.SetCheck(0);
	m_check_qdvdp.SetCheck(0);
	m_check_qdvdm.SetCheck(0);

	m_check_vdsony.SetCheck(0);
	m_check_vdsonyc.SetCheck(0);
	m_check_vdsonyp.SetCheck(0);
	m_check_vdsonym.SetCheck(0);
	m_check_qdvdp90.SetCheck(0);
}

void CMenualBacodePrintDlg::OnBnClickedCheckQdvdc()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_labeltype = 2;
	m_str_labeltype = "2";

	m_check_qdvd.SetCheck(0);
	m_check_qdvdc.SetCheck(1);
	m_check_qdvdp.SetCheck(0);
	m_check_qdvdm.SetCheck(0);

	m_check_vdsony.SetCheck(0);
	m_check_vdsonyc.SetCheck(0);
	m_check_vdsonyp.SetCheck(0);
	m_check_vdsonym.SetCheck(0);
	m_check_qdvdp90.SetCheck(0);
}

void CMenualBacodePrintDlg::OnBnClickedCheckQdvdp()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_labeltype = 3;
	m_str_labeltype = "3";

	m_check_qdvd.SetCheck(0);
	m_check_qdvdc.SetCheck(0);
	m_check_qdvdp.SetCheck(1);
	m_check_qdvdm.SetCheck(0);

	m_check_vdsony.SetCheck(0);
	m_check_vdsonyc.SetCheck(0);
	m_check_vdsonyp.SetCheck(0);
	m_check_vdsonym.SetCheck(0);
	m_check_qdvdp90.SetCheck(0);
}

void CMenualBacodePrintDlg::OnBnClickedCheckQdvdm()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_labeltype = 4;
	m_str_labeltype = "4";

	m_check_qdvd.SetCheck(0);
	m_check_qdvdc.SetCheck(0);
	m_check_qdvdp.SetCheck(0);
	m_check_qdvdm.SetCheck(1);

	m_check_vdsony.SetCheck(0);
	m_check_vdsonyc.SetCheck(0);
	m_check_vdsonyp.SetCheck(0);
	m_check_vdsonym.SetCheck(0);
	m_check_qdvdp90.SetCheck(0);
}

void CMenualBacodePrintDlg::OnBnClickedCheckVdsony()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_labeltype = 5;
	m_str_labeltype = "5";

	m_check_qdvd.SetCheck(0);
	m_check_qdvdc.SetCheck(0);
	m_check_qdvdp.SetCheck(0);
	m_check_qdvdm.SetCheck(0);

	m_check_vdsony.SetCheck(1);
	m_check_vdsonyc.SetCheck(0);
	m_check_vdsonyp.SetCheck(0);
	m_check_vdsonym.SetCheck(0);
	m_check_qdvdp90.SetCheck(0);
}

void CMenualBacodePrintDlg::OnBnClickedCheckVdsonyc()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_labeltype = 6;
	m_str_labeltype = "6";

	m_check_qdvd.SetCheck(0);
	m_check_qdvdc.SetCheck(0);
	m_check_qdvdp.SetCheck(0);
	m_check_qdvdm.SetCheck(0);

	m_check_vdsony.SetCheck(0);
	m_check_vdsonyc.SetCheck(1);
	m_check_vdsonyp.SetCheck(0);
	m_check_vdsonym.SetCheck(0);
	m_check_qdvdp90.SetCheck(0);
}

void CMenualBacodePrintDlg::OnBnClickedCheckVdsonyp()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_labeltype = 7;
	m_str_labeltype = "7";

	m_check_qdvd.SetCheck(0);
	m_check_qdvdc.SetCheck(0);
	m_check_qdvdp.SetCheck(0);
	m_check_qdvdm.SetCheck(0);

	m_check_vdsony.SetCheck(0);
	m_check_vdsonyc.SetCheck(0);
	m_check_vdsonyp.SetCheck(1);
	m_check_vdsonym.SetCheck(0);
	m_check_qdvdp90.SetCheck(0);
}

void CMenualBacodePrintDlg::OnBnClickedCheckVdsonym()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_labeltype = 8;
	m_str_labeltype = "8";

	m_check_qdvd.SetCheck(0);
	m_check_qdvdc.SetCheck(0);
	m_check_qdvdp.SetCheck(0);
	m_check_qdvdm.SetCheck(0);

	m_check_vdsony.SetCheck(0);
	m_check_vdsonyc.SetCheck(0);
	m_check_vdsonyp.SetCheck(0);
	m_check_vdsonym.SetCheck(1);
	m_check_qdvdp90.SetCheck(0);
}

void CMenualBacodePrintDlg::OnBnClickedCheckQdvdp90()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_labeltype = 9;
	m_str_labeltype = "9";

	m_check_qdvd.SetCheck(0);
	m_check_qdvdc.SetCheck(0);
	m_check_qdvdp.SetCheck(0);
	m_check_qdvdm.SetCheck(0);

	m_check_vdsony.SetCheck(0);
	m_check_vdsonyc.SetCheck(0);
	m_check_vdsonyp.SetCheck(0);
	m_check_vdsonym.SetCheck(0);
	m_check_qdvdp90.SetCheck(1);
}
