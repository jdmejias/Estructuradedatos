#include <iostream>
#include <string>
#include <vector>
//JHON DEIBY MEJIAS
//8964584
//word.cpp
//La complejidad es O(n*m) donde n es el tamaño del diccionario y m es la longitud máxima de las palabras del diccionario. Por lo tanto, cuanto más grande sea el diccionario y más largas sean las palabras, mayor será la complejidad del programa.
using namespace std;

int main() {
    vector<string> diccionario;
    string palabra, juego;
    while(cin >> palabra && palabra != "#"){
        diccionario.push_back(palabra);
    }
    getline(cin, juego); 
    while (getline(cin, juego) && juego != "#") {
        // Numero de frecuencia de los caracteres
        int cant[26] = {0};
        for (int i = 0; i < juego.size(); i++) {
            cant[juego[i] - 'a']++;
        }
        // Recorrer el diccionario 
        int combinacion = 0;
        for (int i = 0; i < diccionario.size(); i++) {
            // Contar la frecuencia de los caracteres
            int cant_palabra[26] = {0};
            for (int j = 0; j < diccionario[i].size(); j++) {
                cant_palabra[diccionario[i][j] - 'a']++;
            }
            // Verificar si se puede formar la palabra
            bool create = true;
            for (int k = 0; k < 26; k++) {
                if (cant_palabra[k] > cant[k] && create == true) {
                    create = false;
                }
            }
            if (create) {
                combinacion++;
            }
        }
        cout << combinacion << endl;
    }
    return 0;
}
