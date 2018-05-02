#include <cstdlib>
#include <iostream>
#include <windows.h>
#include "WindowGenerate.h"

#define PRUEBA 100
#define SALIR 101
using namespace std;



LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT mensaje, WPARAM wParam,
        LPARAM lParam) {
    switch (mensaje) /* manipulador de mensaje */ {
        case WM_DESTROY:
            PostQuitMessage(0); /* Envía el mensaje WM_QUIT a la cola de mensajes */
            break;
        case WM_COMMAND:
            if(LOWORD(wParam)==PRUEBA){
                MessageBox(hwnd,"Mensaje prueba menu","menu",MB_OK);
            }
            if(LOWORD(wParam)==SALIR){
                MessageBox(hwnd,"Mensaje salir menu","menu",MB_OK);
                PostQuitMessage(0);
            }
            break;
        default: /* Mensajes que no queremos manejar */
            return DefWindowProc(hwnd, mensaje, wParam, lParam);
    }
    return 0;
}


WindowGenerate::WindowGenerate(int xPosition, int yPosition,HINSTANCE hInstance) {
    this->x = xPosition;
    this->y = yPosition;
    this->hInstance = hInstance;
    this->buildWindow("",this->x,this->y);
};

WindowGenerate::WindowGenerate(HINSTANCE hInstance) {
    this->hInstance = hInstance;
    this->buildWindow("",this->x,this->y);
}

void WindowGenerate::show() {
        ShowWindow(this->hwnd, SW_SHOWDEFAULT);
            /* 
     * Obtiene Evento de ventana
    */
        while (TRUE == GetMessage(&mensaje, NULL, 0, 0)) {
            /* Traducir mensajes de teclas virtuales a mensajes de caracteres
             */
            TranslateMessage(&mensaje);
            /* Enviar mensaje al procedimiento de ventana */
            DispatchMessage(&mensaje);
        }
};

void WindowGenerate::hidde() {
    
};


void WindowGenerate::buildWindow(LPCSTR name="VENTANA 1",int x=300, int y=300){
    this->x=(this->x)?this->x:x;
    this->y=(this->y)?this->y:y;
    /* Estructura de la ventana */
    this->wincl.hInstance = this->hInstance;
    this->wincl.lpszClassName = "CLASE";
    this->wincl.lpfnWndProc = WindowProcedure; /* Esta función es invocada por Windows */
    this->wincl.style = CS_DBLCLKS; /* Captura los doble-clicks */
    this->wincl.cbSize = sizeof (WNDCLASSEX);
    /* Usar icono y puntero por defector */
    this->wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    this->wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    this->wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
    this->wincl.lpszMenuName = NULL; /* Sin menú */
    this->wincl.cbClsExtra = 0; /* Sin información adicional para la */
    this->wincl.cbWndExtra = 0; /* clase o la ventana */
    /* Usar el color de fondo por defecto para la ventana */
    this->wincl.hbrBackground = GetSysColorBrush(COLOR_BACKGROUND);
    /* Registrar la clase de ventana, si falla, salir del programa */
    if (!RegisterClassEx(&this->wincl)) return;
    /* La clase está registrada, crear la ventana */
    this->hwnd = CreateWindowEx(
            0, /* Posibilidades de variación */
            "CLASE", /* Nombre de la clase */
            "Ventana 1", /* Texto del título */
            WS_OVERLAPPEDWINDOW, /* Tipo por defecto */
            CW_USEDEFAULT, /* Windows decide la posición */
            CW_USEDEFAULT, /* donde se coloca la ventana */
            this->x, /* Ancho */
            this->y, /* Alto en pixels */
            HWND_DESKTOP, /* La ventana es hija del escritorio */
            NULL, /* Sin menú */
            this->hInstance, /* Manipulador de instancia */
            NULL /* No hay datos de creación de ventana */
            );
    this->crearMenu(this->hwnd);
    /* Mostrar la ventana */
    cout<<"valor ventana "<<hwnd<<endl;
    


}

void WindowGenerate::crearMenu(HWND hwnd){
    
//    HMENU hMenu1, hMenu2;
//    hMenu1 = CreateMenu();
//    hMenu2 = CreateMenu();
//    AppendMenu(hMenu2, MF_STRING, PRUEBA, "&Prueba");
//    AppendMenu(hMenu2, MF_SEPARATOR, 0, NULL);
//    AppendMenu(hMenu2, MF_STRING, SALIR, "&Salir");
//    AppendMenu(hMenu1, MF_STRING | MF_POPUP, (UINT)hMenu2, "&Principal");
//    SetMenu (hwnd, hMenu1);
    
    
    HMENU menu1,menu2,menu3;

    menu1 = CreateMenu();
    menu2 = CreateMenu();
    menu3 = CreateMenu();
    
    AppendMenu(menu1, MF_STRING, PRUEBA, "&Prueba");
    AppendMenu(menu1, MF_SEPARATOR, 0, NULL);
    AppendMenu(menu1, MF_STRING, SALIR, "&Salir");
    AppendMenu(menu2, MF_STRING | MF_POPUP, (UINT)menu1, "&Opcion1");
    AppendMenu(menu3, MF_STRING | MF_POPUP, (UINT)menu2, "&Main");
    SetMenu(hwnd,menu3);
}
