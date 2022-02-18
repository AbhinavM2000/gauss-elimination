#include<stdio.h>

#include<stdlib.h>

void main() {
  int i, j, k, n;
  float A[50][50], c, x[10], s = 0.0;
  printf("\nEnter the order of coefficient matrix: ");
  scanf("%d", & n);
  printf("\nEnter the augmented matrix row-wise:\n\n");
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= (n + 1); j++) {
      printf("A[%d][%d] : ", i, j);
      scanf("%f", & A[i][j]);
    }
  }
  for (j = 1; j <= n; j++) //generating upper triangular matrix
  {
    if (A[j][j] == 0.0) {
      printf("Incosistent system, please try another matrix\n");
      exit(0);
    }

    for (i = 1; i <= n; i++) {
      if (i > j) {
        c = A[i][j] / A[j][j];
        for (k = 1; k <= n + 1; k++) {
          A[i][k] = A[i][k] - c * A[j][k];
        }
      }
    }
  }
  x[n] = A[n][n + 1] / A[n][n];
  //Back substitution
  for (i = n - 1; i >= 1; i--) {
    s = 0;
    for (j = i + 1; j <= n; j++) {
      s = s + A[i][j] * x[j];
    }
    x[i] = (A[i][n + 1] - s) / A[i][i];
  }
  printf("\nThe solution of the system is: \n");
  for (i = 1; i <= n; i++) {
    printf("\nx%d=%f\t", i, x[i]);
  }

  printf("\n");
}
