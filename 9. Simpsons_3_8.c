//C Program to Implement Simpson's 3/8 rule.
#include <stdio.h>
#include <math.h>

double f(double x) { return 1.0 / (1.0 + x*x); }

int main() {
    double a = 0.0, b = 6.0;
    int n = 6;
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        if (i % 3 == 0)
            sum += 2.0 * f(a + i * h);
        else
            sum += 3.0 * f(a + i * h);
    }

    
    double result = (3.0 * h/ 8) * sum;

    printf("Integral = %.6f\n", result);
    return 0;
}
