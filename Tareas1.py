#Jhon Deiby Mejias Cuevas
#Codigo:8964584
#Ejercicio 1 Diagonales
mat = [
[11, 23, 76, 34, 11],
[14, 30, 92, 30, 101],
[12, 45, 58, 92, 22],
[74, 56, 49, 56, 100],
[99, 5, 28, 47, 99]
]
def verificarDiagonales(matriz):
    result=True
    h=len(matriz)
    i=0
    while i<h and result==True:
            if matriz[i][h-i-1] != matriz[i][i]:
                result=False
            i+=1
    return result
#print(verificarDiagonales(mat))

#Ejercicio 2 EsCapicua
def esCapicua(list):
    list2 =list.copy()
    list2.reverse()
    i=0
    result=True
    while i<len(list) and result==True:
        if list[i]!=list2[i]:
            result=False
        i += 1
    return result
#Case True:
#print(esCapicua([42, 12, 90, 90, 12, 42]))
#Case False:
#print(esCapicua([42, 12, 90, 90, 12, 45]))

#Ejercicio 3 Diferencias listas
def diferenciaListas(lista, lista2):
  lista3=[]
  for i in range(0, len(lista)):
    if lista[i] not in lista2:
        lista3.append(lista[i])
    elif lista[i] in lista2:
        lista2.remove(lista[i])       
  return lista3
#print(diferenciaListas([40, 10, 22, 12, 33, 33, 33], [41, 22, 31, 15, 13, 12, 33, 19]))

#Ejercicio 3b
def f_lectura():
    num=int(input())
    for i in range(num):
        a=input()
        listaA=a.split()   
        listaA.pop(0)
        b=input()
        listaB=b.split()    
        listaB.pop(0)
        print(*diferenciaListas(listaA,listaB), sep = ",")
#f_lectura()
#8 41 22 31 15 13 12 33 19
#7 40 10 22 12 33 33 33
#5 10 10 12 12 11
#10 10 11 12 13 14 10 10 12 16 19

#Ejercicio 4
numerosPrimos = []
suma=[]
def sum_digitos(n):
     sum = 0
     while (n > 0):
        sum = sum + (n % 10)
        n = n//10
     return sum
def mostrarPrimos(n):
    for num in range(2,n):
        esPrimo = True
        for primo in numerosPrimos:
            esPrimo = not (num % primo == 0)
            if primo * 2 >= num or not esPrimo:
                break
        if esPrimo:
            numerosPrimos.append(num)
            print("-->",num)
    for primo in numerosPrimos:
            sumaT = 0
            sumaT=sumaT+sum_digitos(primo)
            if sumaT in numerosPrimos:
                suma.append(primo)  
    return suma
#print(mostrarPrimos(100000))
#Ejercicio 5
disp = {
0 : [(0, 1), (5, 4), (7, 5)],
1 : [(6, 4), (7, 7)],
2 : [(0, 2), (1, 2), (4, 9), (6, 1)],
4 : [(2, 8), (3, 1), (5, 7)],
6 : [(0, 3), (5, 6), (7, 2)],
7 : [(0, 4), (1, 4), (2, 7)],
8 : [(1, 9), (3, 8), (5, 7), (7, 6)]
}
def sumarValoresMatriz2(mat, lista):
  sum=0
  for i, j in lista:
    if i in mat:
        for k, a in mat[i]:
          if j == k:
            sum= sum+a
  return sum
#print(sumarValoresMatriz2(disp, [(0, 0), (8, 3), (3, 5), (7, 2), (4, 3), (4,6)]))
