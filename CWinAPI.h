/**
    Created by: Krzysztof Dobrzynski - k.dobrzynski94@gmail.com
                https://github.com/Sejoslaw
*/

#ifndef CWINAPI_H_INCLUDED
#define CWINAPI_H_INCLUDED

/// ============================================ Additional Includes

#include <windows.h>

/// ============================================ Definitions

/// Windows has NULL declared
#ifndef NULL
    #ifdef __cplusplus
        #define NULL 0
    #else
        #define NULL ((void*)0)
    #endif
#endif // NULL

/// Definition for new instance for WinMain.
typedef struct WinAPI_Instance
{
    HINSTANCE hInstance; /// Application Instance
    HINSTANCE hPrevInstance;
    LPSTR lpCmdLine; /// Command Line - char*
    int nCmdShow; /// Application State
} WinAPI_Instance;
/// Instance object
WinAPI_Instance* instance;

/// Window Message
MSG Message;

/// ============================================ Operations

/// Main Function to register WinMain.
int WinAPI_WinMain(
                   HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    instance = malloc(sizeof(WinAPI_Instance));
    instance->hInstance = hInstance;
    instance->hPrevInstance = hPrevInstance;
    instance->lpCmdLine = lpCmdLine;
    instance->nCmdShow = nCmdShow;

    return 1;
}

/// Show Windows Message Box
///
/// Where:
/// hWnd - Window Handler (may be NULL).
/// lpText - Text to be displayed.
/// lpCaption - Window Title.
/// uType - Combination of styles, see: MB_ABORTRETRYIGNORE, MB_OK, MB_OKCANCEL, MB_RETRYCANCEL, MB_YESNO, MB_YESNOCANCEL.
/// Available icons: MB_ICONEXCLAMATION, MB_ICONWARNING, MB_ICONINFORMATION, MB_ICONASTERISK, MB_ICONQUESTION, MB_ICONSTOP, MB_ICONERROR, MB_ICONHAND.
/// Available default main button: MB_DEFBUTTON1, MB_DEFBUTTON2, MB_DEFBUTTON3, MB_DEFBUTTON4.
/// Available window modal: MB_APPLMODAL, MB_SYSTEMMODAL, MB_TASKMODAL.
/// Available returns: 0 - if error, IDABORT, IDCANCEL, IDRETRY, IDIGNORE, IDNO, IDYES, IDOK.
int WinAPI_MessageBox(
                      HWND hWnd,
                      LPCSTR lpText,
                      LPCSTR lpCaption,
                      UINT uType)
{
    return MessageBox(hWnd, lpText, lpCaption, uType);
}

/// Create new Window
///
/// Where:
/// style - Class Styles. Should be 0.
/// lpfnWndProc - Pointer to the procedure which handles Window. Can be WndProc.
/// cbClsExtra - Additional bytes in memory for Window class. Can be 0.
/// cbWndExtra - Additional bytes in memory for Window class. Can be 0.
/// hInstance - Application handler - Window owner. By default it's WinMain first parameter.
/// hIcon - Window Icon. Can be seen when pressing Alt + Tab.
/// hCursor - Mouse Cursor.
/// hbrBackground - Window Background. Color and theme.
/// lpszMenuName - ID Name of the Window which will be seen in Resource View. Can be NULL.
/// lpszClassName - Class Name. Can be anything.
/// hIconSm - Small Icon. Can be seen in the Window corner.
WNDCLASSEX WinAPI_NewWindowClass(
                            UINT style,
                            WNDPROC lpfnWndProc,
                            int cbClsExtra,
                            int cbWndExtra,
                            HINSTANCE hInstance,
                            HICON hIcon,
                            HCURSOR hCursor,
                            HBRUSH hbrBackground,
                            LPCSTR lpszMenuName,
                            LPCSTR lpszClassName,
                            HICON hIconSm)
{
    WNDCLASSEX windowClass;

    windowClass.cbSize = sizeof(WNDCLASSEX);
    windowClass.style = style;
    windowClass.lpfnWndProc = lpfnWndProc;
    windowClass.cbClsExtra = cbClsExtra;
    windowClass.cbWndExtra = cbWndExtra;
    windowClass.hInstance = hInstance;
    windowClass.hIcon = hIcon; /// LoadIcon( NULL, IDI_APPLICATION );
    windowClass.hCursor = hCursor; /// LoadCursor( NULL, IDC_ARROW );
    windowClass.hbrBackground = hbrBackground; /// ( HBRUSH )( COLOR_WINDOW + 1 ); /// - default gray Background
    windowClass.lpszMenuName = lpszMenuName;
    windowClass.lpszClassName = lpszClassName;
    windowClass.hIconSm = hIconSm; /// LoadIcon( NULL, IDI_APPLICATION );

    return windowClass;
}

/// Builds new Window
///
/// Where:
/// dwExStyle - External Window Style. e.x. WS_EX_WINDOWEDGE
/// lpClassName - Window Class Name.
/// lpWindowName - Window Title Name.
/// dwStyle - Window Style: WS_BORDER, WS_CAPTION, WS_CHILD, WS_DISABLED, WS_DLGFRAME, WS_HSCROLL, WS_MAXIMIZE, WS_MAXIMIZEBOX, WS_MINIMIZE, WS_MINIMIZEBOX,
///                           WS_OVERLAPPED, WS_OVERLAPPEDWINDOW, WS_POPUP, WS_POPUPWINDOW, WS_SIZEBOX, WS_SYSMENU, WS_TABSTOP, WS_VISIBLE, WS_VSCROLL.
/// x - Window X-Axis position.
/// y - Window Y-Axis position.
/// nWidth - Window Width.
/// nHeight - Window Height.
/// hWndParent - Parent Window Handler. Can be NULL.
/// hMenu - Window Menu Handler. Can be NULL.
/// hInstance - Applcation Handler. First parameter from WinMain.
/// lpParam - Additional Parameters Painter. Can be NULL.
HWND WinAPI_CreateWindow(
                         DWORD dwExStyle,
                         LPCSTR lpClassName,
                         LPCSTR lpWindowName,
                         DWORD dwStyle,
                         int x,
                         int y,
                         int nWidth,
                         int nHeight,
                         HWND hWndParent,
                         HMENU hMenu,
                         HINSTANCE hInstance,
                         LPVOID lpParam)
{
    return CreateWindowExA(dwExStyle, lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
}

/// Show Window
///
/// Where:
/// hWnd - Window Handler
/// nCmdShow - Window cmd arguments.
BOOL WinAPI_ShowWindow(HWND hWnd, int nCmdShow)
{
    BOOL b = ShowWindow(hWnd, nCmdShow);
    b = UpdateWindow(hWnd);

    return b;
}

#endif // CWINAPI_H_INCLUDED

/***
	License page: http://www.zlib.net/zlib_license.html
	version 1.2.11, January 15th, 2017
	  Copyright (C) 2010-2017 Krzysztof Dobrzynski
	  This software is provided 'as-is', without any express or implied
	  warranty.  In no event will the authors be held liable for any damages
	  arising from the use of this software.
	  Permission is granted to anyone to use this software for any purpose,
	  including commercial applications, and to alter it and redistribute it
	  freely, subject to the following restrictions:
	  1. The origin of this software must not be misrepresented; you must not
		 claim that you wrote the original software. If you use this software
		 in a product, an acknowledgment in the product documentation would be
		 appreciated but is not required.
	  2. Altered source versions must be plainly marked as such, and must not be
		 misrepresented as being the original software.
	  3. This notice may not be removed or altered from any source distribution.
	  Krzysztof Dobrzynski
	  k.dobrzynski94@gmail.com
*/
