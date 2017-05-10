#include "arrays.cpp"
void radixsort(int vetor[], int tamanho);
void bubblesort( int v[], int qtd );
void insertionSort(int vetor[], int tamanho);
void imprime_vetor(int vetor[], int tamanho);

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

    // Para digito cada d ele irá fazer o counting sort
    // que tem uma complexidade ⊝(n + k) e considerando que
    // o valor de k é fixo e pequeno temos que a complexidade
    // do counting sorte no radix pode ser expressa como ⊝(n)
    // assim temos que a complexidade do radix é ⊝(dn)
}



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

void insertionSort(int vetor[], int tamanho) {
      int i, j, chave;
      for (i = 1; i < tamanho; i++) {
          j = i - 1;
          chave = vetor[i];
          while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
          }
          vetor[j + 1] = chave;
      }
}


void imprime_vetor(int vetor[], int tamanho) {
   printf("\nVetor: ");

	 for (int i = 0; i < tamanho; i++)
		 printf("%d ", vetor[i]);

	 printf("\n\n");
}
