#include <stdio.h>
#include <math.h>
float func(float x){
   // return 2 * pow(x, 2) + 3 * x; 
   return x*x;
}
int main(){
   int n;
   float upper, lower, h, sum, integral;
   printf("Enter lower limit : ");
   scanf("%f", &lower);
   printf("Enter upper limit : ");
   scanf("%f", &upper);
   printf("Enter number of subintervals : ");
   scanf("%d", &n);
   h = (upper - lower) / n;
   sum = func(upper) + func(lower);
   int i = 2;
   while (i <= n){
      sum += (2 * func(lower + (i - 1) * h));
      i++;
   }
   integral = (h * sum) / 2;
   printf("\nAnswer is: %f", integral);
   return 0;
}