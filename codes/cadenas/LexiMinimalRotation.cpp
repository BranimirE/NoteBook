#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <utility>
#include <list>
#include <set>
#include <map>
using namespace std;
/*
http://en.wikipedia.org/wiki/Lexicographically_minimal_string_rotation
*/
int Minlex(const char *s, const int slen) {
	int i = 0, j = 1, k = 0, x, y, tmp;
	while(i < slen && j < slen && k < slen) {
		x = i + k;
		y = j + k;
		if(x >= slen)	x -= slen;
		if(y >= slen)	y -= slen;
		if(s[x] == s[y]) {
			k++;
		} else if(s[x] > s[y]) {
			i = j+1 > i+k+1 ? j+1 : i+k+1;
			k = 0;
			tmp = i, i = j, j = tmp;
		} else {
			j = i+1 > j+k+1 ? i+1 : j+k+1;
			k = 0;
		}
	}
	return i;
}

int main(){
	int n;
	scanf("%d",&n);getchar();
	while(n--){
		char str[10009];
		gets(str);
		printf("%d\n",Minlex(str,strlen(str))+1);
	}
}
