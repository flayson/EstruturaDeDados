#include<stdio_ext.h>
#include <stdlib.h>

int main() {

   int *vet;
   int n;

   scanf("%d", &n);
   vet = malloc (n * sizeof (int)); // mesmo que vet = malloc (100 * sizeof (int));
   for (int i = 0; i < n; ++i) {
      scanf ("%d", &vet[i]);
      __fpurge(stdin);
   }

   free (vet);

   return 0;
}
