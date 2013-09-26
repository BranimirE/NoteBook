
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long int> v;
vector<long long int> ancho;
vector<long long int> dp;
int t, n;
long long int lis(int i) {
  if(i == 0)return ancho[0];//(*) si no es pesado 1
  long long int ans = dp[i];
  if(ans != -1LL) return ans;
  ans = ancho[i];//(*) 1
  for(int j = 0; j < i; j++)
    if(v[j] < v[i]) // si no es estrictamente creciente "<="
      ans = max(ans, ancho[i] + lis(j)); // 1 + lis(j)
  return dp[i] = ans;
}
int solve() {
  (vector<long long int>(n, -1LL)).swap(dp);
  long long int ans = 0;
  for(int i = n-1; i >= 0; i--)
    ans = max(ans, lis(i));
  return ans;
}

int main() {
    scanf("%d", &n);
    (vector<long long int>(n)).swap(v);
    (vector<long long int>(n)).swap(ancho);
    for(int i = 0; i < n; i++)
      scanf("%lld", &v[i]);
    for(int i = 0; i < n; i++)//si es pesado
      scanf("%lld", &ancho[i]);//
    printf("lis = %d\n", solve());
  return 0;
}
