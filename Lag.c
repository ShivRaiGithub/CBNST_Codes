#include <stdio.h>
#include <math.h>

int main() {
    int n;
    
    printf("Enter the number of entries: ");
    scanf("%d", &n);

    double x_val;
    double y_val = 0;

    int x[n], y[n];

    printf("Enter the values of x and y:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
        scanf("%d", &y[i]);
    }

    printf("Enter the value of x to find y: ");
    scanf("%lf", &x_val);

    for (int i = 0; i < n; i++) {
        double multi = 1.0;
        double div = 1.0;

        for (int j = 0; j < n; j++) {
            if (j != i) {
                multi *= (x_val - x[j]);
                div *= (x[i] - x[j]);  
            }  
        }  

        y_val += (multi / div) * y[i];
    }

    printf("y(%lf) = %lf", x_val, y_val);

    return 0;
}
