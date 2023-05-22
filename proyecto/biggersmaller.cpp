#include <string>
#include <vector>
#include <iostream>

using namespace std;

class BigInteger {
    private:
    vector<int> vec1;
    bool signo;
    public:
    BigInteger(const string& cadena){
        int start=0;
        if(cadena[0] == '-') { 
            start= 1;
            signo = true;
        } else {
            signo = false;  
        }
        for (int i = start; i < cadena.size(); i++) {
            vec1.push_back(cadena[i] - '0');
        }
    }
    bool operator==(BigInteger& bignumber){
        bool ans=true;
        int i=0;
        if(vec1.size()!= bignumber.vec1.size())
            ans=false;
        while(ans && i < vec1.size()){
            if(vec1[i]!=bignumber.vec1[i])
                ans=false;
            i++;
         }
        if(vec1.empty() && bignumber.vec1.empty())
            ans=true;

        return ans; 
    }
bool operator<(BigInteger& bignumber) {
    bool result = false;
    if (vec1.size() < bignumber.vec1.size()) {
        result = true;
    } else if (vec1.size() == bignumber.vec1.size()) {
        int i = 0;
        while (i < vec1.size() && vec1[i] == bignumber.vec1[i]) {
            i++;
        }
        if (i < vec1.size() && vec1[i] < bignumber.vec1[i]) {
            result = true;
        }
    }

    return result;
}

};
int main() {
    string num1;
    string num2;
    int casos=1;
    while (cin >> num1 >> num2) {
        string temporal1;
        string temporal2;
        string temporal3;
        string temporal4;
        bool encontrar = true;
        int i = 0, tam1 = 0, tam2 = 0;
        //Aqui dividí el numero 1, la parte entera lo coloque en el string temporal 1 y la parte decimal lo coloque en el string temporal 2
        while (i < num1.size()) {
            if (num1[i] != '.' && encontrar) {
                temporal1 += num1[i];
            }
            if (num1[i] == '.') {
                tam1 = i;
                encontrar = false;
            }
            if (!encontrar) {
                temporal2 += num1[i];
            }
            i++;
        }
        // aqui hice lo mismo de arriba para el segundo numero, solo que string temporal 3 y 4
        i = 0;
        encontrar = true;
        while (i < num2.size()) {
            if (num2[i] != '.' && encontrar) {
                temporal3 += num2[i];
            }
            if (num2[i] == '.') {
                tam2 = i;
                encontrar = false;
            }
            if (!encontrar) {
                temporal4 += num2[i];
            }
            i++;
        }
        //esto es para que de la respuesta rapidamente si la parte entera de un numero es superio a otra
        if (tam1 > tam2) 
            cout << "Case " << casos << ": Bigger" << endl;
        else if (tam1 < tam2) 
            cout << "Case " << casos << ": Smaller" << endl;
        // si la parte entera tiene el mismo tamañao proceder a compararlos.
        else {
            // aqui lo que hago es quitar los 0 de la derecha tanto del primer numero como del segundo
            int j = temporal2.size() - 1;
            bool find = true;
            while (j >= 0 && find) {
                if (temporal2[j] == '0') {
                    temporal2.pop_back();
                } else {
                    find = false;
                }
                j--;
            }

            j = temporal4.size() - 1;
            find = true;
            while (j >= 0 && find) {
                if (temporal4[j] == '0') {
                    temporal4.pop_back();
                } else {
                    find = false;
                }
                j--;
            }
            BigInteger numero1(temporal1);
            BigInteger numero2(temporal2);
            BigInteger numero3(temporal3);
            BigInteger numero4(temporal4);   
           if (numero1 == numero3 && numero2 == numero4) {
                cout << "Case " << casos << ": Same" << endl;
            }
            else if (numero1 == numero3) {
                if (numero2 < numero4) {
                    cout << "Case " << casos << ": Smaller" << endl;
                }
                else {
                    cout << "Case " << casos << ": Bigger" << endl;
                }
            }
            else if (numero1 < numero3) {
                cout << "Case " << casos << ": Smaller" << endl;
            }
            else {
                cout << "Case " << casos << ": Bigger" << endl;
            }
              
        }
        casos++;
    }
    return 0;
}
