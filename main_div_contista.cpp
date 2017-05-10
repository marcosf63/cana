#include "arrays.cpp"
#include "seminario.cpp"
#include "time.h"

int main() {
  //int A[] = {1, 3, 5, 7, 8, 9, 11, 12, 13, 25, 45}, n;

  // n = sizeof(A) / sizeof(int);
  // printf("%d\n", buscabin(A, 0, n - 1, 13));
  //int A[] = {5, 2, 4, 7, 3, 8, 1, 6, 13}, n;
  //n = sizeof(A) / sizeof(int);
  //printf("%d\n", inversoes(A, 0, n - 1));

  int B[] = {5, 2, 4, 7, 3, 8, 1, 6, 13};
  mergeSort(B, 0, n - 1);

  for (int i = 0; i < n; i++){
    printf("%d ", B[i]);

  }
  printf("\n" );

  int C[] = {5, 2, 4, 7, 3, 8, 1, 6, 13};
  quickSort(C, 0, n - 1);

  for (int i = 0; i < n; i++){
    printf("%d ", C[i]);

  }
  printf("\n" );

  int D[] = {5, 2, 4, 7, 3, 8};

  printf("Min: ");
  printf("%d ", min(D, 0, 5));
  printf("\n");


  int F[] = {1, 2, 1, 7, 3, 8, 8, 4, 7, 2, 2};
  printf("%d ", duplicata(F, 0, 10));
  printf("\n");

  int G[] = {1, 2, 5, 7, 3, 8, 8, 4, 10, 12, 25};
  printf("%d ", soma_e_x(G, 0, 10, 14));
  printf("\n");


  //int H[] = {1, 2, 3, 6,  8, 9,  10, 12, 25};
  //printf("buscabin:\n");
  //printf("%d ", buscabin(H, 0, 8, 60));
  //printf("\n");

  return 0;

}
