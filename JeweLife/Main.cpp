#include "JeweLife.h"

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpszCmdLine, int nCmdShow)
{
	INITCOMMONCONTROLSEX icc = { sizeof(INITCOMMONCONTROLSEX) };
	icc.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&icc);
	JeweLife dlg;
	MSG msg;
	HWND hDialog = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG1), NULL, JeweLife::DlgProc);
	//HACCEL hAccel = LoadAccelerators(hInst, MAKEINTRESOURCE(IDR_ACCELERATOR1));
	//ShowWindow(hDialog, nCmdShow);
	/*while (GetMessage(&msg, 0, 0, 0))
	{
		if (!TranslateAccelerator(hDialog, hAccel, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}*/
	return DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), NULL, JeweLife::DlgProc);
}