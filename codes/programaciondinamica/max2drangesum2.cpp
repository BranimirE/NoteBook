#include <algorithm>
#include <cstdio>
using namespace std;

int n, A[101][101] = {0}, maxSubRect, subRect;

int main() {  // O(n^3) 1D DP + greedy (Kadane) solucion
  scanf("%d", &n);            // La dimension de la matriz
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      scanf("%d", &A[i][j]);
      A[i][j] += A[i][j - 1]; // vamos acumulando de fila en fila
    }

  maxSubRect = -127*100*100; // El valor mas bajo para la respuesta
  for (int l = 1; l <= n; l++) 
    for (int r = l; r <= n; r++) {
      subRect = 0;
      for (int row = 1; row <= n; row++) {
        // Max 1D Range Sum en las columnas de la fila i
        subRect += A[row][r] - A[row][l - 1];

        // El algoritmo de Kadane en las filas
        if (subRect < 0) subRect = 0;     // golosamente, reiniciamos si sum < 0
        maxSubRect = max(maxSubRect, subRect);
      } 
    }
  printf("%d\n", maxSubRect);
  return 0;
}
        
