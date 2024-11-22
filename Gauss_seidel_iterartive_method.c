

#include<stdio.h>
#include<math.h>
#define E 0.0001
int main(){
   printf("Name :- Shivang Mahendra\n");
   printf("Section :- A\n");
   printf("Class Roll No :- 59\n");
   printf("Univ. Roll No :- 2019103\n\n");
   int r, iterations = 0;
   scanf("%d",&r);
   float a[r][r+1];
   for(int i=0; i<r; i++){
      for(int j=0; j<=r; j++){
         scanf("%f",&a[i][j]);
      }
   }
   float ans[r], prev[r];
   for(int i=0; i<r; i++){
      ans[i] = 0.0;
      prev[i] = 0.0;
   }
   while(1){
      for(int i=0; i<r; i++){
         float sum = 0.0;
         for(int j = 0; j<r; j++){
            if(i != j)
               sum += (ans[j]*a[i][j]); 
         }
         ans[i] = (a[i][r] - sum) / a[i][i];
      }
      iterations++;
      int flag = 0;
      for(int i=0; i<r; i++){
         if(fabs(ans[i] - prev[i]) > E){
            flag = 1;
            break;
         }
      }
      if(!flag)
         break;
      else  
         for(int i=0; i<r; i++)
            prev[i] = ans[i];
   }
   printf("Iterations : %d\n",iterations);
   for(int i=0; i<r; i++){
      printf("x%d = %f\n",i+1,ans[i]);
   }
}
// x=0.985958
// y=-0.594784
// z=1.062186