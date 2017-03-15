#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void radixsort(int vetor[], int tamanho);
void bubblesort( int v[], int qtd );
void insertionSort(int array[], int tamanho);
void imprime_vetor(int vetor[], int tamanho);

int main() {

  // Exemplo de ordenação
  int vetor[7] = {329, 457, 657, 839, 436, 720, 355};
  printf("\nVetor original: ");
	imprime_vetor(vetor, 7);
	radixsort(vetor, 7);
	printf("\nVetor ordenado: ");
	imprime_vetor(vetor, 7);

	// Comparando o radix com outros algoritmos
	int ti1, tf1, ti2, tf2, i, j, *v;

  // Criando os vetores com tamanho 1000, 10000, 100000

	int vetores[3] = {1000, 10000, 100000};
  printf("        Radix Sort | Buble Sort \n");
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

		printf("        %f      %f \n", (float)(tf1 - ti1) / CLOCKS_PER_SEC, (float)(tf2 - ti2) / CLOCKS_PER_SEC);

	}

	return 0;
}


void radixsort(int vetor[], int tamanho) {
    int i;
    int *aux;
    int maior = vetor[0];
    int exp = 1;

    aux = (int *)calloc(tamanho, sizeof(int));

    for (i = 0; i < tamanho; i++) { // Este for procura o maior numero do vetor
        if (vetor[i] > maior)       // para saber a quntidade de digitos
    	    maior = vetor[i];
    }

    while (maior/exp > 0) { // o maior vai ser dividido sucessivamente 1, 10, 100 ... enquanto o resultado for
                            // maior que 0. Assim o while executa d vezes (onde d é a quantidade de digtos do maior)

      int contador[10] = { 0 }; // Inicializa o contador zero em todas as posições

      for (i = 0; i < tamanho; i++) // Incrementa a contadador na posicao igual ao digito (vetor[i] / exp) % 10
    	    contador[(vetor[i] / exp) % 10]++; // ou seja, se d = 5, incrementa a posição contador[5]

    	for (i = 1; i < 10; i++)  // A partir do segundo elemento do vetor contador, soma com o valor anterior
    	    contador[i] += contador[i - 1]; // para saber quantidade de elementos menores

    	for (i = tamanho - 1; i >= 0; i--) // Encontra a posição do elemento na passagem decrementando contador
    	    aux[--contador[(vetor[i] / exp) % 10]] = vetor[i]; // e transfere para vetor auxiliar

    	for (i = 0; i < tamanho; i++) // Retorno os valores ao vetor original
    	    vetor[i] = aux[i];
    	exp *= 10;
      // Este processo se repete para cada digito
    }

    free(aux);
}

// Para digito cada d ele irá fazer o counting sort
// que tem uma complexidade ⊝(n + k) e considerando que
// o valor de k é fixo e pequeno temos que a complexidade
// do counting sorte no radix pode ser expressa como ⊝(n)
// assim temos que a complexidade do radix é ⊝(dn)

void bubblesort( int v[], int qtd )
{
  int i;
  int j;
  int aux;
  int k = qtd - 1 ;

  for(i = 0; i < qtd; i++)
  {
     for(j = 0; j < k; j++)
     {
        if(v[j] > v[j+1])
        {
            aux = v[j];
        v[j] = v[j+1];
        v[j+1]=aux;
        }
     }
     k--;
  }
}

void insertionSort(int array[], int tamanho) {
      int i, j, tmp;
      for (i = 1; i < tamanho; i++) {
            j = i;
            while (j > 0 && array[j - 1] > array[j]) {
                  tmp = array[j];
                  array[j] = array[j - 1];
                  array[j - 1] = tmp;
                  j--;
            }
      }
}


void imprime_vetor(int vetor[], int tamanho) {
   printf("\nVetor: ");

	 for (int i = 0; i < tamanho; i++)
		 printf("%d ", vetor[i]);

	 printf("\n\n");
}
