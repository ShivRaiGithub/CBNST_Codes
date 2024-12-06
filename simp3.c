#include <stdio.h>
#include <conio.h>
#include <math.h>

double function(double x) {
    return 1 / ((x * x) + 1); // The function to integrate
}

int main() {
    int n;  
    // Input the number of terms
    printf("Enter the number of terms: "); 
    scanf("%d", &n); // Number of terms or subintervals for Simpson's 3/8th rule

    int upperLimit, lowerLimit; 

    // Input the integration limits
    printf("Enter the lower limit and upper limit: ");
    scanf("%d%d", &lowerLimit, &upperLimit);

    // Calculate the width of each subinterval
    double h = (double)(upperLimit - lowerLimit) / (n - 1);

    double y[n]; // Array to store function values at each subinterval point

    // Evaluate the function at each subinterval
    for (int i = 0; i < n; i++) {
        double x = (h * i) + lowerLimit;
        y[i] = function(x);
        printf("x_%d : %lf    y_%d : %lf\n", i, x, i, y[i]);
    }

    // Initialize the result with the first and last function values
    double ans = y[0] + y[n - 1];

    // Apply Simpson's 3/8th rule
    for (int i = 1; i < n - 1; i++) {
        if (i % 3 == 0) { 
            ans += 2 * y[i];
        } else {
            ans += 3 * y[i];
        }
    }

    // Finalize the result
    ans *= (3 * h / 8);

    // Print the result
    printf("\nThe value of the integral is %lf", ans);

    return 0;
}
