#include<stdio.h>
#include<stdlib.h>


typedef struct no {
   int valor;
   struct no *proximo;
}no;


void add(no *lista, int v);
void addFim(no *lista, int v);

int findNo(no *lista, int v);

void printList(struct no *lista);

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

no *lista = alocarNovoNoMemoria(5) ;
addFim(lista, 3);
lista = addInicio(lista, 7);

printList(lista);
printf("\n\n");
printf("posicao: %i", getPos(lista, 2));
printf("\n\n");
printf("Tamanho: %i", getTamanho(lista));
/*lista = removeUltima(lista);
printList(lista);
printf("\n\n");
lista = removeUltima(lista);
printList(lista);
printf("\n\n");
lista = removeUltima(lista);
printList(lista);

lista = removeUltima(lista);
printList(lista);*/


printf("\n\n");
   return 0;
}
void addFim(no *lista, int v){

   no *novoNo = alocarNovoNoMemoria(v);

   novoNo->valor = v;
   novoNo->proximo = NULL;

   struct no *temp = lista;
   while(temp->proximo != NULL){
      temp = temp->proximo;
   }
   temp->proximo=novoNo;
}


no *addInicio(no *lista, int v) {
   no *novoNo = alocarNovoNoMemoria(v);
   novoNo->proximo = lista;
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

int isVazia(no *lista) {
   if(lista==NULL) {
      return 1;
   }
   return 0;
}

no *busca_e_remove(no *lista, int y) {
   no *noAtual, *noAnterior;
   noAtual = lista;
   noAnterior = NULL;

   while (noAtual->valor != y && noAtual != NULL) {
      noAnterior = noAtual;
      noAtual = noAtual->proximo;
   }

   if (noAtual == NULL) {
     return lista; //nó não encontrado.
   }

   if (noAnterior == NULL) { //significa que é o primeiro da lista.
      lista = noAtual->proximo;
      
   } else { //caso contrário remove um elemento do meio da lista
      noAnterior->proximo = noAtual->proximo;
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
   no *noTemp = NULL;

   if(!isVazia(lista)) {

      noTemp = lista;
      lista = lista->proximo;
      free(noTemp);
   }
   return lista;
}


no *removeUltima(no *lista) {

   if(!isVazia(lista)) {
	no *noAtual, *noAnterior;
	noAtual = lista;
	noAnterior = NULL;

	while (noAtual->proximo != NULL) {
	      noAnterior = noAtual;
	      noAtual = noAtual->proximo;
	}

 	if (noAnterior == NULL) { //significa que é o primeiro da lista.
	      lista = noAtual->proximo;
	      
	} else { //caso contrário remove um elemento do meio da lista
	      noAnterior->proximo = noAtual->proximo;
	}
   }
   return lista;
}

no *alocarNovoNoMemoria(int v) {

   no *novoNo = malloc (sizeof (no));    //no *novoNo = malloc (sizeof (no));
   novoNo->proximo=NULL;
   novoNo->valor = v;

   if(!novoNo) {
      printf("Erro: não há espaço na memória!");
   } else {
      return novoNo;
   }
}


