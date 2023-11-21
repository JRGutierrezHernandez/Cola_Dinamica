#include <iostream>
#include "Cola.h"
#include <locale>

using namespace std;

int main() {
    Cola<alumno> MiCola;
    alumno x;
    setlocale(LC_ALL,"");
    int opc;

    do {
        setlocale(LC_ALL, "");
        cout << "\n\t********** [MEN�] **********\n" << endl;
        cout << "\t1. Dar de alta una solicitud." << endl;
        cout << "\t2. Elaborar una constancia." << endl;
        cout << "\t3. Salir" << endl;
        cout << "\n\tElija una opci�n: ";
        cin >> opc;

        switch (opc) {
            case 1:
                cout << "\n\tIngrese los datos del alumno\n" << endl;
                cin >> x;
                MiCola.enqueue(x);
                cout << "\n\t!Solicitud de alumno encolada exitosamente!.\n" << endl;
                break;

            case 2:
                if (!MiCola.vacia()) {
                    cout << "\n\tElaborando constancia para el alumn@\n";
                    alumno constancia_alumno = MiCola.dequeue();
                    cout << constancia_alumno << endl;
                } else {
                    cout << "\tLa cola est�  vac�a, no hay alumnos para elaborar constancias." << endl;
                }
                break;

            case 3:
                cout << "\n\tSaliendo del programa..." << endl;
                break;

            default:
                cout << "\n\tOpci�n no v�lida. Por favor, elija una opci�n v�lida." << endl;
                break;
        }

    } while (opc != 3);

    return 0;
}
