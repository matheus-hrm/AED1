#include <stdio.h>

int main(void){

  int tabela[6][6] = {
    0  , 63 , 210, 190, NULL, 190,
    63 , 0  , 160, 150, 95, 10 ,
    210, 160, 0  , 10 , 1 , 10 ,
    190, 150, 10 , 0  , 10, 20 ,
    10 , 95 , 7  , 21 , 0 , 80  ,
    190, 2  , NULL  , 41 , 80, 0  
    }; 

  int i, viagens;

  scanf("%d", &viagens);

  int vet[viagens];

  for (i=0;i<viagens;i++)
  {
    scanf("%d", &vet[i]);
  }

  int soma = 0;

  for (i=0;i<viagens - 1;i++)
  {
    if (tabela[vet[i]][vet[i+1]] == NULL)
    {
      printf("rota invalida!");
      return 0;
    }

    soma = tabela[vet[i]][vet[i+1]] + soma;
  }

  printf("%d", soma);
  return 0;
}