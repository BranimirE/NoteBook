void subMatriz_con_sumaMaxima(int m[n][n]){
	for(int i = 1; i <= n; i++){
		vector<int> vc(n + 1,0);//para aplicar DP magico
		for(int j = i; j <= n; j++){
			mn_temp = n * n;
			for(int k = 1; k <= n; k++)
				vc[k] += m[j][k];

			dp[0] = 0;
			for(int i = 1; i <= n;i++){
				dp[i] = max(vc[i], dp[i-1] + vc[i]);
				if(res < dp[i])
					res = dp[i];
			}
		}
	}
	
	printf("%d\n",res);
}	
