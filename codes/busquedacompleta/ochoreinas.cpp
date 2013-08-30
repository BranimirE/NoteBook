
int sol[10];
bool sePuede(int fila, int col){
	for(int i = col - 1 ; i >= 1; i--)
		if(sol[i] == fila || (abs(sol[i] - fila) == abs(i - col)))
			return false;
	return true;
}
// Llamada solve(1)
void solve(int col){
	if(col == 9){
		for(int i = 1; i <= 8; i++)
			printf(" %d", sol[i]);
		printf("\n");
		return ;
	}
	for(int i = 1; i <= 8; i++)
		if(sePuede(i, col)){
			sol[col] = i;
			solve(col + 1);
		}
}