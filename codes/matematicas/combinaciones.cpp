unsigned long long C(int n, int k) {
	k = min(k,n-k);
	unsigned long long res = 1;
	for(int i = 0; i < k; i++)
	{
		res *= (n-i);
		res /= (i+1);
	}
	return res;
}
