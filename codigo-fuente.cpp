//comentario eduardo
//comentario jeyfreth
//comentario ivan



/* Códigos ANSI de los Colores Seleccionados
\033[3 → Celeste
\033[7 → Blanco
\033[4 → Rojo
\033[2 → Verde
*/

#include <iostream>                                //De aqui a la (//J) hecho por Jeyfreth
#include <windows.h>
#include <string>
#include <cstdlib>
using namespace std;


    


void gotoxy(int x, int y) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void setColor(int color) {
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

int alumnos;
const int examenes = 5;

int main(){ 

    setColor(3);
    cout << "\033[2J\033[H";
    gotoxy(70,0);
    cout << "Sistema De Calificaciones" << endl;
    setColor(3);
    cout << "======================================================================================================================================================================" << endl;
       
    gotoxy(0,3);
    setColor(3);
    cout << "¿cuantos alumnos decea evaluar?";
    setColor(7);
    cin >> alumnos;                                 //J
    

    
    

    
    system("pause");
    cout << "\033[2J\033[H";
    
    return 0;
}