#include <cstdio>
#include <iostream>
#include <cstring>

#define MAXIN 1000001

using namespace std;

struct Lectura{
	char buf[MAXIN];
	int i, tam;
	Lectura(){
		i = 0;
		tam = 0;
	}
	
	int nextInt(){
		// nos deshacemos de los no digitos
		while( true ){
			while(buf[i] != '\0' && !isdigit(buf[i]))i++;
			if(i == tam){
				gets(buf);
				tam = strlen(buf);
				i = 0;
			}
		}
		int ans = 0;
		while(buf[i] != '\0' && isdigit(buf[i])){
			ans = ans * 10 + (buf[i]-'0');
			i++;
		}
		return ans;
	}
};

int main(){
	Lectura in;
	while(true){
		int var = in.nextInt();
		cout << var << endl;
	}
	return 0;
}
