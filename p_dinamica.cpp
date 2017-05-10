void radixsort(int vetor[], int tamanho);
void bubblesort( int v[], int qtd );
void insertionSort(int vetor[], int tamanho);
void imprime_vetor(int vetor[], int tamanho);
void mergeSort(int *, int , int);
void merge(int *, int, int, int);
int buscabin(int *, int, int, int);
int inversoes(int *, int, int);
int inversoesMerge(int *, int, int, int);
int particione(int *, int, int);
int quickSort(int *, int, int);
int min(int *, int, int);
int minimo(int, int);
int duplicata(int *, int, int);
int soma_e_x(int *, int, int, int);
int buscabin(int *, int, int, int);
int penalizacaoMinima(int *, int, int *);
void printSolution(int *, int, int *);

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

// int buscabin(int *A, int p, int r, int v) {
//    if (p < r) {
//
//      int q = (p + r) / 2;
//
//      if (A[q] == v) {
//
//        return q + 1;
//
//      } else {
//
//         if (A[q] > v){
//           return buscabin(A, p, q - 1, v);
//         } else {
//           return buscabin(A, q + 1, r, v);
//         }
//
//      }
//
//    } else {
//      if (A[p] == v)
//        return p + 1;
//      else
//        return -1;
//    }
// }


int inversoes(int *A, int p, int r) {
  int il, ir, it, q;
  if (p < r) {
    q = (p + r) / 2;
    il = inversoes(A, p , q);
    ir = inversoes(A, q + 1, r);
    it = inversoesMerge(A, p, q, r);
    return il + ir + it;
  } return 0;


}
int inversoesMerge(int *A, int p, int q, int r) {
  int i, j;
  int nl = q - p + 1;
  int nr = r - q;

  int * L = (int *)calloc(nl, sizeof(int));
  int * R = (int *)calloc(nr, sizeof(int));


  for (int i = p; i <= q; i++)
    L[i - p] = A[i];

  for (int j = q + 1; j <= r; j++)
    R[j - q - 1] = A[j];

  int inv = 0;

  i = j = 0;

  for (int k = p; k <= r; k++)
    if (i < nl && (j == nr || R[j] >= L[i])) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
      inv = inv + nl - i;
    }
 return inv;

}

void mergeSort(int *A, int p, int r) { //T(n)
  int q;
  if (p < r) {
    q = (p + r) / 2;                        // ⊝(1)
    mergeSort(A, p, q);                 // T(n/2)
    mergeSort(A, q + 1, r);             // T(n/2)
    merge(A, p, q, r);                  // ⊝(n)
  }
}

// Assim temos: T(n) = 2T(n/2) + ⊝(n)
// Pelo teorema mestre temos: T(n) = ⊝(n log n)

void merge(int * A, int p, int q, int r) { // ⊝(n)
  int nl, nr, *L, *R, i, j, k;
  nl = q - p + 1;
  nr = p + r;
  L = (int *)calloc(nl, sizeof(int));
  R = (int *)calloc(nl, sizeof(int));

  for (i = p; i <= q; i++)
    L[i - p] = A[i];

  for (i = q + 1; i <= r; i++)
    R[i - q - 1] = A[i];

  i = j = 0;

  for (k = 0; k <= r; k++)
    if ( (i < nl)  &&  ( (j = nr) || (R[j] >= L[i]) ) ) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }

}

int particione(int *A, int p, int r) {
   int i, j;
   i = p - 1;

   for (j = p; j < r; j++)
     if (A[j] <= A[r]) {
       i++;
       troca(A[i], A[j]);
     }

   i++;
   troca(A[i], A[r]);
   return i;
}
int quickSort(int *A, int p, int r) {
  int q;
  if (p < r) {
    q = particione(A, p, r);
    quickSort(A, p, q - 1);
    quickSort(A, q + 1, r);
  }
}

int min(int *A, int p, int r ) { // T(n)
  int q;
  if (p > r) {
    q = (p + r) / 2;
    int ml = min(A, p, q); //T(n/2)
    int mr = min(A, q + 1, r); // T(n/2)
    if (ml <= mr) // ⊝(1)
      return ml;
    else
      return mr;
  } else{
    return A[p];
  }

}

int duplicata(int *A,int p, int r) {
  int i, j, d = 0;
  quickSort(A, p , r);
  i = 0;
  for (j = i + 1; j <= r; j++) {
    if (A[i] == A[j])
     d++;
    i++;
  }

  return d;
}

int soma_e_x(int *A, int p, int r, int x) {
  int i, j;
  quickSort(A, p , r);
  i = p;
  j = r;
  while (i < j) {
    if (A[i] + A[j] == x)
      return 1;
    else
      if (A[i] + A[j] > x)
        j--;
      else
        i++;
  }
  return 0;
}

//int buscabin(int *A, int p, int r, int v) {
  //int q;
  //if (p < r) {
    //q = (p + r) / 2;
    //if (A[q] == v)
      //return q + 1;
    //else
      //if (A[q] > v)int penalizacaoMinima()
//int penalizacaoMinima()

        //return buscabin(A, p, q - 1, v);
      //else
        //return buscabin(A, q + 1, r, v);
  //} else {
    //if (A[p] == v)
      //return p + 1;
    //else
      //return -1;
  //}
//}

int penalizacaoMinima(int *A, int n, int * B) {
	int i, k , q, P[n];

	P[0] = 0;
	B[0] = 0;

	for (i = 1; i < n; i++) {
		P[i] = abs(200- A[i]);

		for ( k = 1; k < i; k++) {
			q = P[k] + abs(200 - A[i] + A[k]);

			if (q < P[i]) {
				P[i] = q;
				B[i] = k;
			}
		}

	}

	return P[n - 1];
}

void printSolution(int * A, int n, int * B) {

	if (n > 0) {

		printSolution(A, B[n], B);
		printf(" %dkm", B[n]);

	}

}
