#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <windows.h>
#include <tchar.h>
#include <vector>

#include "Window/WindowGenerate.h"




using namespace std;



#pragma comment(lib, "kernel32.lib")


void abrirBlockDeNotas() {
    HWND hWnd;
    STARTUPINFO sInfo;
    PROCESS_INFORMATION pInfo;
    ZeroMemory(&sInfo, sizeof (sInfo));
    sInfo.cb = sizeof (sInfo);
    ZeroMemory(&pInfo, sizeof (pInfo));
    if (CreateProcess("C:\\WINDOWS\\System32\\notepad.exe", "open", NULL, NULL, false, 0, NULL, NULL, &sInfo, &pInfo)) {
        do {
            cout << "suspendido 100ms" << endl;
            Sleep(100);
        } while ((hWnd = FindWindow(NULL, "Sin título: Bloc de notas")) = NULL);

        MoveWindow(hWnd, 0, 0, 20, 20, true);
        cout << pInfo.dwProcessId << endl;
        CloseHandle(pInfo.hProcess);
    }
}




/*punto de entrada de las aplicaciones WINAPI*/
int WINAPI WinMain(
        HINSTANCE hThisInstance,
        HINSTANCE hPrevInstance,
        LPSTR lpszArgument,
        int nFunsterStil
        ) {
    WindowGenerate wg(1024,800,hThisInstance) ;
    wg.show();
    //Sleep(2000);
    //CloseWindow(wg.hwnd);//cierra la venta por el pid
    return 0;
}


