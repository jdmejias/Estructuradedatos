#include <stdio.h>
#include <math.h>
int arreglo[3001];
int main() {
  while (scanf("%d", &arreglo[0]) != EOF) {
    int i;
    int distancia = 0, z = 0;
    for (i = 1; i <= arreglo[0]; i++) {
      scanf("%d", &arreglo[i]);
    }
    for (i = 1; i < arreglo[0]; i++) {
      distancia += fabs(arreglo[i] - arreglo[i + 1]);
    }
    z = ((arreglo[0] - 1) * (arreglo[0])) / 2;

    if (z == distancia) {
      printf("Jolly\n");
    } 
    else {
      printf("Not Jolly\n");
    }
  }
  return 0;
} 