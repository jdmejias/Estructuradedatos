/*

Ejemplo de uso TAD lista implementación estructuras enlazadas simples.

*/

#include "lista.h"
#include <iostream>
//La complejidad modificando la interfaz es O(n) por el ciclo while, donde n es el tamaño de la lista a la cual se insertará, ya que en el peor de los casos tocaría recorrer hasta la ultima posicion de la lista,
int main(){
    Lista prueba;
    prueba.insListaOrdenada(4);
    prueba.insListaOrdenada(3);
    prueba.insListaOrdenada(5);
    prueba.insListaOrdenada(1);
    prueba.insListaOrdenada(32);
    for (int i = 1; i <= prueba.longLista(); i++)
        cout << prueba.infoLista(i) << " ";
    cout << endl;
      return 0;
}
