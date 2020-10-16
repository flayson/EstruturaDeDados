#include <stdio.h>
#include <stdlib.h>

const int TAM = 4;
//int pos = 0;

typedef struct stack {
    int s[4];
    int pos;
}stack;


int isEmpty(stack *stk){
   if(stk->pos < -1){
      return 1;
   }

   return 0;
}

int isFull(stack *stk){
   if(stk->pos == TAM){
      return 1;
   }

   return 0;
}

void push(stack *stk, int value){ //// ou void push(int *stack)
   if(isFull(stk)){
       printf("\nPilha cheia!\n");
       return;
   }
   //printf("Push: %i - %i\n", stk->pos, value);
   stk->pos++;
   stk->s[stk->pos] = value;
   
    
}

int pop(stack *stk) { // ou int pop(int *stack)
    if(isEmpty(stk)){
         printf("\nPilha vazia\n");
        return -1;
    }
    int value = stk->s[stk->pos];
    //printf("1: %i\n", stk->pos);
    stk->s[stk->pos] = 0;
    stk->pos--;
    //printf("2: %i\n", stk->pos);
    return value;
}

stack *alocarNovaStackMemoria() {
    stack *stk = malloc (sizeof (stack));
    
    stk->pos = -1;
    
    if(stk) {
        return stk;
    }
    printf("Erro: a memória principal está sem espaço");
    return NULL;
}

void printStack(stack *stk){
   if(isEmpty(stk)){
       printf("\nPilha vazia!\n");
       return;
   }
   
    printf("Vetor:\n");
   for(int i=stk->pos;i>=0;i--){
      printf("%i - %i\n", i, stk->s[i]);
   }

   stack *stkT = alocarNovaStackMemoria();
   int value;
   int pos = stk->pos;
   for(int i=pos;i>-1;i--){
       value = pop(stk);
       printf("v: %i - %i\n", i, value);
       push(stkT, value);
   }
   printf("\n\n");
   for(int i=pos;i>-1;i--){
       value = pop(stkT);
       printf("v: %i - %i\n", i, value);
       push(stk, value);
   }
  
   /*printf("Vetor:\n");
   for(int i=3;i>=0;i--){
      printf("%i - %i\n", i, stack[i]);
   }*/
}






int main(){
   stack *stk = alocarNovaStackMemoria();
   push(stk, 2);
   
   //pop(stk);
   push(stk, 3);
   push(stk, 4);
   printStack(stk);
   push(stk, 8);
   push(stk, 8);
   
   /*pop(stack);
   printStack(stack);
   pop(stack);
   printStack(stack);
   pop(stack);
   printStack(stack);
   pop(stack);
   printStack(stack);
   pop(stack);
   printStack(stack);*/
   return EXIT_SUCCESS;

}
