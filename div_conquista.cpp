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
  // Assim temos: T(n) = 2T(n/2) + ⊝(n)
  // Pelo teorema mestre temos: T(n) = ⊝(n log n)
}


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
