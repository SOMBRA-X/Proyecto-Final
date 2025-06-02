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
    cin.ignore();                                  

// Declarar arreglos para los datos de los alumnos
    string nombres[alumnos];                        //de aquii a la (//E) hecho por Eduardo
    string apellido1[alumnos];
    string apellido2[alumnos];
    string cedulas[alumnos];
    string cursos[alumnos];
int notas[alumnos][examenes];

                                                    
       // Ingresar los datos de cada alumno
    for(int i = 0; i < alumnos; i++) {
        setColor(3);
        cout << "Alumno " << i+1 << endl;
        cout << "Nombre: ";
        setColor(7);
        getline(cin, nombres[i]);
        setColor(3);
        cout << "Primer apellido: ";
        setColor(7);
        getline(cin, apellido1[i]);
        setColor(3);
        cout << "Segundo apellido: ";
        setColor(7);
        getline(cin, apellido2[i]);
        setColor(3);
        cout << "Cedula: ";
        setColor(7);
        getline(cin, cedulas[i]);
        setColor(3);
        cout << "cursos: ";
        setColor(7);
        getline(cin, cursos[i]);
        setColor(3);
        cout << "Ingrese las notas de los 5 examenes:" << endl;
        for(int j = 0; j < examenes; j++) {
            setColor(3);
            cout << "Nota del examen " << j+1 << ": ";
            setColor(7);
            cin >> notas[i][j];
        }
       
        cout << "\033[2J\033[H";
    }

    // Calcular y mostrar el promedio de cada alumno
    for(int i = 0; i < alumnos; i++) {
        int suma = 0;
        for(int j = 0; j < examenes; j++) {
            suma += notas[i][j];
        }
        double promedio = static_cast<double>(suma) / examenes;
        cout << "El promedio del alumno " << i+1 << " es: " << promedio << endl;
    }                                               //E


    
    system("pause");
    cout << "\033[2J\033[H";
    
    return 0;
}