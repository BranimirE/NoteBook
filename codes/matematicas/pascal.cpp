#define MAXN 100 // largest n or m

int n,m;
long binomial_coefficient(n,m){
	int i,j;
	long bc[MAXN][MAXN];
	for (i=0; i<=n; i++) bc[i][0] = bc[i][i]  = 1;
	for (i=1; i<=n; i++)
		for (j=1; j<i; j++)
			bc[i][j] = bc[i-1][j-1] + bc[i-1][j];
	return bc[n][m];

}
