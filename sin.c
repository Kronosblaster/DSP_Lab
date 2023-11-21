#include<stdio.h>
#include<math.h>

float time[100];
float result[100];
void main(){
    float range=(4*M_PI)/100;
    time[0]=-2*M_PI;
    int i=0;
    for(i=1;i<100;i++){
        time[i]=time[i-1]+range;
    }
    for(i=0;i<100;i++){
        result[i]=sin(time[i]);
        printf("%f\n",result[i]);

    }
}
