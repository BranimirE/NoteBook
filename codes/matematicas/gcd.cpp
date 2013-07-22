//Entrada: Dos enteros a y b
//Salida: El maximo comun divisor entre a y b

#include <algorithm>
int gcd (int a, int b){
	__gcd(a,b);
}

int gcd (int a, int b){
	return b==0?a:gcd(b, a % b);
}

int gcd (int a, int b){
	int c = a % b;
	while(c != 0){
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}