#include "CWindowProcHook.hpp"

CWindowProcHook::CWindowProcHook(HWND pHandleWindow, WNDPROC windowProc) {
	m_lWindowProc = reinterpret_cast<long>(windowProc);
	m_lOriginalWindowProc = 0;
	m_pHandleWindow = pHandleWindow;
	m_bIsInstalled = false;
}

CWindowProcHook::~CWindowProcHook() {
	uninstall();
}

bool CWindowProcHook::install() {
	if (!m_bIsInstalled) {
		m_lOriginalWindowProc = GetWindowLongA(m_pHandleWindow, GWL_WNDPROC);
		SetWindowLongA(m_pHandleWindow, GWL_WNDPROC, m_lWindowProc);
		return true;
	}

	return false;
}

bool CWindowProcHook::uninstall() {
	if (m_bIsInstalled) {
		SetWindowLongA(m_pHandleWindow, GWL_WNDPROC, m_lOriginalWindowProc);
		return true;
	}

	return false;
}

WNDPROC CWindowProcHook::getOriginal() {
	return reinterpret_cast<WNDPROC>(m_lOriginalWindowProc);
}