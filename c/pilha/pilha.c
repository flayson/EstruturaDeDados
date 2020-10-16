#include<stdio.h>
#include<stdlib.h>

const int SIZE = 4;

typedef struct stack{
   int value;
   int pos;
   struct stack *next;
}stack;

int isEmpty(stack *s){
   if(s == NULL){
      return 1;
   }

   /*if(s->pos = -1){
      return 1;
   }*/

   return 0;
}

stack* newStack(){
   stack *newS = malloc(sizeof(stack));
   //newS->value = v;
   newS->pos = -1;
   newS->next = NULL;

   return newS;
}

int isFull(stack *s){
   //printf("%i :: %i\n", s->pos-1, SIZE);
   if(s->pos==SIZE){
      
      return 1;
   }

   return 0;
}

void push(stack **s, int v){

   if(isFull(*s)){
      printf("\nPilha cheia!\n");
      return; 
   }

   stack *newS = malloc(sizeof(stack));
   newS->value = v;
   newS->pos = (*s)->pos + 1;
   newS->next = *s;
   *s = newS; //importante
   //newS = (*s)->next;
}

int pop(stack **s){
   if(isEmpty(*s)){
      printf("\nPilha vazia!\n");
      return -1;
   }
   stack *sTemp = *s;
   *s = (*s)->next;
   int value = sTemp->value;
   free(sTemp);
   return value;
}

void printStack1(stack *s){
   stack *sTemp  = s;
   if(isEmpty(s)){
      printf("\nPilha vazia!\n");
      return; 
   }
   while(sTemp != NULL){
      printf("\n%i - %i : %i -> %i\n", sTemp->value, sTemp->pos, sTemp, sTemp->next);
      sTemp = sTemp->next;
   }
}


void printStack(stack *stk){
   if(isEmpty(stk)){
       printf("\nPilha vazia!\n");
       return;
   }
   stack *stkT = stk;
    printf("For:\n");
   for(int i=0;stkT->next != NULL;i++){
      printf("%i - %i\n", i, stkT->value);
      stkT = stkT->next;
   }

   stkT = newStack();
   int value;
   int pos = stk->pos;
   for(int i=pos;i>-1;i--){
       value = pop(&stk);
       printf("v: %i - %i\n", i, value);
       push(&stkT, value);
   }
   printf("\n\n");
   for(int i=pos;i>-1;i--){
       value = pop(&stkT);
       printf("v: %i - %i\n", i, value);
       push(&stk, value);
   }
  
   /*printf("Vetor:\n");
   for(int i=3;i>=0;i--){
      printf("%i - %i\n", i, stack[i]);
   }*/
}
int main(){

   stack *s = newStack();
   push(&s, 34);
   push(&s, 3);
   push(&s, 13);
   push(&s, 5);
   printStack(s);  
   
   pop(&s);
   printStack(s);  
   /*pop(&s);
   pop(&s);
   pop(&s);
   pop(&s);
   printStack(s);   */
  
   return -1;
}

