// Trapezoidal rule 
#include <stdio.h>
#include <math.h>

double f(double x) { return exp(-(x*x)); }

int main() {
    double a = 0, b = 1;
    int n = 6;
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++)
        sum += 2 * f(a + i * h);

    double result = (h / 2) * sum;
    printf("Integral = %.6f\n", result);
    return 0;
}



