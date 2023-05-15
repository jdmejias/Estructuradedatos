#include <iostream>
#include <list>
#include <string>
//JHON DEIBY MEJIAS
//8964584
//keyboard.cpp
//la complejidad en general es O(n) donde n es el tamaño de caracteres de la entrada,esto es porque el for lo que hace es recorrer cada letra, y la insercion es O(1) por lo cual no afecta la complejidad.
using namespace std;

int main() {
    string linea;
    while (getline(cin, linea)) {
        list<char> caracteres;
        list<char>::iterator it = caracteres.begin();
        bool lugar=true;  
        for (int i = 0; i < linea.length(); i++) {
            if (linea[i] == '[') {
                lugar = true;
                it = caracteres.begin();
                }
            else if (linea[i] == ']') {
                lugar = false;
                it = caracteres.end();
            }
            else {
                if (lugar) {
                    caracteres.insert(it, linea[i]);
                }
                else {
                    caracteres.insert(caracteres.end(), linea[i]);
                }
            }
        }
        for (list<char>::iterator it = caracteres.begin(); it != caracteres.end(); ++it) {
            cout << *it;
        }
        cout << endl;
    }
    return 0;
}