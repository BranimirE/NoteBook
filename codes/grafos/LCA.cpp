#include <cctype>
#include <cstdio>
#include <iostream>
#define NN 100048
using namespace std;

// LCA con pesos halla camino corto desde a hasta b con numero de consultas q

int P[NN][17], L[NN];
long long W[NN];

int query(int p, int q)
{
    int log, i;
    if (L[p] < L[q]) p ^= q ^= p ^= q;
    for (log = 1; 1 << log <= L[p]; log++);
    log--;
    for (i = log; i >= 0; i--)
        if (L[p] - (1 << i) >= L[q])
            p = P[p][i];
    if (p == q) return p;
    for (i = log; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];

    return P[p][0];
}
int main(void)
{
    int a, b, N, q;
    cin>>N;//nodos
    long long w;
    P[0][0] = -1;
    L[0] = W[0] = 0;
    int lados;
    cin>>lados;
    int ii;//(ii<=>desde), (a<=> hasta), (w<=>peso)
    for(int i = 0; i < lados; ++i)
    {
        cin>>ii>>a>>w;
        for(int j = 0; (1 << j) < N; ++j) P[ii][j] = -1;
        P[ii][0] = a;
        L[ii] = L[a] + 1;
        W[ii] = W[a] + w;
    }
    for(int j = 1; (1 << j) < N; ++j)
        for(int i = 0; i < N; ++i)
            if(P[i][j - 1] != -1)
                P[i][j] = P[P[i][j - 1]][j - 1];
    cin>>q;
    while(q--)
    {
        cin>>a>>b;
        printf("%lld\n", W[a] + W[b] - (W[query(a, b)] << 1));
    }
    return 0;
}
