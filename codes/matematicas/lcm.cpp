//Entrada: Dos enteros a y b
//Salida: El minimo comun multiplo entre a y b
int lcm (int a, int b) {
	return a / gcd (a, b) * b;
}