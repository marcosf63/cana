#include "stdio.h"
#include "stdlib.h"

void radixsort(int vetor[], int tamanho);
void imprime_vetor(int vetor[], int tamanho);

int main() {
	int v[5] = {123,456,56,78,390};

	radixsort(v, 5);

  imprime_vetor(v, 5);

	return 0;
}


void radixsort(int vetor[], int tamanho) {
    int i;   // 1 vez
    int *aux;  // 1 vez
    int maior = vetor[0];  // 1 vez
    int exp = 1; // 1 vez

    aux = (int *)calloc(tamanho, sizeof(int)); // 1 vez

    for (i = 0; i < tamanho; i++) { // 2n  vezes
        if (vetor[i] > maior)       // n  vezes
    	    maior = vetor[i];
    }

    while (maior/exp > 0) {                     //d  vezes - quantidade de dígitos
        int contador[10] = { 0 };
    	for (i = 0; i < tamanho; i++)             //2n
    	    contador[(vetor[i] / exp) % 10]++;    //n  vezes
    	for (i = 1; i < 10; i++)                  //2k
    	    contador[i] += contador[i - 1];       // k vezes - depende da base
    	for (i = tamanho - 1; i >= 0; i--)        // 2n
    	    aux[--contador[(vetor[i] / exp) % 10]] = vetor[i]; // n  vezes
    	for (i = 0; i < tamanho; i++)  //2n  vezes
    	    vetor[i] = aux[i];        // n
    	exp *= 10;                     //
    }

    free(aux); // 1
}

//Complexidade
// Considerando somente o que está dentro do while
//  2n + n + 2k + k + 2n + n + 2n + n = 9n + 3k
// Logo a complexidade do que está dentro do while é:
// O(n + k)
// Como o laço while vai executar d vezes temos
// O(d(n + k))

// Cógido está:
// https://github.com/marcosf63/cana


void imprime_vetor(int vetor[], int tamanho) {
   printf("\nVetor: ");

	 for (int i = 0; i < tamanho; i++)
		 printf("%d ", vetor[i]);

	 printf("\n\n");
}
