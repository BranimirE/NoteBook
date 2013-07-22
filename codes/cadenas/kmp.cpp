//Entrada: Una cadena S y el patron k 
//Salida: El numero de ocurrencia del patron k en S
int KMP(string S, string K)
{
	vector<int> T(K.size() + 1, -1);
	for(int i = 1; i <= K.size(); i++)
	{
		int pos = T[i - 1];
		while(pos != -1 && K[pos] != K[i - 1]) pos = T[pos];
		T[i] = pos + 1;
	}
	vector<int> matches;
	int sp = 0;
	int kp = 0;
	while(sp < S.size())
	{
		while(kp != -1 && (kp == K.size() || K[kp] != S[sp])) kp = T[kp];
		kp++;
		sp++;
		if(kp == K.size()) matches.push_back(sp - K.size());
	}
	/* En el vector matches se guardan los índices a cada una de las ocurrencias, por tanto el tamaño de dicho vector nos dirá cuántas ocurrencias se han encontrado. */
	return matches.size();
}
