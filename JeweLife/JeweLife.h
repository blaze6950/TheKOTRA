#pragma once
#include "header.h"

class JeweLife
{
public:
	JeweLife();
	~JeweLife();
	static BOOL CALLBACK DlgProc(HWND hWnd, UINT mes, WPARAM wp, LPARAM lp);
	static JeweLife* ptr;
	BOOL Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
	void Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
	static void Cls_OnClose(HWND hwnd);

	HWND hDialog, hStart, hAbout, hExit, hFon, hLogo, hFrameMenu;
	HINSTANCE hInst;
};

