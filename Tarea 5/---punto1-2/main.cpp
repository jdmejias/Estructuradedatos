#include "lista.h"
#include <iostream>
using namespace std;
//La complejidad  de ContarOcurrencias es O(n^2 ), donde n es el tamaño de la lista, esto ocurre porque tenemos un for que hace una comparacion por cada elemento de la lista, como tenemos a info lista adentro del if   que tiene complejodad O(n), entonces solo la complejidad final seria n*n que daria O(n^2)
int contarOcurrencias(Lista& l, int v) {
    int veces = 0;
    for (int i=1; i <= l.longLista(); ++i) {
        if (l.infoLista(i) == v) {
            ++veces;
        }
    }
    return veces;
}
//La complejidad de obtenerMenores O(n^2) donde n es el tamaño de la lista, primero porque el for depende de n y por cada iteraccion del for se realizar el if de infoLista y si cumple se hace la operacion anxLista y infoListas que estas tienen una complejidad de O(n), por lo tanto al multiplicar quedaria O(n^2)
Lista obtenerMenores(Lista& l, int v){
    Lista menores;
    for (int i=1; i <= l.longLista(); ++i) {
        if (l.infoLista(i) < v) {
            menores.anxLista(l.infoLista(i));
        }
    }
    return menores;
}
int main(){
    Lista prueba;
    prueba.anxLista(1);
    prueba.anxLista(4);
    prueba.anxLista(4);
    prueba.anxLista(5);
    prueba.anxLista(12);
    prueba.anxLista(7);
    int prueba1 = 4;
    int prueba2= 7;
    int ocurrencias = contarOcurrencias(prueba, prueba1);
    cout << "El numero " << prueba1 << " esta " << ocurrencias << " veces en la lista" << endl;
    Lista menores = obtenerMenores(prueba, prueba2);
    cout << "Los numeros menores a " << prueba2 << " son estos:";
    for (int i = 1; i <= menores.longLista(); ++i) {
    cout << menores.infoLista(i) << " ";
        }
      return 0;
}
