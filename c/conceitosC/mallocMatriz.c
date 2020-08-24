#include<stdio_ext.h>
#include <stdlib.h>

int main() {

   int **mat;//vetores de vetores
   int l, c;
   printf("Nº de linhas: ");
   scanf("%d", &l);
   printf("Nº de colunas: ");
   scanf("%d", &c);
   mat = malloc (l * sizeof (int)); // mesmo que vet = malloc (l * sizeof (int));
   for (int il = 0; il < l; ++il) {
      mat[il] = malloc (c * sizeof (int));
      for (int ic = 0; ic < c; ++ic) {
         scanf ("%d", &mat[il][ic]);
         __fpurge(stdin);
      }
   }

   free (mat);
   return 0;
}
