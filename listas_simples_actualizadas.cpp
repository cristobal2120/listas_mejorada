#include <iostream>

class Nodo {
public:
    int dato;
    Nodo* siguiente;

    Nodo(int valor) : dato(valor), siguiente(nullptr) {}
};

class ListaSimple {
private:
    Nodo* cabeza;

public:
    ListaSimple() : cabeza(nullptr) {}

    void agregar(int valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        if (!cabeza) {
            cabeza = nuevoNodo;
        } else {
            Nodo* temp = cabeza;
            while (temp->siguiente) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevoNodo;
        }
    }

    void imprimir() {
        Nodo* temp = cabeza;
        while (temp) {
            std::cout << temp->dato << " ";
            temp = temp->siguiente;
        }
        std::cout << std::endl;
    }

    bool buscar(int valor) {
        Nodo* temp = cabeza;
        while (temp) {
            if (temp->dato == valor) {
                return true;
            }
            temp = temp->siguiente;
        }
        return false;
    }

    bool eliminar(int valor) {
        if (!cabeza) {
            return false;
        }

        if (cabeza->dato == valor) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
            return true;
        }

        Nodo* temp = cabeza;
        while (temp->siguiente) {
            if (temp->siguiente->dato == valor) {
                Nodo* nodoAEliminar = temp->siguiente;
                temp->siguiente = nodoAEliminar->siguiente;
                delete nodoAEliminar;
                return true;
            }
            temp = temp->siguiente;
        }
        return false;
    }

    bool actualizar(int valor, int nuevoValor) {
        Nodo* temp = cabeza;
        while (temp) {
            if (temp->dato == valor) {
                temp->dato = nuevoValor;
                return true;
            }
            temp = temp->siguiente;
        }
        return false;
    }
};

int main() {
    ListaSimple lista;

    char opcion;
    do {
        std::cout << "Menú:" << std::endl;
        std::cout << "1. Insertar elemento" << std::endl;
        std::cout << "2. Mostrar elementos" << std::endl;
        std::cout << "3. Buscar elemento" << std::endl;
        std::cout << "4. Eliminar elemento" << std::endl;
        std::cout << "5. Actualizar elemento" << std::endl;
        std::cout << "6. Salir" << std::endl;
        std::cout << "Ingrese su opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case '1': // Insertar elemento
                int nuevoElemento;
                std::cout << "Ingrese el nuevo elemento: ";
                std::cin >> nuevoElemento;
                lista.agregar(nuevoElemento);
                break;

            case '2': // Mostrar elementos
                std::cout << "Elementos: ";
                lista.imprimir();
                break;

            case '3': // Buscar elemento
                int elementoABuscar;
                std::cout << "Ingrese el elemento a buscar: ";
                std::cin >> elementoABuscar;
                if (lista.buscar(elementoABuscar)) {
                    std::cout << "Elemento encontrado." << std::endl;
                } else {
                    std::cout << "Elemento no encontrado." << std::endl;
                }
                break;

            case '4': // Eliminar elemento
                int elementoAEliminar;
                std::cout << "Ingrese el elemento a eliminar: ";
                std::cin >> elementoAEliminar;
                if (lista.eliminar(elementoAEliminar)) {
                    std::cout << "Elemento eliminado." << std::endl;
                } else {
                    std::cout << "Elemento no encontrado." << std::endl;
                }
                break;

            case '5': // Actualizar elemento
                int valorAActualizar, nuevoValor;
                std::cout << "Ingrese el valor a actualizar: ";
                std::cin >> valorAActualizar;
                std::cout << "Ingrese el nuevo valor: ";
                std::cin >> nuevoValor;
                if (lista.actualizar(valorAActualizar, nuevoValor)) {
                    std::cout << "Elemento actualizado." << std::endl;
                } else {
                    std::cout << "Elemento no encontrado." << std::endl;
                }
                break;

            case '6': // Salir
                std::cout << "Saliendo del programa." << std::endl;
                break;

            default:
                std::cout << "Opción no válida. Intente de nuevo." << std::endl;
                break;
        }
    } while (opcion != '6');

    return 0;
}





