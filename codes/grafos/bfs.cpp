#include <queue>
#include <vector>
#include <cstring>

#define MAXN 1000

using namespace std;

vector<int> grafo[MAXN];
int d[MAXN];
queue<int> cola;

void BFS(int ini){
	memset(d,-1, sizeof d);
	cola.push(ini);
	d[ini] = 0;
	while(!cola.empty()){
		int act = cola.front();cola.pop();
		for(int i = 0; i < grafo[act].size(); i++){
			int ady = grafo[act][i];
			if(d[ady] == -1){
				d[ady] = d[act] + 1;
				cola.push(ady);
			}
		}
	}
}