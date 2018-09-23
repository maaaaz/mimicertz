/*	Benjamin DELPY `gentilkiwi`
	http://blog.gentilkiwi.com
	benjamin@gentilkiwi.com
	Licence : https://creativecommons.org/licenses/by/4.0/
*/
#pragma once

#include "globals.h"
#include "modules/kuhl_m_standard.h"
#include "modules/kuhl_m_crypto.h"

#include <io.h>
#include <fcntl.h>
#define DELAYIMP_INSECURE_WRITABLE_HOOKS
#include <delayimp.h>

extern VOID WINAPI RtlGetNtVersionNumbers(LPDWORD pMajor, LPDWORD pMinor, LPDWORD pBuild);

int wmain(int argc, wchar_t * argv[]);
void mimikatz_begin();
void mimikatz_end();

BOOL WINAPI HandlerRoutine(DWORD dwCtrlType);

NTSTATUS mimikatz_initOrClean(BOOL Init);

NTSTATUS mimikatz_doLocal(wchar_t * input);
NTSTATUS mimikatz_dispatchCommand(wchar_t * input);

#ifdef _POWERKATZ
__declspec(dllexport) wchar_t * powershell_reflective_mimikatz(LPCWSTR input);
#elif defined _WINDLL
void reatachIoHandle(DWORD nStdHandle, int flags, const char *Mode, FILE *file);
void CALLBACK mimikatz_dll(HWND hwnd, HINSTANCE hinst, LPWSTR lpszCmdLine, int nCmdShow);
#ifdef _M_X64
#pragma comment(linker, "/export:mainW=mimikatz_dll")
#elif defined _M_IX86
#pragma comment(linker, "/export:mainW=_mimikatz_dll@16")
#endif
#endif