#include <stdio.h>
#include <stdlib.h>

int main() {
    char *p;
    //char p2;
    
    p = (char *) malloc (1); // ou p = malloc(1); não é necessário informar o tipo de variáve, porque a *p é do tipo char.
    scanf("%c", p);

    printf("char: %c\n\n", *p);

   return 0;
}
