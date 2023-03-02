#include <stdio.h>
int main(){
    float result,dis1,dis2,dis3;
    float position,combination1,combination2,combination3=1.0;
    while (position != 0 || combination1 != 0 || combination2 != 0 || combination3 != 0 ){
        int degrees=1080;
        int max=40;
        int z;
        scanf("%f",&position);
        scanf("%f",&combination1);
        scanf("%f",&combination2);
        scanf("%f",&combination3);
        if (position>=combination1){
            dis1=position-combination1;
            }
        else{
            dis1=(max-(combination1-position));
        }   
        if (combination1<=combination2){
            dis2=combination2 -combination1;
        }
        else{
            dis2=(max-(combination1-combination2));
        }
         if (combination2>=combination3){
            dis3=combination2 -combination3;           
         }
        else{
            dis3=(max-(combination3-combination2));
            }
        result= degrees +(((dis1)/max)*360)+(((dis2)/max)*360)+(
        ((dis3)/max)*360);
        z=(int)result;
        printf("%d\n",z);
        }
    return 0;

}
