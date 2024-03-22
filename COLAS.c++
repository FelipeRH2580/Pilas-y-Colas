#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Proceso {
    int id;
};

int main() {
    vector<stack<Proceso>> pilas(3);
    int opcion, id, prioridad;

    do {
        cout << "1. Insertar proceso\n";
        cout << "2. Atender proceso\n";
        cout << "3. Mostrar procesos\n";
        cout << "4. Salir\n";
        cout << "Ingrese la opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el ID del proceso: ";
                cin >> id;
                cout << "Ingrese la prioridad del proceso (1-3): ";
                cin >> prioridad;
                if (prioridad < 1 || prioridad > 3) {
                    cout << "Prioridad inválida. Debe ser un número entre 1 y 3.\n";
                } else {
                    pilas[prioridad - 1].push({id});
                }
                break;
            case 2:
                for (int i = 2; i >= 0; --i) {
                    if (!pilas[i].empty()) {
                        cout << "Proceso " << pilas[i].top().id << " con prioridad " << i + 1 << " atendido\n";
                        pilas[i].pop();
                        break;
                    }
                }
                break;
            case 3:
                for (int i = 2; i >= 0; --i) {
                    if (!pilas[i].empty()) {
                        stack<Proceso> copia = pilas[i];
                        while (!copia.empty()) {
                            cout << "Proceso " << copia.top().id << " con prioridad " << i + 1 << "\n";
                            copia.pop();
                        }
                    }
                }
                break;
            case 4:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción inválida\n";
        }
    } while (opcion != 4);

    return 0;
}