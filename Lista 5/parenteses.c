//usar pilha


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
  Pilha *prox;
  Pilha *ant;
  char *c;
} Pilha;

Pilha *createPilha (void){
  Pilha *pilha = (Pilha*) malloc(sizeof(Pilha));
  pilha->prox = NULL;
  pilha->ant = NULL;
  return pilha;
}

int main (void){
  
  Pilha *pilha = createPilha();

  char string[1000];

  scanf("%[^\n]", string);

  int i = 0;
  
  
  return 0;
}