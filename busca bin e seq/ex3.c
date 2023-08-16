#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_MAX 100
#define NUM_CHAVES 50

int buscaBinaria(int *vetor, int tamanho, int chave) {
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

int buscaSequencial(int *vetor, int tamanho, int chave) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == chave) {
            return i;
        }
    }
    return -1;
}

int selectionSort(int *vet, int n) {
    int i, j, min, aux;
    for (i = 0; i < (n - 1); i++) {
        min = i;
        for (j = (i + 1); j < n; j++) {
            if (vet[j] < vet[min]) {
                min = j;
            }
        }
        if (vet[i] != vet[min]) {
            aux = vet[i];
            vet[i] = vet[min];
            vet[min] = aux;
        }
    }
    return 0;
}

void randvet(int *vet, int n) {
    for (int i = 0; i < n; i++) {
        vet[i] = rand() % 1000;
    }
}

int main(void) {
    int *vetor = malloc(N_MAX * sizeof(int));
    int *chave = malloc(NUM_CHAVES * sizeof(int));

    srand(time(NULL)); 

    randvet(vetor, N_MAX);
    randvet(chave, NUM_CHAVES);

    printf("Vetor de numeros:\n");
    for (int i = 0; i < N_MAX; i++) {
        printf("%d ", vetor[i]);
    }
  
    printf("\nVetor de chaves:\n");
    for (int i = 0; i < NUM_CHAVES; i++) {
        printf("%d ", chave[i]);
    }

    printf("\nBusca sequencial:\n");

    clock_t start_seq = clock(); 
    for (int i = 0; i < NUM_CHAVES; i++) {
        int result = buscaSequencial(vetor, N_MAX, chave[i]);
        if (result == -1) {
            printf("O numero nao foi encontrado.\n");
        } else {
            printf("O numero foi encontrado na posicao %d.\n", result);
        }
    }
    clock_t end_seq = clock(); 
    double time_taken_seq = ((double)(end_seq - start_seq)) / CLOCKS_PER_SEC;
    

    selectionSort(vetor, N_MAX);

    printf("Busca binaria:\n");

    clock_t start_bin = clock();
    for (int i = 0; i < NUM_CHAVES; i++) {
        if (buscaBinaria(vetor, N_MAX, chave[i]) == -1) {
            printf("O numero nao foi encontrado.\n");
        } else {
            printf("O numero foi encontrado na posicao %d.\n", buscaBinaria(vetor, N_MAX, chave[i]));
        }
    }
    clock_t end_bin = clock();
    double time_taken_bin = ((double)(end_bin - start_bin)) / CLOCKS_PER_SEC;
    printf("Tempo de busca binaria: %f segundos\n", time_taken_bin);
    printf("Tempo de busca sequencial: %f segundos\n", time_taken_seq);

    free(vetor);
    free(chave);

    return 0;
}
