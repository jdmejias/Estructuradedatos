#ifndef BIGNUMBER_H
#define BIGNUMBER_H

#include <string>
#include <vector>
using namespace std;
class BigInteger {
    private:
    vector<int> vec1;
    bool signo;
    public:
    // Constructor 
    BigInteger(const string& cadena);
    BigInteger(const BigInteger& bignumber);
    // Sobrecarga de operacdores
    BigInteger operator+(BigInteger& bignumber);
    BigInteger operator-(BigInteger& bignumber);
    BigInteger operator*(BigInteger& bignumber);
    BigInteger operator/(BigInteger& bignumber);
    BigInteger operator%(BigInteger& bignumber);
    bool operator==(BigInteger& bignumber);
    bool operator<(BigInteger& bignumber);
    bool operator<=(BigInteger& bignumber);
    // Funciones 
    void add(BigInteger& bignumber);
    void product(BigInteger& bignumber);
    void substract(BigInteger& bignumber);
    void quotient(BigInteger& bignumber);
    void remainder(BigInteger& bignumber);
    void pow(int bignumber);
    string toString();
    //operaciones estaticas
    static BigInteger sumarListaValores(vector<BigInteger>& list);
    static BigInteger multiplicarListaValores(vector<BigInteger>& list);
};
#endif

