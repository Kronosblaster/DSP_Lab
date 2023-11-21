#include <stdio.h>

#define N 12

int result[N];
int x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
int h[] = {1, 1, 1};

void convolve(int x_len, int h_len) {
    int x_padded[N];
    int h_padded[N];
    int i,j;
    // Pads x to length N
    for (i = 0; i < N; i++) {
        x_padded[i] = (i < x_len) ? x[i] : 0;
    }

    // Pads h to length N
    for (i = 0; i < N; i++) {
        h_padded[i] = (i < h_len) ? h[i] : 0;
    }

    int h_conv[N][N];
    for (i = 0; i < N; i++) {
        for ( j = 0; j < N; j++) {
            h_conv[i][j] = h_padded[j];
        }

        int temp = h_padded[N - 1];
        for (j = N - 1; j > 0; j--) {
            h_padded[j] = h_padded[j - 1];
        }
        h_padded[0] = temp;
    }

    int h_result[N];

    for (i = 0; i < N; i++) {
        h_result[i] = 0;
        for (j = 0; j < N; j++) {
            h_result[i] += x_padded[j] * h_conv[j][i];
        }
    }

    for (i = 0; i < N; i++) {
        result[i] = h_result[i];
        printf("%d ", result[i]);
    }
}

int main() {
    int x_len = 10;
    int h_len = 3;
    convolve(x_len, h_len);

    return 0;
}
