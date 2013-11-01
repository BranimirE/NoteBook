#include <cstdio>
#include <list>
#include <queue>

//Emparejamiento Bipartito hasta 50000 nodos y 150000 caminos :) crazy...

using namespace std;
//MAX_N y SINK son mayores al numero de nodos
const int SINK = 50001;
const int MAX_N = 50005;
const int INFINITO = 87654321;

int N, M, P;
int grafo1[MAX_N], grafo2[MAX_N], dist[MAX_N];
list< int > adj[MAX_N];

bool bfs() {
    queue< int > q; // cola de G1 nodes

    for (int v = 0; v < N; ++v) {
        if (grafo1[v] == SINK) {
            dist[v] = 0;
            q.push(v);
        }
        else {
            dist[v] = INFINITO;
        }
    }
    dist[SINK] = INFINITO;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (dist[v] < dist[SINK]) {
            for (list< int >::iterator it = adj[v].begin(); it != adj[v].end(); ++it) {
                int u = *it;

                if (dist[grafo2[u]] == INFINITO) {
                    dist[grafo2[u]] = dist[v] + 1;
                    q.push(grafo2[u]);
                }
            }
        }
    }
    return dist[SINK] != INFINITO;
}

bool dfs(int u) {
    // DFS comienza en el nodo u de G1

    if (u == SINK) {
        return true;
    }

    for (list< int >::iterator it = adj[u].begin(); it != adj[u].end(); ++it) {
        int v = *it;

        if (dist[grafo2[v]] == dist[u] + 1) {
            if (dfs(grafo2[v])) {
                grafo1[u] = v;
                grafo2[v] = u;
                return true;
            }
        }
    }
    dist[u] = INFINITO;
    return false;
}

int hopcroft_karp() {
    int matching = 0;

    for (int i = 0; i < N; ++i) {
        grafo1[i] = SINK;
    }
    for (int j = 0; j < M; ++j) {
        grafo2[j] = SINK;
    }

    while (bfs()) {
        for (int i = 0; i < N; ++i) {
            if (grafo1[i] == SINK) {
                matching += dfs(i);
            }
        }
    }
    return matching;
}

int main() {
        // inside in main() ggg al estilo halim
          //N primer conjunto
          //M segundo conjunto
          //P numero de relaciones (arcos)
    scanf("%i %i %i", &N, &M, &P);
          //clear
    for (int i = 0; i < N; ++i) {
        adj[i] = list< int >();
    }

    for (int i = 0; i < P; ++i) {
        int u, v;

        scanf("%i %i", &u, &v);
        --u; --v;
        adj[u].push_back(v);
    }

    printf("%i\n", hopcroft_karp());

    return 0;
}
