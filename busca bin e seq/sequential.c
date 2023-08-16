#include <stdio.h>

int buscaSequencial (int *vetor, int tamanho, int chave) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == chave) {
            return i;
        }
    }

    return -1;
}

int main (void){

  int vetor[10];

  printf("Digite 10 numeros:\n");
  for (int i = 0; i < 10; i++){
    scanf("%d", &vetor[i]);
  }

  printf("Digite o numero que deseja buscar:\n");
  int chave;
  scanf("%d", &chave);

  if (buscaSequencial(vetor, 10, chave) == -1){
    printf("O numero não foi encontrado.\n");
  } else {
    printf("O numero foi encontrado na posicao %d.\n", buscaSequencial(vetor, 10, chave));
  }

  return 0;

}