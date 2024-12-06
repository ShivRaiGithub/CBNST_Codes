#include <stdio.h>
#include <conio.h>
#include <math.h>

double function(double x) {
    return 1 / ((x * x) + 1);
}


int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    int upperLimit, lowerLimit;
    printf("Enter the lower limit and upper limit: ");
    scanf("%d%d", &lowerLimit, &upperLimit);

    double h = (double)(upperLimit - lowerLimit) / (n - 1);

    double y[n];

    for (int i = 0; i < n; i++) {
        double x = (h * i) + lowerLimit;
        y[i] = function(x);
        printf("x_%d : %lf    y_%d : %lf\n", i, x, i, y[i]);
    }

    double ans = y[0] + y[n - 1];

    for (int i = 1; i < n - 1; i++) {
        if (i % 2 == 0) {
            ans += 2 * y[i];
        } else {
            ans += 4 * y[i];
        }
    }

    ans *= (h / 3);

    printf("\nThe value of the integral is %lf", ans);

    return 0;
}
