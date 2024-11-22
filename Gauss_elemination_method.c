
#include<stdio.h>
#include<math.h>
int main(){
   int r;
   scanf("%d", &r);
   float aug[r][r+1];
   for(int i=0; i<r; i++){
      for(int j=0; j<=r; j++){
         scanf("%f", &aug[i][j]);
      }
   }
   for(int i=0; i<r-1; i++){
      for(int k=i+1; k<r; k++){
         float mul = aug[k][i]/aug[i][i];
         aug[k][i] = 0.0;
         for(int j=i+1; j<=r; j++){
            aug[k][j] = aug[k][j] - mul*aug[i][j];
         }
      }
   }
   printf("Upper Matrix : \n");
   for(int i=0; i<r; i++){
      for(int j=0; j<=r; j++){
         printf("%f\t", aug[i][j]);
      }
      printf("\n");
   }
   float ans[r]; 
   for(int i = r-1; i >= 0; i--){
      float res = aug[i][r];
      for(int j=r-1; j>i; j--){
         res -= (ans[j] * aug[i][j]);
      }
      // printf("%f  %f\n", res, aug[i][k]);
      ans[i] = res/aug[i][i];
   }
   for(int i=0; i<r; i++){
      printf("x%d = %f \n",i+1, ans[i]);
   }
}

#include <stdio.h>
#include <math.h>
int main()
{
   int n;
   scanf("%d", &n);
   float mat[n][n + 1];
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j <= n; j++)
      {
         scanf("%f", &mat[i][j]);
      }
   }
   for (int i = 0; i < n - 1; i++){
      for (int j = i + 1; j < n; j++){
         float mul = mat[j][i] / mat[i][i];
         for (int k = i; k <= n; k++){
            mat[j][k] -= (mul * mat[i][k]);
         }
      }
   }
   float ans[n];
   for (int i = n - 1; i >= 0; i--){
      float temp = 0.0;
      for (int j = n - 1; j > i; j--){
         temp += (ans[j] * mat[i][j]);
      }
      ans[i] = (mat[i][n] - temp) / mat[i][i];
   }
   for (int i = 0; i < n; i++){
      printf("%f ", ans[i]);
   }
}