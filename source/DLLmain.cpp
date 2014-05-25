/*
 *	DLLMain.cpp
 *
 *	Main code for the IFC22.dll replacement.
 *	This is reverse engineered from LouCypher's
 *	IFC22.dll replacement from somewhere on either
 *	the TribesNext.com or The-Construct.net forums.
 *
 *	Robert MacGregor
 */

#include "stdafx.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
    return true;
}

class CImmCompoundEffect 
{
	public:
	_declspec(dllexport) int Start(unsigned long x, unsigned long y) { return 8; }
	_declspec(dllexport) int Stop() { return 1; }
};

class CImmDevice 
{
	public:
      	_declspec(dllexport) static CImmDevice * CreateDevice(HINSTANCE__ *, HWND__ *) 
	{ 
		typedef void (*LPINITT2DLL)(void);
		HINSTANCE hDLL = NULL;
		LPINITT2DLL lpinitT2DLL = NULL;
		hDLL = LoadLibrary(L"t2dll.dll"); // AfxLoadLibrary is probably better.

		if (hDLL == NULL)
			return 0; // The DLL doesn't exist
		else
			lpinitT2DLL = (LPINITT2DLL)GetProcAddress(hDLL, "_Z9initT2Dllv"); // Attempt to load our entry point

		if (lpinitT2DLL == NULL)
			return 0; // Unable to load entry point
		else
			lpinitT2DLL(); // The function was loaded, call TribesNext and move on to postTN Startup

		return 0;
	  }

	  _declspec(dllexport) int UsesWin32MouseServices(int) { return 4; }
};

class CImmProject 
{
	public:
	_declspec(dllexport) CImmProject() {}
	_declspec(dllexport) ~CImmProject() {}

	_declspec(dllexport) CImmCompoundEffect *GetCreatedEffect(int) { return 0; } 
	_declspec(dllexport) CImmCompoundEffect *GetCreatedEffect(const char *) { return 0; } 
	_declspec(dllexport) CImmCompoundEffect *CreateEffect(char const *, CImmDevice *, unsigned long) { return 0; }
	_declspec(dllexport) int Start(char const *, unsigned long, unsigned long, class CImmDevice *) { return 1; }
	_declspec(dllexport) int Stop(const char *) { return 1; }
	_declspec(dllexport) int LoadProjectFromMemory(void *, CImmDevice *) { return 1; }
};

#ifdef _MANAGED
#pragma managed(pop)
#endif
