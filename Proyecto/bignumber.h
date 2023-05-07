#ifndef LISTA_H
#define LISTA_H

#include <string>
#include <vector>

using namespace std;

typedef int Elemento;

class BigInteger {
public:
    vector<Elemento> vec1;
    // el bool lo implementé recien por eso no veras en las funciones su uso, por ahora lo he usado para imprimir.
     bool signo;
    // Constructor 
    BigInteger(const string& cadena);
    BigInteger(const BigInteger& bignumber);
    // Sobrecarga de operacdores
    BigInteger operator+(BigInteger bignumber);
    BigInteger operator-(BigInteger bignumber);
    BigInteger operator*(BigInteger bignumber);
    BigInteger operator/(BigInteger bignumber);
    BigInteger operator+(BigInteger bignumber);
    BigInteger operator%(BigInteger bignumber);
    bool operator==(BigInteger bignumber);
    bool operator<(BigInteger bignumber);
    bool operator<=(BigInteger bignumber);
    // Funciones 
    void add(BigInteger& bignumber);
    void product(BigInteger& bignumber);
    void substract(BigInteger& bignumber);
    void quotient(BigInteger& bignumber);
    void pow(BigInteger& bignumber);
    void  remainder(BigInteger& bignumber);
    void removerCeros(BigInteger& bignumber);
    void imprimir();
    string toString();
};

#endif

