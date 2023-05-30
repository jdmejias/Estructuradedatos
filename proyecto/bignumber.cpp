  #include "bignumber.h"
/*
Funcion: Constructor de la clase BigInteger 
Entrada:  recibe una cadena de caracteres.
Descripcion: Este constructor lo que hace es crear una instancia de BigInteger 
*/
BigInteger::BigInteger(const string& cadena){
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
/*
Funcion: Constructor de la clase BigInteger
Entrada: Un objeto BigIngeger.
Descripcion: Lo que hace es crear una instancia de BigInteger usando otro objeto BigInteger
*/
BigInteger::BigInteger(const BigInteger& bignumber) {
        for(int i=0; i < bignumber.vec1.size(); i++)
            vec1.push_back(bignumber.vec1[i]);
        signo = bignumber.signo;
    }
/*
Funcion: Sobrecarga del operador suma para BigInteger
Entrada: Un objeto BigInteger
Salida: Un objeto BigInteger
Descripcion: Realiza la suma de los dos BigIntegeres usando add y devuelve la suma
*/    
BigInteger BigInteger::operator+(BigInteger& bignumber){
    BigInteger suma(*this);
    suma.add(bignumber);
    return suma;
}
/*
Funcion: Sobrecarga del operador resta para BigInteger
Entrada: Un objeto BigInteger
Salida: Un objeto BigInteger
Descripcion:Realiza la resta de dos BigIntegeres usando substract y devuelve la resta.
*/ 
BigInteger BigInteger::operator-(BigInteger& bignumber){
    BigInteger resta(*this);
    resta.substract(bignumber);
    return resta;
}
/*
Funcion: Sobrecarga del operador multiplicar para Biginteger
Entrada: Un objeto BigInteger
Salida: Un objeto BigInteger
Descripcion:  Realiza la multiplicacion de dos BigInteger usando la funcion product y un Biginteger nuevo con dicha multiplicacion.
*/ 
BigInteger BigInteger::operator*(BigInteger& bignumber){
    BigInteger multiplicacion(*this);
    multiplicacion.product(bignumber);
    return multiplicacion;
}
/*
Funcion:  Sobrecarga del operador dividir para Biginteger
Entrada: Un objeto BigInteger
Salida: Un objeto BigInteger
Descripcion: Realiza la division de dos BigInteger usando la funcion quotient que es dividir, y retorna un BigInteger nuevo con dicha division.
*/ 
BigInteger BigInteger::operator/(BigInteger& bignumber){
    BigInteger division(*this);
    division.quotient(bignumber);
    return division;
}
/*
Funcion: Sobrecarga del operador modulo para BigInteger
Entrada: Un objeto BigInteger
Salida: Un objeto BigInteger
Descripcion: Lo que hace es sacar el residuo o modulo de dos BigInteger creando un nuevo BigInteger con el resultado.
*/ 
BigInteger BigInteger::operator%(BigInteger& bignumber){
    BigInteger modulo(*this);
    modulo.remainder(bignumber);
    return modulo;
}
/*
Funcion: Sobrecarga del operador igual igual
Entrada: Un objeto BigInteger
Salida: Verdadero o Falso.
Descripcion:Lo que hace es comparar dos BigInteger, si son iguales retorno true en lo contrario falso.
*/ 
bool  BigInteger::operator==(BigInteger& bignumber){
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
/*
Funcion: Sobrecarga del operador menor 
Entrada: Un objeto BigInteger
Salida: Verdadero o Falso
Descripcion: Lo que hace es comparar dos BigInteger, si es menor retorna verdadero en lo contrario falso.
*/ 
bool BigInteger::operator<(BigInteger& bignumber) {
        bool result = false;
        bool encontrar = false;
        if (signo && !bignumber.signo) {
            encontrar = true;
            result = true;   
        }
        else if (!signo && bignumber.signo) 
            encontrar = true;
        else if (vec1.size() > bignumber.vec1.size()) { 
            if (signo && bignumber.signo) { 
                result = true;
                encontrar = true;
            }
            else 
                encontrar = true;
        }
        else if (vec1.size() < bignumber.vec1.size()) { 
            if (signo && bignumber.signo) 
                encontrar = true;
            else {
                result = true;
                encontrar = true;
            }
        }
        
        else if(!encontrar) {
                int i = 0;
                while (i < vec1.size() && vec1[i] == bignumber.vec1[i]) {
                    i++;
                }
                if (i < vec1.size() && vec1[i] < bignumber.vec1[i]) {
                    if (signo && bignumber.signo) {
                        result = false;
                    }
                    else {
                        result = true;
                    }
                }
                else{
                    if (signo && bignumber.signo) {
                        result = true;
                    }
                    else {
                        result = false;
                    }
                }
        }

        return result;
    }
/*
Funcion: Sobrecarga del operador <=
Entrada: Un objeto BigInteger
Salida: Verdadero o Falso
Descripcion: Lo que hace es comparar dos BigInteger si es menor o igual retorna verdadero en lo contrario falso.
*/ 
bool BigInteger::operator<=(BigInteger& bignumber) {
    ans=false;
    if((*this < bignumber)|| (*this == bignumber))
        ans=true;
        
    return ans;
}
/*
Funcion: add
Entrada: Un objeto BigInteger
Descripcion: Lo que hace es sumarle un BigInteger a la entrada la cual es otro BigInteger, al final queda el BigInteger que uso la funcion modificado con la suma de ambos BigInteger.
*/ 
void BigInteger::add(BigInteger& bignumber) {
    int z = 0;
    vector<int> vec2 = bignumber.vec1;
    int max1 = vec1.size();
    int max2 = vec2.size();
    int tam = max(max1, max2) + 1;
    vector<int> vec3(tam, 0);

    if (signo == bignumber.signo) {
        while (max1 > 0 || max2 > 0) {
            int sum = z;
            if (max1 > 0)
                sum += vec1[max1 - 1];
            if (max2 > 0)
                sum += vec2[max2 - 1];
            vec3[tam - 1] = sum % 10;
            z = sum / 10;
            max1--;
            max2--;
            tam--;
        }
        if (z == 1)
            vec3[0] = 1;
        else
            vec3.erase(vec3.begin());

        vec1 = vec3;
        } 
        else {
        // Los números tienen signos diferentes, realizamos la resta
        BigInteger temp = bignumber;
        temp.signo = !temp.signo;
        substract(temp);
    }
}

/*
Funcion: Product
Entrada: Un objeto BigInteger
Descripcion: Lo que hace esta funcion es multiplicar dos BigInteger, modificando el BigInteger que uso la funcion haciendo que quede con la multiplicacion.
*/ 
void BigInteger::product(BigInteger& bignumber) {
    vector<int> vec2 = bignumber.vec1;
    vector<int> vec3(vec1.size() + vec2.size(), 0);
    for (int i = vec1.size() - 1; i >= 0; i--) {
        int temp = 0;
        for (int j = vec2.size() - 1; j >= 0; j--) {
            int sum = vec3[i + j + 1] + vec1[i] * vec2[j] + temp;
            vec3[i + j + 1] = sum % 10;
            temp = sum / 10;
        }
        vec3[i] += temp;
    }

    // Eliminar ceros principales
    while (vec3.size() > 1 && vec3[0] == 0)
        vec3.erase(vec3.begin());

    vec1 = vec3;
    if(signo==bignumber.signo)
        signo =false;
    else
        signo=true;
}
/*
Funcion: substract
Entrada: Un objeto BigInteger
Descripcion: Lo que hace es que al Biginteger que uso la funcion se le reste el Biginteger que recibe como entrada.
*/ 
void BigInteger::substract(BigInteger& bignumber) {
    int z = 0;
    vector<int> vec2 = bignumber.vec1;
    int max1 = vec1.size();
    int max2 = vec2.size();
    int tam = max(max1, max2);
    vector<int> vec3(tam, 0);

    if (signo == bignumber.signo) {
        // Son del mismo signo 
        for (int j = max1 - 1; j >= 0; j--) {
            int res = vec1[j] - z;

            if (max2 > 0)
                res -= vec2[max2 - 1];

            if (res < 0) {
                vec3[j] = res + 10;
                z = 1;
            } else {
                vec3[j] = res;
                z = 0;
            }

            max2--;
        }

        // Eliminar ceros principales
        while (vec3.size() > 1 && vec3[0] == 0)
            vec3.erase(vec3.begin());

        vec1 = vec3;
        signo = bignumber.signo;
    } else {
        // Los números tienen signos diferentes, realizamos la suma
        BigInteger temp = bignumber;
        temp.signo = !temp.signo;
        add(temp);
    }
}
/*
Funcion: quotient
Entrada: Un objeto BigInteger
Descripcion: Lo que hace es dividir el Biginteger que uso la funcion con otro Biginteger que recibe como entrada.
*/ 
void BigInteger::quotient(BigInteger& bignumber){
    BigInteger dividendo(*this);
    BigInteger divisor(bignumber);
    string cero = "0";
    string uno = "1";
    BigInteger cociente(cero); 
    BigInteger temp(uno);
    bool encontrar = false;

    if (dividendo < divisor) {
        *this = BigInteger(cero);  
        encontrar=true;
    }
    while (divisor <= dividendo && !encontrar) {
        dividendo.substract(divisor);
        cociente.add(temp);
    }
    vec1=cociente.vec1;
}
/*
Funcion: remainder
Entrada: Un objeto BigInteger
Descripcion: Lo que hace es buscar el modulo de Dos BigInteger, el que uso la funcion con el que recibe de entrada. modificando el Biginteger que recibio la funcion quedando con el modulo.
*/ 
void BigInteger::remainder(BigInteger& bignumber){
    BigInteger dividendo(*this);
    BigInteger divisor(bignumber);
    string cero = "0";
    BigInteger cociente(cero); 

    while (divisor <= dividendo) {
        dividendo.substract(divisor);
    }
    vec1=dividendo.vec1;
}
/*
Funcion: pow
Entrada: entero negativo o positivo
Descripcion: Lo que hace es que al Biginteger que usa esta funcion lo eleva al numero del exponente que recibe como entrada.
*/ 
void BigInteger::pow(int exponente) {
    string uno ="1";
    BigInteger result(uno);
    BigInteger base(*this);
    bool encontrar=false;
    if(exponente<0){
        exponente= -exponente;
        if(exponente%2 ==0)
            signo=false;
        else
            signo=true;
    }
    if (exponente==0){
        encontrar=true;
        vec1.clear();
        vec1.push_back(1);
    }
    for (int i = 0; i < exponente && !encontrar; i++) {
        result.product(base);
    }
    if(!encontrar)
        vec1=result.vec1;
}
/*
Funcion: toString
Salida: Retorna un string 
Descripcion:Lo que hace es que los digitos del vector que esta dentro de la clase BigInteger lo pasa a un string.
*/ 
string BigInteger::toString() {
    string cadena = "";

    for (int i = vec1.size()-1; i >= 0 ; i--) {
        cadena = char(vec1[i] + '0') + cadena;
    }
    if (signo)
        cadena= "-" + cadena;
    return cadena;
} 
/*
Funcion: sumarListaValores
Entrada: recibe un vector de BigInteger
Salida:  Retorna un Biginteger 
Descripcion: Lo que hace es que al BigInteger que use la funcion se le debe pasar una Lista de BigInteger y calcula la sumatoria de todos.
*/ 
BigInteger BigInteger::sumarListaValores(vector<BigInteger>& list){
            string cero = "0";
            BigInteger suma(cero);
            for (vector<BigInteger>::iterator it = list.begin(); it != list.end(); ++it) {
                suma.add(*it);
            }
            return suma;
}
/*
Funcion: multiplicarListaValores
Entrada: recibe un vector de BigInteger
Salida: Retorna un Big Integer
Descripcion: Lo que hace es que al BigInteger que use la funcion se le debe pasar una Lista de BigInteger y calcula la multiplicacion de todos.
*/ 
BigInteger BigInteger::multiplicarListaValores(vector<BigInteger>& list){
             string uno = "1";
             BigInteger producto(uno);
             for (vector<BigInteger>::iterator it = list.begin(); it != list.end(); ++it) {
                    producto.product(*it);
             }
            return producto;
 }