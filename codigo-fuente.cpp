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
#include <iomanip>
#include <cctype>
#include <algorithm>
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

bool soloLetras(const string& s) {
    return !s.empty() && all_of(s.begin(), s.end(), [](char c){ return isalpha(c) || isspace(c); });
}

bool soloNumeros(const string& s) {
    return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
}

  


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
double notas[alumnos][examenes];

                                                    
       // Ingresar los datos de cada alumno
       for(int i = 0; i < alumnos; i++) {           //de aqui hice el bucle para los errores del usuario de ivan(//I)
    setColor(3);
    cout << "Alumno " << i+1 << endl;

    // Validar nombre (solo letras)
    cout << "Nombre: ";
    setColor(7);
    getline(cin, nombres[i]);
    while (nombres[i].empty() || !all_of(nombres[i].begin(), nombres[i].end(), [](char c){ return isalpha(c) || isspace(c); })) {
        setColor(4);
        cout << "El dato ingresado es invalido. Solo letras. Intente de nuevo: ";
        setColor(7);
        getline(cin, nombres[i]);
    }

    setColor(3);
    cout << "Primer apellido: ";
    setColor(7);
    getline(cin, apellido1[i]);
    while (apellido1[i].empty() || !all_of(apellido1[i].begin(), apellido1[i].end(), [](char c){ return isalpha(c) || isspace(c); })) {
        setColor(4);
        cout << "El dato ingresado es invalido. Solo letras. Intente de nuevo: ";
        setColor(7);
        getline(cin, apellido1[i]);
    }

    setColor(3);
    cout << "Segundo apellido: ";
    setColor(7);
    getline(cin, apellido2[i]);
    while (apellido2[i].empty() || !all_of(apellido2[i].begin(), apellido2[i].end(), [](char c){ return isalpha(c) || isspace(c); })) {
        setColor(4);
        cout << "El dato ingresado es invalido. Solo letras. Intente de nuevo: ";
        setColor(7);
        getline(cin, apellido2[i]);
    }

    setColor(3);
    cout << "Cedula: ";
    setColor(7);
    getline(cin, cedulas[i]);
    while (
        cedulas[i].empty() ||
        !all_of(cedulas[i].begin(), cedulas[i].end(), ::isdigit) ||
        cedulas[i].length() > 9
    ) {
        setColor(4);
        cout << "El dato ingresado es invalido. Solo numeros y maximo 9 digitos. Intente de nuevo: ";
        setColor(7);
        getline(cin, cedulas[i]);
    }

    setColor(3);
    cout << "cursos: ";
    setColor(7);
    getline(cin, cursos[i]);
    while (cursos[i].empty()) {
        setColor(4);
        cout << "El dato ingresado es invalido. Intente de nuevo: ";
        setColor(7);
        getline(cin, cursos[i]);
    }

    setColor(3);
    cout << "Ingrese las notas de los 5 examenes:" << endl;
    for(int j = 0; j < examenes; j++) {
        setColor(3);
        cout << "Nota del examen " << j+1 << ": ";
        setColor(7);
        cin >> notas[i][j];
        while(cin.fail() || notas[i][j] < 0 || notas[i][j] > 100) {
            cin.clear();
            cin.ignore(1000, '\n');
            setColor(4);
            cout << "El dato ingresado es invalido. Solo numeros (0-100). Intente de nuevo: ";
            setColor(7);
            cin >> notas[i][j];
        }
    }
    cin.ignore(); // Limpiar buffer antes del siguiente getline
    cout << "\033[2J\033[H";
}                                                  //I
    

    // Calcular y mostrar el promedio de cada alumno
    for(int i = 0; i < alumnos; i++) {
        double suma = 0.0;
        for(int j = 0; j < examenes; j++) {
            suma += notas[i][j];
        }
        double promedio = suma / 5.0;
        cout<<fixed<<setprecision(2); // Establece 2 decimales
        cout << "El promedio del alumno " << i+1 << " es: " << promedio << endl;
    }                                               //E


    
    system("pause");
    cout << "\033[2J\033[H";
    
    return 0;
}