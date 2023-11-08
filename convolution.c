#include <stdio.h> 
#include <stdlib.h>
int* convolve(int *x,int x_len,int *h,int h_len,int N){
    int x_padded[N];
    int *h_padded=(int *)malloc(N * sizeof(int));;

    //Pads x to length N
    for(int i=0;i<N;i++){
        x_padded[i]=(i<x_len)?x[i]:0;
    }
    //Pads h to length N
    for(int i=0;i<N;i++){
        h_padded[i]=(i<h_len)?h[i]:0;
    }
    //Creates the shifted sw
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
    int x_len, h_len;
    // Input for array x
    printf("Enter the size of array x: ");
    scanf("%d", &x_len);
    int x[x_len];
    printf("Enter the elements of array x:\n");
    for (int i = 0; i < x_len; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &x[i]);
    }

    // Input for array h
    printf("Enter the size of array h: ");
    scanf("%d", &h_len);
    int h[h_len];
    printf("Enter the elements of array h:\n");
    for (int i = 0; i < h_len; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &h[i]);
    }

    //Input for N
    int N;
    printf("Enter N: ");
    scanf("%d", &N);

    int *result=convolve(x,x_len,h,h_len,N);
    for(int i=0;i<N;i++){
        printf("%d ",result[i]);
    }
}