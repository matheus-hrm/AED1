#include <stdio.h>
#include <stdlib.h>


#define SUCESSO 1
#define FALHA -1  
#define TAM_MAX 100


typedef struct {
  unsigned int chave;
  unsigned int elemento;
} Celula;

typedef struct {
  Celula celulas[TAM_MAX];
  int tamanho;
} Lista;

int cria_lista (Lista *l){
  int i;
  for (i=0; i < TAM_MAX; i++){
    l->celulas[i].chave = 0;
    l->celulas[i].elemento = 0;
  }
  l->tamanho = 0;
  return SUCESSO;
}

int adiciona (Lista *l, Celula c){
  if (l->tamanho == TAM_MAX){
    return FALHA;
  }
  l->celulas[l->tamanho] = c;
  l->tamanho++;
  return SUCESSO;
}

void print_lista (Lista *l){
  int i;
  for (i=0; i < l->tamanho; i++){
    printf("Chave: %d, Elemento: %d\n", l->celulas[i].chave, l->celulas[i].elemento);
  }
}

int main(void){
  Lista l;
  if(cria_lista(&l) == SUCESSO){
    printf("Lista criada com sucesso\n");
  }
  else{
    printf("Falha ao criar lista\n");
  }
  

  Celula c1;
  int elementos;
  printf("Quantos elementos deseja adicionar?\n");
  scanf("%d", &elementos);
  
  while(elementos--){
    printf("Insira uma chave e um elemento\n");
    scanf("%d %d", &c1.chave, &c1.elemento);
    adiciona(&l, c1);
  } 
  print_lista(&l);

  return 0;
}