/* 
 * File:   WindowGenerate.h
 * Author: USER
 *
 */

#ifndef WINDOWGENERATE_H
#define WINDOWGENERATE_H

#include <winnt.h>


LRESULT CALLBACK WindowProcedure(HWND,UINT, WPARAM,LPARAM);


class WindowGenerate
{

    HINSTANCE hInstance;
    WNDCLASSEX wndClassex;
    int x=600;
    int y=800;
public:
    HWND hwnd; /* Manipulador de ventana */
    WNDCLASSEX wincl; /* Estructura de datos para la clase de ventana */
    MSG mensaje;
    WindowGenerate(HINSTANCE);
    WindowGenerate(int,int,HINSTANCE);
    void show();
    void hidde();
    int buildWindow2();
    void crearMenu(HWND);
private:
    void buildWindow(LPCSTR,int,int);
    
    
};


#endif /* WINDOWGENERATE_H */

