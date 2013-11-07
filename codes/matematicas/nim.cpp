#include <cstdio>
 
int main() {
  int N;
  while (scanf("%d", &N) && N) {
    int b = 0;
    while (N--) {
      int v;
      scanf("%d", &v);
      b ^= v;
    }
    puts(b ? "Yes" : "No");
  }
  return 0;
}