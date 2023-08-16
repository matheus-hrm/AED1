#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct {
  int hora;
  int minuto;
  int critico;
  struct Fila *prox;
} Fila;

typedef struct {
  Fila *inicio;
  Fila *fim;
  int tamanho;
  int hora_atual;
  int minuto_atual;
}node;

node* criaFila(){
  node *fila = (node*) malloc(sizeof(node));
  fila->inicio = NULL;
  fila->fim = NULL;
  fila->tamanho = 0;
  return fila;
}

void insereFila (node *fila, int hora, int minuto, int critico){
  Fila *novo = (Fila*) malloc(sizeof(Fila));
  novo->hora = hora;
  novo->minuto = minuto;
  novo->critico = critico;
  novo->prox = NULL;
  if(fila->inicio == NULL){
    fila->inicio = novo;
    fila->fim = novo;
  }else{
    fila->fim->prox = novo;
    fila->fim = novo;
  }
  fila->tamanho++;
}




int main (void){

  int pacientes;

  scanf("%d", &pacientes);

  Fila *fila = criaFila();

  while(pacientes--){
    int h, m, c;
    scanf("%d %d %d", &h, &m, &c);
    insereFila(fila, h, m, c);
  } 

  int n = atendePaciente(fila);

  printf("%d\n", n);

  return 0;
} 