#include<stdio.h>
#include<math.h>
int main(){
    float range=(4*M_PI)/1000;
    float time[1000];
    time[0]=-2*M_PI;
    for(int i=1;i<1000;i++){
        time[i]=time[i-1]+range;
    }
    for(int i=0;i<1000;i++){
        time[i]=sin(time[i]);
        printf("%f\n",time[i]);
    }
    return 1;
}