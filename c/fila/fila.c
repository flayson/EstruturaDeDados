#include <stdio.h>
#include <stdlib.h>


typedef struct no {
 int valor;
 struct no *proximo;
    
}no;

int isNull(no *fila){
    if(fila==NULL){
        printf("\nfila Vazia!\n");
        return 1;
    }
    return 0;
}


no *incluirNoFinal(no *fila, int v){
    no *novoNo = malloc(sizeof(no));
    novoNo->valor = v;
   
    if(isNull(fila)){ //primerio no na fila
        novoNo->proximo = NULL;
        return novoNo;
    }
    no *noAtual = fila;
    while(noAtual->proximo!=NULL){ //buscar o ultimo no da fila
        noAtual = noAtual->proximo;
    }
    
    noAtual->proximo=novoNo;
    novoNo->proximo = NULL;
    return fila;   
}


void incluirNoFinal1(no *fila, int v){

   no *novoNo = malloc(sizeof(no));
   novoNo->valor = v;
   novoNo->proximo = NULL;

   if(isNull(fila)){
      //não permite add em uma fila NULL!
      return;
   }

   struct no *temp = fila;
   while(temp->proximo != NULL){
      temp = temp->proximo;
   }
   temp->proximo=novoNo;
}

void incluirNoFinal2(no** fila, int v){
    no *novoNo = malloc(sizeof(no));
    novoNo->proximo = NULL;
    novoNo->valor = v;
   
    if(isNull(*fila)){ //primerio no na fila
        *fila = novoNo;
         return;
    }
    no *noAtual = *fila;
    while(noAtual->proximo!=NULL){ //buscar o ultimo no da fila
        noAtual = noAtual->proximo;
    }
    
    noAtual->proximo=novoNo;
}


void listarfila(no *fila){
    no *noAtual = fila;
    int i=0;
    printf("\n..::Listar fila:\n\n");
    while(noAtual!=NULL){
       printf("%i - %i\n", i++, noAtual->valor);
       noAtual = noAtual->proximo;
    }
}

void listarFilaComEnderecos(no *fila){
    no *noAtual, *noAnterior;
    noAtual = fila;
    noAnterior = NULL;
    int i=0;
    printf("\n..:: Listar fila com endereços:\n\n");
    while(noAtual!=NULL){
       printf("%i - [%i - %i] --> %i ;\n", noAnterior, i++, noAtual->valor, noAtual);
       noAnterior = noAtual;
       noAtual = noAtual->proximo;
    }
}

no *novoNo(int valor){
   no *novoNo = malloc(sizeof(no));
   novoNo->valor = valor;
   novoNo->proximo = NULL;
   return novoNo;
}

void remover(no** fila) { //sempre o primeiro
   no *noAtual;
   noAtual = *fila;

   if (noAtual == NULL) {
     return; //nó não encontrado.
   }
   *fila = noAtual->proximo; //significa que é o primeiro da fila.
   free(noAtual);
}

int main() {
 /*no *fila = malloc(sizeof(no));
 fila->valor=2;
 fila->proximo=NULL;*/

 no *fila = novoNo(2);
// no *fila = NULL;
 
 incluirNoFinal1(fila, 10);
 //printf("%i ",   fila);
 incluirNoFinal2(&fila, 11);
 incluirNoFinal2(&fila, 11);
 fila = incluirNoFinal(fila, 12);
 listarFilaComEnderecos(fila);
 remover(&fila);
 listarFilaComEnderecos(fila);
 remover(&fila);
remover(&fila);
 listarFilaComEnderecos(fila);
remover(&fila);

 listarFilaComEnderecos(fila);

 return 0;   
}
