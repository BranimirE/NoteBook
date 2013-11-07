/*Permite encontrar los coeficientes (x, y) mas pequenios de:
	ax + by = gcd(a, b);
*/
int x, y;//Al terminar la sol estara aqui
void solve(int a, int b){
	if(b == 0){x = 1; y = 0; d = a; return;}
	solve(b, a % b);
	int x1 = y;
	int y1 = x - (a / b) * y;
	x = x1;
	y = y1;
}