#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

typedef long long lli;
typedef pair<int, int> pii;
#define LENGTH(a) ((int)a.length())
#define SIZE(a) ((int)a.size())
int const MAX = 100;
int const INF = 1000000;

class Grafo
{
public:
    vector<vector<int> > L;
    vector<int> num, low;
    vector<bool> visitado;
    vector<int> componente;
    int nComponentes, numCnt;

    Grafo(int n)
    {
        init(n);
    }

    void init(int n)
    {
        L = vector<vector<int> >(n);
        num = vector<int>(n, -1);
        low = vector<int>(n, 0);
        visitado = vector<bool>(n, false);
        componente.clear();
        nComponentes = numCnt = 0;
    }

    void add(int a, int b)
    {
        L[a].push_back(b);
    }

    void ejecutarTarjan()
    {
        for (int i = 0; i < SIZE(L); ++i)
            if (num[i] == -1)
                tarjan(i);
    }

    void tarjan(int u)
    {
        low[u] = num[u] = numCnt++;
        visitado[u] = true;
        componente.push_back(u);
        for (int i = 0; i < SIZE(L[u]); ++i)
        {
            int v = L[u][i];
            if (num[v] == -1)
                tarjan(v);
            if (visitado[v])
                low[u] = min(low[u], low[v]);
        }
        if (num[u] == low[u])
        {
            nComponentes++;
            int v;
            do
            {
                v = componente[SIZE(componente) - 1];
                visitado[v] = false;
                componente.erase(--componente.end());
            }
            while (v != u);
        }
    }
};

int main(){
int nodos;
cin>>nodos;
Grafo g(nodos);
//leer lados
g.ejecutarTarjan();
//g.nComponentes contiene el numero de SCC
return 0;
}

