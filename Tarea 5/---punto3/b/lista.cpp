#include "lista.h"

Lista::Lista(){
  act = NULL;
}
void Lista::insListaOrdenada(Elemento elem){
  Nodo* tmp, *anterior;
  Nodo* nuevo = new Nodo;
  nuevo->dato = elem;
  nuevo->sig = NULL;
    if(act == NULL){
       act = nuevo;
    }
    else{
      if(elem < act->dato){
        nuevo->sig=act;
        act = nuevo;
      }
      else{
        tmp=act;
        anterior= NULL;
        while( tmp !=NULL && elem > tmp->dato ){
          anterior=tmp;
          tmp=tmp->sig;
        }
        anterior->sig = nuevo;
        nuevo->sig =tmp;

        
      }
    }
}

void Lista::elimLista(int pos){
  Nodo *tmp, *elim;
  if(pos >= 1 && pos <= longLista()){
    if(pos == 1)
      act = act->sig;
    else{
      tmp = act;
      for(int i = 0; i < pos-2; i++)
	tmp = tmp->sig;
      elim = tmp->sig;
      tmp->sig = tmp->sig->sig;
      delete elim;
    }
  }
}

Elemento Lista::infoLista(int pos){
  Nodo* tmp = act;

  for(int i = 1; i < pos; i++)
    tmp = tmp->sig;

  return tmp->dato;
}

int Lista::longLista(){
  Nodo* tmp = act;
  int cont = 0;

  while(tmp != NULL){
    tmp = tmp->sig;
    cont++;
  }

  return cont;
}

bool Lista::vaciaLista(){
  return act == NULL;
}
