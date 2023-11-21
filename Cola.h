#ifndef COLA_H
#define COLA_H

#include <iostream>

using namespace std;

class alumno {
private:
    string nombre;
    string nombreCarrera;
    int materiasAprobadas;
    float promedioGeneral;

public:
    alumno() : nombre(""), nombreCarrera(""), materiasAprobadas(0), promedioGeneral(0.0) {}
    alumno(string n, string nc, int ma, float pg) : nombre(n), nombreCarrera(nc), materiasAprobadas(ma), promedioGeneral(pg) {}

   void operator=(const alumno& x) {
    nombre = x.nombre;
    nombreCarrera = x.nombreCarrera;
    materiasAprobadas = x.materiasAprobadas;
    promedioGeneral = x.promedioGeneral;
}

    friend ostream& operator<<(ostream& os, const alumno& a) {
        os << "\tNombre: " << a.nombre
           << ", Carrera: " << a.nombreCarrera
           << ", Materias Aprobadas: " << a.materiasAprobadas
           << ", Promedio General: " << a.promedioGeneral;
        return os;
    }

    friend istream& operator>>(istream& is, alumno& a) {
        cout << "\tIngrese nombre del alumno: ";
        is >> a.nombre;
        cout << "\tIngrese nombre de la carrera: ";
        is >> a.nombreCarrera;
        cout << "\tIngrese cantidad de materias aprobadas: ";
        is >> a.materiasAprobadas;
        cout << "\tIngrese promedio general: ";
        is >> a.promedioGeneral;
        return is;
    }
};


template<class T>
class node {
public:
    T data;
    node<T>* sig;

    node() : sig(nullptr) {}
};


template<class T>
class Cola {
private:
    node<T>* frente;
    node<T>* final;

public:
    Cola() : frente(nullptr), final(nullptr) {}

    bool vacia() const {
        return frente == nullptr;
    }

   void enqueue(const T& elem) {
        node<T>* nuevo = new node<T>;
        nuevo->data = elem;
        nuevo->sig = nullptr;

        if (vacia()) {
            frente = final = nuevo;
        } else {
            final->sig = nuevo;
            final = nuevo;
        }
        cout << "\t¡Elemento encolado correctamente!." << endl;
    }

    T dequeue() {
        if (vacia()) {
            cout << "\tLa cola está vacía, no se puede eliminar ningún elemento." << endl;
            return T();
        } else {
            node<T>* temp = frente;
            T eliminado = frente->data;
            frente = frente->sig;
            if (frente == nullptr) {
                final = nullptr;
            }
            delete temp;
            return eliminado;
        }
    }

    void imprimir() const {
        node<T>* aux = frente;
        while (aux != nullptr) {
            cout << aux->data << "-> ";
            aux = aux->sig;
        }
    }
};

#endif // COLA_H
