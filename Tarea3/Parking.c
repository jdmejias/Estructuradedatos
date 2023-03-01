#include <stdio.h>
int main() {
    int posicion[100];
    int casos, tienda;
    scanf("%d", &casos);
    int i = 1;
    while (i <= casos) {
        int j = 0;
        int z = 0;
        scanf("%d", &tienda);
        scanf("%d", &posicion[0]);
        for (j = 1; j < tienda; j++) {
            scanf("%d", &posicion[j]);
        }
        int max = posicion[0];
        int min = posicion[0];

        for (j = 1; j < tienda; j++) {
        if (posicion[j] > max) {
            max = posicion[j];
        }
        if (posicion[j] < min) {
            min = posicion[j];
        }
        }
        z = (max-min)*2;
        i++;
        printf("%d\n", z);
    }
    return 0;
}


