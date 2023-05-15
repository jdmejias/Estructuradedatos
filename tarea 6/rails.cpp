#include <iostream>
#include <vector>
#include <stack>
//JHON DEIBY MEJIAS
//8964584
//rails.cpp
//Analizando la complejidad, los dos primeros while no afecta la complejidad, el primero for itera n-1, ya que ya se pregunto el primer elemento, donde en es el numero de vagones. Lo importante son el segundo for y adentro que tiene el while, el peor de los casos la complejidad será O(n^2), ya que el primer for seria n-1, y el while puede ser n dependiendo, por lo tanto quedaria O(n^2).
using namespace std;

int main() {
    int vagones;
    while (cin >> vagones && vagones != 0) {
        vector<int> vagon(vagones);
        while (cin >> vagon[0] && vagon[0] != 0) {
            int temp = 0;
            stack<int> pila;
            for (int i = 1; i < vagones; i++)
                cin >> vagon[i];
            for (int i = 1; i <= vagones; i++) {
                pila.push(i);
                while (!pila.empty() && vagon[temp] == pila.top()) {
                    temp++;
                    pila.pop();
                }
            }
            if (pila.empty())
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        cout << endl;
    }
    return 0;
}
