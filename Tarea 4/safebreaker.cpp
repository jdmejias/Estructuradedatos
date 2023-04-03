//JHON DEIBY MEJIAS
//8964584
//safebreaker.cpp
//LA COMPLEJIDAD EN EL PEOR DE CASOS ES QUE RECCORA TODOS LOS NUMEROS DE 4 DIGITOS, SERIA O(10000). EL FOR INTERNO RECCORE TODAS LAS PISTAS, POR LO QUE DA ADICIONAL O(PISTAS). TAMBIEN SE REALIZA UNA COMPARACION LO QUE DA O(14) EN EL PEOR DE LOS CASOS. EN GENERAL LA COMPLEJIDAD ES O(10000*14*PISTAS)
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
//
// FUNCION PA CONVERTIR DE ENTERO A STRING
string to_stringg(int n) {
    string s = "";
    for (int i = 0; i < 4; i++) {
        s = char(n % 10 + '0') + s;
        n /= 10;
    }
    return s;
}

int main() {
    int casos, pistas;
    cin >> casos;
   
    while(casos--) {
        cin >> pistas;
        vector<int> num(pistas);
        vector<int> pista1(pistas);
        vector<int> pista2(pistas);
        for(int k = 0; k < pistas; k++) {
            scanf("%d %d/%d", &num[k], &pista1[k], &pista2[k]);
        } 
        int soluciones = 0;
        int respuesta;
        // ITERAR DESDE 0000 HASTA 9999
        for (int i = 0; i < 10000; i++) {
            string s = to_stringg(i);
            bool es_solucion = true;
            // COMPARAR EL NUMERO SI CUMPLE CON LAS CONDICIONES
            for (int j = 0; j < pistas && es_solucion; j++) {
                int identico = 0, diferente = 0;
                string p = to_stringg(num[j]);
                // COINCIDENCIAS 
                for (int k = 0; k < 4; k++) {
                    if (s[k] == p[k]) {
                        identico++;
                    }
                }
                // COINCIDENCIAS DIFERENTES POSICIONES
                for (int k = 0; k < 10; k++) {
                    int contar1 = count(s.begin(), s.end(), char(k + '0'));
                    int contar2 = count(p.begin(), p.end(), char(k + '0'));
                    diferente += min(contar1, contar2);
                }
                diferente -= identico;
                // COMPROBAR CON EL NUMERO ACTUAL
                if (identico != pista1[j] || diferente != pista2[j]) {
                    es_solucion = false;
                }
            }
            //IR GUARDANDO LA RESPUESTA
            if (es_solucion) {
                soluciones++;
                respuesta = i;
            }
        }
        // IMPRIMIR
        if (soluciones == 1) {
            cout << to_stringg(respuesta) << endl;
        } else if (soluciones == 0) {
            cout << "impossible" << endl;
        } else {
            cout << "indeterminate" << endl;
        }
    }
    return 0;
}

