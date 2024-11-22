
#include<stdio.h>
#include<math.h>
int main(){
   double a, b, c;
   printf("Enter coefficient of x^2 : ");
   scanf("%lf",&a);
   printf("Enter coefficient of x : ");
   scanf("%lf",&b);
   printf("Enter constant : ");
   scanf("%lf",&c);
   int d = (b*b) - (4*a*c);
   if(d>0){
      printf("Distinct and Real Roots\n");
      double r1 = (-b + sqrt(d)) / (2 * a);
      double r2 = (-b - sqrt(d)) / (2 * a);
      printf("root1 = %.2lf, root2 = %.2lf\n",r1,r2);
   }
   else if(d==0){
      printf("Equal and Real Roots\n");
      double r = -b / (2 * a);
      printf("root1 = root2 = %.2lf\n",r);
   }
   else{
      printf("Imaginary Roots\n");
      double r  = -b / (2 * a);
      double c = sqrt(-d) / (2 * a);
      printf("root1 = %.2lf + %.2lfi, root2 = %.2lf - %.2lfi\n", r,c,r,c);
   }
}