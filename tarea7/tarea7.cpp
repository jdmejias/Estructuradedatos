#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <vector>
//JHON DEIBY MEJIAS
//8964584
//tarea7.cpp

using namespace std;
//La complejidad es O(n) donde n es el tamaño de la pila, ya que el primer while itera hasta !pil.empty y en cada iteracion borra el elemento de la pila, por lo cual lo que hace es recorrerla, en este caso el tamaño del vector no importa porque siempre sera menor o igual que el tamaño de la pila en el peor caso, ya que representa posiciones de la pila.
void eliminarPosicionesPila(stack<int> &pil, vector<int> &l) {
    stack<int> temp;
    int aux = pil.size();
    while (!pil.empty()) {
        if (!l.empty() && aux == [l.size()-1]) {
            pil.pop();
            l.pop_back();
        } else {
            temp.push(pil.top());
            pil.pop();
        }
        aux--;
    }

    while (!temp.empty()) {
        pil.push(temp.top());
        temp.pop();
    }   
}
//La complejidad es O(n) donde n es el tamaño de la cola ya que el while se hace hasta que la cola este vacia.
bool verificarOrdenadoCola(queue<int> &cola){
    int auxiliar;
    bool ans;
    while(!cola.empty()){
    auxiliar= cola.front();
    cola.pop();
    if(cola.front()>auxiliar)
        ans=true;
    else
        ans=false;
   }
    cola.push(auxiliar);
    return bool
}
//ejercicio de obtener mayores funcion 
bool comparadorMenor(int a, int b) {
    bool ans=1;
    if(a !=b){
        ans= a < b;
    }
    return ans;
}
//La complejidad es O(n logn) lo que sucede es que el while itera n veces, y en cada iteracion de elmina pop de una cola de prioridad el cual es O( log(n)) y multiplicado la n veces del while quedaria la complejidad reportada al inicio.
int obtenerMenorCosto(vector<int> & l) {
    int costomin = 0, ;
    priority_queue<int, vector<int>, ComparadorMenor> colaP;
    for (int i =0; i < l.size(), i++) {
        colaP.push(num);
    }
    while (!colaP.empty()) {
        int num1 = colaP.top();
        colaP.pop();
        int num2 = colaP.top();
        colaP.pop();
        int sum = num1 + num2;
        costomin += sum;
        colaP.push(sum);
    }

    return costomin;
}
//La complejidad es O(n), donde n es la longitud de la cadena. ya que tiene unicamente un for que literalmente itera el tamaño.
map<char, vector<int>> obtenerPosicionesOcurrencias( string& cad) {
    map<char, vector<int>> mapa;

    for (int i = 0; i < cad.length(); ++i) {
        char letra = cad[i];
        mapa[letra].push_back(i);
    }
    return mapa;
}
//La complejidad es o(N) donde N es el numero de elementos que se deben filtrar.
stack<int> filtrarNParesCola(queue<int>& col, int N) { 
    stack<int> pila;

    int temporal = 0;
    while (!col.empty() && temporal < N) {
        int valor = col.front();
        col.pop();
        if (valor % 2 == 0) {
            pila.push(valor);
            temporal++;
        }
    }

    return pila;
}
int main() {
    stack<int> pila;
    pila.push(1);
    pila.push(2);
    pila.push(5);
    pila.push(6);
    pila.push(8);
    
    vector<int> vec;
    vec.push_back(2);
    vec.push_back(3);
    
    eliminarPosicionesPila(pila, vec);
    
    while (!pila.empty()) {
        cout << pila.top() << endl;
        pila.pop();
    }
     


    return 0;
}
