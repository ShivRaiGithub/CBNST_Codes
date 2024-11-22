
#include<stdio.h>
int main(){
   int r;
   scanf("%d", &r);
   float aug[r][r+1];
   for(int i=0; i<r; i++){
      for(int j=0; j<=r; j++){
         scanf("%f", &aug[i][j]);
      }
   }
   // if(aug[0][0] == 0){
   //    int i;
   //    for(i = 1; i<r; i++){
   //       if(aug[i][0] != 0)
   //          break;
   //    }
   //    for(int j=0; j<=r; j++){
   //       int t = aug[0][j];
   //       aug[0][j] = aug[i][j];
   //       aug[i][j] = t;
   //    }
   // }
   
   // printf("\nAugmented Matrix\n");
   // for(int i=0; i<r; i++){
   //    for(int j=0; j<=r; j++){
   //       printf("%f ",aug[i][j]);
   //    }
   //    printf("\n");
   // }

   for(int i=0; i<r; i++){
      for(int j=0; j<r; j++){
         if(i != j){
            float mul = aug[j][i]/aug[i][i];
            for(int k=0; k<=r; k++){
               aug[j][k] -= (aug[i][k] * mul); 
            }
         }
      }
   }
   
   // printf("\nDigonal Matrix\n");
   // for(int i=0; i<r; i++){
   //    for(int j=0; j<=r; j++){
   //       printf("%f ",aug[i][j]);
   //    }
   //    printf("\n");
   // }

   float ans[r];
   printf("\nAnswer\n");
   for(int i=0; i<r; i++){
      ans[i] = aug[i][r] / aug[i][i]; 
      printf("x%d = %f \n",i+1, ans[i]);
   }
}