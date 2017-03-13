#include "stdio.h"
#include "stdlib.h"

typedef int*   vetor;
typedef int**  mat2D;
typedef int*** mat3D;

vetor AlocaVetor(int tam);
mat2D AlocaMatriz2D(int lin, int col);
mat3D AlocaMatriz3D(int lin, int col, int prf);

vetor   AlocaVetor(int tam) {
  vetor v;

  v = (vetor) calloc(tam, sizeof(int));
  return v;
}

mat2D AlocaMatriz2D(int lin, int col) {
  int i, j;
  mat2D v = (mat2D) calloc(lin, sizeof(vetor));

  for (i = 0; i < lin; i++)
    v[i] = (vetor) calloc(col, sizeof(int));

  return v;
};

mat3D AlocaMatriz3D(int lin, int col, int prf) {
  int i, j;
  mat3D v = (mat3D) calloc(lin, sizeof(mat2D));

  for (i = 0; i < lin; i++) {
    v[i] = (mat2D) calloc(col, sizeof(vetor));

    for (j = 0; j < col; j++)
      v[i][j] = (vetor) calloc(prf, sizeof(int));
  }

  return v;
};
