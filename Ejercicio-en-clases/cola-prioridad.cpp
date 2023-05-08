/*
Autor: Carlos Ramírez
Fecha: Abril 28 de 2023

Implementación TAD Cola

 */

#include "cola-prioridad.h"

Cola::Cola(){
}

Elemento Cola::frontMayor(){
  Cola temporal;
  Elemento ans = vec.front();
  while(!vaciaCola()){ 
    Elemento elem = vec.front();
    if(elem > ans){
      ans = elem;
    }
    temporal.enqueue(elem);
    vec.erase(vec.begin());
  }
  while(!temporal.vaciaCola()){
    vec.push_back(temporal.front());
    temporal.deque();
  } 
  return ans;
}

Elemento Cola::front(){
  Elemento ans = vec[0];
 return ans;
}

void Cola::enqueue(Elemento e){
  //vec.push_back(e);
  vec.insert(vec.begin(), e);
}

void Cola::dequeMayor(){
  Elemento max = frontMayor();
  Cola temporal;
  while(!vaciaCola()){
    Elemento elem = vec.front();
    if(elem == max){
      deque();
    } else {
      temporal.enqueue(elem);
      vec.erase(vec.begin());
    }
  }
  while(!temporal.vaciaCola()){
    vec.push_back(temporal.front());
    temporal.deque();
  }
}

void Cola::deque(){
  vec.erase(vec.begin());
 
}

bool Cola::vaciaCola(){
  bool ans;
  if(vec.empty())
     ans = true;
  else
     ans = false;
  return ans;
}