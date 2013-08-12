#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 50001

struct nodo{
    int sum;
    nodo() { }
    nodo(int _sum){
        sum = _sum;  
    }
}T[MAXN*4];
int n, a[MAXN];

void update(int b, int e, int node, int i, int val){
    if(i < b || i > e) return;

    if( b == e ) T[node].sum = a[i] = val;
    else{
        int mid = (b + e)/2, le = 2*node, ri = 2*node+1;
        
        update(b, mid, le, i, val);
        update(mid + 1, e, ri, i, val);
        
        T[node].sum  = T[le].sum + T[ri].sum;
    }
}

void init(int b, int e, int node){
    if(b == e) T[node].sum = a[b];
    else{
        int mid = (b + e)/2, le = 2*node, ri = 2*node+1;
        init(b, mid, le);
        init(mid + 1, e, ri);
        
        T[node].sum  = T[le].sum + T[ri].sum;
    }
}

nodo query(int b, int e, int node, int i, int j){
    if(i <= b && e <= j) return T[node];
    
    int mid = (b + e) / 2, le = 2*node + 1, ri = 2*node + 2;
    
    if(j <= mid) return query(b, mid, le, i, j);
    else if(mid < i) return query(mid + 1, e, ri, i, j);
    else{
        nodo ret1 = query(b, mid, le, i, j);
        nodo ret2 = query(mid + 1, e, ri, i, j);
        
        nodo ret;
        ret.sum  = ret1.sum + ret2.sum;
        return ret;
    }
}

int main(){
    init(0, n, 0);
    printf("%d\n", query(1, n, 1, x, y).sum);
    update(1, n, 1, x, y);    
	return 0;
}
