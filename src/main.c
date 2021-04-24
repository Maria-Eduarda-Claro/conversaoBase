#include <stdio.h>
#include <ctype.h>

/*
GNU GENERAL PUBLIC LICENSE
Version 3, 29 June 2007
    
Estre programa é gratuito e livre para copiar, modificar e redistribuir contanto que mantenha sempre as modificações com o codigo aberto e disponivel para todos.

Criado por: Diovani Eduardo Coelli e Maria Eduarda Claro
UTFPR campus Pato Branco 2021

###O programa solicita a entrada do valor em decimal e converte para binário, octal ou hexadecimal.###

*/

void decimalParaOutrasBases(int decimal, int base);

int main()
{
  int decimal, opcao = 0;
  char continuar;

  printf("UTFPR Campus Pato Branco 2021\n");
  printf("Criado por: Diovani Eduardo Coelli e Maria Eduarda Claro\n\n");

  printf("O programa solicita a entrada do valor em decimal e converte para binário, octal ou hexadecimal.\n\n");

  // loop principal do programa
  while (1)
  {
    printf("Informe um numero decimal inteiro: ");
    scanf("%d", &decimal);

    printf("Converter Decimal para:\n");
    printf("1- Binario\n");
    printf("2- Octal\n");
    printf("3- Hexadecimal\n");

    while(1)
    {
      scanf("%d", &opcao);

      switch (opcao)
      {
      case 1:
        printf("O valor decimal %d em binario fica: ", decimal );
        decimalParaOutrasBases(decimal, 2);
        break;

      case 2:
        printf("O valor decimal %d em octal fica: ", decimal);
        decimalParaOutrasBases(decimal, 8);
        break;

      case 3:
        printf("O valor decimal %d em hexadecimal fica: #", decimal);
        decimalParaOutrasBases(decimal, 16);
        break;

      default:
        printf("Opcao invalida porfavor digite novamente! [1,2,3]\n");
        continue;
      }
      break;
    };

    printf("Deseja continuar executando o programa? [S/N]: ");

    while (1)
    {
      scanf(" %c", &continuar);
      continuar = tolower(continuar);

      if (continuar != 's' && continuar != 'n')
      {
        printf("Opcao invalida porfavor digite novamente! [S/N]\n");
        continue;
      }
      break;
    }

    if (continuar == 'n')
    {
      break;
    }
  }

  printf("Muito obrigado por participar! :D\n");
  printf("FIM\n");

  return 0;
}

void decimalParaOutrasBases(int decimal, int base)
{
  int resto, i, tamanho = 0;

  // acha o tamanho nescessario para armazenar o resultado
  for (i = decimal; i > 0; i /= base)
  {
    tamanho++;
  }
  // cria um array de caracteres com o tamanho certo para armazenar o resultado
  char resultado[tamanho];

  // faz um loop inverso no array para ficar na ordem certa
  for (i = tamanho - 1; i >= 0; i--)
  {
    resto = decimal % base;

    // Armazena os resulto baseado na tabela ASCII, se o resultado for de 0 a 9, o equivalente na tabela fica de 48 a 57, para cima de 9 os resultado sao apresentado em forma de letras maiscular seguind a ordem do alfabeto ex: 10 = A, B = C, isso na tabela começa no numero 65, entao 65 - 10 = 55.
    resultado[i] = resto < 10 ? resto + 48 : resto + 55;

    decimal /= base;
  }

  // imprime no console direto da funcao porque retornar um array e muito doloroso tanto pra mim que teria que escrever como para voce que esta lendo
  printf("%s\n", resultado);

}
