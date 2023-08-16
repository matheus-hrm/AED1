#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct Jogador{
  char nome[20];
  struct Jogador *prox;
}Jogador;

Jogador* cria_lista(){
  return NULL;
}

void insere(Jogador *l, char *nome){
  Jogador *novo = (Jogador*) malloc(sizeof(Jogador));
  strcpy(novo->nome, nome);
  novo -> prox = l;
  l = novo;
}

void remover(Jogador* l, char* nome) {
    Jogador* atual = l;
    Jogador* ant = NULL;

    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        ant = atual;
        atual = atual->prox;
    }
    if (atual == NULL) {
        return; 
    }
    if (ant == NULL) {
        l = atual->prox; 
    } else {
        ant->prox = atual->prox; 
    }
    free(atual);
}

void imprimir(Jogador *l){
  Jogador *p;
  for(p = l; p != NULL; p = p->prox){
    printf("%s\n", p->nome);
  }
}

int main (void){
  
  Jogador *l = cria_lista();
  char nome[20];
  while ((strcmp(nome, "Fim") != 0)){
    scanf("%s", nome);
    insere(l, nome);
  }
  
  char bobinho[20];
  scanf("%s", bobinho);

  int jogadas = 0;
  scanf("%d", &jogadas);

  int i;
  for(i = 0; i < jogadas; i++){
    char roubou[20];
    char perdeu[20];
    scanf("%s %s",perdeu, roubou);
    if(strcmp(bobinho, roubou) == 0){
      insere(l, perdeu);
      remover(l, bobinho);
      strcpy (bobinho, perdeu);
    }
    else {
      remover(l, perdeu);
      insere(l, perdeu);
    }

  }


  imprimir(l);
  if (l->prox == NULL) printf ("Vencedor(a): %s\n", l->nome);
  return 0;

}