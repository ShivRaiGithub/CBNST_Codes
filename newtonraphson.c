
#include <stdio.h>
#include <math.h>
#define E 0.00001
float function(float x){
    return (x * x * x) - (3 * x) - 5;
}
float functionDer(float x){
    return (3 * x * x) - 3;
}
// double function(double x){
//     return tan(x) - (4 * x);
// }
// double functionDer(double x){
//     // return ((1/cos(x)) * (1/cos(x))) - 4;
//     return (tan(x) * tan(x)) - 3;
// }
int main(){
    printf("Name :- Shivang Mahendra\n");
    printf("Section :- A\n");
    printf("Class Roll No :- 59\n");
    printf("Univ. Roll No :- 2019103\n\n");
    double a, b;
    printf("Enter value\n");
    while (1){
        scanf("%lf %lf", &a, &b);
        if (function(a) == 0){
            printf("Root is %f\n", a);
            return 0;
        }
        else if (function(b) == 0){
            printf("Root is %f\n", b);
            return 0;
        }
        if (function(a) * function(b) < 0){
            break;
        }
        printf("Incorrect guess , enter again!\n");
    }
    double x0 = fabs(function(a)) < fabs(function(b))? a : b;
    // if (function(x0) == 0){
    //     printf("Root is %f\n", x0);
    //     return 0;
    // }
    double h, x1;
    // int iterations = 1000;
    // while (iterations--){
    while(1){
        h = function(x0) / functionDer(x0);
        x1 = x0 - h;
        if(fabs(function(x1) - function(x0)) <= E){
            // x0 = x1;
            break;
        }
        x0 = x1;
    }
    // printf("Iterations = %d\n", 1000 - iterations);
    printf("Root is %.10lf\n", x0);
    return 0;
}

#include <stdio.h>
#include <math.h>
#define E 0.001
double f(double x){
    return x * log10(x) - 1.2;  // 2 3 -> 2.740646
}
double derv(double x){
    return log10(x) + 0.43429;
}
int main(){
    int iterations = 0;
    double a, b;
    scanf("%lf %lf", &a, &b);
    if (f(a) == 0){
        printf("%lf", a);
        return 0;
    }
    if (f(b) == 0){
        printf("%lf", b);
        return 0;
    }
    double x = (a + b) / 2.0, prev;
    while (1){
        prev = x;
        x = x - (f(x) / derv(x));
        if (fabs(x - prev) < E)
            break;
    }
    printf("%lf", x);
}