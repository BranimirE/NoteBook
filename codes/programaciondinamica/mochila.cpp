/*
Nota:
Si los pesos son muy grandes o el valor de llenar la mochila es muy grande
se puede utilizar un map en vez de una matriz para la memoizacion
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

long long int lib;

bool sel[35][1005], sol[35];//para reconstruccion (*)
int cant ; // * cantidad de elementos tomados

long long int dp[35][1005], v[35], p[35];//dp[OBJETOS + 1][LIBRE + 1]
long long int mochila(int i, int libre) { // Llamar mochila(N-1, libre)
  if(i < 0)return 0LL;
  long long int &ans = dp[i][libre];
  if(ans != -1) return ans;
  ans = mochila(i-1, libre);// no lo tomo
  if(p[i] <= libre) { // si cabe en el espacio disponible
    ans = max(ans ,v[i] + mochila(i-1, libre - p[i])); // pruebo si lo tomaria
    if(ans ==  v[i] + mochila(i-1, libre - p[i]))//si se tomo el objeto (*)
      sel[i][libre] = true;// marco como tomado (*)
  }
  return ans;
}

//* Marca en el vector sol[ELEMEMTOS] los elementos que fueron tomados
void reconstruir(int i, int libre) {
  if(i < 0) return;
  if(sel[i][libre]) { //si fue seleccionado
    sol[i] = true;//marco
    cant++;
    reconstruir(i-1, libre - p[i]);
  } else
    reconstruir(i-1, libre);
}

int main() {
  int n;
  scanf("%d %lld", &n, &lib);
  for(int i = 0; i < n; i++)
    scanf("%lld %lld", &p[i], &v[i]);
  memset(dp, -1, sizeof(dp));
  memset(sel, false, sizeof(sel));//para la reconstruccion (*)
  printf("%lld\n", mochila(n-1, lib));
  // imprimir los elementos
  memset(sol, false, sizeof(sol));
  cant = 0;
  reconstruir(n-1, lib);
  printf("%d\n", cant);
  for(int i = 0; i < n; i++)
    if(sol[i])
      printf("%lld %lld\n", p[i], v[i]);
  return 0;
}
