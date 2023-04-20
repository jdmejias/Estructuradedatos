#include "lista.h"
#include <iostream>
using namespace std;
//El while itera hasta la posicion en la que se va a colocar, por lo cual en el peor de los casos seria hasta N,donde n es el tamaño de la lista, para cada while se debe hacer un infolista e longLista,a ambos tienen complejidad O(n), por lo cual la complejidad general seria de O(n^2 )
    void insertarEnListaOrdenada(Lista& l, int v ){
    int j=1;
    while(j <= l.longLista() && l.infoLista(j) < v){
        ++j;
    }
    if (l.longLista()==0)
        l.anxLista(v);
    else
        l.insLista(v,j);
} 

int main(){
    Lista prueba;
    insertarEnListaOrdenada(prueba,7);
    insertarEnListaOrdenada(prueba,3);
    insertarEnListaOrdenada(prueba,5);
    insertarEnListaOrdenada(prueba,4);
    for (int i = 1; i <= prueba.longLista(); i++)
        cout << prueba.infoLista(i) << " ";
    cout << endl;

      return 0;
}
