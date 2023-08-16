#include <stdio.h>


int main(void){

  int elementos, i, j, aux;

  scanf("%d", &elementos);

  int vetor[elementos];

  for(i = 0; i < elementos; i++){
    scanf("%d", &vetor[i]);
  }

  int iguais = 0, diferentes = 0;

  for(i = 0; i < elementos; i++){
    for(j=i+1; j < elementos; j++){
      if(vetor[i] > vetor[j]){
        aux = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = aux;
      }
    }
  }
  
  for(i = 0; i < elementos; i++){
    if(vetor[i] != vetor[i+1]){
      diferentes++;
    }else if(vetor[i] == vetor[i+1]){
      iguais++;
    }
  }

  printf("%d\n",(diferentes-iguais));

  return 0;
}