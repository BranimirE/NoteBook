#define MAX 1001
#define pain 64
int n;
int mat[MAX][MAX];
bool visitado[MAX][MAX];
int di[]={1,1, 1,-1,-1,-1,0, 0};
int dj[]={1,0,-1, 1, 0,-1,1,-1};

void ff_dfs(int i, int j) {
	visitado[i][j] = true;
	for(int k=0; k<8; k++) {
		int a = di[k] + i;
		int b = dj[k] + j;
		if(a >= 0 && b >= 0 && a < n && b < n &&!visitado[a][b]) {
			if(mat[a][b]==pain) ff_dfs(a,b);
			else visitado[a][b]=true;
		}
	}
}
