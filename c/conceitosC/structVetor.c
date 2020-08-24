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

   struct funcionario func[2];

   printf("\nCadastro de funcionário\n");
   
   printf("Nome: ");
   scanf("%70[^\n]", func[0].nome);
   __fpurge(stdin);

   printf("CPF: ");
   scanf("%11[^\n]", func[0].cpf);
   __fpurge(stdin);

   printf("Salário: ");
   scanf("%lf", &func[0].salario);
   __fpurge(stdin);
  
   printf("\nCadastro de funcionário\n");
   printf("\nNome.....: %s", func[0].nome );
   printf("\nCPF......: %s", func[0].cpf);
   printf("\nSalário..: %lf\n", func[0].salario);

   getchar();

   return 0;
}
