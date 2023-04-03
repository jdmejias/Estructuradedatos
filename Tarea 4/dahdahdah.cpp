#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//JHON DEIBY MEJIAS
//8964584
//dahdahdah.cpp
//En general sobre la complejidad, el programa tiene una complejidad de O(casos* n) n es el numero maximo de caracteres de cualquier linea ejecutada
using namespace std;

int main() {
    int j = 1;  
    int casos;
    cin >> casos;
    cin.ignore();
    string vocabulario[] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","0","1","2","3","4","5","6","7","8","9",".",",","?","'","!","/","(",")","&",":",";","=","+","-","_", "\"" ,"@"};
    string morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","-----",".----","..---","...--","....-",".....","-....","--...","---..","----.",".-.-.-","--..--","..--..",".----.","-.-.--","-..-.","-.--.","-.--.-",".-...","---...","-.-.-.","-...-",".-.-.","-....-","..--.-",".-..-.",".--.-."};
    vector<string> vec1(vocabulario, vocabulario + 53);
    vector<string> vec2(morse, morse + 53); 
    while(j < casos + 1) { // Ejecutar hasta el numero de casos // Complejidad "un while que depende de los numeros de casos" casos+1
        string linea;
        bool espacios=false;
        getline(cin, linea);
        cout << "Message #" << j << endl;
        string letra = "";
            for(int i=0;i<linea.length(); i++){ // Recorrer la linea del input // Complejidad "un for que recorre la linea para cada mensaje que depende del tamaño de la linea seria entonces O(n)
                if(i >0  && linea[i]==' ' && linea[i-1]==' ') {// Si hay un doble espacio
                espacios =true;
                } 
                else {      
                    if(espacios) {  //colocar el espacio
                        cout <<" ";
                        espacios =false;
                    }
                    if(linea[i]!=' ') {// añadir a la letra hasta que haya un espacio
                        letra += linea[i];
                    }
                    else { // la letra hacerla una letra del vocabulario
                    vector<string>::iterator it = find(vec2.begin(), vec2.end(), letra);//el find tiene una complejidad O(n)
                    int pos = it - vec2.begin(); 
                    cout << vec1[pos];
                    letra = "";
                    }
                }
            }
        if(letra.length() > 0) {  // Imprimir la ultima letra 
            vector<string>::iterator it = find(vec2.begin(), vec2.end(), letra);
            int pos = it - vec2.begin();    
            cout << vec1[pos]<< endl;
        }
        cout << endl;
        j++;
    }
    return 0;
}