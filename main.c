#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
int main(int argc, char *argv[])
{
#define nomeImutavel = " JOhn ";

    char nomeMutavel[12] = "";
    int idade = 0;
    float altura = 0.0;

    printf("Valor inicial de idade: %d.\n", idade);

    printf("Digite o nome,idade e  ltura \n ");
    scanf("%s", &nomeMutavel);
    scanf("%d", &idade);
    scanf("%f", &altura);

    printf("nome informado: %s.\n", nomeMutavel);
    printf("Idade informada: %d.\n", idade);
    printf("altura informada: %.2f.\n", altura);
};

int main(int argc, char *argv[])
{
    int A, B, soma, subtr, mult, divis;

    printf("Digite o primeiro valor: ");
    scanf("%d", &A);
    printf("\n");

    printf("Digite o segundo valor: ");
    scanf("%d", &B);

    soma = A + B;
    subtr = A - B;
    mult = A * B;
    divis = A / B;

    printf("Resultados: \n");
    printf("%d.\n%d.\n%d.\n %.d.\n", soma, subtr, mult, divis);
}
*/

int main(int argc, char *argv[])
{
    char name1[25];

    /*  printf("Write yor first name and last name:");
      scanf("%s", &name1);

      printf("This is your name: %s\nOps somthing is missing.\n", &name1);

      system("pause");
  */
    char name2[25];
    printf("Write again:");

    fgets(name2, 25, stdin);

    printf("\nThis is your name: %s\n.", &name2);
}
