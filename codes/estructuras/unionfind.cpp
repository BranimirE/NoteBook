#define MAX 100010

using namespace std;

int padre[ MAX ];
int rango[ MAX ];

void MakeSet( int n ){for(int i = 0 ; i <= n ; ++i )padre[ i ] = i, rango[ i ] = 0;}
int Find(int x){return (padre[x]==x?x:padre[x]=Find(padre[x]));}
bool sameComponent(int x, int y){ return Find(x) == Find(y);}

void Union( int x , int y ){
    int xRoot = Find( x );
    int yRoot = Find( y );
    if( rango[ xRoot ] > rango[ yRoot ] )
        padre[ yRoot ] = xRoot;            
    else{                   
        padre[ xRoot ] = yRoot;
        if( rango[ xRoot ] == rango[ yRoot ] )
            rango[ yRoot ]++;
    }
}