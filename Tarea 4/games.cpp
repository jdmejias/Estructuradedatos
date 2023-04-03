//JHON DEIBY MEJIAS
//8964584
//games.cpp
//La complejidad en general de este codigo es O(n log n), donde n es la cantidad de invitados, debido al costo de ordenar el vector de nombres con la funcion sort
//La complejidad del segundo while es  O(n), donde "n" es la longitud de la cadena "mediana"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int invitados;
    string name, mediana, sig_mediana;
    bool encontrar = true;
    while (cin >> invitados && invitados != 0) {
        vector<string> names;
        for(int i = 0; i < invitados; i++) {
            cin >> name;
            names.push_back(name);
        }
        // ORDENAR LA LISTA
        sort(names.begin(), names.end()); 
        // MEDIANA
        mediana = names[invitados/2 - 1]; 
        // SIG.ELEMENTO DE LA MEDIANA
        sig_mediana = names[invitados/2]; 
        string indicador="";
        //EMPEZAR CON  LA LETRA A
        indicador+= 'A';  
        int posicion = 0;
        while(posicion < mediana.size() && encontrar == true){
            // INCREMENTAR EL INDICADOR HASTA QUE IGUALE A LA MEDIANA
            if( indicador.compare(mediana) < 0  && indicador[posicion] <= 'Z') {
                indicador[posicion]++;
                }
            else if( indicador.compare(mediana) >= 0 && indicador.compare(sig_mediana) < 0 && indicador[posicion] <= 'Z') {
                encontrar = false;
                }
            else if(mediana[posicion] != indicador[posicion]) {
                indicador[posicion] -= 1;
                indicador += 'A';
                posicion++; 
                }
            else {
                posicion++;
                }
        }
        cout << indicador << endl;
        names.clear();
        encontrar = true;
    }
    return 0;
}
