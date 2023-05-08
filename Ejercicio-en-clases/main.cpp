/*
Autor: Carlos Ramírez
Fecha: Abril 28 de 2023

Ejemplo de uso de la implementación del TAD Cola

 */

#include <iostream>
#include "cola-prioridad.h"
using namespace std;
void imprimirElementos(Cola &c){
  while(!c.vaciaCola()){
     printf("%d\n",  c.front());
     c.deque();
  }
}
int main(){
    Cola practica;
    practica.enqueue(10);
    practica.enqueue(22);
    practica.enqueue(45);
    practica.enqueue(15);
    practica.enqueue(5);
    practica.enqueue(44);
    int a=practica.frontMayor();
    cout << "el valor mas grande es " << a << endl ;
    //eliminar
    practica.dequeMayor();
    imprimirElementos(practica);


   return 0;
}