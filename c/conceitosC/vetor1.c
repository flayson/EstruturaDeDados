 #include <stdio.h>

int main() {

   //Declaração de um vetor em C:
   int vetor[5] = {2, 6, 1, -9, 4};
   int vetor1[5] = {2, 6, 1}; //os demais itens são atribuidos como 0
   int vetor2[] = {3, 0, 8}; //o compilador faz a contagem dos itens

   for(int i=0;i<5;i++){
      printf("%i\n", vetor[i]);
   }

   return 0;
}
