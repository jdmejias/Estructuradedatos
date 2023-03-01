#include <stdio.h>
int main(){
    int ejecuciones;
    int i=0;
    int gasolineras[100001];
    int requiere[100001];
    scanf("%d",&ejecuciones);
    while(i<ejecuciones){
        int tamano;
        int j,sum=0,sum2=0,n=0;
        int valor=1;
        scanf("%d",&tamano);
        for(j=0;j<tamano;j++){
            scanf("%d",&gasolineras[j]);
        }
        for(j=0;j<tamano;j++){
            scanf("%d",&requiere[j]);
        }

        for (j=0;j<=tamano;j++){
            sum2+=gasolineras[j]-requiere[j];
            sum+=gasolineras[j]-requiere[j];
            if (sum<0){
                valor = j+1; 
                sum=0;
                n+=1;
                }
        }
        if (sum2<0){
            printf("Case %d: Not possible\n", i+1);
        }
        else if(sum2>0 && n==0){
            printf("Case %d: Possible from station 1\n", i+1);
        }
        else {
            printf("Case %d: Possible from station %d\n", i+1, valor+1);
        }
        i++;
        }
    return 0;
    }
