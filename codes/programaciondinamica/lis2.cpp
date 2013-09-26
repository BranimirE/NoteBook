#include <algorithm>
#include <cstdio>
#include <stack>
using namespace std;

#define MAX_N 100000

void imprimir(int end, int a[], int p[]) {
  int x = end;
  stack<int> s;
  for (; p[x] >= 0; x = p[x]) s.push(a[x]);
  printf("%d\n", a[x]);
  for (; !s.empty(); s.pop()) printf("%d\n", s.top());
}

int main() {
  int A[MAX_N], L[MAX_N], L_id[MAX_N], P[MAX_N];
  int n, tmp;
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &A[i]);

  int lis = 0, lis_end = 0;
  for (int i = 0; i < n; i++) {
    int pos = lower_bound(L, L + lis, A[i]) - L;
    L[pos] = A[i];
    L_id[pos] = i;//(*) marcamos que posicion es la que estamso guardando
    P[i] = pos ? L_id[pos - 1] : -1;//(*) El padre del i esimo elemento
    if (pos + 1 > lis) {
      lis = pos + 1;
      lis_end = i;
    }
  }
  printf("%d\n", lis);
  imprimir(lis_end, A, P);
  return 0;
}