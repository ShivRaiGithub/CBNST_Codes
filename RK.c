#include <stdio.h>

double func(double x, double y) {
    return x + y; // Example equation: dy/dx = x + y
}

int main() {
    double x_0, y_0, h, x_n;

    // Input initial conditions and step size
    printf("Enter initial x, initial y, step size, and last x value: ");
    scanf("%lf %lf %lf %lf", &x_0, &y_0, &h, &x_n);

    // Calculate the number of steps
    int n = (int)((x_n - x_0) / h) + 1;

    // Declare arrays for x and y
    double x[n], y[n];

    // Initialize with initial conditions
    x[0] = x_0;
    y[0] = y_0;

    // Perform RK4 method
    for (int i = 1; i < n; i++) {
        double k1 = h * func(x[i - 1], y[i - 1]);
        double k2 = h * func(x[i - 1] + h / 2, y[i - 1] + k1 / 2);
        double k3 = h * func(x[i - 1] + h / 2, y[i - 1] + k2 / 2);
        double k4 = h * func(x[i - 1] + h, y[i - 1] + k3);

        x[i] = x[i - 1] + h;
        y[i] = y[i - 1] + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    }

    // Print results
    printf("The solution is given by:\n");
    printf(" x           y\n");
    for (int i = 0; i < n; i++) {
        printf("%lf   %lf\n", x[i], y[i]);
    }

    return 0;
}
