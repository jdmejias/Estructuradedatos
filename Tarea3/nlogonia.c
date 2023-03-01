#include <stdio.h>
int main() {
    int ejecuciones=1;
    scanf("%d",&ejecuciones);
    while(ejecuciones!=0){
        int division[2];
        int coordenadas[2];
        int j,x,y=0;
        scanf("%d",&division[0]);
        scanf("%d",&division[1]);
        for(j=0;j<ejecuciones;j++){
            scanf("%d",&coordenadas[0]);
            scanf("%d",&coordenadas[1]);
            x=coordenadas[0]-division[0];
            y=coordenadas[1]-division[1];
            if(x>0 && y>0){
                printf("NE\n");
                }            
            else if(x>0 && y<0){
                printf("SE\n");
                }
            else if(x<0 && y>0){
                printf("NO\n");
            }
            else if(x<0 && y<0){
                printf("SO\n");}
            else{
                printf("divisa\n");
            }
        }
        scanf("%d", &ejecuciones);
    }
    return 0;
}