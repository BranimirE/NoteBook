#define MOD 1000000007
#define MAXN 16

int size;

struct Matrix {
  int X[MAXN][MAXN];
  Matrix () {}
  Matrix (int k) {
    memset(X, 0, sizeof(X));

    for(int i=0; i<size; i++)
      X[i][i] = k;
  }
};

Matrix operator *(Matrix &A, Matrix &B) {
  Matrix M;

  for(int i=0; i<size; i++) {
    for(int j=0; j<size; j++) {
      long long tmp = 0;
      for(int k=0; k<size; k++)
        tmp += (long long)A.X[i][k] * B.X[k][j];
      M.X[i][j] = tmp % MOD;
    }
  }
  return M;
}
Matrix pow(Matrix x, long long n) {
  Matrix P(1);
  while(n) {
    if(n & 1) P = P * x;

    n >>= 1;
    x = x * x;
  }
  return P;
}
long long modpow(long long x, long long n) {
  long long P = 1;

  while(n) {
    if(n & 1) P = P * x % MOD;
    n >>= 1;
    x = x * x % MOD;
  }
  return P;
}
