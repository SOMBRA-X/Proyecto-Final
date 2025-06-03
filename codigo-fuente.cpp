//comentario eduardo
//comentario jeyfreth
//comentario ivan


/* Códigos ANSI de los Colores Seleccionados
\033[3 → Celeste
\033[7 → Blanco
\033[4 → Rojo
\033[2 → Verde
*/

#include <iostream>                        //De aqui a la (//J) hecho por Jeyfreth
#include <windows.h>
#include <string>
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

const int examenes = 5;

bool soloLetras(const string& s) {
    return !s.empty() && all_of(s.begin(), s.end(), [](char c){ return isalpha(c) || isspace(c); });
}

bool soloNumeros(const string& s) {
    return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
}

int main() {
    char repetir;
    cout << "\033[2J\033[H";
    int alumnos;

do {                                           //de aqui hice el bucle para el codigo completo ivan(//I)
    cout << "\033[2J\033[H";
    gotoxy(50,0);
    setColor(3);
    cout << "Sistema De Calificaciones "<<endl;
    setColor(3);
    cout << "=============================================================================================================================" << endl;
    gotoxy(0,3);
    setColor(3);
    cout << "¿cuantos alumnos decea evaluar? ";
    setColor(7);                           //J

    
    // ingresar datos de los alumnos
    string alumnosStr;                      //desde aqui a la (//E) hecho por Eduardo
    do {
        getline(cin, alumnosStr);
        if (!soloNumeros(alumnosStr) || alumnosStr.empty()) {
            setColor(4);
            cout << "El dato ingresado es invalido. Solo numeros. Intente de nuevo: ";
            setColor(7);
        }
    } while (!soloNumeros(alumnosStr) || alumnosStr.empty());
    alumnos = stoi(alumnosStr);

    string nombres[alumnos], apellido1[alumnos], apellido2[alumnos], cedulas[alumnos], ciclos[alumnos];
    double notas[alumnos][examenes];

    for(int i = 0; i < alumnos; i++) {
        setColor(3);
        cout << "Alumno " << i+1 << endl;

        // Nombre
        do {                            //de aqui hice el bucle para los errores del usuario de ivan(//I)
            cout << "Nombre: ";
            setColor(7);
            getline(cin, nombres[i]);
            if (!soloLetras(nombres[i])) {
                setColor(4);
                cout << "El dato ingresado es invalido. Solo letras. Intente de nuevo: ";
                setColor(3);
            }
        } while (!soloLetras(nombres[i]));

        // Primer apellido
        do {
            setColor(3);
            cout << "Primer apellido: ";
            setColor(7);
            getline(cin, apellido1[i]);
            if (!soloLetras(apellido1[i])) {
                setColor(4);
                cout << "El dato ingresado es invalido. Solo letras. Intente de nuevo: ";
                setColor(3);
            }
        } while (!soloLetras(apellido1[i]));

        // Segundo apellido
        do {
            setColor(3);
            cout << "Segundo apellido: ";
            setColor(7);
            getline(cin, apellido2[i]);
            if (!soloLetras(apellido2[i])) {
                setColor(4);
                cout << "El dato ingresado es invalido. Solo letras. Intente de nuevo: ";
                setColor(3);
            }
        } while (!soloLetras(apellido2[i]));

        // Cedula
        do {
            setColor(3);
            cout << "Cedula: ";
            setColor(7);
            getline(cin, cedulas[i]);
            if (!soloNumeros(cedulas[i]) || cedulas[i].length() > 9) {
                setColor(4);
                cout << "El dato ingresado es invalido. Solo numeros y maximo 9 digitos. Intente de nuevo: ";
                setColor(3);
            }
        } while (!soloNumeros(cedulas[i]) || cedulas[i].length() > 9);

        // ciclo
        do {
            setColor(3);
            cout << "ciclos: ";
            setColor(7);
            getline(cin, ciclos[i]);
            if (ciclos[i].empty()) {
                setColor(4);
                cout << "El dato ingresado es invalido. Intente de nuevo: ";
                setColor(3);
            }
        } while (ciclos[i].empty());

        // Notas
        bool validInput=true;
        setColor(3);
        cout << "Ingrese las notas de los 5 examenes:" << endl;
        for(int j = 0; j < examenes; j++) {
            do {
                setColor(3);
                cout << "Nota del examen " << j+1 << ": ";
                setColor(7);
                cin >> notas[i][j];
                if(cin.fail() || notas[i][j] < 0 || notas[i][j] > 100) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    validInput = false;
                    setColor(4);
                    cout << "El dato ingresado es invalido. Solo numeros (0-100). aprete cualquier tecla para intentar de nuevo: ";
                    cin.ignore();
                    setColor(3);
                }else {
                    validInput = true;
                }
            } while(!validInput);
        }                                   //I
        cin.ignore();
        cout << "\033[2J\033[H";
    }                                       //E

//IU y procesos de sacar promedios

cout << "\033[2J\033[H";                    //De aqui a la (//J) hecho por Jeyfreth
gotoxy(50,0);
setColor(3);
cout << "Sistema De Calificaciones" << endl;
setColor(3);
cout << "=============================================================================================================================" << endl;

// Encabezados con gotoxy
setColor(2);
gotoxy(10,3);  cout << "Aprobados";
setColor(4);
gotoxy(70,3);  cout << "Reprobados";

setColor(2);
gotoxy(2,5);   cout << "Nombre";
gotoxy(29,5);  cout << "Ciclo";
gotoxy(38,5);  cout << "Cedula";
gotoxy(50,5);  cout << "Promedio";

setColor(4);
gotoxy(62,5);  cout << "Nombre";
gotoxy(89,5);  cout << "Ciclo";
gotoxy(98,5);  cout << "Cedula";
gotoxy(110,5); cout << "Promedio";           //J  

// Clasificar alumnos
setColor(7);                                 //De aqui a la (//E) hecho por Eduardo
int apIndex = 0, rpIndex = 0;
string aprobadosNombres[alumnos], aprobadosCiclos[alumnos], aprobadosCedulas[alumnos];
double aprobadosPromedios[alumnos];
string reprobadosNombres[alumnos], reprobadosCiclos[alumnos], reprobadosCedulas[alumnos];
double reprobadosPromedios[alumnos];

for(int i = 0; i < alumnos; i++) {
    double suma = 0;
    for(int j = 0; j < examenes; j++) suma += notas[i][j];
    double promedio = suma / examenes;
    string nombreCompleto = nombres[i] + " " + apellido1[i] + " " + apellido2[i];
    if (promedio >= 70.00) {
        aprobadosNombres[apIndex] = nombreCompleto;
        aprobadosCiclos[apIndex] = ciclos[i];
        aprobadosCedulas[apIndex] = cedulas[i];
        aprobadosPromedios[apIndex] = promedio;
        apIndex++;
    } else {
        reprobadosNombres[rpIndex] = nombreCompleto;
        reprobadosCiclos[rpIndex] = ciclos[i];
        reprobadosCedulas[rpIndex] = cedulas[i];
        reprobadosPromedios[rpIndex] = promedio;
        rpIndex++;
    }
}                                             //E

// Imprimir en columnas lado a lado usando gotoxy
int filas = max(apIndex, rpIndex);           //De aqui a la (//J) hecho por Jeyfreth
for(int i = 0; i < filas; i++) {
    int y = 7 + i;
    // Aprobados
    if(i < apIndex) {
        setColor(2);
        gotoxy(2, y);   cout << left << setw(15) << aprobadosNombres[i];
        gotoxy(29, y);  cout << left << setw(15) << aprobadosCiclos[i];
        gotoxy(38, y);  cout << left << setw(15) << aprobadosCedulas[i];
        gotoxy(50, y);  cout << fixed << setprecision(2) << aprobadosPromedios[i];
        //setColor(7);
    }
    // Reprobados
    if(i < rpIndex) {
        setColor(4);
        gotoxy(62, y);  cout << left << setw(15) << reprobadosNombres[i];
        gotoxy(89, y);  cout << left << setw(15) << reprobadosCiclos[i];
        gotoxy(98, y);  cout << left << setw(15) << reprobadosCedulas[i];
        gotoxy(110, y); cout << fixed << setprecision(2) << reprobadosPromedios[i];
        //setColor(7);
    }                                        //J
}

    setColor(3);
        cout << endl << endl;
        cout << "¿Desea evaluar otro grupo de alumnos? (s para si y cualquier Letra o Numero para no): ";
        setColor(7);
        cin >> repetir;
        cin.ignore();
    }while (repetir == 's' || repetir == 'S'); //I



    setColor(3);
    system("pause");
    cout << "\033[2J\033[H";
    return 0;
}