#include <stdio.h>
#include <complex.h>
#include <math.h>

void fft(double complex arr[], int N) {
    if (N > 1) {
        double complex odd[N / 2], even[N / 2];
        double complex tf = cexp(-2 * M_PI * I / N);

        for (int i = 0; i < N; i += 2) {
            even[i / 2] = arr[i];
            odd[i / 2] = arr[i + 1];
        }

        fft(even, N / 2);
        fft(odd, N / 2);

        for (int i = 0; i < N / 2; i++) {
            odd[i] *= cpow(tf, i);
        }

        for (int i = 0; i < N; i++) {
            arr[i] = (i < N / 2) ? (even[i] + odd[i]) : (even[i - N / 2] - odd[i - N / 2]);
        }
    }
}

int main() {
    double complex arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    fft(arr, 8);

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        printf("Real: %f, Imaginary: %f\n", creal(arr[i]), cimag(arr[i]));
    }

    return 0;
}
