#pragma once
#include "header.h"

class AddDialogPlay
{
public:
	AddDialogPlay(void);
	AddDialogPlay(LPCTSTR lpStr);
	~AddDialogPlay(void);

	static BOOL CALLBACK DlgProc(HWND hWnd, UINT mes, WPARAM wp, LPARAM lp);
	static AddDialogPlay* ptr;
	BOOL Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
	void Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
	void Cls_OnClose(HWND hwnd);
	RECT *coords;
	HWND hFon, hLogo, hFrameMenu, hBlitz, hRelax, hClassic, hTimed, hBack;
};
