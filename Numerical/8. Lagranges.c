//Lagrange Interpolation
#include <stdio.h>

int main() {
    double x[] = {5, 6, 9, 11};
    double y[] = {12, 13, 14, 16};
    int n = 4;
    double xp = 10, yp = 0;

    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i)
                term *= (xp - x[j]) / (x[i] - x[j]);
        }
        yp += term;
    }

    printf("Interpolated value at x = %.2f is y = %.4f\n", xp, yp);
    return 0;
}

