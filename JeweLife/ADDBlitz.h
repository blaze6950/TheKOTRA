#pragma once
#include "header.h"

struct Gems{
	int type;
};

class ADDBlitz
{
public:
	ADDBlitz(void);
	ADDBlitz(LPCTSTR lpStr);
	~ADDBlitz(void);

	static BOOL CALLBACK DlgProc(HWND hWnd, UINT mes, WPARAM wp, LPARAM lp);
	static ADDBlitz* ptr;
	BOOL Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
	void Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
	void Cls_OnClose(HWND hwnd);
	RECT *coords;
	HWND hFon, hScore, hMode, hLevel, hStarIco, hBarInfo, hFrameArea, hTime, hPause, hResume, hQuit;
	HWND hGems[8][8];
	Gems GGms[8][8];
	BOOL isHover = FALSE;
	int numHover = -1;
	int numSHover = -1;
	BOOL GoFullButtoms(HWND hwnd);
	BOOL CheckMatches(HWND hwnd);
};