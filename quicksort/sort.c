#include <stdlib.h>
#include <stdio.h>

int partition (int *A, int p, int r);
void QuickSort(int* A, int p, int r);

void QuickSort(int* A, int p, int r){
   if (p < r) {
      int q = partition(A, p, r);
      printf("%d\n", q); // 
      QuickSort(A, p, q-1);
      QuickSort(A, q+1, r); 
   }
}
int partition (int *A, int p, int r){
   int aux, pivo = A[r], i = p;
   for (int j = p; j <= r - 1; j++) {
      if (A[j] <= pivo) {
         aux = A[i];
         A[i] = A[j];
         A[j] = aux;
         i++;
      }
   }
   A[r] = A[i];
   A[i] = pivo;
   return i;
}

int main(void){

  int vet[9];

  for(int i = 0; i < 9; i++){
    scanf("%d", &vet[i]);
  }
  
  QuickSort(vet, 0, 8);

  for(int i = 0; i < 9; i++){
    printf("%d ", vet[i]);
  }

  return 0;
}