#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
long long int pow(int b, int e){
	if(!e) return 1;

	long long int ans = pow(b, e>>1);
	ans *= ans;

	if(e&1)
		ans *= b;
	return ans;
}

unsigned long long int modpow(long long int b, int e, int m){
	if(!e) return 1;

	unsigned long long int ans = modpow(b, e>>1, m);
	ans = (ans * ans) % m;// cuidado con desborde en la multiplicacion

	if(e&1)
		ans = (ans * b) % m;
	return ans;
}
//podemos utilizar una idea similar para evitar el desborde en la multiplicacion
int multi(long long a, long long b, long long mod){
	if(b == 0) return 0;
	long long int ans = (multi( a, b / 2, mod ) * 2) % mod;
	if( b % 2 == 1 ) ans = (ans + a) % mod;
	return ans;
}

int main(){
	freopen("entrada.in", "r", stdin);
	return 0;
}
