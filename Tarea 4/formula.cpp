//JHON DEIBY MEJIAS
//8964584
//formula.cpp
// la complejidad despues de la lectura de los datos es:O(carreras * pilotos * sistemasPuntuacion), ya que hay 3 ciclos anidados y cada uno depende de lo anterior mencionado.
// sobre  usar max element no influye porque esta en el segundo ciclo anidado y la complejidad de max_element es la del o(n) donde n es el vector que seria igual al piloto.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int carreras, pilotos;
    int add = 0, numsistemas = 0, sistemasPuntuacion = 0;
    int punto, itera;
    scanf("%d %d", &carreras, &pilotos);
    while (carreras != 0 && pilotos != 0) {
        vector<int> posiciones;
        vector<vector<int>> puntajes;
        vector<int> ganadores(pilotos, 0);
        //LEER LAS ENTRADAS, UN VECTOR POSICIONES QUE INCLUYE LAS CADA CARRERA CON LOS PILOTOS 
        for (int j = 0; j < carreras; j++) {
            for (int i = 0; i < pilotos; i++) {
                cin >> add;
                posiciones.push_back(add-1);
            }
        }
        // PARA CADA SISTEMA CREAR UN VECTOR E INTRODUCIRLO EN UN VECTOR DE VECTORES.
        cin >> sistemasPuntuacion;
        for (int i = 0; i < sistemasPuntuacion; i++) {
            cin >> numsistemas;
            vector<int> nuevoVector;
            for (int j = 0; j < numsistemas; j++) {
                cin >> punto;
                nuevoVector.push_back(punto);
            }
            puntajes.push_back(nuevoVector);
        }
        // DESPUES DE HABER LEIDO LA ENTRADA PROCEDER CON LA IMPLEMENTACIÓN
        vector<int> suma(pilotos, 0);
        
        for (int k = 0; k < sistemasPuntuacion; k++) {
            // RECORRER EL VECTOR DE LAS POSICIONES
            for (int j = 0; j < carreras; j++) {
                for (int i = 0; i < pilotos; i++) {
                    itera = posiciones[j * pilotos + i];
                    // SI LA POSICION QUE QUEDO ES MENOR A AL TAMAÑO DEL SISTEMA QUE SE PREMIARA ENTRAR
                    if (itera < puntajes[k].size()) {
                        //EN EL VECTOR GANARDORES IR SUMANDO LOS PUNTOS DE LAS POSICIONES
                        ganadores[i] += puntajes[k][itera];
                    }
                }
            }
            // PARA CADA SISTEMA GENERAR EL COUT POR ESO VA DENTRO DEL PRIMER FOR
            vector<int>::iterator it = max_element(ganadores.begin(), ganadores.end());
            // UN FOR PARA QUE RECORRA EL VECTOR GANADOR Y PUEDA IMPRIMIR EN EL CASO QUE EXISTAN VARIOS GANADORES
            for (int i = 0; i <= ganadores.size(); i++) {
                if (ganadores[i] == *it) {
                    cout << i + 1 << " ";
                }
            }
            cout << endl;
            ganadores = vector<int>(pilotos, 0);
        }
        scanf("%d %d", &carreras, &pilotos);
    }
    return 0;
}
