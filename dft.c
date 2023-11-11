#include <stdio.h>
#include <complex.h>
#include <math.h>
#include <stdlib.h>
void genTwiddleMatrix(int N, double complex twiddleMatrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double arg = (-2.0 * M_PI * i * j) / N;
            twiddleMatrix[i][j] = cexp(arg * I);
        }
    }
}
double complex* dft(int N,int input[N]){
    double complex twiddleMatrix[N][N];
    double complex *result = malloc(N * sizeof(double complex));
    genTwiddleMatrix(N, twiddleMatrix);
    for(int i=0;i<N;i++){
        result[i]=0;
        for(int j=0;j<N;j++){
            result[i]+=(double complex)input[j]*twiddleMatrix[i][j];
        }
    }
    return result;
}
int main() {
    int x_len;
    printf("Enter the size of array x: ");
    scanf("%d", &x_len);
    int x[x_len];
    printf("Enter the elements of array x:\n");
    for (int i = 0; i < x_len; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &x[i]);
    }
    double complex* result;
    result=dft(x_len,x);
    for(int i=0;i<x_len;i++){
        printf("%f + %fi\n", creal(result[i]), cimag(result[i]));
    }



    return 0;
}
