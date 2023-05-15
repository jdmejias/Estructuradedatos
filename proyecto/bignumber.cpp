#include "bignumber.cpp"

BigInteger::BigInteger(const string& cadena){
        int start=0;
        if(cadena[0] == '-') { 
            start= 1;
            signo = false;
        } else {
            signo = true;
        }
        for (int i = start; i < cadena.size(); i++) {
            vec1.push_back(cadena[i] - '0');
        }
    }
BigInteger::BigInteger(const BigInteger& bignumber) {
        for(int i=0; i < bignumber.vec1.size(); i++)
            vec1.push_back(bignumber.vec1[i]);
        signo = bignumber.signo;
    }
    
BigInteger operator+(BigInteger bignumber);
BigInteger operator-(BigInteger bignumber);
BigInteger operator*(BigInteger bignumber);
BigInteger operator/(BigInteger bignumber);
BigInteger operator+(BigInteger bignumber);
BigInteger operator%(BigInteger bignumber);
bool operator==(BigInteger bignumber);
bool operator<(BigInteger bignumber);
bool operator<=(BigInteger bignumber);


void BigInteger::add(BigInteger& bignumber){
    int z = 0;
    vector<int> vec2 = bignumber.vec1;
    vector<int> vec3;
    int max1 = vec1.size();
    int max2 = vec2.size();
    int distancia = 0;
    if (max1 >= max2) {
        distancia = max1 - max2;
        for (int i = 0; i < distancia; i++)
            vec2.insert(vec2.begin(), 0);
    } else {
        distancia = max2 - max1;
        for (int i = 0; i < distancia; i++)
            vec1.insert(vec1.begin(), 0);
    }
    for (int j = vec1.size() - 1; j >= 0; j--) {
        if (vec1[j] + vec2[j] + z >= 10) {
            vec3.insert(vec3.begin(), (vec1[j] + vec2[j] + z) % 10);
            z = 1;
        } else {
            vec3.insert(vec3.begin(), vec1[j] + vec2[j] + z);
            z = 0;
        }
    }
    if (z == 1)
        vec3.insert(vec3.begin(), 1);

    vec1 = vec3;
}

void BigInteger::product(BigInteger& bignumber) {
    vector<int> vec2 = bignumber.vec1;
    vector<int> vec3(vec1.size() + vec2.size(), 0);
    int max1 = vec1.size();
    int max2 = vec2.size();
    int distancia = 0;
    if (max1 >= max2) {
        distancia = max1 - max2;
        for (int i = 0; i < distancia; i++)
            vec2.insert(vec2.begin(), 0);
    } else {
        distancia = max2 - max1;
        for (int i = 0; i < distancia; i++)
            vec1.insert(vec1.begin(), 0);
    }
    for (int i = vec1.size() - 1; i >= 0; i--) {
        int suma = 0;
        for (int j = vec2.size() - 1; j >= 0; j--) {
            int actual = vec3[i + j + 1] + vec1[i] * vec2[j] + suma;
            vec3[i + j + 1] = actual % 10;
            suma = actual / 10;
        }
        vec3[i] += suma;
    }
    vec1 = vec3;
}

void BigInteger::substract(BigInteger& bignumber){
    int z = 0;
    vector<int> vec2 = bignumber.vec1;
    vector<int> vec3;
    int max1 = vec1.size();
    int max2 = vec2.size();
    int distancia = 0;
    if (max1 >= max2) {
        distancia = max1 - max2;
        for (int i = 0; i < distancia; i++)
            vec2.insert(vec2.begin(), 0);
    } else {
        distancia = max2 - max1;
        for (int i = 0; i < distancia; i++)
            vec1.insert(vec1.begin(), 0);
    }

    for (int j = vec1.size() - 1; j >= 0; j--) {

        if (vec1[j] < vec2[j] ) {
            vec3.insert(vec3.begin(), ((vec1[j]-z+10) - vec2[j]) % 10);
            z = 1;
        } else {
            vec3.insert(vec3.begin(), (vec1[j]-z) - vec2[j]);
            z = 0;
        }
    }
    vec1 = vec3;
}

void BigInteger::quotient(BigInteger& bignumber){

}

void BigInteger::pow(BigInteger& bignumber){

}

void BigInteger::remainder(BigInteger& bignumber){

}
string BigInteger::toString() {
    string cadena = "";
    for (int i = vec1.size()-1; i >= 0 ; i--) {
        cadena = char(vec1[i] + '0') + cadena;
    }
    return cadena;
}
void BigInteger::removerCeros(BigInteger& bignumber){
    
}


void BigInteger::imprimir() {
    if(signo==false){
        cout << "-";
    }
    for (int i = 0; i < vec1.size(); i++)
        cout << vec1[i];
    cout << endl;
}
