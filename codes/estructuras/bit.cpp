#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 1000000

int T[MAXN + 1];
int A[MAXN];
int N;
int lowbit(int i) {
	return (i & -i);  
}
int sum(int i){
	int value = 0;
	for(; i > 0; i-= lowbit(i)) 
		value+= T[i];
	return value;
}
int sum(int i, int j){
	return i > 1 ? sum(j) - sum(i-1) : sum(j);
}
void update(int i, int value){
	for(; i <= N ; i += lowbit(i))
		T[i] += value;
}
void build(){
	memset(T, 0, sizeof(T));
	for(int i=0; i < N; i++)
		update(i+1, A[i]);
}
int main(){
	cin >> N;
	for(int i = 0; i < N; ++i)	
		cin >> A[i];

	build();
	cout << sum( 1, N ) << endl;
	return 0;
}
