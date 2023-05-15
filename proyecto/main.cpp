#include "bignumber.h"

int main() {
    string num1 = "123456789";
    BigInteger bignum1(num1);
    bignum1.imprimir(); 

    BigInteger bignum2(bignum1);
    bignum2.imprimir(); 
    string num2 = bignum1.toString();
    cout << num2 << endl;
    string num3 = "15";
    BigInteger prueba1(num3);
    string num4 = "-04";
    BigInteger prueba2(num4);
    prueba2.imprimir();


    

    return 0;
}
