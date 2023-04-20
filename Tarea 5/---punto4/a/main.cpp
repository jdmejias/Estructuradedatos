#include "lista.h"
#include <iostream>
using namespace std;
//La complejidad es O(n^2) donde n es el tamño de la segunda lista, ya que en el while se hará una vez por cada elemento de la lista2, ademas dentro del while esta laas operacionaes anxLista e infoLista, que tienen complejidad o(n), por lo tanto en general seria O(n^2)
    void concatenarListas(Lista& l, Lista& l2){
    int i =1;
    while(i<=l2.longLista()){
    l.anxLista(l2.infoLista(i));
    i++;
    }
} 

int main(){
    Lista prueba;
    Lista prueba2;
    prueba.anxLista(1);
    prueba.anxLista(2);
    prueba2.anxLista(3);
    prueba2.anxLista(4);
    concatenarListas(prueba,prueba2);
    for (int i = 1; i <= prueba.longLista(); i++)
        cout << prueba.infoLista(i) << " ";
    cout << endl;

      return 0;
}
