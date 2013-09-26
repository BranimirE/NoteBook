/*
Nota: 
-Tomar en cuenta que para calcular la fila i solo se necesita la fila i-1 entonces,
si el problema utiliza demasiada memoria o no entra se puede hacer el mismo procedimiento
con solo 2 vectores llenando la fila actual con la fila ya calculada
y luego actual.swap(anterior), para todas la filas

- La version recursiva corre mas rapido por que no es necesario llenar toda la matriz dp
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

long long int d[35], w, lib;
//Para recosntruccion (*)
bool sel[35][1005]; //seleccionados (*)
bool sol[35];//el elemento fue seleccionado (*)
int cant ; // * cantidad de elementos tomados (*)

long long int dp[35][1005], v[35], p[35];//dp[OBJETOS + 1][LIBRE + 1]

long long int mochila(int n, int libre) { //Llamar con mochila(N, libre)
  memset(sel, false, sizeof(sel));
  memset(dp, 0, sizeof(dp));
  for(int i = 1; i <= n; i++)
    for(int j = 1; j<= libre; j++)
      if(p[i-1] <= j) {
        dp[i][j] = max(dp[i-1][j-p[i-1]] + v[i-1], dp[i-1][j]);
        if(dp[i][j] == dp[i-1][j-p[i-1]] + v[i-1])// se selecciono el elemento ? (*)
          sel[i][j] = 1; // marcar (*)
      } else
        dp[i][j] = dp[i-1][j];

  return dp[n][libre];
}
void reconstruir(int n, int libre) {
  int j = libre;
  cant = 0;
  memset(sol, false, sizeof(sol));
  for(int i = n; i >= 1; i--)
    if(sel[i][j] == 1) {
      sol[i-1] = true;
      cant++;
      j = j - p[i-1];
    }
}

int main() {
  int n;

  scanf("%d %lld", &n, &lib);//N objetos y LIV espacio de la mochila
  for(int i = 0; i < n; i++)
    scanf("%lld %lld", &p[i], &v[i]);

  memset(dp, -1, sizeof(dp));
  memset(sel, false, sizeof(sel));//para reconstruccion (*)
  printf("%lld\n", mochila(n, lib));

  reconstruir(n, lib);
  printf("%d\n", cant);
  for(int i = 0; i < n; i++)
    if(sol[i])
      printf("%lld %lld\n", p[i], v[i]);
  return 0;
}
