#include <stdio.h> 
#include <stdlib.h>
int* convolve(int *x,int x_len,int *h,int h_len,int N){
    int x_padded[N];
    int *h_padded=(int *)malloc(N * sizeof(int));;
    for(int i=0;i<N;i++){
        x_padded[i]=(i<x_len)?x[i]:0;
    }
    for(int i=0;i<N;i++){
        h_padded[i]=(i<h_len)?h[i]:0;
    }

    int h_conv[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            h_conv[i][j]=h_padded[j];
        }
        int temp=h_padded[N-1];
        for(int j=N-1;j>0;j--){
            h_padded[j]=h_padded[j-1];
        }
        h_padded[0]=temp;
    }

    for (int i = 0; i < N; i++) {
        h_padded[i]=0;
        for (int j = 0; j < N; j++) {
        h_padded[i]+=x_padded[j]*h_conv[j][i];
    }
    }

    return h_padded;
}
int main(){
    int x[]={1,1,1};
    int h[]={4,9,19,1,3};

    int x_len=sizeof(x) / sizeof(x[0]);
    int h_len=sizeof(h) / sizeof(h[0]);
    int N=7;

    int *result=convolve(x,x_len,h,h_len,N);
    for(int i=0;i<N;i++){
        printf("%d ",result[i]);
    }
}