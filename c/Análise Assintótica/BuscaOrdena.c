#include <stdio.h>

#define TAM_MAX 5
 
void print(int vetor[TAM_MAX]){
   for(int i=0;i<TAM_MAX;i++){
      printf("%i - %i\n", i, vetor[i]);
   }
}

void print1(int *v){
   
   for(int i=0;i<TAM_MAX;i++){
      printf("%i - %i\n", i, v[i]);
   }
}
// TAM_MAX = 10   (x== 9)
void ordena(int vetor[TAM_MAX]){
int temp;
		
   for(int x = 0; x<TAM_MAX; x++) {
      for(int y=0;y<x; y++) {
         if(vetor[x] < vetor[y]) {
            temp = vetor[x];
            vetor[x] = vetor[y];
            vetor[y] = temp;
         }
      }
   }
}

int busca(int *vetor, int valor) {
   for(int x = 0; x<TAM_MAX; x++) {		
      if(vetor[x] == valor) {
      return x;
      }
   }
   return -1;
}

int main() {


   int vetor[] = {2, 6, 1, -9, 4};

   print1(vetor);
   printf("\nBusca -9: %i", busca(vetor, -9));
   printf("\n\nOrdenado: \n");
   ordena(vetor);
   print1(vetor);
   printf("\nBusca -9: %i\n\n", busca(vetor, -9));
   return 0;
}

