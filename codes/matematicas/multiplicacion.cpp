//Entrada: Una cadena y un numero entero
//Salida: La multiplicacion de la cadena con el numero
#include <iostream>
#include <string.h>

using namespace std;

unsigned int c,i,n;
char res[1000];

void multi(int n){
	for(c = i = 0; res[i]; i++){
		c = (res[ i ] - '0') * n + c;
		res[ i ] = c % 10 + '0';
		c /= 10;
	}
	while( c ){
		res[ i++ ] = '0' + c % 10;
		c /= 10;
	}
	res[i] = 0;
}

int main(){
	string cad;
	int m;

	cin >> cad;
	cad = string(cad.rbegin(), cad.rend());
	strcpy(res, cad.c_str());

	multi(m);
	string r(res);
	string sal(r.rbegin(), r.rend());

	cout << sal << endl;
	return 0;
}
