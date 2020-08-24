#include<stdio.h>
#include<stdlib.h>


typedef struct no {
   int valor;
   struct no *proximo;
}no;


void add(no *lista, int v);
void printList(struct no *lista);
void addFim(no *lista, int v);
void addInicio(no *lista, int v);
int findNo(no *lista, int v);
void removeNo(no *lista, int v);
void removeNoInicio(no *lista);
void addMeio(no *lista, int pos, int v);
int getPos(no *lista, int pos);
int isVazia(no *lista);

no *addPrimeiroNo(int v);
no *alocarNovoNoMemoria();
no *noInicio;

int main(){

   //no *lista = alocarNovoNoMemoria();
   //lista->valor = 9;
   //lista->proximo = NULL;
printList(noInicio);
   no *lista = addPrimeiroNo(9);
   addFim(lista, 3);
   addFim(lista, 56);
   addInicio(lista, 33);

   printList(noInicio);

   //int valorPesquisa;
   //printf("Informe o valor para a busca: ");
   //scanf("%i", &valorPesquisa);
   //printf("\n\nPosição: %i\n\n", findNo(noInicio, valorPesquisa));
   //printf("\n\nValor da Posição: %i\n\n", getPos(noInicio, valorPesquisa));
   removeNo(noInicio, 3);
printList(noInicio);
   //removeNo(noInicio, 33);
   removeNoInicio(noInicio);
   printList(noInicio);
   //removeNo(noInicio, 56);
   //printList(noInicio);
   //removeNo(noInicio, 9);
   
   //addMeio(noInicio, 0, 40);
   //printList(noInicio);
   return 0;
}
int isVazia(no *lista) {

   if(noInicio==NULL)
      return 1;

   return 0;
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
no *addPrimeiroNo(int v) {

   no *lista = alocarNovoNoMemoria();
   noInicio = lista;
   lista->valor = v;
   lista->proximo = NULL;
}
void addFim(no *lista, int v){

   no *novoNo = alocarNovoNoMemoria();

   novoNo->valor = v;
   novoNo->proximo = NULL;

   struct no *temp = lista;
   while(temp->proximo != NULL){
      temp = temp->proximo;
   }

   temp->proximo=novoNo;

}

void addInicio(no *lista, int v) {
   no *novoNo = alocarNovoNoMemoria();
   novoNo->valor = v;
   no *noTemp = alocarNovoNoMemoria();

   noTemp = lista;
   novoNo->proximo = noTemp;
   noInicio = novoNo;

    //if(lista-> proximo != NULL){
    //  no *noTemp = alocarNovoNoMemoria();
    //  noTemp = lista-> proximo;
    //  lista->proximo = novoNo;
    //  novoNo->proximo=noTemp;
    //} else {
    //   lista->proximo=novoNo;
    // }
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

void removeNoInicio(no *lista) {
   no *noTemp = NULL;
   if(lista != NULL) {
      noTemp = lista;
      lista = lista->proximo;
      free(noTemp);
   }
}
void removeNo(no *lista, int v) {
   //if(!findNo(lista, v)){
     // printf("Elemento não encontrado!");
      //return;
   //}

    no *noAnterior = NULL;
    no *noAtual = NULL;

    noAtual = lista;

    while(noAtual != NULL){
       if(noAtual->valor == v){
          //novoNo->proximo = noTemp;
         if( noAtual->proximo == NULL) {
            //free(noAtual);
            noInicio = alocarNovoNoMemoria();
         }
         if(noAnterior == NULL){
            noInicio = noAtual->proximo;
            free(noAtual);
         } else {
            noAnterior->proximo = noAtual->proximo;
            free(noAnterior);
         }
         printf("Elemento: %i removido!\n", v);
         return;
       }

       noAnterior = noAtual;
       noAtual = noAtual->proximo;
         
    }
}
void addMeio(no *lista, int pos, int v) {

   no *noTemp = NULL;// = alocarNovoNoMemoria();
   no *noAnterior = NULL;//alocarNovoNoMemoria();
   noTemp = lista;
   int i = 0;
   
   while(i <= pos && noTemp !=NULL){
      if(i==pos) {

         no *novoNo = alocarNovoNoMemoria();
         novoNo->valor = v;
         novoNo->proximo = noTemp;
         if(noAnterior == NULL){
          noInicio = novoNo;
         } else {
            noAnterior->proximo = novoNo;
         }

         break;
      }
      noAnterior = noTemp;
      noTemp = noTemp->proximo;
      i++;
   }
   //printf("Posição: i %i - pos %i", i, pos);
}

void printList(struct no *lista){
   struct no *temp = lista;
   int i = 0;

   if(isVazia(lista)) {
    
      printf("\n\nVazia.\n\n");
      return;
   }
   printf("\n%i - %i", i++, temp->valor);

   while(temp->proximo != NULL){
      temp = temp->proximo;
      printf("\n%i - %i", i++, temp->valor);
   }
   printf("\n");
}

no *alocarNovoNoMemoria() {

   no *novoNo = malloc (sizeof (no));
   novoNo->proximo=NULL;
   //ou
   //no *novoNo = malloc (sizeof (no));
   if(!novoNo) {
      printf("Erro: não há espaço na memória!");
   } else {
      return novoNo;
   }
}


