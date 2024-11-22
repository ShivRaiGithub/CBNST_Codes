
#include<stdio.h>
#include<math.h>
#define E 0.0001
// 2 3 -> 2.27
double solve(double x){
   return (x * x * x) - (3 * x) - 5;
}
int main(){
   double x0, x1, x2, f0, f1, f2, temp = -1; 
   printf("Enter 2 roots : ");
   while(1){
      scanf("%lf %lf",&x0, &x1);
      if(solve(x0) * solve(x1) < 0)
         break;
      printf("Incorrect Input Enter again\n");
   }
   f0 = solve(x0);
   f1 = solve(x1);
   // if(f0*f1 > 0){
   //    printf("Wrong guess\n");
   //    return 0;
   // }
   while(1){
      x2 = (x0*f1 - x1*f0)/(f1 - f0);
      f2 = solve(x2);
      printf("%lf\n", x2);
      if(temp != -1 && fabs(x2 - temp) <= E){
         break;
      } 
      if(f0*f2 < 0){
         x1 = x2;
         f1 = f2;
      }
      else{
         x0 = x2;
         f0 = f2;
      }
      temp = x2;
   }
   printf("%lf\n",x2);
}

#include <stdio.h>
#include <math.h>
#define E 0.005
double f(double x){
   return cos(x) - x * exp(x);    // 0 1 -> 0.5169
   // return x * log10(x) - 1.2;
}
int main()
{
   int iterations = -1;
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
   double x, prev;
   while (1){
      if (iterations == -1){
         x = (a * f(b) - b * f(a)) / (f(b) - f(a));
         if (x * f(a) >= 0)
            a = x;
         else
            b = x;
         iterations++;
      }
      else{
         iterations++;
         prev = x;
         x = (a * f(b) - b * f(a)) / (f(b) - f(a));
         if (x * f(a) >= 0)
            a = x;
         else
            b = x;
         if (fabs(x - prev) < E)
            break;
      }
   }
   printf("%lf", x);
}