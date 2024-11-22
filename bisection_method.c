
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
double solve(double x){
   return (x*x*x) - (2*x) - 5;
}
// double solve(double x){
//    return (x*x*x) - (4*x) + 1;
// }
int main()
{
   printf("Name :- Shivang Mahendra\n");
   printf("Section :- A\n");
   printf("Class Roll No :- 59\n");
   printf("Univ. Roll No :- 2019103\n\n");
   double a = 0.0, b = 1.0;
   double curr = 0.0, prev = 0.0;
   // curr = solve(b);
   prev = solve(a);
   while(1){
      curr = solve(b);
      // printf("%lf\n",curr);
      if((curr * prev < 0))
         break;
      b++;
      prev = curr;
   }
   a = b - 1;
   printf("a = %lf \nb = %lf\n", a,b);
   prev = -1;
   int c = 0;
   while(1){
      c++;
      double t1 = (a + b) / 2.0;
      // printf("a = %lf \tb = %lf\t%lf\n", a,b,t1);
      if(prev != -1 && fabs(prev - t1) <= 0.0001)
         break;
      curr = solve(t1);
      double t2 = solve(a); 
      if(curr * t2 >= 0){
         a = t1;
      }
      else{
         b = t1;
      }
      prev = t1;
      // printf("a = %lf \tb = %lf\t%d\t%lf\n", (a+b)/2.0-prev,b,c,prev);
      // double t = (a+b)/2.0 - prev;
      // if(t < 0){
      //    t = prev - (a+b)/2.0;
      // }
      // printf("%lf\t%d\n",t,c);
      // if(t <= 0.001){
      //    break;
      // }
      // prev = (a+b) / 2.0;
   }
   printf("root = %lf\n",(a+b)/2.0);
   return 0;
}




#include <stdio.h>
#include <math.h>
#define E 0.001
double f(double x){
   return x * x * x - 4 * x - 9; //5 9 -> 8.999
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
   double x = (a + b) / 2.0, prev = 0;
   while (1){
      double t = f(x);
      if (t * f(a) >= 0){
         a = x;
      }
      else{
         b = x;
      }
      prev = x;
      x = (a + b) / 2;
      iterations++;
      if (fabs(x - prev) < E)
         break;
   }
   printf("%lf", x);
}