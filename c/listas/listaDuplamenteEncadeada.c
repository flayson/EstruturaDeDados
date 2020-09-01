#include<stdio.h>
#include<stdlib.h>


typedef struct no {
   int valor;
   struct no *anterior;
   struct no *proximo;
}no;


int findNo(no *lista, int v);

void printList(struct no *lista);
void printListEnderecos(struct no *lista);

void addFim(no *lista, int v);

no *busca_e_remove(no *lista, int y);

int getPos(no *lista, int pos);
int getTamanho(no *lista);

int isVazia(no *lista);

no *alocarNovoNoMemoria(int v);

int main(){

no *lista = alocarNovoNoMemoria(5);
printListEnderecos(lista);
printf("\n\n");
addFim(lista, 3);
addFim(lista, 6);
addFim(lista, 2);


printf("Remove 5");
lista = busca_e_remove(lista, 5);
printListEnderecos(lista);
printf("\n\n");

   return 0;
}


void printList(struct no *lista){
   struct no *temp = lista;
   int i = 0;
   if(isVazia(lista)) {
      printf("\n\nVazia.\n\n");
      return;
   }

   while(temp != NULL){
      printf("\n%i - %i", i++, temp->valor);
      temp = temp->proximo;
   }
   printf("\n");
}

void printListEnderecos(struct no *lista){
   struct no *temp = lista;
   int i = 0;
   if(isVazia(lista)) {
      printf("\n\nVazia.\n\n");
      return;
   }

   while(temp != NULL){
      printf("\n%i - %i [%i (%i <-- %i --> %i)]", i++, temp->valor, temp, temp->anterior, temp->valor, temp->proximo);
      temp = temp->proximo;
   }
   printf("\n");
}

int isVazia(no *lista) {
   if(lista==NULL) {
      return 1;
   }
   return 0;
}

no *busca_e_remove(no *lista, int y) {
   if(!isVazia(lista)) {
      no *noAtual;
      noAtual = lista;
      //noAnterior = NULL;
      
      if(noAtual->proximo == NULL && noAtual->anterior == NULL) {
         free(noAtual);
         return NULL;
      }
      while (noAtual->valor != y && noAtual != NULL) {
         //noAnterior = noAtual;
         noAtual = noAtual->proximo;
      }
      //printf("\n noAtual: %i (%i <-- %i --> %i)", noAtual, noAtual->anterior, noAtual->valor, noAtual->proximo);
      if (noAtual == NULL) {
        return lista; //nó não encontrado.
      }
//printf("\n noAtual: %i (%i <-- %i --> %i)", noAtual, noAtual->anterior, noAtual->valor, noAtual->proximo);
      if (noAtual->anterior == NULL) { //significa que é o primeiro da lista.
         lista = noAtual->proximo;
          noAtual->proximo->anterior = NULL;
      
      } else { //caso contrário remove um elemento do meio da lista
         if(noAtual->anterior != NULL)
            noAtual->anterior->proximo = noAtual->proximo;
         if(noAtual->proximo != NULL)
            noAtual->proximo->anterior = noAtual->anterior;
      }
   }
   return lista;
}

int getPos(no *lista, int pos){
   int i = -1;
   no *listaTemp = lista;
   while(listaTemp != NULL && pos > i) {
      i++;
      if(pos == i){
        return listaTemp->valor;
      }
      listaTemp = listaTemp->proximo;
   }
   return -1;

}


int getTamanho(no *lista){
   int i = 0;
   no *listaTemp = lista;
   for(i=0; listaTemp != NULL; i++) {
      listaTemp = listaTemp->proximo;
   }
   return i;
}


no *alocarNovoNoMemoria(int v) {

   no *novoNo = malloc (sizeof (no));    //no *novoNo = malloc (sizeof (no));
   //novoNo->proximo=NULL;
   //novoNo->anterior=NULL; 
   novoNo->valor = v;

   if(!novoNo) {
      printf("Erro: não há espaço na memória!");
   } else {
      return novoNo;
   }
}

void addFim(no *lista, int v){

   no *novoNo = alocarNovoNoMemoria(v);

   novoNo->valor = v;
   novoNo->proximo = NULL;

   if(isVazia(lista)){
      lista = novoNo;
      lista->anterior = NULL;
      return;
   }

   struct no *temp = lista;
   while(temp->proximo != NULL){
      temp = temp->proximo;
   }
   temp->proximo=novoNo;
   novoNo->anterior = temp;

}



