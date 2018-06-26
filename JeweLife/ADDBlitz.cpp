#include "ADDBlitz.h"
ADDBlitz* ADDBlitz::ptr = NULL;

ADDBlitz::ADDBlitz(void)
{
	ptr = this;
}

ADDBlitz::ADDBlitz(LPCTSTR lpStr)
{
	ptr = this;
}

ADDBlitz::~ADDBlitz(void)
{

}

void ADDBlitz::Cls_OnClose(HWND hwnd)
{
	EndDialog(hwnd, IDCANCEL);
}

BOOL ADDBlitz::GoFullButtoms(HWND hwnd)
{
	BOOL change = FALSE;
	TCHAR buf[10];
	for (size_t y = 0; y < 8; y++)
	{
		for (size_t x = 0; x < 8; x++)
		{
			GetWindowText(hGems[y][x], buf, 10);
			int num = _wtoi(buf);
			if (num == -1)
			{
				change = TRUE;
				num = rand() % 8;
				swprintf_s(buf, 10, TEXT("%d"), num);
				SetWindowText(hGems[y][x], buf);
				GGms[y][x].type = num;
			}
		}
	}
	if (change)
	{
		CheckMatches(hwnd);
	}
	return TRUE;
}

BOOL ADDBlitz::CheckMatches(HWND hwnd)
{
	TCHAR buf[10];
	int count = 0;
	for (size_t y = 0; y < 8; y++)
	{
		for (size_t x = 0; x < 8; x++)
		{
			if (GGms[y][x].type == -1){ continue; }
			while (true)
			{
				if (x < 6)
				{
					if (GGms[y][x].type == GGms[y][x + count + 1].type/* || GGms[y][x].type == GGms[y][x + count + 1].type * 10 || GGms[y][x].type == GGms[y][x + count + 1].type / 10*/)
					{
						count++;
					}
					else if(count >= 2){
						GGms[y][x].type *= 10;
						swprintf_s(buf, 10, TEXT("%d"), GGms[y][x].type);
						SetWindowText(hGems[y][x], buf);
						for (size_t i = 1; i <= count; i++)
						{
							GGms[y][x + i].type *= -1;
							swprintf_s(buf, 10, TEXT("%d"), -1);
							SetWindowText(hGems[y][x + i], buf);
						}
						count = 0;
						break;
					}
					else{
						if (GGms[y][x].type != GGms[y][x + count + 1].type/* || GGms[y][x].type != GGms[y][x + count + 1].type * 10 || GGms[y][x].type != GGms[y][x + count + 1].type / 10*/)
						{
							count = 0;
						}
						break;
					}
				}
				else{
					if (count < 2)
					{
						break;
					}
					GGms[y][x].type *= 10;
					swprintf_s(buf, 10, TEXT("%d"), GGms[y][x].type);
					SetWindowText(hGems[y][x], buf);
					for (size_t i = 1; i <= count; i++)
					{
						GGms[y][x + i].type *= -1;
						swprintf_s(buf, 10, TEXT("%d"), -1);
						SetWindowText(hGems[y][x + i], buf);
					}
					count = 0;
					break;
				}
			}
			
			
		}
	}
	count = 0;
	for (size_t x = 0; x < 8; x++)
	{
		for (size_t y = 0; y < 8; y++)
		{
			if (GGms[y][x].type == -1){ continue; }
			while (true)
			{
				if (y < 6)
				{
					if (GGms[y][x].type == GGms[y + count + 1][x].type/* || GGms[y][x].type == GGms[y + count + 1][x].type * 10 || GGms[y][x].type == GGms[y + count + 1][x].type / 10*/)
					{
						count++;
					}
					else if (count >= 2){
						GGms[y][x].type *= 10;
						swprintf_s(buf, 10, TEXT("%d"), GGms[y][x].type);
						SetWindowText(hGems[y][x], buf);
						for (size_t i = 1; i <= count; i++)
						{
							GGms[y + i][x].type *= -1;
							swprintf_s(buf, 10, TEXT("%d"), -1);
							SetWindowText(hGems[y + i][x], buf);
						}
						count = 0;
						break;
					}
					else{
						if (GGms[y][x].type != GGms[y + count + 1][x].type/* || GGms[y][x].type == GGms[y + count + 1][x].type * 10 || GGms[y][x].type == GGms[y + count + 1][x].type / 10*/)
						{
							count = 0;
						}
						break;
					}
				}
				else{
					if (count < 2)
					{
						break;
					}
					GGms[y][x].type *= 10;
					swprintf_s(buf, 10, TEXT("%d"), GGms[y][x].type);
					SetWindowText(hGems[y][x], buf);
					for (size_t i = 1; i <= count; i++)
					{
						GGms[y + i][x].type *= -1;
						swprintf_s(buf, 10, TEXT("%d"), -1);
						SetWindowText(hGems[y + i][x], buf);
					}
					count = 0;
					break;
				}
			}


		}
	}
	GoFullButtoms(hwnd);
	return TRUE;
}

BOOL ADDBlitz::Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
	hFon = GetDlgItem(hwnd, IDC_FON1);
	hScore = GetDlgItem(hwnd, IDC_SSCORE);
	hMode = GetDlgItem(hwnd, IDC_SMODE);
	hLevel = GetDlgItem(hwnd, IDC_SLEVEL);
	hStarIco = GetDlgItem(hwnd, IDC_SSTARICO);
	hBarInfo = GetDlgItem(hwnd, IDC_BARINFO);
	hFrameArea = GetDlgItem(hwnd, IDC_FRAMEAREA);
	hTime = GetDlgItem(hwnd, IDC_TIME);
	hPause = GetDlgItem(hwnd, IDC_PAUSE);
	hResume = GetDlgItem(hwnd, IDC_RESUME);
	hQuit = GetDlgItem(hwnd, IDC_QUIT);
	
	int i = 0;
	for (size_t y = 0; y < 8; y++)
	{
		for (size_t x = 0; x < 8; x++)
		{
			hGems[y][x] = GetDlgItem(hwnd, IDC_BUTTON01 + i);
			i++;
		}
	}

	TCHAR buf[10];
	for (size_t y = 0; y < 8; y++)
	{
		for (size_t x = 0; x < 8; x++)
		{
			swprintf_s(buf, 10, TEXT("%d"), -1);
			SetWindowText(hGems[y][x], buf);
			GGms[y][x].type = -1;
		}
	}

	GoFullButtoms(hwnd);

	MoveWindow(hwnd, coords->left, coords->top, coords->right - coords->left, coords->bottom - coords->top, TRUE);
	return TRUE;
}


void ADDBlitz::Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
	if (id == IDC_PAUSE)
	{
		//TCHAR buffer[200];
		//GetWindowText(hEdit, buffer, 200);
		//_tcscpy(text, buffer);
		//HWND hParent = GetParent(hwnd);
		//// Передача данных главному диалогу
		//SetWindowText(hParent, TEXT("Привет от дочернего окна!"));
		//EndDialog(hwnd, IDOK);
	}
	else if (id == IDC_RESUME)
	{
		//открытие нового диалогового игра с логикой игры, присущей для этого режима игры.
	}
	else if (id == IDC_QUIT)
	{
		GetWindowRect(hwnd, coords);
		EndDialog(hwnd, IDC_QUIT);
	}
	else if (id == IDC_CLASSIC)
	{
		//открытие нового диалогового игра с логикой игры, присущей для этого режима игры.
	}
	else if (id == IDC_TIMED)
	{
		//открытие нового диалогового игра с логикой игры, присущей для этого режима игры.
	}
	else if (id >= IDC_BUTTON01 || id <= IDC_BUTTON064)
	{
		if (isHover)
		{
			if (id - 1 == numHover || id + 1 == numHover || id + 8 == numHover || id - 8 == numHover)
			{
				numSHover = id;
				CheckMatches(hwnd);
			}
			else{
				EnableWindow(GetDlgItem(hwnd, numHover), TRUE);
				EnableWindow(GetDlgItem(hwnd, id), FALSE);
				numHover = id;
			}
		}
		else{
			//TCHAR buf[10];
			//GetWindowText(GetDlgItem(hwnd, id), buf, 10);
			EnableWindow(GetDlgItem(hwnd, id), FALSE);
			numHover = id;
			isHover = TRUE;
		}
	}
}

BOOL CALLBACK ADDBlitz::DlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		HANDLE_MSG(hwnd, WM_CLOSE, ptr->Cls_OnClose);
		HANDLE_MSG(hwnd, WM_INITDIALOG, ptr->Cls_OnInitDialog);
		HANDLE_MSG(hwnd, WM_COMMAND, ptr->Cls_OnCommand);
	}
	return FALSE;
}
