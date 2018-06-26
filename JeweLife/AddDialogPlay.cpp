#include "AddDialogPlay.h"
#include "ADDBlitz.h"

AddDialogPlay* AddDialogPlay::ptr = NULL;

AddDialogPlay::AddDialogPlay(void)
{
	ptr = this;
}

AddDialogPlay::AddDialogPlay(LPCTSTR lpStr)
{
	ptr = this;
}

AddDialogPlay::~AddDialogPlay(void)
{

}

void AddDialogPlay::Cls_OnClose(HWND hwnd)
{
	EndDialog(hwnd, IDCANCEL);
}

BOOL AddDialogPlay::Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
	hFon = GetDlgItem(hwnd, IDC_FON1);
	hLogo = GetDlgItem(hwnd, IDC_LOGO);
	hFrameMenu = GetDlgItem(hwnd, IDC_FRAME_MENU);
	hBlitz = GetDlgItem(hwnd, IDC_BLITZ);
	hRelax = GetDlgItem(hwnd, IDC_RELAX);
	hClassic = GetDlgItem(hwnd, IDC_CLASSIC);
	hTimed = GetDlgItem(hwnd, IDC_TIMED);
	hBack = GetDlgItem(hwnd, IDCANCEL);
	MoveWindow(hwnd, coords->left, coords->top, coords->right - coords->left, coords->bottom - coords->top, TRUE);
	// ���������� �� �������� ������� ������ ������������ �� �������
	/*SetWindowText(hStatic, text);
	SetWindowText(hwnd, TEXT("�������������� ��������� ������"));
	SetWindowText(hEdit, TEXT("�������� ������ �������� �������!"));*/
	return TRUE;
}


void AddDialogPlay::Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
	if (id == IDOK)
	{
		//TCHAR buffer[200];
		//GetWindowText(hEdit, buffer, 200);
		//_tcscpy(text, buffer);
		//HWND hParent = GetParent(hwnd);
		//// �������� ������ �������� �������
		//SetWindowText(hParent, TEXT("������ �� ��������� ����!"));
		//EndDialog(hwnd, IDOK);
	}
	else if (id == IDC_BLITZ)
	{
			ADDBlitz dlgBlitz;
			RECT coords;
			GetWindowRect(hwnd, &coords);
			dlgBlitz.coords = &coords;
			//GetWindowText(hEdit1, buffer, 200);
			// �������� ������ ����� public-���� ������ CAdditionalModalDialog ��������������� �������
			//_tcscpy(dlg.text, buffer);
			CloseWindow(hwnd);
			INT_PTR result = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG3), hwnd, ADDBlitz::DlgProc);
			ShowWindow(hwnd, SW_RESTORE);
			MoveWindow(hwnd, dlgBlitz.coords->left, dlgBlitz.coords->top, dlgBlitz.coords->right - dlgBlitz.coords->left, dlgBlitz.coords->bottom - dlgBlitz.coords->top, TRUE);
	}
	else if (id == IDC_RELAX)
	{
		//�������� ������ ����������� ���� � ������� ����, �������� ��� ����� ������ ����.
	}
	else if (id == IDC_CLASSIC)
	{
		//�������� ������ ����������� ���� � ������� ����, �������� ��� ����� ������ ����.
	}
	else if (id == IDC_TIMED)
	{
		//�������� ������ ����������� ���� � ������� ����, �������� ��� ����� ������ ����.
	}
	else if (id == IDCANCEL)
	{
		GetWindowRect(hwnd, coords);
		EndDialog(hwnd, IDCANCEL);
	}
}

BOOL CALLBACK AddDialogPlay::DlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		HANDLE_MSG(hwnd, WM_CLOSE, ptr->Cls_OnClose);
		HANDLE_MSG(hwnd, WM_INITDIALOG, ptr->Cls_OnInitDialog);
		HANDLE_MSG(hwnd, WM_COMMAND, ptr->Cls_OnCommand);
	}
	return FALSE;
}
