 #include<stdio_ext.h>
/*
Sintaxe de um struct:

struct <identificador>
{
 variáveis
}
struct <identificador> <variavel_struct>;

*/

struct funcionario {
      char nome[70];
      char cpf[11];
      double salario;
   };

int main() {

   struct funcionario func;

   printf("\nCadastro de funcionário\n");
   
   printf("Nome: ");
   scanf("%70[^\n]", func.nome);
   __fpurge(stdin);

   printf("CPF: ");
   scanf("%11[^\n]", func.cpf);
   __fpurge(stdin);

   printf("Salário: ");
   scanf("%lf", &func.salario);
   __fpurge(stdin);
  
   printf("\nCadastro de funcionário\n");
   printf("\nNome.....: %s", func.nome );
   printf("\nCPF......: %s", func.cpf);
   printf("\nSalário..: %lf\n", func.salario);

   getchar();

   return 0;
}
