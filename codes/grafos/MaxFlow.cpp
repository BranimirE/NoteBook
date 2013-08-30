#include <algorithm>
#include <cstring>
#include <cstdio>
#include <limits>
#include <queue>

using namespace std;
 
#define N 1000 //maximo de nodos
//halla el flujo maximo desde el nodo s
//hasta el nodo t
//cap[][] almacena flujos parciales
int cap[N][N], padre[N], n, s, t;
 
bool bfs() {
    queue<int> q;
    q.push(s);
    memset(padre, -1, sizeof padre);
    padre[s] = s;
    while (q.size()) {
        int u = q.front();
        q.pop();
        if (u == t)
            return true;
        for (int v = 0; v < n; ++v)
            if (padre[v] == -1 && cap[u][v])
                padre[v] = u, q.push(v);
    }
    return false;
}
 
int maxFlow() {
    int mf = 0, f, v;
    while (bfs()) {
        
        v = t;
        f = numeric_limits<int>::max();
        while (padre[v] != v)
            f = min(f, cap[padre[v]][v]), v = padre[v];
        
        v = t;
        mf += f;
        while (padre[v] != v)
            cap[padre[v]][v] -= f, cap[v][padre[v]] += f, v = padre[v];
    }
    return mf;
}
 

#define capacidad(i, j, c) cap[i][j] += c, cap[j][i] += c
int main() {
    int c;
        printf("ingrese el numero de nodos\n");
        scanf("%d", &n);
        printf("ingrese el inicio destino y nro nodos");
        memset(cap, 0, sizeof cap);
        scanf("%d %d %d", &s, &t, &c);
        --s, --t;
        printf("ingrese los lados x y & capacidad");
        for (int i = 0, x, y, z; i < c; ++i)
            scanf("%d %d %d", &x, &y, &z), capacidad(x - 1, y - 1, z);
        
        
        printf("el flujo maximo entre s y t es %d\n", maxFlow());
    
    return 0;
}
