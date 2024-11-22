#include<stdio.h>
int main(){
   int n; 
   float xf, yf = 0.0;
   printf("Enter no. of data and x andd y values \n");
   scanf("%d",&n);
   float x[n], y[n];
   for(int i=0; i<n; i++){
      scanf("%f",&x[i]);
   }
   for(int i=0; i<n; i++){
      scanf("%f",&y[i]);
   }
   printf("Enter value of x where y is to be calculated : ");
   scanf("%f", &xf);
   for(int i=0; i<n; i++){
      int num = 1.0, den = 1.0;
      for(int j=0; j<n; j++){
         if(i != j){
            num *= (xf - x[j]);
            den *= (x[i] - x[j]);
         }
      }
      yf += ((num*1.0/den)*y[i]);
   }
   printf("Answer : %f\n",yf);
}