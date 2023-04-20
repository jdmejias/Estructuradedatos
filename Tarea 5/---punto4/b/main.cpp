#include "lista.h"
#include <iostream>
using namespace std;
//la complejidad de la sobrecarga del operador + para sumar dos listas, es de n^2, ya que tiene un while, que itera por el tamaño de la lista 1 y 2, y en cada iteracion usa la funcion anxLista para agregarla, por lo cual seria nxn que daria n^2
int main(){
    Lista prueba;
    Lista prueba2;
    Lista prueba3;
    prueba.anxLista(1);
    prueba.anxLista(2);
    prueba2.anxLista(3);
    prueba2.anxLista(4);
    prueba.anxLista(0);
    prueba3=prueba + prueba2;
    for (int i = 1; i <= prueba3.longLista(); i++)
        cout << prueba3.infoLista(i) << " ";
    cout << endl;
 for (int i = 1; i <= prueba.longLista(); i++)
        cout << prueba.infoLista(i) << " ";
    cout << endl;
     for (int i = 1; i <= prueba2.longLista(); i++)
        cout << prueba2.infoLista(i) << " ";
    cout << endl;
      return 0;
}
