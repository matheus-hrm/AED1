#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Lista{
  char nome[20];
  int ligacoes;
  char telefone[10];
  struct Lista *prox;
  struct Lista *ant;
}Agenda;


Agenda* cria_lista(){
  return NULL;
}

Agenda* insere(Agenda *l, char *nome, char *telefone, int ligacoes){
  Agenda *novo = (Agenda*) malloc(sizeof(Agenda));
  strcpy(novo->nome, nome);
  strcpy(novo->telefone, telefone);
  novo->ligacoes = ligacoes;
  novo -> prox = l;
  novo -> ant = NULL;
  if(l != NULL){
    l->ant = novo;
  }
  l = novo;
  return novo;
}


void ligacao (Agenda *l, char *nome){
  Agenda *p;
  for(p = l; p != NULL; p = p->prox){
    if(strcmp(p->nome, nome) == 0){
      p->ligacoes++;
      return;
    }
  }
}

void remover(Agenda *l, char *nome){
  Agenda *p;
  for(p = l; p != NULL; p = p->prox){
    if(strcmp(p->nome, nome) == 0){
      if(p->ant == NULL){
        l = p->prox;
      }else{
        p->ant->prox = p->prox;
      }
      if(p->prox != NULL){
        p->prox->ant = p->ant;
      }
      free(p);
      return;
    }
  }
}

void ordenaAgenda(Agenda *l){
  Agenda *p, *q;
  for (p = l; p != NULL; p = p->prox) {
    for (q = p->prox; q != NULL; q = q->prox) {
      if (p->ligacoes < q->ligacoes) {
        char auxNome[20];
        strcpy(auxNome, p->nome);
        strcpy(p->nome, q->nome);
        strcpy(q->nome, auxNome);

        char auxTelefone[10];
        strcpy(auxTelefone, p->telefone);
        strcpy(p->telefone, q->telefone);
        strcpy(q->telefone, auxTelefone);

        int auxLigacoes = p->ligacoes;
        p->ligacoes = q->ligacoes;
        q->ligacoes = auxLigacoes;
      }
    }
  }
}
void libera(Agenda *l){
  Agenda *p = l;
  while(p != NULL){
    Agenda *t = p->prox;
    free(p);
    p = t;
  }
}

void imprime(Agenda *l){
  while(l->prox != NULL){
    printf("%s - %s\n", l->nome, l->telefone);
    l = l->prox;
  }
}

int main(void){
  Agenda *l = cria_lista();
  char opcao;
  char nome[20], telefone[10];
  int ligacoes;

  
  l = insere(l, "Ooloneia", "4523-4887",  299);
  l = insere(l, "Hermanoteu", "4523-2248", 300);
  while (opcao != 'F'){
    scanf(" %c" , &opcao); 

    if (opcao == 'I'){
      scanf(" %s %s %d", nome, telefone, &ligacoes);
      l = insere(l, nome, telefone, ligacoes);
    }
    if (opcao == 'L'){
      scanf(" %s", nome);
      ligacao(l, nome);
    }
    if (opcao == 'R'){
      scanf(" %s", nome);
      remover(l, nome);
    }
  }

  ordenaAgenda(l);
  imprime(l);
  libera(l);
  
  return 0;
}