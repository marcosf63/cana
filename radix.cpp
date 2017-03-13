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
    	for (i = 0; i < tamanho; i++)
    	    contador[(vetor[i] / exp) % 10]++;    //dn  vezes
    	for (i = 1; i < 10; i++)
    	    contador[i] += contador[i - 1];       // dk vezes - depende da base
    	for (i = tamanho - 1; i >= 0; i--)
    	    aux[--contador[(vetor[i] / exp) % 10]] = vetor[i]; // dn  vezes
    	for (i = 0; i < tamanho; i++)  //dn  vezes
    	    vetor[i] = aux[i];
    	exp *= 10;                     //d vezes
    }

    free(aux); // d vezes
}

Complexide
// 5 + 3n + 2dn + dk + 2d
// Usando a tecnica
// n + dn + dk + d
//n + d(n + k + 1)
//n + d(n + k) = n + dn + dk = n (1 + d) + dk = dn + dk
// d(n + k)
// https://github.com/marcosf63/cana


void imprime_vetor(int vetor[], int tamanho) {
   printf("\nVetor: ");

	 for (int i = 0; i < tamanho; i++)
		 printf("%d ", vetor[i]);

	 printf("\n\n");
}
