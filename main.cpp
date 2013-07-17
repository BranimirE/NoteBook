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

	unsigned long long int ans = pow(b, e>>1);
	ans = (ans * ans) % m;

	if(e&1)
		ans = (ans * b) % m;
	return ans;
}

int main(){
	freopen("entrada.in", "r", stdin);

	return 0;
}
