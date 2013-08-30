int dp[100][100]; //grafo matriz de ady

void floyd_warshall(){
   for(int k=1;k<=n;k++)
      for(int i=1;i<=n;i++)
         for(int j=1;j<=n;j++)
            dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]);
}

