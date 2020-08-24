 #include <stdio.h>
#define TAM_L 3
#define TAM_C 2

int main() {

   //Declaração de uma matriz em C:
   int matriz[TAM_L][TAM_C];

   matriz[0][0] = 2;
   matriz[0][1] = 4;
   matriz[1][0] = -1;
   matriz[1][1] = 9;
   matriz[2][0] = 5;
   matriz[2][1] = 3;

   printf("[L][C] : VALOR\n");

   for(int l=0;l<TAM_L;l++){
      for(int c=0;c<TAM_C;c++){
         printf("[%i][%i] : %i\n", l, c, matriz[l][c]);
   }   }

   return 0;
}
