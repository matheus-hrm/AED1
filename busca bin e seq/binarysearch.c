#include <stdio.h>

int buscaBinaria (int *vetor, int tamanho, int chave) {
    int inicio = 0;
    int fim = tamanho - 1;
    int meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (vetor[meio] == chave) {
            return meio;
        } else if (vetor[meio] < chave) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1;
}

int main (void){

  int vetor[10];


  printf("Digite 10 numeros de forma ordenada:\n");
  for (int i = 0; i < 10; i++){
    scanf("%d", &vetor[i]);
  }

  printf("Digite o numero que deseja buscar:\n");
  int chave;
  scanf("%d", &chave);


  if (buscaBinaria(vetor, 10, chave) == -1){
    printf("O numero não foi encontrado.\n");
  } else {
    printf("O numero foi encontrado na posicao %d.\n", buscaBinaria(vetor, 10, chave));
  }

  return 0;
}