#include "seminario.cpp"
#include "time.h"

int main() {
  // Exemplo de ordenação
  int vetor[7] = {329, 457, 657, 839, 436, 720, 355};
  printf("\nVetor original: ");
	imprime_vetor(vetor, 7);
	radixsort(vetor, 7);
	printf("\nVetor ordenado: ");
	imprime_vetor(vetor, 7);


	// Comparando o radix com outros algoritmos
	int ti1, tf1, ti2, tf2, ti3, tf3, i, j, *v;

  // Criando os vetores com tamanho 1000, 10000, 100000

	int vetores[3] = {1000, 10000, 100000};
  srand(time(0));
  printf("        Radix Sort | Buble Sort \n");
  // printf("        Radix Sort | Insertion Sort\n");
  for (i = 0; i < 3; i++) {
		v = (int *) calloc(vetores[i], sizeof(vetores[i]));
		for (j= 0; j < vetores[i]; j++)
		  v[j] = rand() % vetores[i];

   	ti1 = clock();
	  radixsort(v, vetores[i]);
		tf1 = clock();

		ti2 = clock();
		bubblesort(v, vetores[i]);
		tf2 = clock();

    // ti3 = clock();
		// insertionSort(v, vetores[i]);
		// tf3 = clock();

		printf("        %f      %f \n", (float)(tf1 - ti1) / CLOCKS_PER_SEC, (float)(tf2 - ti2) / CLOCKS_PER_SEC);
    // printf("        %f      %f \n", (float)(tf1 - ti1) / CLOCKS_PER_SEC, (float)(tf3 - ti3) / CLOCKS_PER_SEC);
	}
  return 0;

}
