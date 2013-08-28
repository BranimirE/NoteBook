#include <stack>
#include <queue>
#include <vector>
#include <cstring>

#include <map>
#include <cstdio>
#include <iostream>

using namespace std;

/*
Algoritmo de Kosaraju para
Componentes Fuertemente Conexas
*/

#define MAX_V 1000

int V,num_scc;
vector< vector<int> > G;
vector< vector<int> > GT;
bool visited[MAX_V];
stack<int> S;
queue<int> Q;

void dfs(int v){
    visited[v] = true;
    
    for(int i=G[v].size()-1;i>=0;--i)
        if(!visited[G[v][i]])
            dfs(G[v][i]);
    
    S.push(v);
}

void bfs(int v){
    Q.push(v);
    visited[v] = true;
    
    int aux;
    
    while(!Q.empty()){
        aux = Q.front();
        Q.pop();
        
        for(int i=GT[aux].size()-1;i>=0;i--){
            if(!visited[GT[aux][i]]){
                Q.push(GT[aux][i]);
                visited[GT[aux][i]] = true;
            }
        }
    }
}
void SCC(){
    memset(visited,false,sizeof(visited));
    
    for(int i=0;i<V;++i) if(!visited[i]) dfs(i);
    
    num_scc = 0;
    int aux;
    
    memset(visited,false,sizeof(visited));
    
    for(int i=0;i<V;++i){
        aux = S.top();
        S.pop();
        
        if(!visited[aux]){
            bfs(aux);
            ++num_scc;
        }
    }
}

int main(){
    int E,u,v;
    string s;
    map<string, int> num;
    
    while(true){
        scanf("%d %d",&V,&E);
        if(V==0) break;
        
        getline(cin,s);
        num.clear();
        
        for(int i=0;i<V;++i){
            getline(cin,s);
            num[s] = i;
        }
        
        G.clear(); G.resize(V);
        GT.clear(); GT.resize(V);
        
        for(int i=0;i<E;++i){
            getline(cin,s);
            u = num[s];
            getline(cin,s);
            v = num[s];
            
            G[u].push_back(v);
            GT[v].push_back(u);
        }
        
        SCC();
        
        printf("%d\n",num_scc);
    }
    
    return 0;
}
