#include <ctime>
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int c[100000];
int tree[400001];
//si es segment tree de -,* o / solo sustituir el + en init query y update
void init(int node,int a,int b)
{
    if(a==b)
    {
        tree[node]=c[a];
        return ;
    }
    init(2*node+1,a,(a+b)/2);
    init(2*node+2,(a+b)/2+1,b);
    tree[node]=tree[2*node+1]+tree[2*node+2];
}
// consula para llamar query(0,0,n-1,desde,hasta)
int query(int node,int a,int b,int p,int q)
{
    //la consulta se hace en el rango desde p a q, a y b son los limites del rango
    if( q<a || b<p )return 0;
    if(p<=a && b<=q)
    {
        return tree[node];
    }
    return query(2*node+1,a,(a+b)/2,p,q)+query(2*node+2,(a+b)/2+1,b,p,q);
}
//sustituir para llamar(0,0,n-1,posicion,valor)
void update(int node,int a,int b,int p,int val)
{
    if(p<a || b<p)return;
    if(a==b)
    {
        tree[node]=val;
        return ;
    }
    update(2*node+1,a,(a+b)/2,p,val);
    update(2*node+2,(a+b)/2+1,b,p,val);
    tree[node]=tree[2*node+1]+tree[2*node+2];
}

int main()
{
    int n,aux;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&aux);
        c[i]=aux;
    }
    init(0,0,n-1);
    //ejemplo de sustitucion tree[a]=val
    int a,b;
    int val;
    scanf("%d %d",&a,&val);
    a--;//solo si los subindices del problema van de 1...n
    update(0,0,n-1,a,val);
    //ejemplo de consulta x=SUM(a,a+1,....,b)
    scanf("%d %d",&a,&b);
    a--;//solo si los subindices del problema van de 1...n
    b--;//solo si los subindices del problema van de 1...n
    int x=query(0,0,n-1,a,b);
    printf("%d\n",x);
    printf("\n");
    return 0;
}
