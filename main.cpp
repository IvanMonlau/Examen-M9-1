#include <iostream> 
#include <thread>   
#include <mutex>    
#include <chrono>   

using namespace std;

mutex mtx;

// funcion que hace que un hilo imprima números
void imprimirNumeros(int inicio, int fin, int incremento) {
    for (int i = inicio; i <= fin; i += incremento) {
        lock_guard<mutex> lock(mtx);
        cout << i;
        // si no es el último número, añade una coma
        if (i != fin) {
            cout << ", ";
        }

        cout.flush();

        // sleep de 0.5 segundos para mejorar legibilidad
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

int main() {
    // Creamos dos hilos
    thread t1(imprimirNumeros, 1, 10, 2);
    thread t2(imprimirNumeros, 2, 10, 2);

    // Esperamos a que los hilos terminen
    t1.join();
    t2.join();

    return 0;
}