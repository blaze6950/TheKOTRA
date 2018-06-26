#include "JeweLife.h"
#include "AddDialogPlay.h"

JeweLife* JeweLife::ptr = nullptr;

JeweLife::JeweLife(void)
{
	ptr = this;
}


JeweLife::~JeweLife(void)
{
}

void JeweLife::Cls_OnClose(HWND hwnd)
{
	EndDialog(hwnd, 0);
}

BOOL JeweLife::Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
	hDialog = hwnd;
	hStart = GetDlgItem(hDialog, IDOK);
	hAbout = GetDlgItem(hDialog, IDC_BUTTON1);
	hExit = GetDlgItem(hDialog, IDCANCEL);
	hFon = GetDlgItem(hDialog, IDC_FON1);
	hLogo = GetDlgItem(hDialog, IDC_LOGO);
	hFrameMenu = GetDlgItem(hDialog, IDC_FRAME_MENU);


	return TRUE;
}

// Обработчик сообщения WM_COMMAND будет вызван при выборе пункта меню
void JeweLife::Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
	switch (id)
	{
	case IDOK:
	{
		 AddDialogPlay dlg;
		 RECT coords;
		 GetWindowRect(hwnd, &coords);
		 dlg.coords = &coords;
		 //GetWindowText(hEdit1, buffer, 200);
		 // передача данных через public-поле класса CAdditionalModalDialog дополнительного диалога
		 //_tcscpy(dlg.text, buffer);
		 CloseWindow(hwnd);
		 INT_PTR result = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG2), hwnd, AddDialogPlay::DlgProc);
		 ShowWindow(hwnd, SW_RESTORE);
		 MoveWindow(hwnd, dlg.coords->left, dlg.coords->top, dlg.coords->right - dlg.coords->left, dlg.coords->bottom - dlg.coords->top, TRUE);
		 break;
	}
	case IDC_BUTTON1:

		break;
	case IDCANCEL:
		EndDialog(hwnd, IDCANCEL);
		break;
	}
}

BOOL CALLBACK JeweLife::DlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		HANDLE_MSG(hwnd, WM_CLOSE, ptr->Cls_OnClose);
		HANDLE_MSG(hwnd, WM_INITDIALOG, ptr->Cls_OnInitDialog);
		HANDLE_MSG(hwnd, WM_COMMAND, ptr->Cls_OnCommand);
		//HANDLE_MSG(hwnd, WM_MENUSELECT, ptr->Cls_OnMenuSelect);
	}
	return FALSE;
}