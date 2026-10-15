#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

class Pila {
private:
    Nodo* top;

public:
    Pila() {
        top = NULL;
    }

    bool estaVacia() {
        return top == NULL;
    }

    void push(int valor) {
        Nodo* nuevo = new Nodo();

        nuevo->dato = valor;
        nuevo->siguiente = top;

        top = nuevo;

        cout << "Se agrego: " << valor << endl;
    }

    int pop() {
        if (estaVacia()) {
            cout << "Error: la pila esta vacia.\n";
            return -1;
        }

        Nodo* auxiliar = top;
        int valor = auxiliar->dato;

        top = top->siguiente;

        delete auxiliar;

        return valor;
    }

    int peek() {
        if (estaVacia()) {
            cout << "La pila esta vacia.\n";
            return -1;
        }

        return top->dato;
    }

    ~Pila() {
        while (!estaVacia()) {
            pop();
        }
    }   
};

int main() {
    Pila pila;

    pila.push(100);
    pila.push(200);
    pila.push(300);

    return 0;
}