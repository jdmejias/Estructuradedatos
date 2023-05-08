/*
Autor: Carlos Ramírez
Fecha: Abril 28 de 2023

Implementación TAD Cola

 */

#ifndef  COLA_H
#define COLA_H

#include <vector>

typedef int Elemento;
using namespace std;

class Cola{
   vector<Elemento> vec;

   public:
      Cola(); // crearCola
      Elemento frontMayor();
      Elemento front();
      void deque();
      void dequeMayor();
      void enqueue(Elemento);
      bool vaciaCola();
};

#endif