#pragma once

#include <Windows.h>

class CWindowProcHook {
private:
	long m_lWindowProc;
	long m_lOriginalWindowProc;
	HWND m_pHandleWindow;
	bool m_bIsInstalled;

public:
	CWindowProcHook(HWND pHandleWindow, WNDPROC windowProc);
	~CWindowProcHook();

	bool install(); 
	bool uninstall();
	WNDPROC getOriginal();	
};