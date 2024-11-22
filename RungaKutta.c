#include <stdio.h>
#include <math.h>
float f(float x, float y){
   return (x - y) / (x + y);
   // return (1 + x) / y;
   // return (x*x + y*y) / 5;
   // return (y * y - x * x) / (y * y + x * x);
   return (x*x)/(2*y);
}
int main(){
   float x0, y0, k1, k2, k3, k4, k, y, x, h, xn;
   printf("Enter x0 :");
   scanf("%f", &x0);
   printf("Enter y0 :");
   scanf("%f", &y0);
   printf("Enter xn :");
   scanf("%f", &xn);
   printf("Enter h :");
   scanf("%f", &h);
   // printf("\n\nX\t\tY\n");
   x = x0;
   y = y0;
   // printf("%f\t%f\n",x,y);
   while (x0 < xn){
      k1 = f(x0, y0);
      k2 = f((x0 + h / 2.0), (y0 + k1 / 2.0));
      k3 = f((x0 + h / 2.0), (y0 + k2 / 2.0));
      k4 = f((x0 + h), (y0 + k3));
      k = ((k1 + 2 * k2 + 2 * k3 + k4) / 6.0);
      y0 = y0 + k * h;
      x0 = x0 + h;
   }
   printf("Value of y at  %.3f is : %.3f\n", x0, y0);
}