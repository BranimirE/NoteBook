#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>

#define clr(a)  memset(a,0,sizeof(a))
#define pb push_back
using namespace std;
/*
Finding Strongly Connected Components
*/
vector<int>grafo[N];
vector<int>gaux;
bool visitado[N];
void dfs(int u){
	visitado[u]=true;
	for(int i=0;i<grafo[u].size();i++){
		if(!visitado[grafo[u][i]]) dfs(grafo[u][i]);
	}
}
int main(){
	//r(input);
	int t;
	int x,y;
	int n,m;
	sc("%d",&t);
	while(t--){
		sc("%d %d",&n,&m);
		clr(visitado);
		for(int i=0;i<=n;i++)   grafo[i].clear();
			gaux.clear();
		while(m--){
			sc("%d %d",&x,&y);
			grafo[x].pb(y);
		}
		int M=0;
		for(int i=1;i<=n;i++){
			if(!visitado[i]){ 
				dfs(i),gaux.pb(i);
			}
		}
		clr(visitado);
		M=0;
		for(int i=gaux.size()-1;i>=0;i--){
			if(!visitado[gaux[i]]){
				dfs(gaux[i]);
				M++;
			}
		}
		cout<<M<<endl;
	}
}
