#include<stdio.h>
#include<stdlib.h>


typedef struct no {
   int valor;
   struct no *anterior;
   struct no *proximo;
}no;


void add(no *lista, int v);
void addFim(no *lista, int v);

int findNo(no *lista, int v);

void printList(struct no *lista);
void printListEnderecos(struct no *lista);

no *busca_e_remove(no *lista, int y);
no  *removePrimeira(no *lista);
no  *removeUltima(no *lista);

int getPos(no *lista, int pos);
int getTamanho(no *lista);

int isVazia(no *lista);

no *addPrimeiroNo(int v);
no *alocarNovoNoMemoria(int v);
//void addInicio(no *lista, int v);
no *addInicio(no *lista, int v);

int main(){

no *lista = alocarNovoNoMemoria(5);
printListEnderecos(lista);
printf("\n\n");
addFim(lista, 3);
printListEnderecos(lista);
printf("\n\n");



lista = addInicio(lista, 7);

printListEnderecos(lista);
printf("\n\n");
//printf("posicao: %i", getPos(lista, 2));
//printf("\n\n");
//printf("Tamanho: %i", getTamanho(lista));

printf("Remove 7");
lista = busca_e_remove(lista, 7);
printListEnderecos(lista);
printf("\n\n");

printf("Remove 3");
lista = busca_e_remove(lista, 3);
printListEnderecos(lista);
printf("\n\n");


printf("Remove 5");
lista = busca_e_remove(lista, 5);
printListEnderecos(lista);
printf("\n\n");

printf("Remove 5");
lista = busca_e_remove(lista, 5);
printListEnderecos(lista);
printf("\n\n");

/*
printf("Remove 3");
lista = removeUltima(lista);
printListEnderecos(lista);
printf("\n\n");

printf("Remove 5");
lista = removeUltima(lista);
printListEnderecos(lista);
printf("\n\n");

printf("Remove 7");
lista = removeUltima(lista);
printList(lista);
printf("\n\n");

printf("Remove nada");
lista = removeUltima(lista);
printList(lista);


printf("\n END TEMP: %i (%i <-- %i --> %i)", temp, temp->anterior, temp->valor, temp->proximo);
printf("\n END novoNo:- %i (%i <-- %i --> %i)", novoNo, novoNo->anterior, novoNo->valor, novoNo->proximo);
*/


printf("\n\n");
   return 0;
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


no *addInicio(no *lista, int v) {
   no *novoNo = alocarNovoNoMemoria(v);
   //novoNo->anterior = NULL;
   novoNo->proximo = lista;
   lista->anterior = novoNo;

//printf("\n NOVO NO: %i (%i <-- %i --> %i)", novoNo, novoNo->anterior, novoNo->valor, novoNo->proximo);


   return novoNo;
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


int findNo(no *lista, int v) {

   no *noTemp = malloc (sizeof (no));
   noTemp = lista;
   int pos = 0;
   while(noTemp != NULL){
      if(noTemp->valor == v)
         return pos;

      noTemp = noTemp->proximo;
      pos++;
   }
   return -1;
}

no  *removePrimeira(no *lista) {
   if(!isVazia(lista)) {
      lista = lista->proximo;
      free(lista->anterior);
   }
   return lista;
}


no *removeUltima(no *lista) {
//printf("\nlista1: \n");
//printf("\nno1: %i\n", lista->valor);
   if(!isVazia(lista)) {
	no *noAtual = lista;
	
	while (noAtual->proximo != NULL) {
	      noAtual = noAtual->proximo;
	}
//printf("\nno atual: %i\n", noAtual->valor);

 	if (noAtual->anterior == NULL) { //significa que é o primeiro da lista.
//printf("\nno anterior NULL: %i\n", noAtual->valor);
	      lista = noAtual->proximo;
	      
	} else { //caso contrário remove um elemento do meio da lista
//printf("\nno anterior !NULL: %i\n", noAtual->valor);
	      noAtual->anterior->proximo = noAtual->proximo;
	}
   }
//printf("\nlista: \n");
//printf("\nno: %i\n", lista);
//no *noAtual = lista;
//while (noAtual->proximo != NULL && noAtual != NULL) {
//printf("\nno: %i\n", noAtual->valor);
	 //     noAtual = noAtual->proximo;
	//}

   return lista;
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


