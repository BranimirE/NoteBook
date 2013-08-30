#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#define f first
#define s second
#define pb push_back
#define mp make_pair
using namespace std;

#define M 1000000000
typedef pair<pair<int,int>,int> P;
int N;
vector <P> v;
int bellmandford(int a, int b){
	vector<int>d(N,M);
	d[a]=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<v.size();j++){
			if(d[v[j].f.f]<M && d[v[j].f.f]+v[j].s < d[v[j].f.s]){
				d[v[j].f.s] = d[v[j].f.f]+v[j].s;
			}
		}
	}
	for(int j=0;j<v.size();j++){
		if(d[v[j].f.f] < M && d[v[j].f.f]+v[j].s < d[v[j].f.s]){
			return -M; /// ciclo negativo
		}
	}
	return d[b];
}
int main(){
	N=5;
	v.pb(mp(mp(0,1),-1));
	v.pb(mp(mp(0,2),0));
	v.pb(mp(mp(1,3),3));
	v.pb(mp(mp(2,1),2));
	v.pb(mp(mp(3,2),-6));
	v.pb(mp(mp(3,4),-3));
	printf("%d\n",bellmandford(0,4));
	return 0;
}
