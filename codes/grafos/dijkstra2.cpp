#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
#define MAX 10005
#define Node pair< int , int >
#define INF 1<<30
struct cmp {
    bool operator() ( const Node &a , const Node &b ) {
        return a.second > b.second;
    }
};
vector< Node > ady[ MAX ];
int distancia[ MAX ];
bool visitado[ MAX ];
priority_queue< Node , vector<Node> , cmp > Q;
int V;
int previo[ MAX ];


void init(){
    for( int i = 0 ; i <= V ; ++i ){
        distancia[ i ] = INF;
        visitado[ i ] = false;
        previo[ i ] = -1;
    }
}
void relajacion( int actual , int adyacente , int peso ){
    if( distancia[ actual ] + peso < distancia[ adyacente ] ){
        distancia[ adyacente ] = distancia[ actual ] + peso;
        previo[ adyacente ] = actual;
        Q.push( Node( adyacente , distancia[ adyacente ] ) );
    }
}
void print( int destino ){
    if( previo[ destino ] != -1 )
        print( previo[ destino ] );
    printf("%d " , destino );
}

void dijkstra( int inicial ){
    init();
    Q.push( Node( inicial , 0 ) );
    distancia[ inicial ] = 0;
    int actual , adyacente , peso;
    while( !Q.empty() ){
        actual = Q.top().first;
        Q.pop();
        if( visitado[ actual ] ) continue;
        visitado[ actual ] = true;

        for( int i = 0 ; i < ady[ actual ].size() ; ++i ){
            adyacente = ady[ actual ][ i ].first;
            peso = ady[ actual ][ i ].second;
            if( !visitado[ adyacente ] ){
                relajacion( actual , adyacente , peso );
            }
        }
    }


    printf( "Distancias mas cortas iniciando en vertice %d\n" , inicial );
    for( int i = 1 ; i <= V ; ++i ){
        printf("Vertice %d , distancia mas corta = %d\n" , i , distancia[ i ] );
    }

    puts("\n**************Impresion de camino mas corto**************");
    printf("Ingrese vertice destino: ");
    int destino;
    scanf("%d" , &destino );
    print( destino );
    printf("\n");
}


int main(){
    int E , origen, destino , peso , inicial;
    scanf("%d %d" , &V , &E );
    while( E-- ){
        scanf("%d %d %d" , &origen , &destino , &peso );
        ady[ origen ].push_back( Node( destino , peso ) ); //consideremos grafo dirigido
        //ady[ destino ].push_back( Node( origen , peso ) ); //grafo no dirigido
    }
    printf("Ingrese el vertice inicial: ");
    scanf("%d" , &inicial );
    dijkstra( inicial );
    return 0;
}
