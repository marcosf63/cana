#include "arrays.cpp"
#include "seminario.cpp"
#include "time.h"

int main() {
  // Seminario
  // // Exemplo de ordenação
  // int vetor[7] = {329, 457, 657, 839, 436, 720, 355};
  // printf("\nVetor original: ");
	// imprime_vetor(vetor, 7);
	// radixsort(vetor, 7);
	// printf("\nVetor ordenado: ");
	// imprime_vetor(vetor, 7);


	// // Comparando o radix com outros algoritmos
	// int ti1, tf1, ti2, tf2, ti3, tf3, i, j, *v;
  //
  // // Criando os vetores com tamanho 1000, 10000, 100000
  //
	// int vetores[3] = {1000, 10000, 100000};
  // srand(time(0));
  // printf("        Radix Sort | Buble Sort \n");
  // // printf("        Radix Sort | Insertion Sort\n");
  // for (i = 0; i < 3; i++) {
	// 	v = (int *) calloc(vetores[i], sizeof(vetores[i]));
	// 	for (j= 0; j < vetores[i]; j++)
	// 	  v[j] = rand() % vetores[i];
  //
  //  	ti1 = clock();
	//   radixsort(v, vetores[i]);
	// 	tf1 = clock();
  //
	// 	ti2 = clock();
	// 	bubblesort(v, vetores[i]);
	// 	tf2 = clock();
  //
  //   // ti3 = clock();
	// 	// insertionSort(v, vetores[i]);
	// 	// tf3 = clock();
  //
	// 	printf("        %f      %f \n", (float)(tf1 - ti1) / CLOCKS_PER_SEC, (float)(tf2 - ti2) / CLOCKS_PER_SEC);
  //   // printf("        %f      %f \n", (float)(tf1 - ti1) / CLOCKS_PER_SEC, (float)(tf3 - ti3) / CLOCKS_PER_SEC);
	// }

  //int A[] = {1, 3, 5, 7, 8, 9, 11, 12, 13, 25, 45}, n;

  // n = sizeof(A) / sizeof(int);
  // printf("%d\n", buscabin(A, 0, n - 1, 13));
  //int A[] = {5, 2, 4, 7, 3, 8, 1, 6, 13}, n;
  //n = sizeof(A) / sizeof(int);
  //printf("%d\n", inversoes(A, 0, n - 1));

  //int B[] = {5, 2, 4, 7, 3, 8, 1, 6, 13};
  //mergeSort(B, 0, n - 1);

  //for (int i = 0; i < n; i++){
    //printf("%d ", B[i]);

  //}
  //printf("\n" );

  //int C[] = {5, 2, 4, 7, 3, 8, 1, 6, 13};
  //quickSort(C, 0, n - 1);

  //for (int i = 0; i < n; i++){
    //printf("%d ", C[i]);

  //}
    //printf("\n" );

  //int D[] = {5, 2, 4, 7, 3, 8};int penalizacaoMinima()

  //printf("Min: ");
  //printf("%d ", min(D, 0, 5));
  //printf("\n");


  //int F[] = {1, 2, 1, 7, 3, 8, 8, 4, 7, 2, 2};penalizacaoMinima(int *A, int n; int * B)
  //printf("%d ", duplicata(F, 0, 10));
  //printf("\n");

  //int G[] = {1, 2, 5, 7, 3, 8, 8, 4, 10, 12, 25};
  //printf("%d ", soma_e_x(G, 0, 10, 14));
  //printf("\n");


  //int H[] = {1, 2, 3, 6,  8, 9,  10, 12, 25};
  //printf("buscabin:\n");
  //printf("%d ", buscabin(H, 0, 8, 60));
  //printf("\n");

  int A[] = {0, 180, 210, 320, 400, 450, 560};
  int n = sizeof(A) / sizeof(int);
  int B[n];

  printf("%d\n", penalizacaoMinima(A, n, B));
  //for (int i = 0; i < n; i++)
     //printf(" %d ", B[i]);
  printf("\n");

  //printSolution(A,n,B);
  printf("\n");
  return 0;

}
