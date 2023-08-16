#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int elementos[100];
    int tamanho;
} Integer;
int buscarElemento(Integer *conjunto, int elemento);

int uniao(Integer *conjunto1, Integer *conjunto2);

int interseccao(Integer *conjunto1, Integer *conjunto2);


int main() {
    int elementos, i;

    scanf("%d", &elementos);

    Integer conjunto1;
    conjunto1.tamanho = elementos;

    for (i = 0; i < elementos; i++){
        scanf("%d", &conjunto1.elementos[i]);
    }

    int elementos2;

    scanf("%d", &elementos2);

    Integer conjunto2;
    conjunto2.tamanho = elementos2; 

    for (i = 0; i < elementos2; i++){
        scanf("%d", &conjunto2.elementos[i]);
    }

    int testes;

    scanf("%d", &testes);

    int p, input, result;
    int *vet;

    while (testes--){
        scanf("%d", &p);
        
        switch (p){
            case 1:
                scanf("%d", &input);
                result = buscarElemento(&conjunto1, input);
                if (result == 1)
                    printf("S\n");
                else
                    printf("N\n");
                break;
                
            case 2:
                scanf("%d", &input);
                result = buscarElemento(&conjunto2, input);
                if (result == 1)
                    printf("S\n");
                else
                    printf("N\n");
                break;
                
            case 3:
                uniao(&conjunto1, &conjunto2);
                printf("\n");
                break;
                
            case 4:
                interseccao(&conjunto1, &conjunto2);
                printf("\n");
                break;
        }
    }

    return 0;

}

int buscarElemento(Integer *conjunto, int elemento){
    int i;
    for (i = 0; i < conjunto->tamanho; i++){
        if (conjunto->elementos[i] == elemento){
            return 1;
        }
    }
    return 0;
}
int uniao(Integer *conjunto1, Integer *conjunto2){
    int i, j;
    int tamanho = conjunto1->tamanho + conjunto2->tamanho;
    int *uniao = malloc(sizeof(int) * tamanho);
    for (i = 0; i < conjunto1->tamanho; i++){
        uniao[i] = conjunto1->elementos[i];
    }
    for (j = 0; j < conjunto2->tamanho; j++){
        uniao[i] = conjunto2->elementos[j];
        i++;
    }
    for (i = 0; i < tamanho; i++){
        for (j = i + 1; j < tamanho; j++){
            if (uniao[i] == uniao[j]){
                uniao[j] = uniao[tamanho - 1];
                tamanho--;
                j--;
            }
        }
    }
    for (i = 0; i < tamanho; i++){
        for (j = i + 1; j < tamanho; j++){
            if (uniao[i] > uniao[j]){
                int aux = uniao[i];
                uniao[i] = uniao[j];
                uniao[j] = aux;
            }
        }
    }
    for (i = 0; i < tamanho; i++){
       printf("%d ", uniao[i]);
    }
    return 0;
}
int interseccao(Integer *conjunto1, Integer *conjunto2){
    int i, j;
    int tamanho = conjunto1->tamanho + conjunto2->tamanho;
    int *interseccao = malloc(sizeof(int) * tamanho);
    int indice = 0;
    for (i = 0; i < conjunto1->tamanho; i++){
        for (j = 0; j < conjunto2->tamanho; j++){
            if (conjunto1->elementos[i] == conjunto2->elementos[j]){
                interseccao[indice] = conjunto1->elementos[i];
                indice++;
            }
        }
    }
    for (i = 0; i < indice; i++){
       printf("%d ", interseccao[i]);
    }
    return 0;
}